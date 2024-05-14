#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo *prox;
};

Nodo* crearNodo(int valor) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = valor;
  nuevo->prox = NULL;
  return nuevo;
}

bool listaVacia(Nodo *inicio){
    return inicio==NULL;
}

void insertarPrincipio(Nodo **inicio, int valor) {
  Nodo *nuevo = crearNodo(valor);
  nuevo->prox = *inicio;
  *inicio = nuevo;
}

void insertarUltimo(Nodo **inicio, int valor){
    Nodo *nuevo = crearNodo(valor);
 
   if (listaVacia(*inicio)) {
       *inicio = nuevo;
    } 
    else {
       Nodo *auxiliar = *inicio;
       while (auxiliar->prox != NULL) {
           auxiliar = auxiliar->prox;
       }
        auxiliar->prox = nuevo;
  }
   
}

void buscarElemento(Nodo *inicio, int valor) {
  Nodo *aux = inicio; bool encontrado = false;

  if (listaVacia(inicio))
     cout<<"Lista vacia"<<endl;
  else
    {
      while (aux != NULL && encontrado == false) {
         if (aux->dato == valor) {
            cout<<"El dato "<<valor<< " fue encontrado con exito"<<endl;
            encontrado = true;
         }
      else 
          aux = aux->prox;
     }
     if (encontrado == false)
        cout<<"Valor no encontrado en la lista "<<endl;
    }   
}

int pedir_valor(){
   int valor;
   cout<<"Indica valor: ";
   cin>>valor;
   return valor;
}

void mostrarLista(Nodo *inicio){
   Nodo *mover;

   if (!listaVacia(inicio)){
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

void porcentaje( Nodo *inicio, int a, int b, int c, int valor ){
    a = 1;
    b = 100;
    c = 0;
    valor = 0;
    Nodo *mover;

    if (!listaVacia(inicio)) {
        mover = inicio;
    }

    cout << "Indicar valor a encontrar: ";
    cin >> valor;

    while ( mover != NULL ) {

        a += 1;

        if ( mover -> dato == valor ){
            c += 1;

            mover = mover -> prox;
        }
        else {
            mover = mover -> prox;
        }
    }

    if (mover == NULL ) {
        a -= 1;
        cout << "Tu valor a encontrar aparece en el " << (( c * b ) / a) << "% de la lista enlazada" << endl;
    }
}

main() {
    int contador, maximo, buscar, dato, opcion;

    opcion = 0;
    Nodo *primero = NULL;

    contador = 0;
    maximo = 100;
    buscar = 0;
    dato = 0;

    while ( opcion != 6 ) {
        cout<<"***********     MENU DE OPCIONES     **********"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"1.- Agregar un nodo al inicio de la Lista"<<endl;
        cout<<"2.- Agregar un nodo al final de la Lista"<<endl;
        cout<<"3.- Buscar un elemento en la Lista"<<endl;
        cout<<"4.- Mostrar contenido de la Lista"<<endl;
        cout<<"5.- Mostrar porcentaje del valor a buscar en la Lista"<<endl;
        cout << "Ingrese la opcion deseada del Menu: ";
        cin >> opcion;

            switch (opcion) {
            case 1:
                // Agregar un nodo al inicio de la Lista
                insertarPrincipio(&primero, pedir_valor());
                break;
            case 2:
                // Agregar un Nodo al final de la Lista
                insertarUltimo(&primero,pedir_valor());
                break;
            case 3: 
                // Buscar un elemento en la lista
                if (listaVacia(primero))
                    cout<<"Lista vacia, no es posible hacer una busqueda"<<endl;
                else
                    buscarElemento(primero, pedir_valor());
                break;
            case 4: 
                // Mostrar contenido de la lista
                if (listaVacia(primero))
                    cout<<"Lista vacia, no es posible mostrar su contenido"<<endl;
                else
                    mostrarLista(primero);
                break; 
            case 5:
                // Porcentaje del valor a buscar en la lista
                porcentaje( primero, contador, maximo, buscar, dato );
                break;
    }
}
}