#ifndef BASICOPERATIOS_H
#define BASICOPERATIOS_H

#include<string> // para poder usar el tipo de datos "string"
#include<array> // para poder crear arreglos y usar el metodo size()


using namespace std ;


void getInt( string , int& ) ; // obtener la entrada de un entero validado
void getString ( string , istream& , string& ) ; // obtener la entrada de un string validado
void msn( string , bool  = true) ; // mostrar un mensaje en pantalla
#endif // BASICOPERATIOS_H

