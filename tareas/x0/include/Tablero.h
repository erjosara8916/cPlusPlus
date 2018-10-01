#ifndef TABLERO_H
#define TABLERO_H

#include<Casilla.h>

#include<array> // para crear arreglos y acceder a su propiedad

// definir un tipo de dato que sera igual a una arreglo con 3 objetos de tipo Casilla
typedef array< Casilla , 3 > columnas ;


/*
    tablero sobre el cual se desarrolla el juego
*/
class Tablero
{
    public:

        Tablero() ; // constructor de la clase
     //   void setCasilla( int , string ) ; // cambiar el valor de una casilla
        void setInterfaz() ; // crear la interfaz grafica de el tablero
        void mostrarTablero() ; // mostrar la interfaz grafica de el tablero
        array< columnas , 3 > filas ; // arreglo que supone una tabla de 3 x 3 donde se almacenaran los datos del juego


    private:

        string interfaz ; // contiene el tablero de una forma amigable para el usuario
        void crearFilas() ; // crea las filas del tablero
        void crearInterfaz() ;
};

#endif // TABLERO_H
