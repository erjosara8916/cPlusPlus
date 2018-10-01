#include "Tablero.h"
#include<Casilla.h> // para crear objetos de tipo casilla

#include<iostream> // usar el flujo de entrada y salida

using namespace std ;

Tablero::Tablero()  // constructor
{
   crearFilas() ; // crear una tabla con nueve casillas
}



// crear las filas que formaran el tablero del juego
void Tablero :: crearFilas ()
{
   //crear las filas del tablero del juego
    for ( int i = 0 ; i < filas.size() ; i++ ){ // recorrer filas

        //crear las columnas del tablero
        for ( int j = 0 ; j < filas[i].size() ; j++ ){ // recorrer las pocisiones para las casillas de la fila
            filas[i][j] = Casilla() ; // crear una nueva casilla en la posicion reservada
            filas[i][j].setId( i * 3 + j ) ; // colocar el identificador a la casilla correspondiente a su posicion
        }

    }
}

// crear ( modificar si ya existe ) la interfaz grafica del juego
void Tablero :: crearInterfaz ()
{

    interfaz = "\n" ; // para que no este pegada al borde superior de la ventana

    //llenarla interfaz grafica con los datos del tablero
    for ( int i = 0 ; i < filas.size() ; i++ ){  // recorrer las filas

        interfaz += "                 "; // centrar el contenido en la consola

        //colocar los valores de las columnas
        for ( int j = 0 ; j < filas[i].size() ; j++ ){ // recorrer las casillas de la fila

            interfaz += string(filas[i][j].getValor()) ; // concatenar el valor de la casilla

            if ( j < filas[i].size() - 1 ) {    // para que no se coloque en la ultima columna

                interfaz +=  "|" ; // separador entre los valores de las casillas en la misma columna

            } else if( i != filas[i].size() - 1 ) { // para que no se coloque en la ultima fila

                interfaz += "\n                -------------\n" ; // separador de las filas

            }

        }


    }

    interfaz += "\n" ; // salto de linea para lo que lo proximo que se imprima sea en una nueva linea

}

// mostrar tablero en pantalla
void Tablero :: mostrarTablero() {
    crearInterfaz () ; // crea la cadena de texto que contendra el tablero a imprimir
    system("cls") ; // borra el contenido de la cosnsola
    cout << interfaz ; // imprime el tablero en la pantalla
}
