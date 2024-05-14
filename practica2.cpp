#include <iostream>
using namespace std;
// Hecho por Freddy Fernandez

void procedimiento( int sueldo, int porcentaje, int *aumento ) {
    *aumento = (porcentaje * sueldo) / 100;
};

float iva( int sueldo ) {

    if ( sueldo > 5000) {
        cout << "Usted debe pagar " << ( 20 * sueldo ) / 100 << "$ en impuestos. Que es equivalente a un 20% de su sueldo";
    }
    else if ( sueldo < 5000 and sueldo >= 1000 ) {
        cout << "Usted debe pagar " << ( 10 * sueldo ) / 100 << "$ en impuestos. Que es equivalente a un 10% de su sueldo";
    }
    else {
        cout << "Usted no debe pagar impuestos.";
    }
    return 0;
}

main() {
    
    int x, y, z = 0;

    cout << "Ingresar sueldo inicial: " << endl;
    cin >> x,

    cout << "Ingresar el porcentaje de aumento: " << endl;
    cin >> y;

    procedimiento( x, y, &z);

    cout << "El sueldo base eran " << x << "$. Ahora su sueldo es de " << x + z << "$." << endl;

    iva(x);

};