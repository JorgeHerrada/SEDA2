#ifndef SERIE_H
#define SERIE_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Serie
{
public:
    string nombre, episodios, estreno;

    void Agregar();
	void Mostrar();
	void Modificar();
	void Eliminar();
	void Buscar();
	void menu();
    int dim1, dim2, dim3; 
    string opc = "0";  
};

void Serie::Agregar()
{
    system("cls");
    fflush( stdin );
    cout<<"ESCRIBE EL NOMBRE DE LA SERIE: " << endl;
    getline(cin,nombre);
    fflush( stdin );
    cout<<"ESCRIBE EL NUMERO DE EPISODIOS: " << endl;
    getline(cin,episodios);
    fflush( stdin );
    cout<<"ESCRIBE EL ANHO DE ESTRENO: " << endl;
    getline(cin,estreno);
    ofstream Archivo("Serie.txt",ios::app);
    dim1 = nombre.length();
    dim2 = episodios.length();
    dim3 = estreno.length();
    
    Archivo << dim1 << "\n" << nombre << "\n";
    Archivo << dim2 << "\n" << episodios << "\n";
    Archivo << dim3 << "\n" << estreno << "\n";

    Archivo.close();

}
void Serie::Mostrar()
{
	system("cls");

    string s_dim1,s_dim2, s_dim3;

    ifstream archivo("Serie.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
		while(!archivo.eof()){
            getline(archivo,s_dim1);
            getline(archivo,nombre);
            getline(archivo,s_dim2);
            getline(archivo,episodios);
            getline(archivo,s_dim3);
            getline(archivo,estreno);
            
            if(!archivo.eof())
            {
                cout << nombre << "  " << episodios << "  " << estreno << endl;
            }
		}
	}
    archivo.close();
}


void Serie::Modificar()
{
    system("cls");
    int band = 0;
    string nombre2;
    string prueba;
    string s_dim1,s_dim2, s_dim3;

	ifstream archivo("Serie.txt");
	if(!archivo.good())
    {
			cout<<"\nEl archivo no existe...";
	}
	else
	{
	    cout << "escribe el nombre de la Serie: " << endl;
        fflush( stdin );
        getline(cin,nombre2);
        
		while(!archivo.eof() && !band)
        {
            getline(archivo,prueba);
            getline(archivo,nombre);
            getline(archivo,prueba);
            getline(archivo,episodios);
            getline(archivo,prueba);
            getline(archivo,estreno);

            if(nombre2 == nombre) // comparar cadenas
            {
                cout << nombre << "  " << episodios << "  " << estreno << endl;
                band = 1;
                cout<<"DESEA MODIFICAR?\n1.SI\n0.NO\n>: " << endl;
                fflush( stdin );
                getline(cin,opc);
            }//condicion

        }	//ciclo
	    archivo.close();

    	if(opc == "1")
        {
            ifstream archivo("Serie.txt");
            ofstream temporal("temporal.txt", ios::app);
            while(!archivo.eof())
            {
                getline(archivo,s_dim1);
                getline(archivo,nombre);
                getline(archivo,s_dim2);
                getline(archivo,episodios);
                getline(archivo,s_dim3);
                getline(archivo,estreno);

                if (!archivo.eof())
                {
                    if(nombre == nombre2)
                    {
                        cout<<"ESCRIBE EL NUEVO NOMBRE DE LA SERIE: " << endl;
                        fflush( stdin );
                        getline(cin,nombre);
                        cout<<"ESCRIBE LA NUEVA CANTIDAD DE EPISODIOS: " << endl;
                        fflush( stdin );
                        getline(cin,episodios);
                        cout<<"ESCRIBE EL NUEVO ANHO DE ESTRENO: " << endl;
                        fflush( stdin );
                        getline(cin,estreno);
                        ofstream Archivo("Serie.txt",ios::app);
                        dim1 = nombre.length();
                        dim2 = episodios.length();
                        dim3 = estreno.length();
                        s_dim1 = to_string(dim1);
                        s_dim2 = to_string(dim2);
                        s_dim3 = to_string(dim3);

                    }//condicion
                    
                    temporal << s_dim1 << "\n" << nombre << "\n";
                    temporal << s_dim2 << "\n" << episodios << "\n";
                    temporal << s_dim3 << "\n" << estreno << "\n";
                }
                
            }//ciclo while

            temporal.close();
            archivo.close();
            remove("Serie.txt");
            rename("temporal.txt", "Serie.txt");

	    }//condicional de la opcion

    }// else

}

void Serie::Eliminar()
{
    system("cls");
    int band = 0;
    string nombre2, prueba;
    string s_dim1,s_dim2, s_dim3;

	ifstream archivo("Serie.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe..." << endl;
	}
	else
	{
	    cout << "NOMBRE DE LA SERIE QUE QUIERES ELIMINAR: " << endl;
        fflush( stdin );
        getline(cin,nombre2);
        
		while(!archivo.eof() && !band)
        {
            getline(archivo,prueba);
            getline(archivo,nombre);
            getline(archivo,prueba);
            getline(archivo,episodios);
            getline(archivo,prueba);
            getline(archivo,estreno);

            if(nombre2 == nombre)
            {
                cout << nombre << "  " << episodios << "  " << estreno << endl;
                band = 1;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: " << endl;
                fflush( stdin );
                getline(cin,opc);
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == "1")
    {
        ifstream archivo("Serie.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            getline(archivo,s_dim1);
            getline(archivo,nombre);
            getline(archivo,s_dim2);
            getline(archivo,episodios);
            getline(archivo,s_dim3);
            getline(archivo,estreno);

            if (!archivo.eof())
            {
                if(nombre != nombre2)
                {
                    temporal << s_dim1 << "\n" << nombre << "\n";
                    temporal << s_dim2 << "\n" << episodios << "\n";
                    temporal << s_dim3 << "\n" << estreno << "\n";

                }//condicion
            }
            


            

        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Serie.txt");
	rename("temporal.txt", "Serie.txt");
	}//condicional de la opcion

    }//

}

void Serie::Buscar()
{
    string nombre2,prueba;
    int band = 0;
    system("cls");

    ifstream archivo("Serie.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
        cout << "Escribe el nombre de la Serie que quieres buscar: " << endl;
        fflush( stdin );
        getline(cin,nombre2);

		while(!archivo.eof() && !band)
        {
			getline(archivo,prueba);
            getline(archivo,nombre);
            getline(archivo,prueba);
            getline(archivo,episodios);
            getline(archivo,prueba);
            getline(archivo,estreno);

			if( nombre == nombre2)
            {
                cout << nombre << "  " << episodios << "  " << estreno << endl;
                band = 1;
            }
		}
		if (!band)
        {
            cout << "NO SE ENCUENTRA LA SERIE..." << endl;
        }
	}
    archivo.close();
}

#endif