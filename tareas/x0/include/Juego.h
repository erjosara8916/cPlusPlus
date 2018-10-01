#ifndef JUEGO_H
#define JUEGO_H

#include<Jugador.h> // para manejar a los jugadores
#include<array> // para crear tipos de usuario
#include<Tablero.h> // para poder crear un tablero sobre el cual se jugara

using namespace std ;

class Juego
{
    private:
        // participantes del juego
        array< Jugador , 2 > jugadores = { {
           Jugador( " x " ) , Jugador( " 0 " )
        } } ;

        Tablero tab = Tablero() ; // crear el tablero sobre el que jugara
        string descripcion ; // descripcion del juego
        string instrucciones ; // instrucciones del juego
        string tabMuestra ; // ejemplo que muestra el numero de las casillas del tablero a utilizar
        int tJugador = 0 ;  // a que jugador le corresponde la jugada
        int answerUser ; // respuesta del usuario a los menus
        int nMovimientos ; // numero de movimientos validos
        bool hayGanador = false ; // si algun jugador ya gano el juego

        int ganador ; // pocision del arreglo "jugadores" perteneciente al ganador del juego

    public:
        Juego() ; // constructor
        void generarIndicaciones ( ) ; // crear la cadena de texto que contendra la descripcion del juego
        void crearMuestra (  ) ; // crear tablero de muestra con el numero que identifica a cada casilla
        bool casillaValida ( int ) ; // verificar si en la casilla se puede ingresar un valor ( si su valor actual es igual a 3 espacios )
        bool tresEnFila  () ; // verificar si ya hay tres "x" o "0" iguales en la misma fila ( alguien ya gano )
        bool tresEnColumna () ; // verificar si ya hay tres "x" o "0" iguales en la misma columna ( alguien ya gano )
        bool tresEnDiagonal () ; // verificar si ya hay tres "x" o "0" iguales una diagonal ( alguien ya gano )
        int contarEspaciosLibres () ; // verificar si el jugo sigue o ya no hay espacios donde colocar
        void jugar ( ) ; // iniciar el juego
        void pedirJugada () ;
        void colocarCaracter () ;
        void showMenu () ; // mostrar menu al final del juego
        void mostrarCasillas ( ) ; // muestra en patalla las casillas disponibles
        void reset () ; // resetear valores paravolver a jugar



};

#endif // JUEGO_H
