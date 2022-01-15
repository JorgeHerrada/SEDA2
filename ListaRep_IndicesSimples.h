#ifndef LISTA_REP_H
#define LISTA_REP_H

#include "Pelicula_Delimitadores.h"

#include <iostream>
#include <fstream>
#include <string.h>
//#include <stdlib.h>
#include <conio.h>
//#include <vector>

using namespace std;
//int orden=0;

class Lista_Rep
{
    public:
    char usuario[40], list_name[30]; 
    Pelicula peliculas[10]; //numero limite de peliculas en la lista
    int num_peliculas; // numero de peliculas 

    void capturar();
    void buscar();
    void mostrar();
    void Modificar();
    void Eliminar();
    void Mostrar_Indice();
    //void Orden();
}x;

class Indice
{
    public:
    char usuario[40];
    long int pos;

}y;

void Lista_Rep::mostrar()
{
    ifstream data("datos.txt");
    if(!data.good())
    cout<<"No existe el archivo";
    else
    {
        while(!data.eof())
        {
            data.read((char*)&x,sizeof(x));
            if(data.eof())
                break;
            cout<<"Usuario:"<<x.usuario<<endl<<"Lista:"<<x.list_name<<endl;
            cout << "Peliculas: \n";

            for (size_t i = 0; i < x.num_peliculas; i++)
            {
                x.peliculas[i].Imprimir_Pelicula();
                cout << "\n";
            }
            

            cout<<"\n";
        }
    }
    data.close();
}

void Lista_Rep::Mostrar_Indice()
{
  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&y,sizeof(y));
            if(a.eof())
                break;
            cout<<"Usuario:"<<y.usuario<<endl<<endl;
        }
    }
    a.close();
}




void Lista_Rep::capturar()
{
    Pelicula pelicula;
    fflush(stdin);
    cout<<"Usuario que crea la lista: "<<endl;
    cin.getline(x.usuario,40);
    cout<<"Nombre de la lista de reproduccion: "<<endl;
    cin.getline(x.list_name,30);

    string conf;
    // Agregando peliculas
    for (size_t i = 0; i < 10; i++)
    {
        pelicula.Capturar(); // capturar datos de pelicula
        x.peliculas[i] = pelicula; // guardar en lista de reproduccion

        cout << "¿Deseas agregar otra pelicula?  Y/N" << endl;
        getline(cin,conf);

        if (conf == "N" || conf == "n")
        {
            num_peliculas = i + 1;
            break;
        }
        else if (conf == "Y" || conf == "y")
        {
            /* code */
        }
        else
        {
            cout << conf << " No es una respuesta valida.No se agregaran nuevos elementos. "<<endl;
            num_peliculas = i+1;
            break;
        }

        if(i == 9)
        {
            cout << "Se ha alcanzado el limite de peliculas en la lista (" << i+1 << ")." <<endl;
            cout << "Si requiere listas de mayor lonjitud, contacte al administrador del sistema."<<endl;
        }
    }

    ofstream data("datos.txt",ios::app);   //Abre el archivo en modo append

    // Guarda en el archivo el objeto x, despues de haberlo convertido
    // en un puntero a un array del objeto x
    data.write((char*)&x,sizeof(x));
    // Retorna la posición del puntero en el archivo
    y.pos = data.tellp();    
    // Resta el tamaño del objeto y se obtiene la posicion dentro del
    // archivo en la cual se guardó el objeto
    y.pos -= sizeof(x);   
    data.close();

    strcpy(y.usuario,usuario);
    ofstream index("indice.txt",ios::app);
    index.write((char*)&y,sizeof(y));
    index.close();
    //orden++;
}

void Lista_Rep::buscar()
{
    char usuario_buscado[40];
    int band=0;
    //cout<<"posicion "<<y.pos;
    ifstream index("indice.txt");
    if(!index.good())
    {
        cout<<"No existe el archivo";
    }
    else
    {
        cout<<"\nUsuario a buscar!"<<endl;
        fflush(stdin);
        cin.getline(usuario_buscado,40);

        while(!index.eof())
        {
            index.read((char*)&y,sizeof(y));
            if(index.eof())
            {
                break;
            }
            if(strcmp(y.usuario,usuario_buscado)==0)
            {
                ifstream data("datos.txt");
                data.seekg(y.pos,ios::beg);
                data.read((char*)&x,sizeof(x));


                //cout<<"RFC:"<<x.usuario<<endl<<"peliculas: "<<x.peliculas<<endl<<"Direccion: "<<x.direccion<<endl<<"Colonia:"<<x.colonia<<endl<<"Ciudad:"<<x.ciudad<<endl<<"Estado:"<<estado<<endl<<"CP:"<<cp<<endl<<"Limite de Credito:"<<limite<<endl<<"Saldo:"<<x.saldo<<endl<<"Dias de credito:"<<x.dias<<endl;
                
                cout<<"Usuario:"<<x.usuario<<endl<<"Lista:"<<x.list_name<<endl;
                cout << "Peliculas: \n";

                for (size_t i = 0; i < x.num_peliculas; i++)
                {
                    x.peliculas[i].Imprimir_Pelicula();
                    cout << "\n";
                }
                
                data.close();
                band=1;
                break;
            }
        }
        if(band==0)
        {
            cout<<"\n NO EXISTE REGISTRO....."   ;
        }
    }
    index.close();
}

void Lista_Rep::Modificar()
{
    Pelicula pelicula;
    char usuario_modificar[40];
    int band=0;
    int opc;
    ifstream index("indice.txt");
    if(!index.good())
    {
        cout<<"No existe el archivo";
    }
    else
    {
        cout<<"\nUsuario a modificar"<<endl;
        fflush(stdin);cin.getline(usuario_modificar,40);

        while(!index.eof())
        {   
            opc=0;
            index.read((char*)&y,sizeof(y));
            if(index.eof())
            {
                break;
            }
            if(strcmp(y.usuario,usuario_modificar)==0 && band==0)
            {
                ifstream data("datos.txt");
                data.seekg(y.pos,ios::beg);

                data.read((char*)&x,sizeof(x));
                if(data.eof())   break;

                //cout<<"RFC:"<<x.usuario<<endl<<"peliculas: "<<x.peliculas<<endl<<"Direccion: "<<x.direccion<<endl<<"Colonia:"<<x.colonia<<endl<<"Ciudad:"<<x.ciudad<<endl<<"Estado:"<<estado<<endl<<"CP:"<<cp<<endl<<"Limite de Credito:"<<limite<<endl<<"Saldo:"<<x.saldo<<endl<<"Dias de credito:"<<x.dias<<endl;
                
                cout<<"Usuario:"<<x.usuario<<endl<<"Lista:"<<x.list_name<<endl;
                cout << "Peliculas: \n";

                for (size_t i = 0; i < x.num_peliculas; i++)
                {
                    x.peliculas[i].Imprimir_Pelicula();
                    cout << "\n";
                }
                
                cout<<"DESEAS MODIFICARLA?\n"<<"1.-Si   2.-No\n"; 
                cin>>opc;
                band=1;
                data.close();
                break;

            }//if de comparacion
         }//while

        index.close();
        if(opc==1)
        {
            fflush(stdin);
            ifstream indice("indice.txt");
            ifstream datos("datos.txt");
            while(!indice.eof())
            {
                //cout<<"entro al ciclo\n";
                indice.read((char*)&y,sizeof(y));
                datos.read((char*)&x,sizeof(x));
                //cout<<"\n Usuario: "<<y.usuario<<"\n";
                if(indice.eof())
                {
                    break;
                }
                if(strcmp(y.usuario,usuario_modificar)==0)
                {
                    fflush(stdin);
                    cout<<"Usuario que crea la lista: "<<endl;
                    cin.getline(x.usuario,40);
                    cout<<"Nombre de la lista de reproduccion: "<<endl;
                    cin.getline(x.list_name,30);

                    string conf;
                    // Agregando peliculas
                    for (size_t i = 0; i < 10; i++)
                    {
                        pelicula.Capturar(); // capturar datos de pelicula
                        x.peliculas[i] = pelicula; // guardar en lista de reproduccion

                        cout << "¿Deseas agregar otra pelicula?  Y/N" << endl;
                        getline(cin,conf);

                        if (conf == "N" || conf == "n")
                        {
                            num_peliculas = i + 1;
                            break;
                        }
                        else if (conf == "Y" || conf == "y")
                        {
                            /* code */
                        }
                        else
                        {
                            cout << conf << " No es una respuesta valida.No se agregaran nuevos elementos. "<<endl;
                            num_peliculas = i+1;
                            break;
                        }

                        if(i == 9)
                        {
                            cout << "Se ha alcanzado el limite de peliculas en la lista (" << i+1 << ")." <<endl;
                            cout << "Si requiere listas de mayor lonjitud, contacte al administrador del sistema."<<endl;
                        }
                    }
                }

                ofstream temp("temp.txt",ios::app);
                temp.write((char*)&x,sizeof(x));

                strcpy(y.usuario,usuario);
                ofstream idxtemp("tempind.txt",ios::app);
                idxtemp.write((char*)&y,sizeof(y));
                idxtemp.close();
                temp.close();

            }//while archivo

        }
        else
        {
            cout << "No se modificara la lista de reproduccion \n" << endl;
        }

        if(band==0)
        {
            cout<<"\n NO EXISTE REGISTRO....."   ;
        }

    }//else
    remove("indice.txt"); 
    rename("tempind.txt","indice.txt");

    remove("datos.txt");  
    rename("temp.txt","datos.txt");
}

void Lista_Rep::Eliminar()
{
    char usuario_eliminar[40];
    int band=0;
    int opc,cont=0,cont2=0;
    ifstream index("indice.txt");
    if(!index.good())
    {
        cout<<"No existe el archivo";
    }
    else
    {
        cout<<"\nUsuario a eliminar!"<<endl;
        fflush(stdin);
        cin.getline(usuario_eliminar,40);
        while(!index.eof())
        {
            index.read((char*)&y,sizeof(y));
            cont++;
            //cout<<"contador --"<<cont;
            if(index.eof())
            {
                break;
            }
            if(strcmp(y.usuario,usuario_eliminar)==0)
            {
                ifstream data("datos.txt");
                data.seekg(y.pos,ios::beg);
                data.read((char*)&x,sizeof(x));
                if(data.eof())   
                {
                    break;
                }
                //cout<<"RFC:"<<x.usuario<<endl<<"peliculas:"<<x.peliculas<<endl<<"Direccion:"<<x.direccion<<endl<<"Colonia:"<<x.colonia<<endl<<"Ciudad:"<<x.ciudad<<endl<<"Estado:"<<estado<<endl<<"CP:"<<cp<<endl<<"Limite de Credito:"<<limite<<endl<<"Saldo:"<<x.saldo<<endl<<"Dias de credito:"<<x.dias<<endl;
                
                cout<<"Usuario:"<<x.usuario<<endl<<"Lista:"<<x.list_name<<endl;
                cout << "Peliculas: \n";

                for (size_t i = 0; i < x.num_peliculas; i++)
                {
                    x.peliculas[i].Imprimir_Pelicula();
                    cout << "\n";
                }
                
                cout<<"Deseas eliminar\n"<<"1.-Si   2.-No\n"; 
                cin>>opc;
                band=1;
                data.close();
                break;
            }//if de comparacion

        }//while
        
        index.close();
        //cout<<"salio--";

        if(opc==1)
        {
            //cout<<"entro al si\n";
            ifstream index("indice.txt");
            ifstream data("datos.txt");
            while(!index.eof())
            {
                //cout<<"entro al ciclo\n";
                index.read((char*)&y,sizeof(y));
                cout<<"\nUsuario:"<<y.usuario<<"\n";
                data.read((char*)&x,sizeof(x));
                if(index.eof())
                {
                    break;
                }
                if(strcmp(y.usuario,usuario_eliminar))
                {
                    //cont2++; cout<<"contador de if es "<<cont2;
                    //cout<<"peliculas escrito es "<<x.peliculas;
                    ofstream temp("temp.txt",ios::app);
                    temp.write((char*)&x,sizeof(x));

                    strcpy(y.usuario,usuario);
                    ofstream idxtemp("tempind.txt",ios::app);
                    idxtemp.write((char*)&y,sizeof(y));
                    idxtemp.close();
                    temp.close();
                }
            }//while archivo

            index.close();
            data.close();
            
            remove("indice.txt"); 
            rename("tempind.txt","indice.txt");
            remove("datos.txt");  
            rename("temp.txt","datos.txt");
        }//if
        else
        {
            
        }

        if(band==0)
        {
            cout<<"\n NO EXISTE REGISTRO....."   ;
        }

    }//else


}

#endif