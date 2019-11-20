
#include <iostream>
#include <fstream>
#include "ArbolBinario.h"
#include <vector>
using namespace std;

//Ordenamiento Quicksort
void quickSort(int *array,string *arrb, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;
    string tempb;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            tempb = arrb[i];
            array[i] = array[j];
            arrb[i] = arrb[j];
            array[j] = temp;
            arrb[j] = tempb;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, arrb, low, j);
    if (i < high)
        quickSort(array,arrb, i, high);
}


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
        }
        else {
            archivo = argv[i];
        }
    }

    cout << argc << "\n" << argv[0];//<< "\n" << argv[2];
    ifstream myArchivo(archivo);
    myArchivo.open("../archivo.txt");

    if (myArchivo.is_open()) {
        while (getline(myArchivo, linea)) {
            contLinea++;
            contLetra += linea.length();
            palInicio = 0;
            for (int i = 0; i < linea.length(); i++) {
                if(linea[i]=='A')
                    linea[i]='a';
                if(linea[i]=='B')
                    linea[i]='b';
                if(linea[i]=='C')
                    linea[i]='c';
                if(linea[i]=='D')
                    linea[i]='d';
                if(linea[i]=='E')
                    linea[i]='e';
                if(linea[i]=='F')
                    linea[i]='f';
                if(linea[i]=='G')
                    linea[i]='g';
                if(linea[i]=='H')
                    linea[i]='h';
                if(linea[i]=='I')
                    linea[i]='i';
                if(linea[i]=='J')
                    linea[i]='j';
                if(linea[i]=='K')
                    linea[i]='k';
                if(linea[i]=='L')
                    linea[i]='l';
                if(linea[i]=='M')
                    linea[i]='m';
                if(linea[i]=='N')
                    linea[i]='n';
                if(linea[i]=='O')
                    linea[i]='o';
                if(linea[i]=='P')
                    linea[i]='p';
                if(linea[i]=='Q')
                    linea[i]='q';
                if(linea[i]=='R')
                    linea[i]='r';
                if(linea[i]=='S')
                    linea[i]='s';
                if(linea[i]=='T')
                    linea[i]='t';
                if(linea[i]=='U')
                    linea[i]='u';
                if(linea[i]=='V')
                    linea[i]='v';
                if(linea[i]=='W')
                    linea[i]='w';
                if(linea[i]=='X')
                    linea[i]='x';
                if(linea[i]=='Y')
                    linea[i]='y';
                if(linea[i]=='Z')
                    linea[i]='z';

                if (linea[i] == ' ' || linea[i] == ',' || linea[i] == '.' || linea[i] == '!' || linea[i] == '?' ||  linea[i] == ':' || linea[i] == ';' || linea[i] == '-' || linea[i] == '_' || linea[i] == '"' ||
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

    ArbolBinario<string> sbbst;
    ArbolCtr<string> AOcu;
    string val;
    char ch;
    int n;

    do {
        cout << endl << endl << "Segundo Parcial Programacion III" << endl;
        cout << "-----------------------------------------------------------------------------------------------" << endl;
        cout << "                                      Lineas: " << contLinea << endl;
        cout << "                                      Letras: " << contLetra << endl;
        cout << "                                      Palabras: " << contPalabra << endl;
        cout << "-----------------------------------------------------------------------------------------------" << endl;

        cout << endl << "Operaciones de Arbol:" << endl;
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
                for (int i = 0; i < lista.size(); i++) {
                    sbbst.put(lista[i]);
                }
                cout << "Arbol Palabras Armado";

                break;
            case 2 :
                cout << "Cantidad de palabras = " << sbbst.countNodes() << endl;
                break;
            case 3: {
                cout << "Ingrese la cantidad de palabras que desea buscar: ";
                cin >> n;
                string busqueda[n];
                int arrcont[n];
                string arrstr[n];
                cout << "Ingrese las palabras a buscar: "<<endl;
                for (int i = 0; i <= n; ++i) {
                    cin >> val;
                    busqueda[i] = val;
                }

                for (int i = 0; i <= n; i++) {
                    if (sbbst.search(busqueda[i]) == busqueda[i]) {
                        cout << busqueda[i] << " se encontro en el Arbol con una cantidad total de "
                             << sbbst.searchCont(busqueda[i]) << " ocurrencias" << endl;
//                        arrcont[i]=sbbst.searchCont(busqueda[i]) ;
//                        arrstr[i]=busqueda[i];
                    }
                    else
                        cout << val << " No se encontro";

                }

//                quickSort(arrcont,arrstr,0,n);
//                for (int i=0;i<=n;++i){
//                    cout << arrstr[i] << " " << arrcont[i];
//                }
            }
                break;
            case 4 :
                cout << "Estado del arbol = ";
                if (sbbst.esVacio())
                    cout << "Arbol vacio" << endl;
                else
                    cout << "Arbol No vacio" << endl;
                break;
            case 5 :
                cout << endl << "Se vacio el arbol" << endl;
                sbbst.vaciar();
                    AOcu.vaciar();
                    break;
            case 6 :
                sbbst.insertarOrden(&AOcu);
                cout << endl << "Mostrar por orden de ocurrencias: " << endl;
                AOcu.inorder();
                AOcu.vaciar();
                break;
            case 7 :
                cout << endl << "Listado por orden de Alfabetico : " << endl;
                sbbst.inorder();
                cout << endl;
                //sbbst.insertarOrden(&AOcu);
                break;
            default :
                cout << "Opcion Incorrecta\n ";
                break;
        }
        cout << endl << "Desea Continuar? (Type y or n): ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    cout << "Hasta Pronto!";

    return 0;
}