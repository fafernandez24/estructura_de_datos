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

Cola* Intercalar(Cola *cola1, Cola *cola2, Cola **mix){

    while (!ColaVacia(cola1) || !ColaVacia(cola2)){

        if (!ColaVacia(cola1)){
            Encolar(&*mix, PrimeroCola(cola1) -> dato);

            Desencolar(&cola1);
        }

        if (!ColaVacia(cola2)){
            Encolar(&*mix, PrimeroCola(cola2) -> dato);
            Desencolar(&cola2);
        }
    }

    return *mix;
}

main(){

    Cola* mix = NULL;
 
    Cola *cola1 = NULL;
    llenarCola(&cola1);
    cout<<"Contenido de la Cola 1: "<<endl;
    mostrarCola(cola1);

    Cola* cola2 = NULL;
    llenarCola(&cola2);
    cout << "Contenido de la cola 2: " << endl;
    mostrarCola(cola2);

    Intercalar(cola1, cola2, &mix);

    cout << "Contenido de las colas intercaladas: " << endl;
    mostrarCola(mix);
}