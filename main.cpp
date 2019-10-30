
#include <iostream>
#include <fstream>
#include "Arbolstr.h"

using namespace std;


int main(int argc, char *argv[]) {

    cout << "Segundo Parcial Programacion III" << endl;

    string linea, palabra, archivo, arcExcl;
    vector<string> lista;

    int contLetra = 0, contPalabra = 0, contLinea = 0;
    int palInicio, mostrar = 0, excluir = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-')            // el argumento empieza con guion

        {
            if (argv[i][1] == 'm')
                mostrar = 1;
            if (argv[i][1] == 'e') {
                excluir = 1;
                arcExcl = argv[i + 1];
                i++;
            }


        } else {
            archivo = argv[i];
        }
    }

    cout << argc << "\n" << argv[0];//<< "\n" << argv[2];
    ifstream myArchivo(archivo);
    myArchivo.open("../archivo.txt"); //agregado 2019

    if (myArchivo.is_open()) {
        while (getline(myArchivo, linea)) {
            //cout << linea << endl;
            contLinea++;
            contLetra += linea.length();
            palInicio = 0;
            for (int i = 0; i < linea.length(); i++) {
                if (linea[i] == ' ' || linea[i] == ',' || linea[i] == '.' || linea[i] == '!' || linea[i] == '?' ||
                    i == linea.length() - 1) {
                    palabra = linea.substr(palInicio, i - palInicio);
                    palInicio = i + 1;
                    if (palabra.length() > 0) {
                        if (mostrar)
                            cout << "Palabra '" << palabra << "'" << endl;
                        lista.push_back(palabra);
                        contPalabra++;
                    }
                }
            }
        }
    } else {
        cout << " Error al abrir el archivo";
    }

    cout << endl << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "                                      Lineas: " << contLinea << endl;
    cout << "                                      Letras: " << contLetra << endl;
    cout << "                                      Palabras: " << contPalabra << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    AVLsearchTree sbbst;
    Arbol AOcu;
    string val;
    char ch;

    do {
        cout << "\nOperaciones de Arbol:\n";
        cout << "1. Armar Arboles " << endl;
        cout << "2. Contar Palabras diferentes" << endl;
        cout << "3. Buscar Ocurrencia" << endl;
        cout << "4. Check empty" << endl;
        cout << "5. Vaciar arbol" << endl;
        cout << "6. Ordenar por Ocurrencias" << endl;
        cout << "7. Ordenar Alfabeticamente" << endl;
        int opcion;
        cout << "Ingrese la Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1 :
                cout << "Arbol Palabras Armado";
                for (int i = 0; i < lista.size(); i++)
                    sbbst.insert(lista[i]);


                break;
            case 2 :
                cout << "Cantidad de palabras = " << sbbst.countNodes() << endl;
                break;
            case 3:
                cout << "Ingrese la palabra a buscar: ";
                cin >> val;
                if (sbbst.search(val)) {
                    cout << val << " se encontro en el Arbol ";
                    cout << sbbst.search(val) << ' ';
                    cout << "con una cantidad total de " << sbbst.searchCont(val) << " ocurrencias";
                } else
                    cout << val << " No se encontro" << endl;
                break;
            case 4 :
                cout << "Estado del arbol = ";
                if (sbbst.isEmpty())
                    cout << "Arbol vacio" << endl;
                else
                    cout << "Arbol No vacio" << endl;
                break;
            case 5 :
                cout << endl <<"Se vacio el arbol" << endl;
                sbbst.makeEmpty();
                AOcu.vaciarArbol();
                break;
            case 6 :
                sbbst.insertarOrden(&AOcu);
                cout << endl << "Mostrar por orden de ocurrencias: " << endl;
                AOcu.mostrarOrden();
                AOcu.vaciarArbol();
                break;
            case 7 :
                cout << endl <<"Listado por orden de Alfabetico : " << endl;
                sbbst.inorder();
                cout << endl;
                sbbst.insertarOrden(&AOcu);
                break;
            default :
                cout << "Opcion Incorrecta\n ";
                break;
        }
        cout << endl << "Do you want to continue (Type y or n): ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    cout << "Hasta Pronto!";

    return 0;
}