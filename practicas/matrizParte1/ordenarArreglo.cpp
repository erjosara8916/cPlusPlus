/****************************************************************

    Autor : Erick Josue Saravia Aragon

    N° Carnet : SA18004

    Fecha : 02-10-2018

    Descripcion : ordenar los elementos de un arreglo

*****************************************************************/
#include<iostream> // para usar "cout" y "cin"
#include<conio.h>
#include<time.h>

#define SIZE 10

using namespace std;

int main(){

    cout << "array values : 132, 520, 210, 510, 140, 125, 52, 96, 55, 85 \n" << endl;

    int array[SIZE] = { 135 , 520 , 210 , 510 , 140 , 125 , 52 , 96 , 55 , 85 } ;

    cout << "sorted values : " << endl;

    int numero = 0 ;
    srand(time(NULL)) ;
    int array[SIZE] ;
    //llenar arreglo
    for ( int i = 0 ; i < SIZE ; i++ ){

        numero = rand() / 100 % 10 + 1 ;
        array[i] = numero ;
        cout << numero << endl;

    }

    //ordenar los valores del arreglo
    for ( int startIndex = 0 ; startIndex < SIZE ; startIndex++ ){

        int smallestIndex = startIndex ;

        //nowIndex
        for ( int nowIndex = startIndex + 1 ; nowIndex < SIZE ; nowIndex++ ){

            if ( array[nowIndex] < array[smallestIndex] ) {
                smallestIndex = nowIndex ;
            }

        }

        swap( array[startIndex] , array[] ) ;

    }

    //mostrar el arreglo
    for ( int i = 0 ; i < SIZE ; i++ ){

        cout << array[i] << ", " ;

    }

    return 0;
}
