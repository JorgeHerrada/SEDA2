#ifndef PELICULA_H
#define PELICULA_H

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Pelicula
{
public:
    char nombre[35], duracion[5], categoria[20], clasificacion[5], estreno[6], director[35];
    unsigned int contador = 0;
    void Capturar();
    void Imprimir();
    void Buscar();
    void Eliminar();
    void Modificar();
    void Imprimir_Pelicula();
    int size();
};


void Pelicula::Capturar()
{
    contador ++;
    cout<<"\nNombre: ";
    fflush(stdin);
    cin.getline(nombre, 35);
    cout<<"\nDuracion: ";
    fflush(stdin);
    cin.getline(duracion, 5);
    cout<<"\nCategoria: ";
    fflush(stdin);
    cin.getline(categoria, 20);
    cout<<"\nClasificacion: ";
    fflush(stdin);
    cin.getline(clasificacion, 5);
    cout<<"\nEstreno: ";
    fflush(stdin);
    cin.getline(estreno, 6);
    cout<<"\nDirector: ";
    fflush(stdin);
    cin.getline(director, 35);
    ofstream archivo("Peliculas.txt", ios::app);
    archivo<<nombre<<"|"<<duracion<<"|"<<categoria<<"|"<<clasificacion<<"|"<<estreno<<"|"<<director<<"|";
    
    archivo.close();
}

void Pelicula::Imprimir()
{
    ifstream arc("Peliculas.txt");
    if(!arc.good())
        cout<<"\nEl archivo no existe";
    else
    {
        char c; int i;
        while(!arc.eof())
        {
            // i=0;
            // do
            // {
            //     arc.read((char*)&c, 1);
            //     if(c!='|')
            //     {
            //         nombre[i]=c;
            //         i++;
            //     }
            // }while(c!='|' && !arc.eof());

            // nombre[i]='\0';
            // i=0;
            // do
            // {
            //     arc.read((char*)&c, 1);
            //     if(c!='|')
            //     {
            //         duracion[i]=c;
            //         i++;
            //     }
            // }while(c!='|' && !arc.eof());
            
            // duracion[i]='\0';

            arc.getline(nombre, 35, '|');
            arc.getline(duracion, 5, '|');
            arc.getline(categoria, 20, '|');
            arc.getline(clasificacion, 5, '|');
            arc.getline(estreno, 6, '|');
            arc.getline(director, 35, '|');
            if(!arc.eof())
                cout<<"\nNombre: "<<nombre<<"\nDuracion: "<<duracion<<"\nCategoria:"<<categoria<<"\nClasificacion: "<<clasificacion<<"\nEstreno: "<<estreno<<"\nDirector: "<<director<<endl;
            }
        }
        // cout << "ALLES GUT" << endl;
        arc.close();
    }

void Pelicula::Buscar()
{
    char ref[35], comp[35], prev[35];
    int band=1;
    cout<<"\nEscribe el NOMBRE de la Pelicula a buscar \n";
    fflush(stdin);
    cin.getline(ref, 35);
    ifstream arc("Peliculas.txt");
    if(!arc.good())
        cout<<"\nEl archivo no existe";
    else
    {
        while(!arc.eof() && band==1)
        {
            //arc.getline(prev, 35, '|');
            arc.getline(comp, 35, '|');
            if(strcmp(comp, ref)==0)
            {
                cout<<"\nNombre: "<<ref;
                arc.getline(comp, 5, '|');
                cout<<"\nDuracion: "<<comp;
                arc.getline(comp, 20, '|');
                cout<<"\nCategoria: "<<comp;
                arc.getline(comp, 5, '|');
                cout<<"\nClasificacion: "<<comp;
                arc.getline(comp, 6, '|');
                cout<<"\nEstreno: "<<comp;
                arc.getline(comp, 35, '|');
                cout<<"\nDirector: "<<comp;
                band=0;
            }
            else
            {
                arc.getline(comp, 35, '|');
                arc.getline(comp, 35, '|');
                arc.getline(comp, 35, '|');
                arc.getline(comp, 35, '|');
                arc.getline(comp, 35, '|');
            }
        }
        if(band)
            cout<<"\nNo se encontro la Pelicula: " << ref << endl;
    }
    arc.close();
    cout << endl;
}

void Pelicula::Eliminar()
{
    
    char ref[35], comp[35], prev[35];
    int band=1, op;
    cout<<"\nEscribe el nombre del Pelicula a eliminar \n";
    fflush(stdin);
    cin.getline(ref, 35);
    ifstream arc("Peliculas.txt");
    
    if(!arc.good())
    {
        cout<<"\nEl archivo no existe";
    }
    else
    {
        while(!arc.eof() && band)
        {
            //arc.getline(prev, 35, '|');
            arc.getline(comp, 35, '|');
            if(strcmp(comp, ref)==0)
            {
                cout<<"\nNombre: "<<ref;
                arc.getline(comp, 15, '|');
                cout<<"\nDuracion: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nCategoria: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nClasificacion: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nEstreno: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nDirector: "<<comp;
                band=0;
                arc.close();
                cout<<"\nDesea eliminar esta Pelicula? \n1.Si \n2.No\n";
                cin>>op;
                if(op==1)
                {
                    cout<<"\nEsta seguro? \n1.Si \n2.No \n";
                    cin>>op;
                    if(op==1)
                    {
                        ifstream elim("Peliculas.txt");
                        ofstream nuevo("Temporal.txt", ios::app);
                        while(!elim.eof())
                        {
                            //elim.getline(prev, 35, '|');
                            elim.getline(comp, 35, '|');
                            if(strcmp(comp, ref)!=0 && !elim.eof())
                            {
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                            }
                            else
                            {
                                elim.getline(comp, 35, '|');
                                elim.getline(comp, 35, '|');
                                elim.getline(comp, 35, '|');
                                elim.getline(comp, 35, '|');
                                elim.getline(comp, 35, '|');
                            }
                        }
                    nuevo.close();
                    elim.close();
                    remove("Peliculas.txt");
                    rename("Temporal.txt", "Peliculas.txt");
                    }
                }
            }
            // else
            // {
            //     arc.getline(comp, 35, '|');
            //     arc.getline(comp, 35, '|');
            //     arc.getline(comp, 35, '|');
            //     arc.getline(comp, 35, '|');
            //     arc.getline(comp, 35, '|');
            // }
        }
    if(band)
    cout<<"\nNo se encontro la Pelicula";
    }
}

void Pelicula::Modificar()
{
    
    char ref[35], comp[35], prev[35];
    int band=1, op;
    bool modificado = false;
    cout<<"\nEscribe el nombre del Pelicula a Modificar \n";
    fflush(stdin);
    cin.getline(ref, 35);
    ifstream arc("Peliculas.txt");
    
    if(!arc.good())
    {
        cout<<"\nEl archivo no existe";
    }
    else
    {
        while(!arc.eof() && band)
        {
            //arc.getline(prev, 35, '|');
            arc.getline(comp, 35, '|');
            if(strcmp(comp, ref)==0)
            {
                cout<<"\nNombre: "<<ref;
                arc.getline(comp, 15, '|');
                cout<<"\nDuracion: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nCategoria: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nClasificacion: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nEstreno: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nDirector: "<<comp;
                band=0;
                arc.close();
                cout<<"\nDesea modificar esta Pelicula? \n1.Si \n2.No\n";
                cin>>op;
                if(op==1)
                {
                    cout<<"\nEsta seguro? \n1.Si \n2.No \n";
                    cin>>op;
                    if(op==1)
                    {
                        ifstream elim("Peliculas.txt");
                        ofstream nuevo("Temporal.txt", ios::app);

                        cout<< "Ingresa los nuevos datos de la pelicula: " << ref << endl;
                        cout<<"\nNombre: ";
                        fflush(stdin);
                        cin.getline(nombre, 35);
                        cout<<"\nDuracion: ";
                        fflush(stdin);
                        cin.getline(duracion, 5);
                        cout<<"\nCategoria: ";
                        fflush(stdin);
                        cin.getline(categoria, 20);
                        cout<<"\nClasificacion: ";
                        fflush(stdin);
                        cin.getline(clasificacion, 5);
                        cout<<"\nEstreno: ";
                        fflush(stdin);
                        cin.getline(estreno, 6);
                        cout<<"\nDirector: ";
                        fflush(stdin);
                        cin.getline(director, 35);

                        while(!elim.eof())
                        {
                            //elim.getline(prev, 35, '|');
                            elim.getline(comp, 35, '|');
                            if(strcmp(comp, ref)!=0 && !elim.eof())
                            {
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 35, '|');
                                nuevo<<comp<<"|";
                            }
                            else
                            {
                                elim.getline(comp, 35, '|');
                                elim.getline(comp, 35, '|');
                                elim.getline(comp, 35, '|');
                                elim.getline(comp, 35, '|');
                                elim.getline(comp, 35, '|');
                                
                                if(!modificado)
                                {
                                    nuevo<<nombre<<"|";
                                    nuevo<<duracion<<"|";
                                    nuevo<<categoria<<"|";
                                    nuevo<<clasificacion<<"|";
                                    nuevo<<estreno<<"|";
                                    nuevo<<director<<"|";

                                    modificado = true;
                                }
                            }
                        }
                    nuevo.close();
                    elim.close();
                    remove("Peliculas.txt");
                    rename("Temporal.txt", "Peliculas.txt");
                    }
                }
            }
            // else
            // {
            //     arc.getline(comp, 35, '|');
            //     arc.getline(comp, 35, '|');
            //     arc.getline(comp, 35, '|');
            //     arc.getline(comp, 35, '|');
            //     arc.getline(comp, 35, '|');
            // }
        }
    if(band)
    cout<<"\nNo se encontro la Pelicula";
    }
}

void Pelicula::Imprimir_Pelicula()
{
    cout << "\tNombre:" << this->nombre << endl;
    cout << "\tDuracion:" << this->duracion << " minutos" << endl;
    cout << "\tCategoria:" << this->categoria << endl;
    cout << "\tClasificacion:" << this->clasificacion << endl;
    cout << "\tAnho de estreno:" << this->estreno << endl; 
    cout << "\tDirector:" << this->director << endl; 
}

#endif