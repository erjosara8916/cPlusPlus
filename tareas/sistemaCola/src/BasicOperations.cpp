#include "BasicOperations.h"

#include<string> // para usar el tipo de datos "string"
#include<iostream> // para usar el flujo de entrada y salida de datos

using namespace std ; /// para poder usar el espacio de nombres std

/**
    pedir el ingreso de un numero entero que se ingrese un dato invalido
    volvera a pedirlo hasta que este sea valido y lo guarda en la variable
*/
void  getInt ( string msn , int& var )
{
    cout << msn ;  // imprime mensaje para indicar que representara el dato
    cin >> var ;   // pide el dato

    while ( cin.fail() ){ // mientras que el dato sea erroneo

        cin.clear() ;  /// borra el contenido del buffer de entrada
        /// ignora 1000 caracteres o hasta encontrar un salto de lines
        cin.ignore( 1000 , '\n' ) ;

        /// volver a pedir el dato
        cout << msn ;
        cin >> var ;

    }

}

/**
    muestra un mensaje en pantalla de una forma resaltada
*/
void mostrarMensaje( string mensaje , bool pause ) {
    system("cls") ;

    cout << "\n------------------------------------------------------------------------\n" << endl;
    cout << mensaje << endl;
    cout << "\n-------------------------------------------------------------------------\n" << endl;

    /// si se quiere que se pause la consola al mostrar el mensaje
    if ( pause )  {

        system("pause") ;

    }
}
