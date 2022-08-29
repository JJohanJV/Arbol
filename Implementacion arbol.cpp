#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* hijos[6];
  
};

void agregar(Nodo*& raiz, int dato) {

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    raiz = nuevoNodo;
}

void agregar(Nodo*& raiz, int dato, int padre) {

    Nodo* actual = raiz;

}


int main()
{
    int padre;
    int hijos;
    int dato;
    bool continuar = true;
    Nodo* raiz = NULL;
    

    cout << "inserte el valor de la raiz ->";
    cin >> dato;
    agregar(raiz, dato);

    while(continuar){
        cout << "Ingrese 1 para agregar un nuevo nodo al arbol o 0 para terminar arbol ->";
        cin >> dato;
        switch (dato)
        {
        case 1: 
            cout << "Ingrese el valor del padre del nuevo nodo ->";
            cin >> dato;

        }
    }

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
