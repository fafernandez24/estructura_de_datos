#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cctype>
#include <iostream>
using namespace std;
// Hecho por Freddy Fernandez

struct Mundo{

    string region;
    int jugadores;

    Mundo *prox;
    Mundo *CaracteristicasZona;
};

struct Players{

    int jugador;
    string nombre;
    string team;
    int dinero;

    Players *proxPlayer;
    Players *Tipo;

};

struct Tipo{

    string fortaleza;
    string debilidad;

    string descripcion;
    string habilidad;

    Tipo *Players;
};

Players* CrearPlayers (int num_jugador, string nombrejugador, string clase, int cash){

    Players *jugadores = new Players;

    jugadores -> jugador = num_jugador;
    jugadores ->  nombre = nombrejugador;
    jugadores -> team = clase;
    jugadores -> dinero = cash;

    jugadores -> proxPlayer = NULL;
    jugadores -> Tipo = NULL;

    return jugadores;
};

Mundo* CrearMundo( string zona, int cantidad_jugadores){

    Mundo *tablero = new Mundo;
    
    tablero -> region = zona;
    tablero -> jugadores = cantidad_jugadores;

    tablero -> prox = NULL;
    tablero -> CaracteristicasZona = NULL;

    return tablero;
};

bool ListaVaciaMundo(Mundo *tablero){
    return tablero == NULL;
};

bool ListaVaciaPlayers(Players *jugadores){
    return jugadores == NULL;
}

void MostrarPersonajes(Players *personajes){

    Players *mover1;
    //Players *mover2;

    if (!ListaVaciaPlayers(personajes)){

        mover1 = personajes;

        while (mover1 != NULL){

            //bool bol = false;

            cout << "-------------------------------" << endl;
            cout << "Nick name: " << mover1 -> nombre <<endl;
            cout << "-------------------------------" << endl;
            
            cout << "JUGADOR #" << mover1 -> jugador << endl;
            cout << "Clase: " << mover1 -> team << endl;
            cout << "Dinero: " << mover1 -> dinero << endl;
            cout << "-------------------------------" << endl;

            mover1 = mover1 -> proxPlayer;

            /*mover2 = mover1 -> Tipo;

            if (mover2 != NULL){

                cout << "CARACTERISTICAS" << endl;
                cout << "-------------------------------" << endl;

                while (bol == false){

                    cout << " - Habilidades: " << mover2 -> habilidades << endl;
                    cout << " - Fortalezas: " << mover2 -> fortalezas << endl;
                    cout << " - Debilidades: " << mover2 -> debilidades << endl;

                }
            }

            else
                cout << "No tiene una clase asignada!" << endl;

            cout << "-------------------------------" << endl;*/
        }
    }
    else
        cout << "No existen personajes creados" << endl;
}

void InsertarUltimoPlayer( Players **personajes, int playerN, string nombre, string clase, int money ){

    /* Insertar personajes. */

    Players *insertPlayer = CrearPlayers(playerN,  nombre, clase, money);
    Players *aux = NULL;

    if (ListaVaciaPlayers(*personajes))
        *personajes = insertPlayer;
    else{
        aux = *personajes;

        while (aux -> proxPlayer != NULL){
            aux = aux -> proxPlayer;
        }
        aux -> proxPlayer = insertPlayer;
    }
}

Mundo* InsertarUltimoMundo(Mundo **casilla, string zona, int posicionJugadores){

    Mundo *insertCasilla = CrearMundo(zona, posicionJugadores);
    Mundo *aux = NULL;

    if (ListaVaciaMundo(*casilla))
        *casilla = insertCasilla;

    else{

        aux = *casilla;

        while ( aux -> prox != NULL ){
            aux = aux -> prox;
        }

        aux -> prox = insertCasilla;
    }

    return *casilla;

}

void MostrarTablero (Mundo* casilla){

    int count = 0;
    Mundo *aux = casilla;

    while (aux -> prox != NULL){

        count += 1;
        cout << aux -> region << "  ";

        if (count == 20){
            cout << endl;
            count = 0;
        }

        aux = aux -> prox;

    }
  }


main(){

    Mundo* casillas = NULL;

    Players *jugadores = NULL;

    char name[6];

    string region = "0", clase, habilidades, fortalezas, debilidades;

    int opciones = 0, num_jugadores = 0, jugadorN, dinero, posicion, a;

    cout << "============================= INICIO =============================" << endl;

    cout << "(1) Comenzar partida" << endl;
    cout << "(2) Ver tablero" << endl;
    cout << "(3) Crear personajes" << endl;
    cout << "(4) Salir" << endl;

    cout << "==================================================================" << endl;

    cout << "Opcion: ";
    cin >> opciones;
    
    cout << "-----------------------------------------------------------------" << endl;

    switch (opciones){

        case 1:

            cout << ":keycap_number_sign:" << endl;
            break;

        case 2:

            while (a <= 400 ){

                if (a == 0 || a == 1 || a == 20 || a == 21)
                    region = "1";
                else
                    region = "0";

                posicion = a;
                InsertarUltimoMundo(&casillas, region, posicion);
                a++;
            }

            cout << "------------------------- TABLERO -------------------------" << endl;

            MostrarTablero(casillas);

            cout << "-----------------------------------------------------------" << endl;

            break;

        case 3:

            while (num_jugadores <= 0 || num_jugadores > 4){
                cout << "Ingresar numero de jugadores: ";
                cin >> num_jugadores;
            }

            for (int i = 1; i <= num_jugadores; i++){
                dinero = 200;
                jugadorN = 1 + rand() % 3;

                cout << "-------------------------------" << endl;
                cout << "Jugador " << jugadorN << endl;
                cout << "-------------------------------" << endl;

                cout << "Ingresar un nick name( max. 6 letras ): ";
                cin >> name;
                cout << "-------------------------------" << endl;

                if ( jugadorN == 1 )
                    clase = "Chavista de closet";

                else if ( jugadorN == 2)
                    clase = "Euro veneco";

                else if ( jugadorN == 3)
                    clase = "Guaidista";

                else if ( jugadorN == 4)
                    clase = "El rey del arroz con pollo";

                InsertarUltimoPlayer(&jugadores, jugadorN, name, clase, dinero);

                MostrarPersonajes(jugadores);

            }
            break;

        case 4:

            cout << "Adios y buena suerte!" << endl;
            cout << "P.D.: Si encuentran algun billete por ahi, ayude al planeta." << endl;
            cout << endl;
            cout << "Firma:" << endl;
            cout << "Guardianes del Medio Ambiente (GMA)." << endl;
            
            break;
    }


    getch();
}