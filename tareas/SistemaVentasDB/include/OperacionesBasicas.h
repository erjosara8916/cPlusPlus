#ifndef OPERACIONESBASICAS_H
#define OPERACIONESBASICAS_H

#include<string> // para poder usar el tipo de datos "string"


using namespace std ;


void getInt( string , int& ) ; // obtener la entrada de un entero validado
void getFloat( string , float& ) ; // obtener un dato decimal validado
void getString ( string , istream& , string& ) ; // obtener la entrada de un string validado
void msn( string , bool  = true) ; // mostrar un mensaje en pantal
void getString() ; // obtener una cadena de texto 
#endif
