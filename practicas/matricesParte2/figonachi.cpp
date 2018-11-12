/****************************************************************

    Autor : Erick Saravia

    N° Carnet : SA18004

    Fecha : 02-10-2018

    Descripcion :

*****************************************************************/
#include<iostream> // para usar "cout" y "cin"
#include<conio.h>

using namespace std;

int main(){

    int fil , col ;

    int matriz[ 30 ][ 30 ] ;

    cout << "ingrese el numero de filas : " ; cin >> fil ;
    while( cin.fail() ){
        cin.clear() ;
        cin.ignore( 1000 , '\n' );
        cout << "El valor no es correcto vuelve a ingresarlo: " ;
        cin >> fil ;
        cout << endl ;
    }
    cout << "ingrese el numero de columnas : "; cin >> col ;
    while( cin.fail() ){
        cin.clear() ;
        cin.ignore( 1000 , '\n' );
        cout << "El valor no es correcto vuelve a ingresarlo: " ;
        cin >> col ;
        cout << endl ;
    }

    //recorrer el filas
    for ( int i = 0 ; i < fil  ; i++ ){

        //recorrer columnas
        for ( int j = 0 ; j < col ; j++ ){

            system("cls") ;
             cout << "ingrese el dato [ " << i << " ] [ " << j << " ] : " ;
             cin >> matriz[ i ][  j ] ;
             while( cin.fail() ){
                 cin.clear() ;
                 cin.ignore( 1000 , '\n' );
                 cout << "El valor no es correcto vuelve a ingresarlo: " ;
                 cin >> matriz[ i ][  j ] ;
                 cout << endl ;
             }

        }

    }

    //mostrar el arreglo
    for ( int i = 0 ; i < fil ; i++ ){

        //mostrar columna
        for ( int j = 0 ; j < col ; j++ ){

            cout << " " << matriz[ i ][ j ] << " ";

        }

        cout << " " << endl;
    }

    system("pause")
    return 0;
}
