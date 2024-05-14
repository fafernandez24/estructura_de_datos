#include <iostream>
using namespace std;
main(){

    int *P, *Q, valor;
    valor = 54;
    P = &valor;
    Q = &valor;
    *P = *Q;
    P = Q;
    cout << *&Q;
    cout << &*Q;
    P = Q;
    cout << P << endl << *P << endl << &P << endl;

    *P = valor;
    cout << *P;

};
