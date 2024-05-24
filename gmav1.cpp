#include <iostream>
#include <locale>
#include <cstdlib>
#include <conio.h>
#include <cctype>
#include <ctime>
using namespace std;
// Hecho por Freddy Fernandez

// TIPOS DE STRUCTS

// STRUCT PARA LAS CASILLAS
struct Casillas{

    string region;
    int jugadores;
    int posicion;

    Casillas *prox;
};

// STRUCT PARA LAS CARACTERISTICAS DE LA REGION
struct CaracteristicasRegion{

    int temperature;
    string vegetation;
    string population;
    string naturaldisaster;

    Casillas *CaracteristicasRegion;

};

//STRUCT PARA LOS DESASTRES NATURALES
struct DesafiosAmbientales{

    int desafioamb;
    Casillas *desafios;

};

// STRUCT DE LOS JUGADORES
struct Jugadores{

    string nombre;
    int njugador;
    int dinero;
    int leam; // Nivel ambiental;

    Jugadores *proxPlayer;
    Casillas *Jugadores;

};

// STRUCT DE LAS CLASES DE LOS JUGADORES
struct Tipo{

    string clase;
    string descripcion;
    string habilidad;

    Jugadores *Tipo;

};

// FUNCIONES

// FUNCIONES DE LISTAS

Casillas* CrearCasilla( string zona, int posicion){

    Casillas *tablero = new Casillas;
    
    tablero -> region = zona;
    tablero -> jugadores = 0;
    tablero -> posicion = posicion;

    tablero -> prox = NULL;

    return tablero;
};

Jugadores* CrearJugadores (string nick, int numjugador){

    Jugadores *jugador = new Jugadores;

    jugador ->  nombre = nick;
    jugador -> njugador = numjugador;
    jugador -> dinero = 200;
    jugador -> leam = 0;

    jugador -> proxPlayer = NULL;
    jugador -> Jugadores = NULL;

    return jugador;
};

Tipo* CrearTipo(string clase, string descripcion, string habilidad, Jugadores *jugador){

    Tipo* classnew = new Tipo;

    classnew -> clase = clase;
    classnew -> descripcion = descripcion;
    classnew -> habilidad = habilidad;

    classnew -> Tipo = jugador;
    
    return classnew;
}

// FUNCIONES BOOLEANAS

bool ListaVaciaCasillas(Casillas *tablero){
    return tablero == NULL;
};

bool ListaVaciaCaracteristicasRegion(CaracteristicasRegion *caracteristica){
    return caracteristica == NULL;
}

bool ListaVaciaPlayers(Jugadores *jugadores){
    return jugadores == NULL;
}

bool ListaVaciaTipo(Tipo *tipo){
    return tipo == NULL;
}

// VALIDACIONES

bool ValidarNJugadores( int numjugadores){
    if (numjugadores < 1 || numjugadores > 4)
        return false;
    else
        return true;
}

// FUNCIONES NORMALES

int Turno(Jugadores *jugador){

    Jugadores *aux = jugador;
    int turno;

    if (aux -> njugador == 1)
        turno = 1;

    if (aux -> njugador == 2)
        turno = 2;

    if (aux -> njugador == 3)
        turno = 3;
    
    if (aux -> njugador == 4)
        turno = 4;

 return turno;

}

int Dado(bool bol){

    int dado;

    srand(time(NULL));
    if (bol == true){
        dado = 1 + rand() % 6;
    }

    return dado;
}

// PROCEDIMIENTOS

void InsertarUltimoCasillas(Casillas **casilla, string zona, int posicion){

    Casillas *insertCasilla = CrearCasilla(zona, posicion);
    Casillas *aux = NULL;

    if (ListaVaciaCasillas(*casilla))
        *casilla = insertCasilla;
    else{

        aux = *casilla;

        while ( aux -> prox != NULL ){
            aux = aux -> prox;
        }

        aux -> prox = insertCasilla;
    }
}

void MostrarPersonajes(Jugadores *personajes){

    Jugadores *mover1;
    //Tipo *mover2;

    if (!ListaVaciaPlayers(personajes)){

        mover1 = personajes;

        while (mover1 != NULL){

            //bool bol = false;

            cout << "-------------------------------" << endl;
            cout << "Nick name: " << mover1 -> nombre <<endl;
            cout << "-------------------------------" << endl;
            
            cout << "JUGADOR #" << mover1 -> njugador << endl;
            cout << "Dinero: " << mover1 -> dinero << endl;
            cout << "Nivel ambiental: " << mover1 -> leam << endl;
            cout << "-------------------------------" << endl;

            mover1 = mover1 -> proxPlayer;

         /*   mover2 = clases;

            if (mover2 != NULL){

                cout << "CARACTERISTICAS" << endl;
                cout << "-------------------------------" << endl;

                while (bol == false){

                    cout << " - Clase: " << mover2 -> clase << endl;
                    cout << " - Fortalezas: " << mover2 -> descripcion << endl;
                    cout << " - Debilidades: " << mover2 -> habilidad << endl;

                }
            }

            else
                cout << "No tiene una clase asignada!" << endl;

        */

            cout << "-------------------------------" << endl;
        }
    }
    else
        cout << "No existen personajes creados" << endl;

}

void InsertarUltimoPlayer(Jugadores **personajes, string nick, int playerN){

    /* Insertar personajes. */

    int contador = 0;

    Jugadores *insertJugador = CrearJugadores(nick, playerN);
    Jugadores *aux = NULL;
    Jugadores *inicio = NULL;

    if (ListaVaciaPlayers(*personajes))
        *personajes = insertJugador;
    else{
        aux = *personajes;
        inicio = *personajes;

        while (aux -> proxPlayer != NULL){
            aux = aux -> proxPlayer;
            contador += 1;
        }

        aux -> proxPlayer = insertJugador;

        if (contador == 3 ){
            aux -> proxPlayer = inicio;
        }
    }

}

void InsertarUltimoClase(Tipo **clasejugador,  Jugadores *personaje, string clase, string descripcion, string habilidad){

    Tipo *nuevoclase = CrearTipo(clase, descripcion, habilidad, personaje);

    if (!ListaVaciaTipo(*clasejugador)){
        *clasejugador = nuevoclase;
    }

}

void InsertarClases(Jugadores **jugador){

    Jugadores *personaje = *jugador;

    string clase = "";
    string descripcion = "";
    string habilidad = "";

    Tipo *clasepersonaje = NULL;


    if  (!ListaVaciaPlayers(*jugador)){

        if (personaje -> njugador == 1){

            clase = "MAESTRO DEL TRUEQUE";
            descripcion = "Un habil negociante que siempre encuentra la manera de intercambiar bienes y servicios, incluso en los momentos mas dificiles.";
            habilidad = "Tienes un gran poder de conviccion, tus acciones de conservacion son mas efectivas.";

        }

        if (personaje -> njugador == 2){

            clase = "GENIO DE LA LUZ";
            descripcion = "Un personaje ingenioso que encuentra soluciones creativas a la falta de electricidad.";
            habilidad = "Tienes mas chance de no verse afectado por un desastre natural.";

        }

        if (personaje -> njugador == 3){

            clase = "MECANICO MACGYVER";
            descripcion = "Un mecanico ingenioso que puede arreglar cualquier cosa con un poco de astucia y piezas de repuesto improvisadas";
            habilidad = "Tienes un gran poder de conviccion, tus acciones de conservacion son mas efectivas.";

        }

        InsertarUltimoClase(&clasepersonaje, personaje, clase, descripcion, habilidad);

    }

}

void CrearPersonajes (Jugadores **jugadores){

    string nick;
    int jugadorN;
    int num_jugadores;

    while (ValidarNJugadores(num_jugadores) == false){

        cout << "Ingresar numero de jugadores: ";
        cin >> num_jugadores;

        if (num_jugadores < 1 || num_jugadores > 4)
            cout << "ERROR, ingresar un numero entero entre 1 y 4!" << endl;

    }

    for (int i = 1; i <= num_jugadores; i++){

         srand(time(NULL));

        jugadorN = (rand() % 4) + 1;

        cout << "-------------------------------" << endl;
        cout << "Jugador " << jugadorN << endl;
        cout << "-------------------------------" << endl;

        cout << "Ingresar un nick name: ";
        cin >> nick;

        cout << "-------------------------------" << endl;

        InsertarUltimoPlayer(*&jugadores, nick, jugadorN);
        InsertarClases(*&jugadores);

    }

}

// Procedimiento para imprimir el tablero;

void MostrarTablero (Casillas* casilla){

    int count = 0;
    Casillas *aux = casilla;

    cout << "------------------------- TABLERO -------------------------" << endl;

    while (aux -> prox != NULL){

        count += 1;
        cout << aux -> region << "  ";

        if (count == 20){
            cout << endl;
            count = 0;
        }

        aux = aux -> prox;

    }

    cout << "-----------------------------------------------------------" << endl;

  }

// PROCEDIMIENTO PARA CREAR EL TABLERO
void CrearTablero(Casillas **casillas){

    string region;
    int a = 0;
    int posicion;

    while (a <= 400 ){

        if (a == 0 || a == 1 || a == 20 || a == 21){
            region = "I";
        }
        
        else if ( a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 10 || a == 11 || a == 12 || a == 13 || a == 14 || a == 15 || a == 16 || a == 17 || a == 22 || a == 23 || a == 24 || a == 25 || a == 26 || a == 27 || a == 28 || a == 29 || a == 30 || a ==31 || a == 32 || a == 33 || a == 34 || a == 35 || a == 36 || a == 37 ){
            region = "A";
        }

        else if ( a == 58 || a == 59 || a == 78 || a == 79 || a == 98 || a == 99 || a == 118 || a == 119 || a == 138 || a == 139 || a == 158 || a == 159 || a == 178 || a == 179 || a == 198 || a == 199 || a == 218 || a == 219 || a == 238 || a == 239 || a == 258 || a == 259 || a == 278 || a ==279 || a == 298 || a == 299 || a == 318 || a == 319 || a == 338  || a == 339 || a == 358 || a == 359 ){
            region = "C";
        }

        else if ( a == 40 || a == 41 || a == 60 || a == 61 || a == 80 || a == 81 || a == 100 || a == 101 || a == 120 || a == 121 || a == 140 || a == 141 || a == 160 || a == 161 || a == 180 || a == 181 || a == 200 || a == 201 || a == 220 || a == 221 || a == 240 || a == 241 || a == 260 || a == 261 || a == 280 || a == 281 || a == 300 || a == 301 || a == 320  || a == 321 || a == 340 || a == 341 ){
            region = "L";
        }

        else if (a == 362 || a == 363 || a == 364 || a == 365 || a == 366 || a == 367 || a == 368 || a == 369 || a == 370 || a == 371 || a == 372 || a == 373 || a == 374 || a == 375 || a == 376 || a == 377 || a == 382 || a == 383 || a == 384 || a == 385 || a == 386 || a == 387 || a == 388 || a == 389 || a == 390 || a == 391 || a == 392 || a == 393 || a == 394 || a == 395 || a == 396 || a == 397 )
            region = "Z";

        else if ( a == 18 || a == 19 || a == 38 || a == 39 || a == 360 || a == 361 || a == 380 || a == 381 || a == 378 || a == 379 || a == 398 || a == 399 ){
            region = "W";
        }

        else{
            region = "0";
        }

        posicion = a;

        InsertarUltimoCasillas(*&casillas, region, posicion);
        a++;
    }
}

void InsertarPersonajes(Casillas **casilla, Jugadores **personajes, int posicion){

    Casillas *aux;
    Jugadores *insertpersonaje;

    int i = 0;

    if (!ListaVaciaCasillas(*casilla) && !ListaVaciaPlayers(*personajes)){

        aux = *casilla;
        insertpersonaje = *personajes;

    while (insertpersonaje != NULL){

        while (i != posicion){
                aux = aux -> prox;
                i++;
        }

        insertpersonaje -> Jugadores = aux;
        aux -> region = "P";
        aux -> jugadores += 1;

        if (posicion == 0)
            posicion = 1;
        
        else if (posicion == 1)
            posicion = 20;

        else if (posicion == 20)
            posicion = 21;

        insertpersonaje = insertpersonaje -> proxPlayer;
        }
    }
}

void MostrarDado(int dado){

    int dadito = dado;

    if (dadito == 1){
        cout << "------" << endl;
        cout << "|     |" << endl;
        cout << "|  *  |" << endl;
        cout << "|     |" << endl;
        cout << "------" << endl;

    }

    if (dadito == 2){
        cout << "------" << endl;
        cout << "|   * |" << endl;
        cout << "|     |" << endl;
        cout << "| *   |" << endl;
        cout << "------" << endl;

    }

    if (dadito == 3){
        cout << "------" << endl;
        cout << "|   * |" << endl;
        cout << "|  *  |" << endl;
        cout << "| *   |" << endl;
        cout << "------" << endl;

    }

    if (dadito == 4){
        cout << "------" << endl;
        cout << "| * * |" << endl;
        cout << "|     |" << endl;
        cout << "| * * |" << endl;
        cout << "------" << endl;

    }

    if (dadito == 5){
        cout << "------" << endl;
        cout << "| * * |" << endl;
        cout << "|  *  |" << endl;
        cout << "| * * |" << endl;
        cout << "------" << endl;

    }

    if (dadito == 6){
        cout << "------" << endl;
        cout << "| * * |" << endl;
        cout << "| * * |" << endl;
        cout << "| * * |" << endl;
        cout << "------" << endl;
    }

}

void MoverJugadorUno(Casillas **casilla, Jugadores **personajes, int dado){

    Casillas *mover;
    Jugadores *jugador;

    int i = 0;

    if (!ListaVaciaCasillas(*casilla) && !ListaVaciaPlayers(*personajes)){

        mover = *casilla;
        jugador = *personajes;

        if (mover -> posicion == 0 || mover -> posicion == 1 || mover -> posicion == 20 || mover -> posicion == 21){
            mover -> region = "I";
        }

        else if ( mover -> posicion == 2 || mover -> posicion == 3 || mover -> posicion == 4 || mover -> posicion == 5 || mover -> posicion == 6 || mover -> posicion == 7 || mover -> posicion == 8 || mover -> posicion == 9 || mover -> posicion == 10 || mover -> posicion == 11 || mover -> posicion == 12 || mover -> posicion == 13 || mover -> posicion == 14 || mover -> posicion == 15 || mover -> posicion == 16 || mover -> posicion == 17 || mover -> posicion == 22 || mover -> posicion == 23 || mover -> posicion == 24 || mover -> posicion == 25 || mover -> posicion == 26 || mover -> posicion == 27 || mover -> posicion == 28 || mover -> posicion == 29 || mover -> posicion == 30 || mover -> posicion ==31 || mover -> posicion == 32 || mover -> posicion == 33 || mover -> posicion == 34 || mover -> posicion == 35 || mover -> posicion == 36 || mover -> posicion == 37 ){
            mover -> region = "A";
        }

        else if (mover -> posicion == 0 || mover -> posicion == 20){
            dado++;
        }

        while (i < dado){

            mover = mover -> prox;
            i++;
        }

        mover -> region = "P";
        mover -> jugadores += 1;

        jugador -> Jugadores = mover;
    }

}

int main(){

    Casillas *casillas = NULL;
    Jugadores *personajes = NULL;
    Jugadores *aux = NULL;

    string region = "0", lanzar = "";

    int opciones = 0, posicion = 0, turno = 1, dado;

    bool juego = true, bol = false;

    while (opciones != 4){

        cout << "======================= MENU INICIO =======================" << endl;

        cout << "(1) Comenzar partida" << endl;
        cout << "(2) Ver tablero" << endl;
        cout << "(3) Crear personajes" << endl;
        cout << "(4) Salir" << endl;

        cout << "===========================================================" << endl;

        cout << "Opcion: ";
        cin >> opciones;

        if (opciones == 1){

            CrearPersonajes(&personajes);
            InsertarClases(&personajes);
            MostrarPersonajes(personajes);

            if (ListaVaciaCasillas(casillas)){
                CrearTablero(&casillas);
                InsertarPersonajes(&casillas , &personajes, posicion);
            }

            aux = personajes;

            while (juego == true){ 
            
                MostrarTablero(casillas);

                cout << "Turno del jugador: " << aux -> nombre << endl;

                while (bol == false){

                    cout << "Presiona ENTER para tirar el dado: ";
                    cin >> lanzar;

                    if (lanzar == "ENTER")
                        bol = true;
                }

                dado = Dado(bol);
                MostrarDado(dado);

                turno++;
                bol = false;
                aux = aux -> proxPlayer;

                MoverJugadorUno(&aux -> Jugadores, &personajes, dado);
                turno++;

                if (turno >= 4){
                    aux = personajes;
                }
    
            }

        }

        if (opciones == 2){

            if (ListaVaciaCasillas(casillas)){
                CrearTablero(&casillas);
                InsertarPersonajes(&casillas, &personajes, posicion);
            }
            
            MostrarTablero(casillas);

        }

        if (opciones == 3){
            CrearPersonajes(&personajes);
            MostrarPersonajes(personajes);
        }

        if (opciones == 4){
            break;
        }
    }

    getch();

    return 0;
}