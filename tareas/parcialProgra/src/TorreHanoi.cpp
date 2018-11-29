#include "TorreHanoi.h"
#include "OperacionesBasicas.h"

/// constructor ( asignar valores por defecto )
TorreHanoi :: TorreHanoi()
{
    cr = '±' ;
    fondo = 177 ;
    con = 0 ; /// numero de turnos
}

/**  */

void TorreHanoi :: linea ( int j )
{

    for ( int i = 0 ; i  < j ; i++ ){
        cout << cr ;
    }
    cout << endl ;
}



/** Llevar a cabo el juego  */
void TorreHanoi :: jugar ()
{
    /// pedir con cuantos discos se jugara
    system( "cls" ) ;
    cout << "Las Torres de Hanoi\n" << endl << endl ;
    getInt( "Digita la cantidad de discos " , n ) ;

    /// validar el dato
    while( n > 13 || n < 3 )
    {
        system( "cls" ) ;
        cout << "Tiene que jugar minimo con tres discos y maximo con 13" << endl ;
        getInt( "Digita la cantidad de discos " , n ) ;
    }

    system("cls");

    tam = n + ( n - 1 ) ;

    /// colocar fondo
    for( i = 1 ; i <= ( ( tam * 3 ) + 3 ) + 1 ; i++ ) {
        cout << fondo ;
    }

    cout << endl << fondo ;
    for( i = 0 ; i < n ; i++ )
    {
        for( j = 0 ; j < 3 ; j++ )
        {
              if( j == 0 )
                  matriz[i][j] = i + 1 ;
              else
                  matriz[i][j] = 0;
              for( k = 1 ; k <= tam ; k++ )
              {
                   tamDisco = matriz[i][j] + ( matriz[i][j] - 1 ) ;
                   espacios = ( tam - tamDisco ) / 2 ;
                   if( matriz[i][j] == 0 )
                       cout << fondo ;
                   else
                   {
                       if( k <= espacios || k > ( tam - espacios ) )
                           cout << fondo ;
                       else
                           cout << "*" ;
                   }
              }
              cout << fondo;
        }
        cout << endl << fondo;
    }
    for( i = 1 ; i <= ( ( tam * 3 ) ) ; i++ )
    {
        if( i == n - 1 )
            cout << "T1" ;
        else if( i == ( ( n * 2 ) + n ) - 2 )
            cout << "T2" ;
        else if( i == ( ( ( n * 2 ) + n ) - 3 ) + n * 2 )
            cout << "T3" ;
        else
            cout << fondo;
    }
    cout << endl ;
    for( i = 1 ; i <= ( ( tam * 3 ) + 4 ) ; i++ )
        cout << fondo ;
    moverDisco ( ) ;
}

/** mover disco en el tablero */
void TorreHanoi :: moverDisco ()
{
    while( matriz[0][1] != 1 && matriz[0][2] != 1 )
    {
        cout<<"\n\n\t\t\tLleva " << con++ << " movimientos\n" ;
    do{
        do{ /// perdir movimiento validado

            getInt ( "Desde cual torre (T) desea mover el disco: " , desde ) ;

        } while ( desde < 1 || desde > 3 ) ;  ///

        if( matriz[ n - 1 ][ desde - 1 ] == 0 ){
            cout << "No hay disco en esa torre" << endl;
        }
    }
    while( matriz[ n - 1 ][ desde - 1 ] == 0 ) ;
    do{
        getInt ( "Hacia cual torre (T) desea mover el disco: " , hacia ) ;
    } while ( hacia < 1 || hacia > 3 ) ;

    desde--;
    hacia--;

    for( i = 0 ; i < n ; i++)
    {
        if( matriz[i][desde] != 0 )
        {
            tem = matriz[i][desde] ;
            tem2 = i ;
            i = n ;
        }
    }

    for( i = n - 1 ; i >= 0 ; i-- )
    {
        if( matriz[i][hacia] == 0 )
        {
            /// validar que el disco se puede ubicar en el espacio que el usuario quiera
            if( matriz[ i + 1 ][ hacia ] > tem || i == ( n - 1 ))
            {
                matriz[i][hacia] = tem ;
                matriz[tem2][desde] = 0 ;
            }
            else
            {
                cout << "\n\nNo puede colocar un disco grande encima de uno pequeno\n" ;
                cout << "ni poner un disco en la misma posicion" << endl ;
                cout <<"Cambie los parametros"<<endl;
                con-- ;

                moverDisco() ; /// pedir otro movimiento

            }

            i = 0 ;
        }
    }

    system("cls") ;
    /// pintar el fondo
    for( i = 1 ; i <= ( ( tam * 3 ) + 3 ) + 1 ; i++ )  {
       cout << fondo ;
    }

    cout << endl << fondo ;

    /// pintar el cambio ( si es valido )s
    for( i = 0 ; i < n ; i++ )
    {
        for( j = 0 ; j < 3 ; j++ )
        {
              for( k = 1 ; k <= tam ; k++ )
              {
                   tamDisco = matriz[i][j] + ( matriz[i][j] - 1 ) ;
                   espacios = ( tam - tamDisco ) / 2 ;
                   if( matriz[i][j] == 0 )
                    {
                        cout << fondo;
                    }
                   else
                   {
                       if( k <= espacios || k > ( tam - espacios ) )
                           cout << fondo ;
                       else
                           cout << "*" ;
                   }
              }
              cout << fondo ;
        }
        cout << endl << fondo ;
    }

    /// pintar los pie de las torres
    for( i = 1 ; i <= ( ( tam * 3 ) ) ; i++ )
    {
        if( i == n - 1 )
            cout << "T1" ;
        else if( i == ( ( n * 2 ) + n ) - 2 )
            cout << "T2" ;
        else if( i == ( ( ( n * 2 ) + n ) - 3 ) + n * 2 )
            cout << "T3" ;
        else
            cout << fondo ;
    }

    cout << endl ;
    /// colocar fondo
    for( i = 1 ; i <= ( ( tam * 3 ) + 4 ) ; i++ )
        cout << fondo ;
    }

    system( "color f1" ) ; /// cambiar color a la consola

    ///mostrar despedida
    msn( "Felicidades has ganado en " + to_string(con) + " turnos " ) ;
    system("cls");

}
