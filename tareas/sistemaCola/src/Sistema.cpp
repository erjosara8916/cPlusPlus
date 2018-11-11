#include "Sistema.h"
#include <iostream>
#include <string>
#include <array>
#include "BasicOperations.h"
#include"Audio.h"
#include<windows.h>

using namespace std ;
/// audios basicos
array< Audio , 20 > basicos = {
    Audio("uno") ,
    Audio("dos") ,
    Audio("tres") ,
    Audio("cuatro") ,
    Audio("cinco") ,
    Audio("seis") ,
    Audio("siete") ,
    Audio("ocho") ,
    Audio("nueve") ,
    Audio("dies") ,
    Audio("once") ,
    Audio("doce") ,
    Audio("trece") ,
    Audio("catorce") ,
    Audio("quince") ,
    Audio("dieciseis") ,
    Audio("diecisiete") ,
    Audio("dieciocho") ,
    Audio("diecinueve") ,
    Audio("veinte")
} ;

/// audios de los multiplos (decensas)
array< Audio , 8 > multiplos = {
    Audio( "veinti" ) ,
    Audio( "treinta" ) ,
    Audio( "cuarenta" ) ,
    Audio( "cincuenta" ) ,
    Audio( "sesenta" ) ,
    Audio( "ochenta" ) ,
    Audio( "noventa" ) ,
    Audio( "cien" ) ,
};

/// audios de apoyo
array< Audio , 6 > otros  = {
  Audio( "tiket" ) ,
  Audio( "pasarAVentanilla" ) ,
  Audio( "y" ) ,
  Audio( "saludo") ,
  Audio( "fondo" ) ,
  Audio( "alerta" )
};

/**
    correr e inicializar los datos del sistema
*/
Sistema::Sistema()
{
    system("color 06") ;
    otros[3].play( 2 ) ; // reproducir bienvenida
    msn = "\n\n                     BIENVENIDO AL SISTEMA DE COLAS \n\n" ;
    mostrarMensaje( msn , true ) ; // mostrar mensaje d ebienvenida


    // definir las opciones del menu
    menu1 = {
       "generar numero" ,
       "llamar nuevo tiket" ,
       "volver a llamar" ,
       "salir"
    } ;


    // iniciacion de los valores iniciales
    cantTikets = 0 ;
    ultimoNumero = 0 ;
    proxAtender = 0 ;
    atendiendo = false ;
    otros[4].play( 3 ) ; // inicia cancion de fondo
    mostrarMenu1() ; // muestra el menu al usuario

}

/**
   rescorre el arreglo de las opciones del menu y las
   muestra en pantalla asignadoles un numero de opcion
   con el cual el usuario pueda escoger dicha opcion a
   travez del teclado
*/
void Sistema :: mostrarMenu1 ()
{
    system("cls"); // borrar pantalla

    // Indicacion del menu
    cout << "que quieres hacer? \n \n" ;

    // mostrar el menu al usuario ( las opciones en el arreglo menu1 )
    for ( int i = 0 ; i < menu1.size() ; i++ ) {

        cout << i + 1 << " -> " << menu1[i] << "\n" ;

    }

    // pedir la respuesta del usuario
    do{

        getInt( "\n Escoge una de la opciones : " , answerUser ) ;

    } while ( answerUser < 1 || answerUser > menu1.size() ) ; // aseura una respuesta coherente

    // Verificar que opcion escogio el usuario
    switch( answerUser ) {

        case 1 : // usuario quiere crear tiket

            generarNumero() ;
            mostrarMenu1() ;
            break ;

        case 2 :// usuario quiere llamar tiket

            llamarNumero() ;
            otros[4].play( 3 ) ;
            mostrarMenu1() ;
            break ;

        case 3 : // usuario quiere mostrar a persona atendida actualmente

            mostrarNumeroAtendido() ;
            mostrarMenu1() ;
            break ;

        default : // usuario quiere

            salir() ;
            break ;
    }
}

/**
    reconoce la cantidad de tikets emitidos obteniendo de esta manera la pocision
    en que se guardara el proximo en crear. Luego identifica cual fue el ultimo numero
    con el que se emitio un tiket y lo incrementa en uno luego asigna ese valor a la
    posicion (definida por la cantidad de tikets que aun no an sido atendidos) dentro
    del arreglo "tikets"
*/
void Sistema :: generarNumero ()
{
    system("cls");
    ultimoNumero++ ; //incrementa el ultimo numero emitido
    // valor anterior se coloca en el primer elemento disponible
    tikets[cantTikets] = ultimoNumero ;
    /**
        define cuantos elementos del arreglo se estan ocupando para no operar con su ongitud que
        es de 100
    */
    cantTikets++ ;

    // crear mensaje a mostrar
    msn = " SE HA CREADO EL TIKET CON IDENTIFICADOR : " + to_string(ultimoNumero)  ;
    mostrarMensaje( msn , true ) ; // mostrar mensaje en pantalla
}

/**
    Si hay tikets emitidos sin atender elimina el primero ( ver eliminarTiket ) del
    arreglo, coloca el sistema en estado de atendiendo, tambien en estado de llamando
    y aumenta en uno el valor del proximo tiket que se atendera.
    Si no hay tikets emitidos quita el estado de atendiendo al sistema.
    Muestra el tiket que le corresponde ser atendido y luego quita el estado llamando
*/
void Sistema :: llamarNumero ()
{
    system("cls");
    msn = "" ; // borra contenido actual del mensaje

    if ( cantTikets > 0 ){

        eliminarTiket() ;
        atendiendo = true ;
        proxAtender++ ;

    } else {

        atendiendo = false ;

    }

    mostrarNumeroAtendido() ;
}

/**
    Mueve los valores del arreglo tikets una pocision antes ( menos el primero )
    dando como resultado el eliminar la primera pocicion. Luego disminuye la
    cantidad de tikets creados sin atender
*/
void Sistema :: eliminarTiket(){

    //mover tikets una pocision antes ( eliminando el primero )
    for ( int i = 0 ; i < cantTikets - 1 ; i++ ){

        tikets[i] = tikets[i+1] ;

    }

    cantTikets--; // disminuir numero atendido
}

/**
   Verifica si ya se llamo a un tiket y este esta siendo atendido o se esta esperando a que
   el tiket pase a la entanilla ( se asume que un tiket deja de ser atendido cuando se llama al siguiente
   y si ya no hay tikets pendientes al hacer esto se supone que ya no esta atendiendo
   a nadie )
*/
void Sistema :: mostrarNumeroAtendido (  )
{
    system("cls");
    otros[5].play( 2 ) ; // reproducir notificacion
    msn = "" ; // borra el contenido actual del mensaje

    if ( atendiendo ){ // si se esta atendiendo a alguien


        msn = "              TURNO DE TIKET  " + to_string(proxAtender) ;

        mostrarMensaje( msn , false ) ;

        /// reproduce el llamado al tiket
        otros[0].play() ;
        repNumero(proxAtender) ; /// reproduce el numero ( ver repNumero )
        otros[1].play() ;


    } else {  /// si ya no hay clientes esperando

        msn = " no hay ningun cliente esperando" ;

        mostrarMensaje( msn , true ) ;

    }

    otros[4].play( 3 ) ; // coloca sonido de fondo nuevamente

}
/**
  Reproduce un numero pasado por parametro Si el numero es mayor que 20
  buscara el audio a reproducir en el arreglo "multiplos" tomando como
  indice el haberle restado 20 al numero y dividirlo entre 10, tras
  reproducir el audio ( ver Audio :: play ) se verifica el residuo del
  proceso de restarle 20 el numero original y dividirlo entre 10, si este
  es distinto de 0 ( no es un multiplo de 10 ), la funcion se llama a si misma
  mandando como numero el resto de la division ( si el num. orig. era mayor que 30
  se reprocuce el audio "y" antes de llamarse nuevamente la funcion.
  Si el numero pasado por parametro no es mayor que 20 buscara el audio a reproducir
  en el arreglo "basicos" tomando como indice el valor del numero menos 1
*/
void Sistema :: repNumero( int num ) {

    if ( num > 20 ) {

        int posMult = ( num - 20 ) / 10 ; // identificar multiplo
        int resto = ( num - 20 ) % 10 ; // identificar resto
        multiplos[ posMult ].play() ; // reporoducir multiplo

        if ( resto != 0 ) { // si el numero no es multipo de 10

            if ( num > 30 ) {

                otros[ 2 ].play() ; // reproducir "y.wav"

            }

            repNumero( resto ) ; // reproducir el resto

        }
    } else {

        basicos[ num - 1 ].play() ; // reproducir numero

    }

}

/**
    mandar mensaje de despedida al usuario
*/
void Sistema :: salir(){
    otros[5].play( 2 ) ;
    msn = "\n\n                       ADIOS ;) \n\n" ;
    mostrarMensaje( msn ) ;

}

Sistema::~Sistema()
{
    //dtor
}
