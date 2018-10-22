
#include<iostream> // poder usar "cin" y "cout"

using namespace std;

int factorial ( int num ) {

}

int main(){

    int num;
    int factorial = 1 ;
    cout << "ingresa un numero : " ;
    cin >> num ;
    while( cin.fail() || num < 1 ){
        cin.clear() ;
        cin.ignore( 1000 , '\n' ) ;
        cout << "ingresa un numero : " ;
        cin >> num ;
        cout << endl ;
    }

    system("cls") ;

    //calcular factorial
    for ( int i = 1 ; i <= num ; i++ ){
        factorial *= i ;
    }

    cout << "el factorial de " << num << " es  : " << factorial << endl;
    system("pause");
    return 0;
}
