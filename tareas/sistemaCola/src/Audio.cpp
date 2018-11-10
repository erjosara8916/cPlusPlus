#include "Audio.h"
#include<string> /// para poder crear datos de tipo string
#include<windows.h> /// para poder usar la funcion PlaySound

using namespace std;

/// crear una nueva funcion
Audio :: Audio( string fil )
{
    file = fil ; /// definir nombre del archivo
    setUrl () ; /// definir la url
}

/**
    Define el nombre del archivo anexandole la ruta y el formato para
    obtener la ubicacion del mismo.
    La ubicacion del archivo se pasa a una variaable tipo char ( arreglo )
    ya que la funcion TEXT() trabaja con ese tipo de parametros
*/
void Audio :: setUrl()
{
/*
    generar la ruta del archivo que se reproducira
*/
    string PREF = "sonidos\\";
    file = PREF + file + ".wav" ; // define la ruta que se utilizara


//  convertir la ruta a tipo char[]
    for ( unsigned i = 0 ; i <= file.size()  ; i++ ){
        url[ i ] = file[ i ];
    }
}

/**
    reproduce el audio cuyo comportamiento deendera del valor del parametro "type"
*/
void Audio :: play ( int type )
{

    /// definir comportamiento del audio
    switch( type ) {

    case 1 : /// se pausara el programa al ser reproducido
       PlaySound( TEXT( url ) , NULL , SND_SYNC ) ;
       break ;

    case 2 : /// el programa seguira corriendo al ser reproducido
       PlaySound( TEXT( url ) , NULL , SND_ASYNC ) ;
       break ;

    case 3 : /// se reproduce de forma ciclica y el programa sigue corriendo
       PlaySound( TEXT( url ) , NULL , SND_LOOP | SND_ASYNC ) ;
       break ;
    } ;

}

Audio::~Audio()
{
    //dtor
}
