#ifndef MENU_H
#define MENU_H

#include<iostream>
using namespace std;

#include "Usuario_LongitudFija.h"
#include "Pelicula_Delimitadores.h"
#include "Serie_CamposDeDimension.h"
#include "ListaRep_IndicesSimples.h"
#include "Factura_Serializacion.h"
#include "Pagos_Hashing.h"

void Pausar();

class Menu
{
private:
    /* data */
public:
    void usuarios();
    void peliculas();
    void series();
    void listas();
    void facturas();
    void pagos();
};

void Menu::usuarios()
{
    int op;
    do
    {
        system("cls");
        cout<<"MENU de Usuarios"<<endl;
        cout<<"1.-Capturar " <<endl;
        cout<<"2.-Imprimir todo" <<endl;
        cout<<"3.-Modificar "<<endl;
        cout<<"4.-Eliminar" <<endl;
        cout<<"5.-Buscar "<<endl;
        cout<<"6.-Salir "<<endl;
        cout<<"Ingresa la opcion->";
        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            n_user.Agregar();
            Pausar();
            break;
        case 2:
            system("cls");
            n_user.Mostrar();
            Pausar();
            break;
        case 3:
            system("cls");
            n_user.Modificar();
            Pausar();
            break;
        case 4:
            system("cls");
            n_user.Eliminar();
            Pausar();
            break;
        case 5:
            system("cls");
            n_user.Buscar();
            Pausar();
            break;
        case 6:
            op=6;
            break;
        }
    }
    while(op!=6);
}

void Menu::peliculas()
{
    Pelicula objeto;
    int op;
    do
    {
        system("cls");
        cout<<"MENU de Peliculas"<<endl;
        cout<<"\nIngresa el numero de la opcion: \n1.Capturar\n2.Imprimir todo \n3.Buscar \n4.Eliminar \n5.Modificar \n6.Salir \n";
        cin>>op;
        switch(op)
        {
        case 1:
            objeto.Capturar();
            break;
        case 2:
            objeto.Imprimir();
            break;
        case 3:
            objeto.Buscar();
            break;
        case 4:
            objeto.Eliminar();
            break;
        case 5:
            objeto.Modificar();
            break;
        default:
            break;
        }
    }while(op!=6);
}

void Menu::series()
{
Serie serie;
	
    int opcion;
	do{
        system("cls");
        cout<<"MENU de Series"<<endl;
		cout<<"\n\tSELECCIONE LA OPCION DESEADA\n1.- AGREGAR\n2.- MOSTRAR\n3.- BUSCAR\n4.- MODIFICAR\n5.- ELIMINAR\n6.- SALIR\n>: ";
		cin>>opcion;

        
		switch(opcion) {
            case 1:
                serie.Agregar();
                break;
            case 2:
                serie.Mostrar();
                break;
            case 3:
                serie.Buscar();
                break;
            case 4:
                serie.Modificar();
                break;
            case 5:
                serie.Eliminar();
                break;
            case 6:
                cout << "Adios, Vaquero!" << endl;
                break;
            default:
                cout << "OPCION INCORRECTA...."<<endl;
        }
        system("Pause");
    }while(opcion != 6);

}

void Menu::listas()
{
    int opc;
    do{
    system("cls");
    cout<<"MENU de Listas de Reproduccion"<<endl;
    cout<<"Selecciona una de la siguientes opciones:"<<endl<<"1.-Capturar"<<endl<<"2.-Buscar"<<endl<<"3.-Mostrar todos"<<endl<<"4.-Modificar"<<endl<<"5.-Eliminar"<<endl<<"6.-Mostrar Indices\n0.-SALIR"<<endl;
    cin>>opc;
    switch(opc)
    {

        case 1:
            x.capturar();
            break;
        case 2:
            x.buscar();
            break;

        case 3:
            x.mostrar();
            break;

        case 4:
            x.Modificar();
            break;

        case 5:
            x.Eliminar();

            break;

        case 6:
            x.Mostrar_Indice(); 
            break;

        default:
            break;
        //case 7:x.Orden(); break;
    }
    getch();
    }while(opc!=0);
}

void Menu::facturas()
{
int op;
    do
    {
        system("cls");
        cout<<"MENU DE Facturas"<<endl;
        cout<<"1.-Capturar" <<endl;
        cout<<"2.-Mostrar todo" <<endl;
        cout<<"3.-Modificar "<<endl;
        cout<<"4.-Eliminar" <<endl;
        cout<<"5.-Buscar "<<endl;
        cout<<"6.-Salir "<<endl;
        cout<<"Ingresa la opcion->";
        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            factura.Agregar();
            Pausar();
            break;
        case 2:
            system("cls");
            factura.Mostrar();
            Pausar();
            break;
        case 3:
            system("cls");
            factura.Modificar();
            Pausar();
            break;
        case 4:
            system("cls");
            factura.Eliminar();
            Pausar();
            break;
        case 5:
            system("cls");
            factura.Buscar();
            Pausar();
            break;
        case 6:
            op=6;
            break;
        default:
            cout << "Opcion invalida, intenta de nuevo" << endl;
            Pausar();
            break;
        }
    }
    while(op!=6);
}

void Menu::pagos()
{
    Pago pago, pagoBuscar, pagoModificar, pagoEliminar, registroAgregar;
    string idABuscar, idAModificar, idAEliminar;
    char opcion, op;

    pago.genera();
        
    do{
        system("cls");
        cout<<"MENU de Pagos"<<endl;
        cout<<"Seleccione una opcion" << endl
            << "1. Agregar"   << endl
            << "2. Mostrar"   << endl
            << "3. Buscar"    << endl
            << "4. Modificar" << endl
            << "5. Eliminar"  << endl
            << "6. Salir"     << endl
            << endl;
        cin >> opcion;
        switch( opcion )
        {
          case '1':
            registroAgregar = pago.pedirRegistro();
            if( pago.agregar( registroAgregar ) )
                cout << "Pago agregado con exito" << endl;
            else
                cout << "No se agrego el pago" << endl;
            break;

          case '2':
            system( "cls" );
            pago.mostrar();
            break;

          case '3':
            cout << "Ingrese el ID del pago a buscar: ";
            fflush( stdin );
            getline( cin, idABuscar );
            if( pago.buscar( idABuscar, pagoBuscar ) )
                cout << endl << pagoBuscar << endl;
            else
                cout << "No existe registro de ese pago" << endl;
            break;

          case '4':
            cout << "Ingrese el ID del pago a modificar: ";
            fflush( stdin );
            getline( cin, idAModificar );
            if( pago.buscar( idAModificar, pagoBuscar ) )
            {
                cout << endl << pagoBuscar << endl;
                cout << "Desea modificarlo?" << endl;
                cout << "1) Si" << endl;
                cout << "2) No" << endl;
                cin >> op;

                if( op == '1' )
                {
                    pagoModificar = pago.pedirRegistro();
                    if( pago.modificar( idAModificar, pagoModificar ) )
                        cout << endl << "Pago modificada con exito" << endl;
                    else
                        cout << endl << "No se pudo modificar el pago" << endl;
                }
            }
            else
                cout << "No existe el registro" << endl;
            break;

          case '5':
            cout << "Ingrese el ID del pago a eliminar: ";
            fflush( stdin );
            getline( cin, idAEliminar );
            if( pago.buscar( idAEliminar, pagoBuscar ) )
            {
                cout << endl << pagoBuscar << endl;
                cout << "Desea eliminarlo?" << endl;
                cout << "1) Si" << endl;
                cout << "2) No" << endl;
                cin >> op;

                if( op == '1' )
                    if( pago.eliminar( idAEliminar, pagoEliminar ) )
                        cout << endl << pagoEliminar << endl << "SE ELIMINO CORRECTAMENTE" << endl;
                    else
                        cout << "NO SE PUDO ELIMINAR" << endl;
            }
            else
                cout << "No existe el registro" << endl;
            break;
        }
        cout << endl;
        system("Pause");
        system( "cls" );
    }while(opcion != '6');
}


#endif 