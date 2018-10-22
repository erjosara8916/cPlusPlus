#include<iostream>
using namespace std;

int main(){

    unsigned limit ; // hasta que tabla se contara

    cout << "escribe hasta que tabla quieres mostrar : " ;
    cin >> limit ;


    while( cin.fail() || limit < 1 ){
        cin.clear() ;
        cin.ignore( 1000 , '\n' ) ;
        cout << "escribe hasta que tabla quieres mostrar : " ;
        cin >> limit ;
        cout << endl ;
    }

    //imprimir tablas del 1 al 10
    for ( int i = 1 ; i <= limit ; i++ ){
        system("cls") ; // borrar consola

        cout << "tabla del " << i << endl << endl; // indicar tabla impresa

        //resultados de tabla
        for ( int j = 1 ; j <= 10 ; j++ ){
            cout << i << " * " << j << " = " << i * j << endl;
        }


        system( "pause" ) ;
    }

    system("cls") ;
    cout << "\n\n  ADIOS ;) \n\n" << endl;

    system( "pause" ) ;

    return 0;
}
