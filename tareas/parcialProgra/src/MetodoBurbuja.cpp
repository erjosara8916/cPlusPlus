#include "MetodoBurbuja.h"
#include<stdlib.h>
#include<time.h>
#include<OperacionesBasicas.h>

MetodoBurbuja :: MetodoBurbuja() { }

/** llenar arreglo de numeros */
void MetodoBurbuja :: llenarNumeros ()
{
    /// iniciar los numeros aleatorios
    srand ( time ( NULL ) ) ;


    //dar valores aleatorios a los elementos del arreglo
    for ( int i = 0 ; i < 100 ; i++ ){
        numeros[i] = rand() % 200 ;
    }
}

/** ordenar la serie de numeros a traves del metodo de la burbuja  */
void MetodoBurbuja :: ordenarNumeros ()
{

    for ( int i = 0 ; i <= numeros.size()  ; i++ ){

         for ( int j = i+ 1 ; j <= numeros.size()  ; j++ ){
            //  ordenar
            if ( numeros[j] < numeros[i]  ){
               temp = numeros[j] ;
               numeros[j] = numeros[i];
               numeros[i] = temp ;
            }
         }
    }
}

/** Mostrar la serie de numeros */
void MetodoBurbuja :: mostrar ()
{
    msn("SERIE DE NUMEROS ORIGINAL") ;

    //mostrar la serie de numeros ordenada
    for ( int i = 0 ; i < numeros.size() ; i++ ){
        cout << "Elemento " << i + 1 << " : " << numeros[i] << endl ;
    }
    system("pause");

    msn("SERIE DE NUMEROS ORDENADA") ;

    ordenarNumeros() ; /// ordenar la serie de numeros

    for ( int i = 0 ; i < numeros.size() ; i++ ){
        cout << "Elemento " << i + 1 << " : " << numeros[i] << endl ;
    }
    system("pause") ;
    system("cls");

}
