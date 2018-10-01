#include "BasicOperations.h"

#include<string> // para usar el tipo de datos "string"
#include<iostream> // para usar el flujo de entrada y salida de datos

using namespace std ;

void  getInt ( string msn , int& var )
{
    // obtener un numero entero validado


        cout << msn ;
        cin >> var ;

        while ( cin.fail() ){

            cin.clear() ;
            cin.ignore( 1000 , '\n' ) ;
            cout << msn ;
            cin >> var ;
            cout << endl;

        }
}

void getString ( string msn , istream& ent , string& var )
{
    cout << msn ;
    ent >> ws ;
    getline( ent , var );
}

void mostrarMensaje( string mensaje ) {
    system("cls") ;

    cout << "\n----------------------------------------------------------------------------------------------\n" << endl;
    cout << mensaje << endl;
    cout << "\n----------------------------------------------------------------------------------------------\n" << endl;
    system("pause") ;
}
