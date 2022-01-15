#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#define NUMREGISTROS 100
#define CONTENEDOR   4

class Pago
{
    private:
        char id[ 12 ];
        char usuario[ 40 ];
        char fecha[ 10 ];
        char precio[ 10 ];

        int dispersion( const char llave[ 12 ] );
        long int buscarId( const string & );
    public:
        Pago( void );
        Pago( const Pago & );
        void setId( const string & );
        void setUsuario( const string & );
        void setFecha( const string & );
        void setPrecio( const string & );
        friend ostream &operator<<( ostream &, const Pago & );

        bool agregar( const Pago & );
        void mostrar( void );
        bool buscar( const string &, Pago & );
        bool eliminar( const string &, Pago & );
        bool modificar( const string &, const Pago & );
        void mostrarIndice( void );
        Pago pedirRegistro( void );
        bool contiene( const string & );
        void genera( void );
};


// constructor
Pago::Pago( void )
{
    for( int i = 0; i < sizeof( id ); id[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( usuario ); usuario[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( fecha ); fecha[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( precio ); precio[ i++ ] = '\0' );
}


bool Pago::contiene( const string &idABuscar )
{
    if( buscarId( idABuscar ) == -1 )
        return false;
    return true;
}


Pago Pago::pedirRegistro( void )
{
    Pago registroARetornar;
    string cadena;

    cout << endl << "ID: ";
    fflush( stdin );
    getline( cin, cadena );
    while( contiene( cadena ) || cadena.size() == 0 )
    {
        cout << "Ese ID ya existe o la cadena es invalida: ";
        fflush( stdin );
        getline( cin, cadena );
    }
    registroARetornar.setId( cadena );

    cout << "Usuario: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setUsuario( cadena );

    cout << "Fecha: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setFecha( cadena );
    
    cout << "Precio: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setPrecio( cadena );

    return registroARetornar;
}



void Pago::genera( void )
{
    Pago promo;
    int contador = 0;
    ofstream archivo( "dispersion2.txt", ios::out );
    if( !archivo )
        cout << "No se pudo crear el archivo" << endl;
    else
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
        	// indica cuantos registros hay en el contenedor
        	archivo.write( ( char * ) &contador, sizeof( int ) );
        	for( int j = 0; j < CONTENEDOR; j++ )
            	archivo.write( ( char * ) &promo, sizeof( Pago ) );
        }
    archivo.close();
}

int Pago::dispersion( const char llave[ 12 ] )
{
    // llena la el sobrante de la llave con espacios
    char llaveCopia[ 12 ];
    strcpy( llaveCopia, llave );
    if( strlen( llaveCopia ) < 12 )
        for( int i = strlen( llaveCopia ); i < 12; i++ )
            llaveCopia[ i ] = ' ';
    llaveCopia[ 12 ] = '\0';

    // realiza el algoritmo
    long sum = 0;
    int j = 0;
    while( j < 12 )
    {
        sum = ( sum + 100 * llaveCopia[ j ] + llaveCopia[ j + 1 ] )  % 20000;
        j += 2;
    }
    return ( sum % 99 ); // retorna la posición donde se guardará el registros.
}

// retorna la posición donde se encontro el registro
long int Pago::buscarId( const string &idABuscar )
{
    Pago promo;
    int contador, posIndice;
    long int posByte;

    ifstream archivo( "dispersion2.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return -1;
    }

    posIndice = dispersion( idABuscar.c_str() );
    posByte = posIndice * ( ( sizeof( Pago ) * CONTENEDOR ) + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    if( contador > 0 )
    {
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &promo, sizeof( Pago ) );
            if( strcmp( promo.id, idABuscar.c_str() ) == 0 )
            {
                posByte = ( long )archivo.tellg() - sizeof( Pago );
                archivo.close();
                return posByte;
            }
        }
    }

    archivo.close();
    return -1;
}

void Pago::setId( const string &valorId )
{
    int longitud = valorId.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorId.copy( id, longitud );
    id[ longitud ] = '\0';
}

void Pago::setUsuario( const string &valorusuario )
{
    int longitud = valorusuario.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorusuario.copy( usuario, longitud );
    usuario[ longitud ] = '\0';
}

void Pago::setFecha( const string &valorfecha )
{
    int longitud = valorfecha.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorfecha.copy( fecha, longitud );
    fecha[ longitud ] = '\0';
}

void Pago::setPrecio( const string &valorPrecio )
{
    int longitud = valorPrecio.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorPrecio.copy( precio, longitud );
    precio[ longitud ] = '\0';
}

ostream &operator<<( ostream &salida, const Pago &Pago )
{
    salida << "ID:        " << Pago.id << endl
            << "Producto:  " << Pago.usuario << endl
            << "Fecha: " << Pago.fecha << endl
            << "Precio:    " << Pago.precio << endl;

    return salida;
}

bool Pago::agregar( const Pago &nuevaPago )
{
    Pago promo;
    string cadena;
    int posIndice, contador;
    long int posByte;
    string idString = nuevaPago.id;

    if( contiene( idString ) )
        return false;

    fstream archivo( "dispersion2.txt", ios::in | ios::out );
    posIndice = dispersion( nuevaPago.id );
    cout << "Se guardara en la posicion indice: " << posIndice << endl;
    posByte = posIndice * ( sizeof( Pago ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) ); // lee el numero de registros en el contador
    if( contador < CONTENEDOR ) // si el contenedor no esta lleno
    {
        // aumenta el contador y lo escribe
        contador++;
        archivo.seekg( posByte, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // escribe el nuevo registro en el contenedor
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &promo, sizeof( Pago ) );
            if( promo.id[ 0 ] == '\0' )
            {
                archivo.seekg( ( long )archivo.tellg() - sizeof( Pago ), ios::beg );
                archivo.write( ( char * ) &nuevaPago, sizeof( Pago ) );
                archivo.close();
                return true;
            }
        }

    }
    else
        cout << endl << "No hay mas espacio para este registro" << endl;
    archivo.close();
    return false;
}

void Pago::mostrar( void )
{
    Pago promo;
    int contador;
    long int posByte;

    ifstream archivo( "dispersion2.txt", ios::in );
    if( !archivo )
        cout << "No existe el archivo" << endl;
    else
    {
        cout << endl;
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
            archivo.read( ( char * ) &contador, sizeof( int ) );
            if( contador > 0 )
            {
                for( int j = 0; j < CONTENEDOR; j++ )
                {
                    archivo.read( ( char * ) &promo, sizeof( Pago ) );
                    if( promo.id[ 0 ] != '\0' )
                        cout << promo << endl;
                }
            }
            else
                archivo.seekg( sizeof( Pago ) * CONTENEDOR, ios::cur );
        }
    }
    archivo.close();
}

bool Pago::buscar( const string &idABuscar, Pago &PagoEncontrada )
{
    long int posByte;

    if( !contiene( idABuscar ) )
        return false;

    ifstream archivo( "dispersion2.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return false;
    }
    
    posByte = buscarId( idABuscar );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &PagoEncontrada, sizeof( Pago ) );
    archivo.close();
    return true;
}

bool Pago::modificar( const string &idAModificar, const Pago &PagoNueva )
{
    Pago registroLimpio, promo;
    int posIndiceAntiguo, posIndiceNuevo, contador;
    long int posByteAntiguo, posByteNuevo;

    if( !contiene( idAModificar ) )
        return false;

    fstream archivo( "dispersion2.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    }

    posIndiceAntiguo = dispersion( idAModificar.c_str() );
    posByteAntiguo = buscarId( idAModificar );
    posIndiceNuevo = dispersion( PagoNueva.id );
    posByteNuevo = posIndiceNuevo * ( sizeof( Pago ) * CONTENEDOR + sizeof( int ) );

    if( posByteAntiguo == posByteNuevo )
    {
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &PagoNueva, sizeof(  Pago) );
    }
    else
    {
        // quita el registro antiguo y resta uno al contador del contenedor
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &registroLimpio, sizeof( Pago ) );
        posByteAntiguo = posIndiceAntiguo * ( sizeof( Pago ) * CONTENEDOR + sizeof( int ) );
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        contador--; 
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // intenta meter el nuevo registro en la nueva posicion
        archivo.seekg( posByteNuevo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        if( contador < CONTENEDOR )
        {
            // aumenta el contador y lo escribe
            contador++;
            archivo.seekg( posByteNuevo, ios::beg );
            archivo.write( ( char * ) &contador, sizeof( int ) );

            // escribe el nuevo registro en el contenedor
            for( int i = 0; i < CONTENEDOR; i++ )
            {
                archivo.read( ( char * ) &promo, sizeof( Pago ) );
                if( promo.id[ 0 ] == '\0' ) // si el lugar no esta ocupado
                {
                    archivo.seekg( ( long )archivo.tellg() - sizeof( Pago ), ios::beg );
                    archivo.write( ( char * ) &PagoNueva, sizeof( Pago ) );
                    archivo.close();
                    return true;
                }
            }
        }
        else // el contenedor esta lleno
            return false;
    }
    return -1;
} // fin funcion modificar

bool Pago::eliminar( const string &idAEliminar, Pago &destinoEliminado )
{
    Pago promo;
    int posIndice, posByte, contador;

    if( !contiene( idAEliminar ) )
        return false;

    fstream archivo( "dispersion2.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    } 

    posIndice = dispersion( idAEliminar.c_str() );
    posByte = buscarId( idAEliminar );

    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &destinoEliminado, sizeof(  Pago) );
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &promo, sizeof(  Pago) );

    posByte = posIndice * ( sizeof( Pago ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    contador--;
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &contador, sizeof( int ) );
    archivo.close();
    return true;
}

