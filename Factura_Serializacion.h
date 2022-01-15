#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <fstream>
#include <cstring>
//#include <cstdlib>
//#include <string.h>

using namespace std;

class Orden
{
public:
    char numero_factura[4],fecha[10],usuario[40],rfc[15],cantidad[10],direccion[40];
    
    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();
} factura;

void Orden::Agregar()
{
    cout<<"GENERAR FACTURA"<<endl;
    cout<<"Numero de factura: ";
    cin.getline(numero_factura,4);
    cin.getline(numero_factura,4);
    cout<<"Fecha: ";
    cin.getline(fecha,10);
    cout<<"Usuario: ";
    cin.getline(usuario,40);
    cout<<"RFC: ";
    cin.getline(rfc,15);
    cout<<"Cantidad: ";
    cin.getline(cantidad,10);
    cout<<"Direccion: ";
    cin.getline(direccion,40);
    ofstream archivo("facturas.txt",ios::app);
    archivo.write((char*)&factura,sizeof(factura));
    archivo.close();
}
void Orden::Mostrar()
{
    // char usuario2[10], password2[10];
    int band=0;
    ifstream archivo("facturas.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"FACTURAS"<<endl;
        while(!archivo.eof())
        {
            archivo.read((char*)&factura,sizeof(factura));
            if(archivo.eof())
            {
                break;
            }
            cout<<"Numero de factura: "<<numero_factura<<endl;
            cout<<"Fecha: "<<fecha<<endl;
            cout<<"Usuario: "<<usuario<<endl;
            cout<<"RFC: "<<rfc<<endl;
            cout<<"Cantidad: "<<cantidad<<endl;
            cout<<"Direccion: $"<<direccion<<endl;
            cout<<""<<endl;
        }
        archivo.close();
    }
}

void Orden::Modificar()
{
    char num_factura_buscar[4];
    ifstream archivo("facturas.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"MODIFICAR FACTURA"<<endl;
        cout<<"Ingrese el numero de factura a modificar: ";
        cin.getline(num_factura_buscar,4);
        cin.getline(num_factura_buscar,4);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&factura,sizeof(factura));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(numero_factura,num_factura_buscar)==0)
            {
                cout<<""<<endl;
                cout<<"Nuevo numero de factura: ";
                cin.getline(numero_factura,4);
                cout<<"Nueva fecha: ";
                cin.getline(fecha,10);
                cout<<"Nuevo usuario: ";
                cin.getline(usuario,40);
                cout<<"Nuevo rfc: ";
                cin.getline(rfc,15);
                cout<<"Nueva Cantidad: ";
                cin.getline(cantidad,10);
                cout<<"Nuevo direccion: ";
                cin.getline(direccion,40);
                ofstream archivo("facturas.txt",ios::app);
                archivo2.write((char*)&factura,sizeof(factura));
            }
            else
            {
                archivo2.write((char*)&factura,sizeof(factura));
            }

        }
        archivo.close();
        archivo2.close();
        remove("facturas.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="facturas.txt";
        rename(oldname,newname);
    }
}
void Orden::Eliminar()
{
    char num_factura_buscar[4];
    int opcion=0;
    ifstream archivo("facturas.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"ELIMINAR FACTURA"<<endl;
        cout<<"Ingrese el numero de factura a eliminar: ";
        cin.getline(num_factura_buscar,4);
        cin.getline(num_factura_buscar,4);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&factura,sizeof(factura));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(numero_factura,num_factura_buscar)==0)
            {
                cout<<"\tFactura Encontrada"<<endl;
                cout<<"Numero de factura: "<<numero_factura<<endl;
                cout<<"Fecha: "<<fecha<<endl;
                cout<<"Usuario: "<<usuario<<endl;
                cout<<"RFC: "<<rfc<<endl;
                cout<<"Cantidad: "<<cantidad<<endl;
                cout<<"Direccion: $"<<direccion<<endl;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&factura,sizeof(factura));
                }
            }
            else
            {
                archivo2.write((char*)&factura,sizeof(factura));
            }
        }
        archivo.close();
        archivo2.close();
        remove("facturas.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="facturas.txt";
        rename(oldname,newname);
    }

}

void Orden::Buscar()
{
    char num_factura_buscar[5];
    ifstream archivo("facturas.txt");
    bool encontrado = 0;

    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"BUSCAR FACTURA"<<endl;
        cout<<"Ingrese el numero de factura a buscar: ";
        cin.getline(num_factura_buscar,4);
        cin.getline(num_factura_buscar,4);
        
        while (!archivo.eof())
        {
            archivo.read((char*)&factura,sizeof(factura));

            if(strcmp(numero_factura,num_factura_buscar)==0)
            {
                cout<<"\tFactura Encontrada"<<endl;
                cout<<"Numero de factura: "<<numero_factura<<endl;
                cout<<"Fecha: "<<fecha<<endl;
                cout<<"Usuario: "<<usuario<<endl;
                cout<<"RFC: "<<rfc<<endl;
                cout<<"Cantidad: "<<cantidad<<endl;
                cout<<"Direccion: $"<<direccion<<endl;

                encontrado = 1;
                break;
            }
            else
            {
                // cout << "Factura no encontrada..." << endl;
            }
        }

        if (!encontrado)
        {
            cout << "Factura no encontrada..." << endl;
        }
    }
    archivo.close();
}

void Pausar()
{
    cin.get();
    cout << "Presione entrar para continuar..." << endl;
    cin.get();
    system("cls");
}


#endif