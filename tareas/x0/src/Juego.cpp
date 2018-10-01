#include "Juego.h"
#include<iostream> // para trabajar con el flujo de entrada y salida de datos
#include<string> // para poder utilizar el tipo de datos string
#include<array> // para trabajar con arreglos y poder usar en metodo size() sobre ellos
#include<windows.h> // para poder usar los comandos de la consola
#include"Jugador.h"
#include"BasicOperations.h" // poder usar operaciones habituales

using namespace std ;

Juego::Juego ( )
{
    PlaySound( "sonidos/SD_ALERT_9.wav" , NULL , SND_ASYNC ) ;
    generarIndicaciones () ; // genera las cadenas de texto que se mostraran al inicio

    mostrarMensaje ( descripcion ) ; // muestra en pantalla la descripcion del juego
    PlaySound( "sonidos/SD_ALERT_21.wav" , NULL , SND_ASYNC ) ;
    mostrarMensaje ( instrucciones ) ; // muestra en pantalla las instrucciones del juego
    PlaySound( "sonidos/SD_ALERT_21.wav" , NULL , SND_ASYNC ) ;
    mostrarMensaje ( tabMuestra ) ;  // muestra en pantalla el tablero con las casillas numeradas

    /**
        pedir los nombres de las personas que jugaran
    */
    PlaySound( "sonidos/SD_ALERT_21.wav" , NULL , SND_ASYNC ) ;
    system( "cls" ) ;  // borrar pantalla
    jugadores[0].setEtiqueta ( " Escribe un nombre para el primer jugador : " ) ;
    PlaySound( "sonidos/SD_ALERT_21.wav" , NULL , SND_ASYNC ) ;
    system( "cls" ) ;
    jugadores[1].setEtiqueta ( " Escribe un nombre para el segundo jugador : " ) ;

    /// iniciar la cancion del juego
    PlaySound( "sonidos/super_mario_world_yoshis_island_sms.wav" , NULL , SND_LOOP|SND_ASYNC ) ;
    /**
        comenzar el juego
    */
    jugar () ;
}

// generar la informacion a mostrar en la pantalla al inicio
void Juego :: generarIndicaciones ()
{
    /**
        generar las cadenas que se mostraran en pantalla ( cadenas informativas )
    */
    descripcion = "\n DESCIPCION : \n\n" ;
    descripcion += " El juego se realizara por turnos en los que cada jugador podra colocar \n" ;
    descripcion += " el carater que le corresponde ( una \"x\" o un \"0\" ) con el objetivo de \n" ;
    descripcion += " colocar tres caracteres alineados en fila, columna o diagonal, siendo el ganador \n" ;
    descripcion += " quien realize esta tarea primero. \n" ;

    instrucciones = "\n INSTRUCCIONES : \n\n" ;
    instrucciones += " 1. Cada jugador debe registrar el nombre con el que se le conocera dentro del juego\n" ;
    instrucciones += " 2. En su turno cada jugador debe escribir el numero de casilla en la que colocara su caracter \n" ;
    instrucciones += "    debiendo esta estar vacia \n" ;
    instrucciones += " 3. Si al llenar las 9 casillas no se puede definir un ganador, se declara un empate. <\n" ;
    instrucciones += " 4. Al iniciar un segundo juego, el perdedor del anterior tendra el primer turno. " ;

    crearMuestra () ; // crear el tablero numerado

}

// crear tablero de ejemplo para el usuario
void Juego :: crearMuestra ()
{
    tabMuestra = "\n Numeracion de las columnas: \n" ;
    tabMuestra += "\n" ;

    //llenarla tabMuestra grafica con los datos del tablero
    for ( int i = 0 ; i < 3 ; i++ ){ // filas

        tabMuestra += "                 ";  // centrar el contenido

        //colocar los valores de las columnas
        for ( int j = 0 ; j < 3 ; j++ ){

            tabMuestra += " " ; // un espacio
            tabMuestra += 48 + ( i * 3  + j + 1 ) ;   // generar el codigo ASCII del numero que definira la casilla
            tabMuestra += " " ; //  un espacio

            if ( j < 2 ) { // que no se genere en la ultima repeticion del ciclo

                tabMuestra +=  "|" ;  // separador

            } else if( i != 2 ) { // que no se genere en la ultima repeticion del primer ciclo

                tabMuestra += "\n                -------------\n" ;

            }

        }


    }

    tabMuestra += "\n " ;

}

/**
    comienza las operaciones del juego
*/
void Juego :: jugar ()
{

    string msn ; // contendra los mensajes que se enviaran en el juego
    system("cls"); // borra la pantalla




    int espaciosLibres = contarEspaciosLibres() ; // verifica cuantas casillas se pueden utilizar

    if ( ! hayGanador && espaciosLibres > 0 ) {  // si aun no hay ganador mostrar a quien le corresponde el turno
        system("color 03") ;
        // generar mensage
        msn = "                                  Turno de " + jugadores[tJugador].getEtiqueta() ;
        mostrarMensaje( msn ) ;

    }

    tab.mostrarTablero() ; // muestra el tablero con los datos actuales

    if ( espaciosLibres > 0 && ! hayGanador )    // si hay casillas disponibles y todavia ningun jugador a ganado el juego
    {

        cout << " En que casilla colocaras tu caracter?" << endl;

        mostrarCasillas() ; // mostrar en pantalla las casillas disponibles
        pedirJugada() ; // pidir donde colocara el jugador su caracter ( la casilla )
        colocarCaracter ( ) ; // colocar caracter en la casilla
        ( tJugador == 0 ) ? tJugador = 1 : tJugador = 0 ; // pasar el turno al siguiente jugador
        hayGanador = tresEnFila() || tresEnColumna() || tresEnDiagonal() ;  // verificar si ya hay un ganador del juego

        if ( hayGanador )   {

            tab.mostrarTablero() ; // mostrar el tablero
            system("pause") ;  // esperar a que el usuario lo vea

        }

        jugar() ; // seguir jugando

    } else{  // se acabaron los espacios o ya hay ganador

        PlaySound( "sonidos/SD_ALERT_8.wav" , NULL , SND_ASYNC ) ;
        ( tJugador == 0 ) ? tJugador = 1 : tJugador = 0 ; // definir ganador

        // dar resultados
        if ( hayGanador ) { // hay ganador
            system("color 03") ;
            msn = "El ganador es : " + jugadores[tJugador].getEtiqueta() ; // crear el mensaje
            mostrarMensaje( msn ) ; // imprimir el mensaje

        } else { // hubo un empate
            system("color fc") ;
            mostrarMensaje( "la partida termino en empate" ) ; // imprimir el resultado

        }

        showMenu() ; // mostrar menu
    }
}

/**
  mostrar las casillas en las que todavia se puede jugar
*/
void Juego :: mostrarCasillas ( )
{

    //mostrar las casillas que se encuentran vacias
    for ( int i = 0 ; i < tab.filas.size() ; i++ ){ // recorrer todas las filas

        //recorrer las columnas de las filas
        for ( int j = 0 ; j < tab.filas[i].size() ; j++ ){ // recorrer casillas

            if ( tab.filas[i][j].getValor() == "   " ){ // si el valor de la casilla es 3 espacios ( esta disponible

                cout << "  " << tab.filas[i][j].getId() + 1 << endl; // mostrar en la casilla en el menu

            }
        }
    }

}

/**
   pedir al jugador donde colocara su caracter ( en caso de ser una casilla no valida
   se le solicitara el dato hasta que este sea valido )
*/
void Juego :: pedirJugada ()
{

    /**
        accion del jugador
    */
    do{
        getInt( " Escribe el numero de una casilla : " , answerUser ) ; // pedir el numero de la casilla en que jugara
    } while (
                ( answerUser < 1 || answerUser > 9 ) || // asegurar que el numero no corresponda a una casilla invalida
                ! casillaValida( answerUser ) // asegurar que la casilla seleccionada este vacia
    ) ;

}

/**
    colocar el caracter del jugador en turno en la casilla seleccionada
*/
void Juego :: colocarCaracter ()
{

    // buscar la casilla sobre la que se escribira el caracter
    for ( int i = 0 ; i < tab.filas.size() ; i++ ){

    //recorrer las columnas de las filas
        for ( int j = 0 ; j < tab.filas[i].size() ; j++ ){ // buscar la casilla que el jugador selecciono

            if ( tab.filas[i][j].getId() == answerUser - 1 ){ // si se encontro
                   tab.filas[i][j].setValor( jugadores[tJugador].getCaracter() ) ; // colocar en la casilla el caracter del jugador

            }
        }
    }

}

// contar si hay espacios donde colocar mas caracteres
int Juego :: contarEspaciosLibres ()
{
    int espaciosLibres = 0 ; // cantidad de espacios donde colocar inicial 0

    //recorrer todas las filas del tablero
    for ( int i = 0 ; i < tab.filas.size() ; i++ ){

        //recorrer las columnas de las filas
        for ( int j = 0 ; j < tab.filas[i].size() ; j++ ){

            if ( tab.filas[i][j].getValor() == "   " ){  // si se encontro un espacio donde colocar

                espaciosLibres++ ; // sumar 1 la cantidad de espacios disponibles

            }

        }

    }
    return espaciosLibres ; // retornar la el calculo de espacios
}

/**
    verificar si en una casilla esta vacia ( su valor es 3 espacios )
*/
bool Juego :: casillaValida ( int casilla ) // se debe indicar el identificador de la casilla
{
    bool vacio = false ; // por defecto se asume que si

    // recorrer las casillas en busqueda de la indicada
    for ( int i = 0 ; i < tab.filas.size() ; i++ ){

        //recorrer las columnas de las filas
        for ( int j = 0 ; j < tab.filas[i].size() ; j++ ){

            if ( tab.filas[i][j].getId() == casilla - 1 ){ // si se encontro la casilla

              //  cout << tab.filas[i][j].getId() << endl ;
                if ( tab.filas[i][j].getValor() == "   " ){ // si esta vacia
                    vacio = true ;  // confirmar que esta vacia
                }

            }
        }
    }
    return vacio ; // retornar la verificacion
}


/**
    verificar si hay tres caracteres ( no vacios ) en fila
*/
bool Juego :: tresEnFila()
{
    bool correcto = false; // se asume que no es correcto lo que se quiere comprobar

    //recorrer las filas
    for ( int i = 0 ; i < 3 ; i++ ){
        if (((// si la primera casilla tiene un caracter distinto de espacios

            tab.filas[i][0].getValor() == jugadores[0].getCaracter() ||
            tab.filas[i][0].getValor() == jugadores[1].getCaracter()

        ) || ( // si la segunsa casilla tiene un caracter distinto de espacios

            tab.filas[i][1].getValor() == jugadores[0].getCaracter() ||
            tab.filas[i][1].getValor() == jugadores[1].getCaracter()

        ) || ( // si la tercera casilla tiene un caracter distinto de espacios

            tab.filas[i][2].getValor() == jugadores[0].getCaracter() ||
            tab.filas[i][2].getValor() == jugadores[1].getCaracter()

        )) && ( // si toda la fila tiene el mismo valor

             tab.filas[i][0].getValor() == tab.filas[i][1].getValor() &&
             tab.filas[i][0].getValor() == tab.filas[i][2].getValor()

        ) ) {
            correcto = true ; // se comprueba que si hay un ganador ( cumplio el objetivo del juego )
        }
    }

    return correcto ; // retornar resultado de la verificacion
}

/**
    saber si se an colocado tres caracteres igualen en una acolumna
*/
bool Juego :: tresEnColumna()
{
    bool correcto = false; // se asume que no es correcto lo que se quiere comprobas

    //recorrer las columnas del tablero
    for ( int i = 0 ; i < 3 ; i++ ){
        if ((( // si la primera casilla tiene un caracter distinto de espacios

            tab.filas[0][i].getValor() == jugadores[0].getCaracter() ||
            tab.filas[0][i].getValor() == jugadores[1].getCaracter()

        ) || ( // si la segunda casilla tiene un caracter distinto de espacios

            tab.filas[1][i].getValor() == jugadores[0].getCaracter() ||
            tab.filas[1][i].getValor() == jugadores[1].getCaracter()

        ) || ( // si la tercera casilla tiene un caracter distinto de espacios

            tab.filas[2][i].getValor() == jugadores[0].getCaracter() ||
            tab.filas[2][i].getValor() == jugadores[1].getCaracter()

        )) && (// si toda la columna tiene el mismo valor

             tab.filas[0][i].getValor() == tab.filas[1][i].getValor() &&
             tab.filas[0][i].getValor() == tab.filas[2][i].getValor()

        ) ) {

            correcto = true ; // se comprueba que si hay un ganador ( cumplio l objetivo del juego )

        }
    }

    return correcto ; // retornar el resultado de la comprobacion
}


/**
    saber si se an colocado tres caracteres iguales en diagonal
*/
bool Juego :: tresEnDiagonal ()
{

    bool correcto = false; // se asume que no es correcto lo que se quiere comprobas

    if( (   // verificar que  el valor de las casillas no sea un espacio

         /**
            solo necesito verificar uno ya que este va incluido en ambos resultados posibles y si
            el valor de la casilla del centro es un espacio no hay forma en que un jugador haya
            colocado sus caracteres en linea
         */

            tab.filas[1][1].getValor() == jugadores[0].getCaracter() ||  // ver si el valor es " x "
            tab.filas[1][1].getValor() == jugadores[1].getCaracter()     // ver si el valor es " 0 "

        ) && ( ( // verificar si el jugador formo una diagonal

            tab.filas[0][0].getValor() == tab.filas[1][1].getValor() &&
            tab.filas[0][0].getValor() == tab.filas[2][2].getValor() &&
            tab.filas[1][1].getValor() == tab.filas[2][2].getValor()

        ) || (  // verificar si el jugador formo una diagonal invertida

            tab.filas[0][2].getValor() == tab.filas[1][1].getValor() &&
            tab.filas[0][2].getValor() == tab.filas[2][0].getValor() &&
            tab.filas[1][1].getValor() == tab.filas[2][0].getValor()
        ) )
    )  {

       correcto = true ; // se comprueba que si hay un ganador ( cumplio l objetivo del juego )
    }

    return correcto ; // retornar el resultado de la comprobacion
}

/**
    mostrar un menu que pregunte al usuario si quiere volver a jugar
*/
void Juego :: showMenu()
{
    PlaySound( "sonidos/SD_ALERT_21.wav" , NULL , SND_ASYNC ) ;
    system("cls") ; // borrar pantalla
    system("color 3f") ;
    // Indicacion del menu
    cout << " quieres volver a jugar? \n \n" ;

    // definicion de las opciones disponibles para el menu
    array< string , 2 > opciones = {
        " Si" , " No"
    } ;

    // mostrar el menu al usuario
    for ( int i = 0 ; i < opciones.size() ; i++ ) {
        cout << " " << i + 1 << " " << opciones[i] << "\n" ;
    }

    // pedir la respuesta del usuario
    do{

        getInt( "\n Escoge una de la opciones " , answerUser ) ;

     // repetir hasta que la respuesta del usuario corresponda a una de las opciones del menu
    } while ( answerUser < 1 || answerUser > opciones.size() ) ;

    // Verificar que opcion escogi el usuario
    switch( answerUser ) {

        case 1 : // si quiere volver a jugar
            reset() ; // resetear los datos a iniciales
            PlaySound( "sonidos/super_mario_world_yoshis_island_sms.wav" , NULL , SND_LOOP|SND_ASYNC ) ;
            jugar() ; // iniciar el juego
            break ;

        case 2 : // no quiere volver a jugar
            PlaySound( "sonidos/SD_ALERT_29.wav" , NULL , SND_ASYNC ) ;
            system("color 3f");
            mostrarMensaje( "                            ADIOS ;) " ) ;
            break ;
    }

}


// resetear valores
void Juego :: reset() // colocar los datos en el estado inicial
{

    // buscar la casilla sobre la que se escribira el caracter
    for ( int i = 0 ; i < tab.filas.size() ; i++ ){

    //recorrer las columnas de las filas
        for ( int j = 0 ; j < tab.filas[i].size() ; j++ ){

            tab.filas[i][j].setValor( "   " ) ;  // colocar todas las casillas en blanco

        }
    }

    ( tJugador == 0 ) ? tJugador = 1 : tJugador = 0 ; // dar turno inicial al que perdio el ultimo juego
    hayGanador = false ; // definir que aun no hay ganador

}


