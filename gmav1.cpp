#include <iostream>
#include <locale>
#include <cstdlib>
#include <conio.h>
#include <cctype>
#include <ctime>
using namespace std;
// Hecho por Freddy Fernandez

// TIPOS DE STRUCTS

struct Casillas{ // STRUCT PARA LAS CASILLAS

    string region;
    int jugadores;
    int posicion;

    Casillas *prox;
};

struct CaracteristicasRegion{ // STRUCT PARA LAS CARACTERISTICAS DE LA REGION

    int temperature;
    string vegetation;
    string population;
    string naturaldisaster;

    Casillas *CaracteristicasRegion;

};

struct DesafiosAmbientales{ //STRUCT PARA LOS DESASTRES NATURALES

    string desafioamb;
    int tipodesafio;

    DesafiosAmbientales *prox;
    Casillas *desafios;

};

struct Jugadores{ // STRUCT DE LOS JUGADORES

    string nombre;
    int njugador;
    int dinero;
    int leam; // Nivel ambiental;

    Jugadores *proxPlayer;
    Casillas *Jugadores;

};

struct Tipo{ // STRUCT DE LAS CLASES DE LOS JUGADORES

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

    // Nodo que apunta a la siguiente casilla;
    tablero -> prox = NULL;

    return tablero;
};

DesafiosAmbientales* CrearDesafioAmbiental( string desafio, int ndesafio, Casillas **casilla){

    DesafiosAmbientales *nuevodesafio = new DesafiosAmbientales;

    nuevodesafio -> desafioamb = desafio;
    nuevodesafio -> tipodesafio = ndesafio;
    
    nuevodesafio -> prox = NULL;

    // Enlace que lo une a la casilla correspondiente;
    nuevodesafio -> desafios = *casilla;

    return nuevodesafio;
}

Jugadores* CrearJugadores (string nick, int numjugador){

    Jugadores *jugador = new Jugadores;

    jugador ->  nombre = nick;
    jugador -> njugador = numjugador;
    jugador -> dinero = 200;
    jugador -> leam = 0;

    // Nodo que apunta al siguiente jugador;
    jugador -> proxPlayer = NULL;

    // Enlace entre los jugadores y las casillas;
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

bool ListaVaciaDesafiosAmbientales(DesafiosAmbientales *desastre){
    return desastre == NULL;
}

bool ListaVaciaPlayers(Jugadores *jugadores){
    return jugadores == NULL;
}

bool ListaVaciaTipo(Tipo *tipo){
    return tipo == NULL;
}

bool ValidarNJugadores( string numjugadores){

    if (numjugadores == "1")
        return true;

    if (numjugadores == "2")
        return true;

    if (numjugadores == "3")
        return true;

    if (numjugadores == "4")
        return true;

    else
        return false;
}

bool PantallaInicio(){ // PANTALLA DE INICIO;

    string inicio;

    cout << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << endl;
    cout << char(176) << char(71) << char(176) << char(85) << char(176) << char(65) << char(176) << char(82) << char(176) << char(68) << char(176) << char(73) << char(176) << char(65) << char(176) << char(78) << char(176) << char(69) << char(176) << char(83) << char(176) << char(32) << char(176) << char(68) << char(176) << char(69) << char(176) << char(76) << char(176) << endl;
    cout << char(176) << char(77) << char(176) << char(69) << char(176) << char(68) << char(176) << char(73) << char(176) << char(79) << char(176) << char(32) << char(176) << char(65) << char(176) << char(77) << char(176) << char(66) << char(176) << char(73) << char(176) << char(69) << char(176) << char(78) << char(176) << char(84) << char(176) << char(69) << char(176) << endl;
    cout << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << char(177) << char(176) << endl;

    cout << "=============================" << endl;
    cout << "INGRESAR START: ";
    cin >> inicio;

    if (inicio == "start")
        return true;

    if (inicio == "START")
        return true;
    else
        return false;

    }

// FUNCIONES DE TIPO ENTERO

int CantidadJugadores(string numjugadores){

    if (numjugadores == "1")
        return 1;
    
    if (numjugadores == "2")
        return 2;

    if (numjugadores == "3")
        return 3;

    if (numjugadores == "4")
        return 4;

    return 0;
}

int CantidadTurno(Jugadores *jugador){

    Jugadores *aux = jugador;
    int contador = 0;

    while (aux != NULL){
        aux = aux -> proxPlayer;
        contador++;
    }

    return contador;

}

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

void InsertarUltimoDesastreAmbiental(string desastrenatural, int tipodesafio, Casillas **casilla, DesafiosAmbientales **desafio){

    DesafiosAmbientales *aux = *desafio;
    DesafiosAmbientales *creardesafio = CrearDesafioAmbiental(desastrenatural, tipodesafio, *&casilla);

    if (ListaVaciaDesafiosAmbientales(*desafio))
        aux = creardesafio;

    else{

        while (aux -> prox != NULL){
            aux = aux -> prox;
        }

        aux -> prox = creardesafio;

    }
}

void MostrarPersonajes(Jugadores *personajes){ //PROCEDIMIENTO PARA MOSTRAR A TODOS LOS PERSONAJES;

    Jugadores *mover1;

    if (!ListaVaciaPlayers(personajes)){

        mover1 = personajes;

        while (mover1 != NULL){

            cout << "-------------------------------" << endl;
            cout << "Nick name: " << mover1 -> nombre <<endl;
            cout << "-------------------------------" << endl;
            
            cout << "JUGADOR #" << mover1 -> njugador << endl;
            cout << "Dinero: " << mover1 -> dinero << endl;
            cout << "Nivel ambiental: " << mover1 -> leam << endl;
            cout << "-------------------------------" << endl;

            mover1 = mover1 -> proxPlayer;

            cout << "-------------------------------" << endl;
        }
    }
    else
        cout << "No existen personajes creados" << endl;

}

void Mostrar1Personaje(Jugadores *personajes, int x ){ // PROCEDIMIENTO PARA MOSTRAR UN PERSONAJE;

    Jugadores *mover1;

    if (!ListaVaciaPlayers(personajes)){

        mover1 = personajes;

        while (mover1 -> njugador != x){
            mover1 = mover1 -> proxPlayer;
        }

        if (mover1 -> njugador == x){
            cout << "-------------------------------" << endl;
            cout << "Nick name: " << mover1 -> nombre <<endl;
            cout << "-------------------------------" << endl;
            
            cout << "JUGADOR #" << mover1 -> njugador << endl;
            cout << "Dinero: " << mover1 -> dinero << endl;
            cout << "Nivel ambiental: " << mover1 -> leam << endl;
            cout << "-------------------------------" << endl;

        }
        
    }
}

void InsertarUltimoPlayer(Jugadores **personajes, string nick, int playerN){

    /* Insertar personajes. */

    Jugadores *insertJugador = CrearJugadores(nick, playerN);
    Jugadores *aux = NULL;

    if (ListaVaciaPlayers(*personajes))
        *personajes = insertJugador;

    else{
        aux = *personajes;

        while (aux -> proxPlayer != NULL){
            aux = aux -> proxPlayer;
        }

        aux -> proxPlayer = insertJugador;

    }

}

void InsertarUltimoClase(Tipo **clasejugador,  Jugadores *personaje, string clase, string descripcion, string habilidad){

    Tipo *nuevoclase = CrearTipo(clase, descripcion, habilidad, personaje);

    if (!ListaVaciaTipo(*clasejugador)){
        *clasejugador = nuevoclase;
    }

}

void InsertarDesastre(Casillas **casillas){

    Casillas *aux = NULL;

    string desastre = "";
    int ndesafio = 0;

    DesafiosAmbientales *desastrenatural = NULL;

    if (!ListaVaciaCasillas(*casillas)){

        aux = *casillas;

        if ( aux -> posicion == 18 || aux -> posicion == 19 || aux -> posicion == 38 || aux -> posicion == 39 ){
            desastre = "avalancha";
            ndesafio = 1;
        }

        else if ( aux -> posicion == 360 || aux -> posicion == 361 || aux -> posicion == 380 || aux -> posicion == 381 ){
            desastre = "sequia";
            ndesafio = 2;
        }

        else if ( aux -> posicion == 378 || aux -> posicion == 379 || aux -> posicion == 398 || aux -> posicion == 399 ){
            desastre = "deforestacion";
            ndesafio = 3;
        }

        InsertarUltimoDesastreAmbiental(desastre, ndesafio, &aux, &desastrenatural);

        aux = aux -> prox;

    }

}

void InsertarClases(Jugadores **jugador){ //PROCEDIMIENTO PARA AGREGAR CLASES A LOS JUGADORES;

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
            habilidad = "Con su gran ingenio, tiene la capacidad de generar artefactos a partir de basura utilizandola como material reciclado.";

        }

        if (personaje -> njugador == 4){
            
            clase = "BOTANICO";
            descripcion = "Un experto en plantas y flores que puede encontrar curas y remedios en la naturaleza, y tiene el conocimiento para saber donde y cuando plantar distintias especies de plantas.";
            habilidad = "Tiene la capacidad de saber cuales plantas sembrar dependiendo del ambiente en donde se encuentre.";
        }

        InsertarUltimoClase(&clasepersonaje, personaje, clase, descripcion, habilidad);

    }

}

void CrearPersonajes (Jugadores **jugadores){

    string nick;
    string num_jugadores;
    int numjugadores;

    while (ValidarNJugadores(num_jugadores) == false){

        cout << "Ingresar numero de jugadores: ";
        cin >> num_jugadores;

        if (ValidarNJugadores(num_jugadores) != true)
            cout << "ERROR, ingresar un numero entero entre 1 y 4!" << endl;
        else
            numjugadores = CantidadJugadores(num_jugadores);

    }

    for (int i = 1; i <= numjugadores; i++){

        cout << "-------------------------------" << endl;
        cout << "Jugador " << i << endl;
        cout << "-------------------------------" << endl;

        cout << "Ingresar un nick name: ";
        cin >> nick;

        cout << "-------------------------------" << endl;

        InsertarUltimoPlayer(*&jugadores, nick, i);
        InsertarClases(*&jugadores);

    }

}

void CrearTablero(Casillas **casillas){ // PROCEDIMIENTO PARA CREAR EL TABLERO;

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
            region = char(220);
        }

        posicion = a;

        InsertarUltimoCasillas(*&casillas, region, posicion);
        a++;
    }
}

void MostrarTablero (Casillas* casilla){ // Procedimiento para imprimir el tablero;

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
    cout << "M - PAUSA | ENTER - LANZAR" << endl;
    cout << "-----------------------------------------------------------" << endl;

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

        if ( mover -> posicion == 2 || mover -> posicion == 3 || mover -> posicion == 4 || mover -> posicion == 5 || mover -> posicion == 6 || mover -> posicion == 7 || mover -> posicion == 8 || mover -> posicion == 9 || mover -> posicion == 10 || mover -> posicion == 11 || mover -> posicion == 12 || mover -> posicion == 13 || mover -> posicion == 14 || mover -> posicion == 15 || mover -> posicion == 16 || mover -> posicion == 17 || mover -> posicion == 22 || mover -> posicion == 23 || mover -> posicion == 24 || mover -> posicion == 25 || mover -> posicion == 26 || mover -> posicion == 27 || mover -> posicion == 28 || mover -> posicion == 29 || mover -> posicion == 30 || mover -> posicion ==31 || mover -> posicion == 32 || mover -> posicion == 33 || mover -> posicion == 34 || mover -> posicion == 35 || mover -> posicion == 36 || mover -> posicion == 37 ){
            mover -> region = "A";
        }

        else if (mover -> posicion == 0 || mover -> posicion == 20){
            dado += 1;
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

main(){

    Casillas *casillas = NULL;
    Jugadores *personajes = NULL;
    Jugadores *aux = NULL;

    string opciones, region = "0", lanzar = "";

    int posicion = 0, dado;

    bool inicio, juego = true, bol = false;

    // PANTALLA DE BIENVENIDA;

    while (inicio != true){
        inicio = PantallaInicio();     
    }  

    while (opciones != "2"){

        cout << "======================= MENU INICIO =======================" << endl;

        cout << "(1) Comenzar partida" << endl;
        cout << "(2) Salir" << endl;

        cout << "===========================================================" << endl;

        cout << "Opcion: ";
        cin >> opciones;

        if (opciones == "1"){

            CrearPersonajes(&personajes);
            InsertarClases(&personajes);
            MostrarPersonajes(personajes);

            if (ListaVaciaCasillas(casillas)){
                CrearTablero(&casillas);
                InsertarPersonajes(&casillas , &personajes, posicion);
            }

            aux = personajes;
            int max = CantidadTurno(aux);

            while (juego == true){ 
            
                MostrarTablero(casillas);

                cout << "Turno del jugador: " << aux -> nombre << endl;

                while (bol == false){

                    cout << "Presiona ENTER para tirar el dado: ";
                    cin >> lanzar;

                    if (lanzar == "M" || lanzar == "m"){

                        string submenu;

                        while (submenu != "2"){
                            cout << "========================" << endl;
                            cout << "          PAUSA         " << endl;
                            cout << "========================" << endl;
                            cout << "(1) Mostrar personaje" << endl;
                            cout << "(2) Regresar al juego" << endl;
                            cout << "========================" << endl;
                            cout << "Opcion: ";
                            cin >> submenu;

                            if (submenu == "1")
                                Mostrar1Personaje(aux, aux -> njugador);
                        
                            if (submenu == "2"){
                                break;
                            }
                        }
                    }

                    if (lanzar == "ENTER" || lanzar == "enter")
                        bol = true;
                    
                    else
                        cout << "ERROR, ingresar ENTER para lanzar el dado!" << endl;
                    
                }

                dado = Dado(bol);
                MostrarDado(dado);

                MoverJugadorUno(&aux -> Jugadores, &personajes, dado);

                if ( Turno(aux) == max)
                    aux -> proxPlayer = personajes;

                aux = aux -> proxPlayer;

                bol = false;

            }

        }

        if (opciones == "2"){
            cout << "Hasta luego my friend" << endl;
            break;
        }

        else
            cout << "ERROR, ingresar un valor valido!" << endl;
    }

    getch();

}
