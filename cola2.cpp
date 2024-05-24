#include <iostream>
using namespace std;

struct Cola{
   int   dato;
   Cola *prox;
};

Cola* crearCola(int valor){
    Cola *nuevo = new Cola;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool ColaVacia(Cola *col){
    return col==NULL;
}

Cola*  PrimeroCola(Cola *col){
   if (!ColaVacia(col))
      return col; 
   else   
      return nullptr;    
}

void Encolar(Cola **col, int valor){
   Cola *nuevo = crearCola(valor);
 
   if (ColaVacia(*col)) {
       *col = nuevo;
    } 
    else {
       Cola *auxiliar = *col;
       while (auxiliar->prox != NULL) {
           auxiliar = auxiliar->prox;
       }
       auxiliar->prox = nuevo;
  }
   
}

void Desencolar(Cola **col){
     if (!ColaVacia(*col))
        *col=(*col)->prox;
     else
       cout<<"Cola vacia imposible desencolar "<<endl;
}

// no es primitiva
void mostrarCola(Cola *col){

    if (ColaVacia(col))
        cout<<"La cola esta vacía "<<endl;
    else
        {
            while (!ColaVacia(col)) {
                cout <<PrimeroCola(col)->dato<< "  ";
                Desencolar(&col);
            }
            cout<<endl;
        }    
}

// no es primitiva
void llenarCola(Cola **col){

    int cantidad,i,valor; 
    cout<<"Indica cantidad de elementos a ser colocados en la Cola: ";
    cin>>cantidad; i=0;
    while (i != cantidad) {
        cout << "Indica valor a colocar: ";
        cin>>valor;
        Encolar(*&col,valor);
        i++;
    }

}

struct Pila{
   int dato;
   Pila *prox;
};

Pila* crearPila(int valor){
    Pila *nuevo = new Pila;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool PilaVacia(Pila *pila){
    return pila==NULL;
}

Pila*  Tope(Pila *pila){
   if (!PilaVacia(pila))
      return pila; 
   else   
      return nullptr;    
}

void Apilar(Pila **pila, int valor){
   Pila *nuevo = crearPila(valor);
   nuevo->prox=*pila;
   *pila=nuevo;
}

void Desapilar(Pila **pila){
   Pila *temp;
     if (!PilaVacia(*pila))
      {
         temp = *pila;
        *pila = (*pila)->prox; 
         delete temp;
      } 
     else
       cout<<"Pila vacia imposible desapilar "<<endl;
}

void mostrarPila(Pila *pila){
  while (!PilaVacia(pila)) {
    cout <<Tope(pila)->dato<< "  ";
    Desapilar(&pila);
  }
}

void InvertirCola(Cola **cola1){

    int n = 0;
    Pila *aux1 = NULL;
    Pila *aux2 = NULL;
    cout << "Ingresar el numero de elementos a mover en la cola: ";
    cin >> n;

    for (int i = 0; i < n; i++){

        Apilar(&aux1, PrimeroCola(*cola1) -> dato);
        Desencolar(cola1);        

    }

    while (!ColaVacia(*cola1)){

        Apilar(&aux2, PrimeroCola(*cola1) -> dato);
        Desencolar(cola1);
    }

    while ( aux1 != NULL){
        Encolar(&*cola1, Tope(aux1) -> dato);
        Desapilar(&aux1);
    }

    while (aux2 != NULL){

        Apilar(&aux1, Tope(aux2) -> dato);
        Desapilar(&aux2);
    }

     while ( aux1 != NULL){
        Encolar(&*cola1, Tope(aux1) -> dato);
        Desapilar(&aux1);
    }

}

main(){
 
    Cola *cola1 = NULL;
    llenarCola(&cola1);
    cout<<"Contenido de la Cola 1: "<<endl;
    mostrarCola(cola1);

    InvertirCola(&cola1);

    mostrarCola(cola1);
}