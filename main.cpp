#include "Menu.h"

int main()
{
    int opc;
    string opc_str;
    Menu menu;

    do
    {
        system("cls");
        cout << "BIENVENIDO\n\n" << endl;

        cout << "1.- Usuarios (Registros de longitud fija) " << endl;
        cout << "2.- Peliculas (Registros de Longitud Variable con DELIMITADORES)" << endl;
        cout << "3.- Series (Registros de Longitud Variable con CAMPOS DE DIMENSION" << endl;
        cout << "4.- Listas de Reproduccion (Indices Simples)" << endl;
        cout << "5.- Facturas (Serializacion)" << endl;
        cout << "6.- Pagos (Dispersion o Hashing)" << endl;
        cout << "0.- SALIR" << endl;
        
        fflush(stdin);
        getline(cin,opc_str);

        try
        {
            opc = stoi(opc_str);
        }
        catch(const std::exception& e)
        {
            cout << opc_str << " no es una opcion valida. Adios." << endl;
            return 0;
        }

        switch (opc)
        {
        case 1:
            menu.usuarios();
            break;
        case 2:
            menu.peliculas();
            break;
        case 3:
            menu.series();
            break;
        case 4:
            menu.listas();
            break;
        case 5:
            menu.facturas();
            break;
        case 6:
            menu.pagos();
            break;
        
        default:
            break;
        }
        
        



        system("pause");
    }while(opc != 0);
    


    return 0;
}