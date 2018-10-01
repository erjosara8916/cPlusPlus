#ifndef JUGADOR_H
#define JUGADOR_H

#include<string> // para datos de tipo "string"

using namespace std ;

class Jugador
{
    private:
        string etiqueta ; // identificador del jugador
        string caracter ; // caracter que el usuario podra colocar en el tablero
    public:
        Jugador( string ) ; // constructor ( caracter que podra colocar en el tablero )
        void setEtiqueta ( string ) ; // colocar como se le llamara el jugador en el juego
        string getEtiqueta () ; // obtener el valor del identificador
        string getCaracter() ;  // obtener el valor del caracter que el jugador puede ingresar



};

#endif // JUGADOR_H
