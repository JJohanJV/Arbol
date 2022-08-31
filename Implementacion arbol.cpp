#include <iostream>
using namespace std;
const int orden = 6;

struct Nodo
{
    int dato;
    Nodo* hijos[orden];
  
};

void agregarRaiz(Nodo*& raiz, int dato) {

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    raiz = nuevoNodo;

	for(int i=0; i<orden; i++){
		raiz->hijos[i]=NULL;
	}
}

int contadorHijos(Nodo*& nodo){
	int contador=0;
	for(int i=0; i<orden; i++){
		if(nodo->hijos[i] != NULL){
			contador++;
		}
	}
	return contador;
}

int contadorHijos(Nodo*& raiz, int datoDelNodo){ //Retorna el numero de hijos del nodo con el dato dado
	
	if(raiz->dato == datoDelNodo){
		int contador=0;
		for(int i=0; i<orden; i++){
			if(raiz->hijos[i] != NULL){
				contador++;
			}
		}
		return contador;
	}else{
		if(raiz->hijos>0){
			for(int i=0; i<contadorHijos(raiz); i++){
				if(raiz->hijos[i]->dato == datoDelNodo){
					int contador=0;
					for(int i=0; i<orden; i++){
						if(raiz->hijos[i] != NULL){
							contador++;
						}
					}
					return contador;
					break;
				}else{
	    			contadorHijos(raiz->hijos[i], datoDelNodo);
				}
			}
		}
	}
}

void buscarNodo(Nodo*& raiz, int datoDelNodo){ //Busca el dato dado y si está lo imprime
	
	if(raiz->dato == datoDelNodo){
		cout << "Encontre el nodo " << raiz->dato << "\n";
	}else{
		if(raiz->hijos>0){
			for(int i=0; i<contadorHijos(raiz); i++){
				if(raiz->hijos[i]->dato == datoDelNodo){
					cout << "Encontre el nodo " << raiz->hijos[i]->dato << "\n";
					break;
				}else{
	    			buscarNodo(raiz->hijos[i], datoDelNodo);
				}
			}
		}
	}
}

void agregarNodo(Nodo*& raiz, int padre, int dato){ //Retorna el padre del dato dado
	
	Nodo* actual;

	if(raiz->dato == padre){
		cout << "Se encontro el padre " << raiz->dato;
		actual=raiz;
		Nodo* nuevoNodo = new Nodo;
		nuevoNodo->dato = dato;
		for(int i=0; i<6; i++){
			nuevoNodo->hijos[i]=NULL;
		}
	
		actual->hijos[contadorHijos(actual)] = nuevoNodo;
		cout << " y se agrego el nodo "<< actual->hijos[contadorHijos(actual)-1]->dato << "\n";
	}else{
		if(raiz->hijos>0){
			for(int i=0; i<contadorHijos(raiz); i++){
				if(raiz->hijos[i]->dato == padre){
					cout << "Se encontro el padre " << raiz->hijos[i]->dato;
					actual = raiz->hijos[i];
					Nodo* nuevoNodo = new Nodo;
					nuevoNodo->dato = dato;
					for(int i=0; i<6; i++){
						nuevoNodo->hijos[i]=NULL;
					}
					actual->hijos[contadorHijos(actual)] = nuevoNodo;
					cout << " y agrego el nuevo nodo "<< actual->hijos[contadorHijos(actual)-1]->dato << "\n";
					break;
				}else{
	    			agregarNodo(raiz->hijos[i], padre, dato);
				}
			}
		}
	}
}



void agregar(Nodo*& raiz){
	
	int hijos;
	int dato;
	
	cout << "Ingrese cuantos hijos tiene el nodo ->";
	cin >> hijos;
	if(hijos>0){
		for(int i=0; i<hijos; i++){
			cout << "Ingrese el valor del hijo " << i+1 << " del nodo con valor" << raiz->dato << " ->";  
			cin >> dato;
			Nodo* nuevoNodo = new Nodo;
    		nuevoNodo->dato = dato;
    		for(int j=0; j<6; j++){
				nuevoNodo->hijos[j]=NULL;
			}
    		raiz->hijos[i] = nuevoNodo;
    		agregar(raiz->hijos[i]);
		}
	}
	
}

void imprimirArbol(Nodo*& raiz){
	
	cout << raiz->dato << " \n";
	
	if(raiz->hijos>0){
		for(int i=0; i<contadorHijos(raiz); i++){
			imprimirArbol(raiz->hijos[i]);
		}
	}
	
}

int main()
{
    int padre;
    int dato;
    bool continuar = true;
    Nodo* raiz = NULL;
    
	
    cout << "Inserte el valor de la raiz ->";
    cin >> dato;
    agregarRaiz(raiz, dato);

	while(continuar){
		cout << "\nIngrese 1 para agregar un nodo al arbol, 2 para ver el arbol actual, 3 para salir ->";
		cin>>dato;
		switch(dato){
			case 1:{
				cout << "\nIngrese el padre del nuevo nodo (Asegurese de que el padre este en el arbol)->";
				cin >> padre;
				cout << "Ingrese el valor del nuevo nodo ->";
				cin >> dato;
				agregarNodo(raiz, padre, dato);
				break;
			}
			
			case 2:{
				cout << "\nObservacion: El arbol se representa por ramas, es decir se parte desde la raiz hasta el final del primer hijo y luego se vuelve al segundo hijo de la raiz y así sucesivamente, se debe identificar donde empieza el siguiente hijo.\n";
				imprimirArbol(raiz);
				break;
			}
			
			case 3:{
				continuar = false;
				cout << "\nPrograma terminado";
				break;
			}
		}
	}	 

}
