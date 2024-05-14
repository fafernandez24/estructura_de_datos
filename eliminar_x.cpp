#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *prox;
};

Nodo *CrearNodo(int valor){

    Nodo *nuevo = new Nodo;

    nuevo -> dato = valor;
    nuevo -> prox = NULL;

    return nuevo;
};

bool ListaVacia(Nodo *inicio){
    return inicio == NULL;
}

void InsertarUltimo(Nodo **inicio, int n){

    Nodo *aux = *inicio;
    Nodo *nuevo = CrearNodo(n);

    if (!ListaVacia(*inicio)){
        while ( aux -> prox != NULL ){
            aux = aux -> prox;
        }
        aux -> prox = nuevo;
    }
    else
        *inicio = nuevo;
}

void EliminarX(Nodo **inicio, int valor){
    Nodo *mover,*anterior = NULL; 
   
    if (ListaVacia(*inicio))
       cout<<"Lista vacia!" <<endl;
    else {   
        mover = *inicio;
        while (mover != NULL && mover->dato != valor){
             anterior = mover;
             mover = mover->prox;
         }
        if (mover == NULL)
             cout<<"El elemento no existe en la lista "<<endl;
        else
           { if (mover == *inicio)
                *inicio=(*inicio)->prox;
             else
                anterior->prox = mover->prox;
             delete mover;  
           }      
   }
}

void EliminarUltimo(Nodo **inicio, int valor){

    Nodo *mover, *mover2, *anterior = NULL; 
    int counter1 = 0, counter2 = 0;

    if (ListaVacia(*inicio)){
        cout << "Lista vacia!" << endl;
    }
    else{

        mover = *inicio;

        while (mover != NULL ){

            if (mover -> dato == valor)
                counter1 = counter1 + 1;
            
            mover = mover -> prox;
        }

        mover2 = *inicio;

        if (counter1 != 0){

            while ( counter2 != counter1 || mover2 == NULL){

                anterior = mover2;
                mover2 = mover2 -> prox;

                if (mover2 -> dato == valor)
                    counter2 = counter2 + 1;
            }

            if (mover2 != NULL){
                if (mover2 == *inicio)
                    *inicio=(*inicio)->prox;
                else
                    anterior->prox = mover2->prox;
                delete mover2;            
            }
            else
                cout << "El elemento no existe en la lista!" << endl;

        }   
   }
}
    
void EliminarTodos (Nodo **inicio, int valor){

    Nodo *aux = *inicio;

    while (aux != NULL){

        if ( aux -> dato == valor ){
            EliminarX(&*inicio, valor);
            aux = *inicio;
        }

        aux = aux -> prox;
    }
}

void MostrarLista(Nodo *inicio){
   Nodo *mover;

   if (!ListaVacia(inicio)){
       mover = inicio;
      while (mover != NULL)
        {
           cout << mover->dato <<"->";
           mover = mover->prox;
         }
         cout<<"NULL"<<endl;
   }  
  else
     cout<<"Lista esta vacia"<<endl;
}


main(){

    Nodo *primero = NULL;
    int numero, opcion, i, valor, eliminar;
    i = 1;

    cout << "Ingresar el numero de casillas de la lista: ";
    cin >> numero;

    while (i <= numero){

        cout << "Ingresar el valor de la casilla " << i << ": ";
        cin >> valor;

        InsertarUltimo(&primero, valor);

        i++;
    }

    cout << "Ingresar el valor que desea eliminar de la lista: ";
    cin >> eliminar;

    cout << "(1) Eliminar la primera vez que lo encuentre" << endl;
    cout << "(2) Eliminar la ultima vez que lo encuentre" << endl;
    cout << "(3) Eliminar todas las veces que lo encuentre" << endl;
    cout << "(4) Salir" << endl;

    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion){

        case 1:
            EliminarX(&primero, eliminar);
            MostrarLista(primero -> prox);
            break;

        case 2:
            EliminarUltimo(&primero, eliminar);
            MostrarLista(primero);
            break;

        case 3:
            EliminarTodos(&primero, eliminar);
            MostrarLista(primero);
            break;
        case 4:
            cout << "Kame-ha-me...HAAAAAAAAAAAAAAAAAAAAAA!!!" << endl;
            break;
    }

    getch();
}