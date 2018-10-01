/* importaciones */
// librerias propias de c++
#include<string> // para usar el tipo de datos "string"
#include<iostream> // para usar el flujo de entrada y salida de datos

// librerias creadas
#include "Casilla.h" // importar la clase casilla



using namespace std ;

// constructor de Casilla
Casilla::Casilla( )
{
    valor = "   "; // dar valor inicial a la casilla
}

void Casilla :: setId ( int identificador ) // colocar  identificador a la casilla
{
    id = identificador ; // dar valor al identificador
}

int Casilla :: getId (  ) // obterner el identificador de la casilla
{
    return id ;
}

void Casilla :: setValor ( string s ) // cambiar el valor de la casilla
{
    valor = s ; // definir nuevo valor

}

string Casilla :: getValor (  )  // obtener el valor contenido en la casilla
{
    return valor ;
}
