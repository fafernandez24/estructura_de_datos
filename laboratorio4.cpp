#include <iostream>
using namespace std;

// Definicion de la estructura de un nodo de lista doblemente enlazada
struct Nodo {
  int dato;
  Nodo *previo;
  Nodo *prox;
};

// Funcion para crear un nuevo nodo de lista doblemente enlazada
Nodo* crearNodo(int dato) {
  Nodo *nuevoNodo = new Nodo;
  nuevoNodo->dato = dato;
  nuevoNodo->previo = NULL;
  nuevoNodo->prox = NULL;
  return nuevoNodo;
}

// Funcion para insertar un elemento al principio de una lista doblemente enlazada
void insertarInicio(Nodo **inicio, int valor) {
  Nodo *nuevoNodo = crearNodo(valor);
  nuevoNodo->prox = *inicio;
  if (*inicio != NULL) {
   (*inicio)->previo = nuevoNodo;
  }
   *inicio = nuevoNodo;
}


// Funcion para comprobar si una lista doblemente enlazada esta vacia
bool listaVacia(Nodo *inicio) {
  return inicio == NULL;
}

// Funcion para mostrar el contenido de una lista doblemente enlazada
void mostrarLista(Nodo *inicio) {
  if (!listaVacia(inicio)) {
    Nodo *actual = inicio;
    while (actual != NULL) {
      cout << actual->dato << "->"; 
      actual = actual->prox;
    }
    cout<<"NULL"<<endl;
  } else {
       cout << "La lista esta vacia" << endl;
  }
}

void insertarUltimo(Nodo **inicio, int valor) 
{
 
   Nodo *nuevo = crearNodo(valor);
 
  // Si la lista esta vacia
    if (listaVacia(*inicio))
       *inicio = nuevo;
    else 
     {

       // Recorremos la lista hasta el ultimo nodo
       Nodo *actual = *inicio;
       while (actual->prox != NULL) {
            actual = actual->prox;
        }

      // Insertamos el nuevo nodo al final de la lista
        actual->prox = nuevo;
        actual->prox->previo = actual;
     }
}

//Procedimiento que recorre la lista de izquierda a derecha 

void OrdenAscendente( Nodo *inicio, bool *bol, int *n){

    Nodo *aux;
    aux = inicio;
    *bol = false;

    if( *n == 1 ){
      cout << "La lista tiene solo un elemento: " << endl;
      mostrarLista(inicio);
      *bol = true;
    }

    if (listaVacia(inicio))
        cout << "La lista se encuentra vacia." << endl;
    else{
        while ( aux -> dato <= aux -> prox -> dato ) {
              aux = aux -> prox;
              if (aux -> prox == NULL ){
                cout << "La lista esta ordenada de forma ascendente: " << endl;
                *bol = true;
                mostrarLista(inicio);
              }
        }
    }
}

void OrdenDescendente( Nodo *inicio){

  Nodo *aux;
  aux = inicio;
  bool bol = false;

  while ( aux -> dato >= aux -> prox -> dato ){
      aux = aux -> prox;
      bol = false;
      if (aux -> prox == NULL ){
        cout << "La lista esta ordenada de forma descendente: " << endl;
        bol = true;
        mostrarLista(inicio);
      }
  }
  if (bol == false){
    cout << "La lista no se encuentra ordenada: " << endl;
    mostrarLista(inicio);
  }
}

main(){
  
  Nodo *primero = NULL;
  int n=0,i=0,valor=0;
  bool bol1;

  cout << "Indica cantidad de elementos a ser agregados: ";
  cin >> n;
  while (i != n) {
      cout << "Indica valor: ";
      cin >> valor;
      insertarUltimo(&primero,valor);
      i++;
      };

  //ver si esta ordenada de forma ascendente o descendente la fila.

  OrdenAscendente(primero, &bol1, &n);
  if (bol1 == false)
    OrdenDescendente(primero);

}