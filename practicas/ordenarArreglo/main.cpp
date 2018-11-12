#include <iostream>

using namespace std;

int main()
{
    /****************************************************************
    Autor : Erick Josue Saravia Aragon
    N° Carnet : SA18004
    Fecha : 2018-11-06
    Descripcion : ordenar los elementos de un arreglo
*****************************************************************/

#include<iostream> // para usar "cout" y "cin"

using namespace std;


    int vector[5] ;
    int i , j , temp ;

    //llenando el vector
    for ( int i = 0 ; i <= 4 ; i++ ){
        cout << i + 1 << " : " << endl;
        cin >> vector[i] ;
        cout << "\n" << endl;
    }

    //mostrar el arreglo
    for ( int i = 0 ; i <= 4 ; i++ ){
        cout <<"original : " << vector[i] << " " << endl;
    }

    //metodo de la burbuja
    for ( int i = 0 ; i <= 4  ; i++ ){

         for ( int j = i+ 1 ; j <= 4  ; j++ ){
            //  ordenar
            if ( vector[j] < vector[i]  ){
               temp = vector[j] ;
               vector[j] = vector[i];
               vector[i] = temp ;
            }
         }
    }

    //mostrar el arreglo
    for ( int i = 0 ; i <= 4 ; i++ ){
        cout <<"arreglado : " << vector[i] << " " << endl;
    }
    system("pause") ;
    return 0;

}
