#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *prox;
};

Nodo* CrearNodo(int valor){

    Nodo *nuevo = new Nodo; 
    nuevo -> dato = valor;
    nuevo -> prox = NULL;

    return nuevo;
}

bool ListaVacia( Nodo *inicio ){
    return inicio == NULL;
}

void InsertarUltimo( Nodo **inicio, int valor){

    Nodo *casilla = CrearNodo(valor);
    Nodo *aux = *inicio;

    if ( ListaVacia(*inicio))
        *inicio = casilla;

    else{
        while (aux -> prox != NULL){
            aux = aux -> prox;
        }

        aux -> prox = casilla;
    }
}

void MostrarLista(Nodo *inicio){

    Nodo *mover = inicio;

    while ( mover != NULL ){
        cout << mover -> dato << "->";
        mover = mover -> prox;
    }

    cout << "NULL" << endl;

}

bool BuscandoN(Nodo *inicio, int n){

    Nodo *aux = inicio;

    if (ListaVacia(inicio))
        cout << "Lista vacia!" << endl;

    else{
        while ( aux -> dato != n || aux != NULL ){
            
            if ( aux -> dato == n)
                return true;

            if (aux -> prox == nullptr)
                return false;
            
            aux = aux -> prox;
        }
    }
    return false;
}

int BuscarContador(Nodo *inicio, int n){

    Nodo *aux = inicio;
    int counter = 0;

    if (!ListaVacia(inicio)){

        while (aux != NULL){
            if (aux -> dato == n)
                counter += 1;
            aux = aux -> prox;
        }
        return counter;
    }
    return 0;
}

void Casilla(Nodo *inicio, int valor){

    Nodo *aux = inicio;

    if (!ListaVacia(inicio)){

        cout << "PUNTEROS: " << endl;

        while (aux != NULL){

            if (aux -> dato == valor)
                cout << aux << "->";

            aux = aux -> prox;
        }
        cout << "NULL" << endl;
    }
}

main(){

    Nodo *primero = NULL;
    int numero, buscar, elementos, counter = 0;
    bool bol;

    cout << "Ingresar numero de casillas de la lista: ";
    cin >> elementos;

    for ( int i = 1; i <= elementos; i++ ){

        cout << "Ingresar el valor de la casilla " << i << ": ";
        cin >> numero;

        InsertarUltimo(&primero, numero);
    }

    cout << "Ingresar numero a buscar en la lista: ";
    cin >> buscar;

    bol = BuscandoN(primero, buscar);
    counter = BuscarContador(primero, buscar);

    if ( bol == false ){
        cout << "El numero ingresado no se encuentre en la lista!" << endl;
    }
    else{
        cout << "El numero ingresado si se encuentra en la lista!" << endl;
    }

    cout << "El " << buscar << " aparece: " << counter << " veces" << endl;

    Casilla(primero, buscar);
    MostrarLista(primero);
}
