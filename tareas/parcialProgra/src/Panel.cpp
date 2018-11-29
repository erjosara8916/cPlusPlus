#include "Panel.h"
#include "OperacionesBasicas.h"
#include "TorreHanoi.h"

Panel::Panel()
{
    menu = {
        "Torres de Hanoi",
        "Metodo de la burbuja",
        "Salir"
    } ;
    juego = TorreHanoi () ;
    burbuja = MetodoBurbuja () ;
    showMenu() ;
}

/// mostrar el menu de opciones al usuario

void Panel :: showMenu ()
{
    system( "color 0f" ) ;
    // Indicacion del menu
    cout << "Que quieres hacer? \n \n" ;

    // mostrar el menu al usuario
    for ( int i = 0 ; i < menu.size() ; i++ ) {
        cout << i + 1 << ". " << menu[i] << "\n" ;
    }

    // pedir la respuesta del usuario
    do{
        getInt( "\n Escoge una de la opciones " , answerUser ) ;
    } while ( answerUser < 1 || answerUser > menu.size() ) ;

    // Verificar que opcion escogi el usuario
    switch( answerUser ) {
        case 1 :
            juego.jugar () ; /// iniciar juego de torres de hanoi
            showMenu () ; /// mostrar menu
            break ;
        case 2 :
            burbuja.llenarNumeros() ; /// generar serie aleatoria de numeros
            burbuja.mostrar() ; /// mostrar la serie original y la version ordenada
            showMenu () ;/// mostrar menu
            break ;
        case 3 :
            salir() ;
            break ;
    }
}

/**  */
void Panel :: salir ()
{
    msn ("                               Adios ;) ") ;
}
