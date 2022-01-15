#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Usuario
{
public:
    char nombres[40],apellidos[40],telefono[15],correo[50],rfc[15],tarjeta[20];
    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();
}n_user;
void Usuario::Agregar()
{
    cout<<"GENERAR NUEVO USUARIO"<<endl;
    cout<<"Nombres: ";
    cin.getline(nombres,40);
    cin.getline(nombres,40);
    cout<<"Apellidos: ";
    cin.getline(apellidos,40);
    cout<<"Telefono: ";
    cin.getline(telefono,15);
    cout<<"Correo: ";
    cin.getline(correo,50);
    cout<<"RFC: ";
    cin.getline(rfc,15);
    cout<<"Numero de Tarjeta: ";
    cin.getline(tarjeta,20);
    ofstream archivo("usuarios.txt",ios::app);
    archivo.write((char*)&n_user,sizeof(n_user));
    archivo.close();
}
void Usuario::Mostrar()
{
    char usuario2[10], password2[10];
    int band=0;
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"USUARIOS: "<<endl;
        while(!archivo.eof())
        {
            archivo.read((char*)&n_user,sizeof(n_user));
            if(archivo.eof())
            {
                break;
            }
            cout<<"Nombre: "<<nombres<<endl;
            cout<<"Apellidos: "<<apellidos<<endl;
            cout<<"Telefono: "<<telefono<<endl;
            cout<<"Correo: "<<correo<<endl;
            cout<<"RFC: "<<rfc<<endl;
            cout<<"Numero de Tarjeta: $"<<tarjeta<<endl;
            cout<<""<<endl;
        }
        archivo.close();
    }
}
void Usuario::Modificar()
{
    char valor[40];
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"MODIFICAR USUARIO"<<endl;
        cout<<"Ingrese el RFC del usuario a modificar: ";
        cin.getline(valor,40);
        cin.getline(valor,40);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&n_user,sizeof(n_user));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(rfc,valor)==0)
            {
                cout<<""<<endl;
                cout<<"Nuevos nombres: ";
                cin.getline(nombres,40);
                cout<<"Nuevos apellidos: ";
                cin.getline(apellidos,40);
                cout<<"Nuevo telefono: ";
                cin.getline(telefono,15);
                cout<<"Nuevo correo: ";
                cin.getline(correo,50);
                cout<<"Nuevo RFC: ";
                cin.getline(rfc,15);
                cout<<"Nuevo numero de tarjeta: ";
                cin.getline(tarjeta,20);
                ofstream archivo("usuarios.txt",ios::app);
                archivo2.write((char*)&n_user,sizeof(n_user));
            }
            else
            {
                archivo2.write((char*)&n_user,sizeof(n_user));
            }

        }
        archivo.close();
        archivo2.close();
        remove("usuarios.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="usuarios.txt";
        rename(oldname,newname);
    }
}
void Usuario::Eliminar()
{
    char valor[40];
    int opcion=0;
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"ELIMINAR ORDEN DE COMPRA"<<endl;
        cout<<"Ingrese el RFC del Usuario a eliminar: ";
        cin.getline(valor,40);
        cin.getline(valor,40);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&n_user,sizeof(n_user));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(rfc,valor)==0)
            {
                cout<<"\tUsuario Encontrado"<<endl;
                cout<<"Nombre: "<<nombres<<endl;
                cout<<"Apellido: "<<apellidos<<endl;
                cout<<"Telefono: "<<telefono<<endl;
                cout<<"Correo: "<<correo<<endl;
                cout<<"RFC: "<<rfc<<endl;
                cout<<"Numero de Tarjeta: $"<<tarjeta<<endl;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&n_user,sizeof(n_user));
                }
            }
            else
            {
                archivo2.write((char*)&n_user,sizeof(n_user));
            }
        }
        archivo.close();
        archivo2.close();
        remove("usuarios.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="usuarios.txt";
        rename(oldname,newname);
    }

}
void Usuario::Buscar()
{
    bool encontrado = false;
    char valor[40];
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"BUSCAR USUARIO"<<endl;
        cout<<"Ingrese el RFC del Usuario a buscar: ";
        cin.getline(valor,40);
        cin.getline(valor,40);

        while (!archivo.eof())
        {
            archivo.read((char*)&n_user,sizeof(n_user));
            if(strcmp(rfc,valor)==0)
            {
                cout<<"\tUsuario Encontrado"<<endl;
                cout<<"Nombre: "<<nombres<<endl;
                cout<<"Apellidos: "<<apellidos<<endl;
                cout<<"Telefono: "<<telefono<<endl;
                cout<<"Correo: "<<correo<<endl;
                cout<<"RFC: "<<rfc<<endl;
                cout<<"Numero de Tarjeta: $"<<tarjeta<<endl;

                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Usuario no encontrada..." << endl;
        } 
        
        
    }
    archivo.close();
}

#endif