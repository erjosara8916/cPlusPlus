#ifndef CASILLA_H
#define CASILLA_H

#include<string> // para poder usar el tipo de datos "string"


using namespace std ; // usar el espacio de nombres std

/*
    Casilla que representa un espacio que contendra una "x" o un "0"
*/

class Casilla
{
    public:
        Casilla ( ) ; // constructor
        int getId ( ) ; // obtener el identificador de la casilla
        void setId( int ) ; // colocar un identificador a la casilla
        void setValor (  string ) ;  // colocar un valor a la casilla
        string getValor () ;  // obtener el valor de la casilla


    private:
        int id ; // numero que identifique a una unica casilla
        string valor ; // valor contenido dentro de la casilla

};

#endif // CASILLA_H
