#include "Jugador.h" // prototipo de la clase jugador
#include<iostream> // poder trabajar con el flujo de entrada y salida
#include<string> // para datos de tipo "string"
#include"BasicOperations.h" // para poder abreviar el uso de operaciones comunes



using namespace std ;

Jugador::Jugador( string ctr ) // constructor
{
    caracter = ctr ;  // definir el caracter que utilizara el usuario
}

// definir como se llamara al jugador en el juego


string Jugador :: getCaracter ( )  // obtener el caracter que el usuario puede uutilizar
{
    return caracter ;
}

void Jugador :: setEtiqueta ( string msn )  // colocar un identificador para el jugador
{
    /*
        pedir al usuario los nombre de los jugadores y guardarlos en la propiedad etiqueta

    */
    getString( msn , cin , etiqueta ) ;
}

string Jugador :: getEtiqueta (  )  // obtener el identificador del jugador
{
    return etiqueta ;
}
