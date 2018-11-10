#ifndef AUDIO_H
#define AUDIO_H
#include<string>  /// para poder tener datos de tipo string

using namespace std ; /// para poder usar el espacio de nombres std

class Audio
{
    public:
        Audio( string  ); /// crear un nuevo audio
        char url[52] ;  /// ruta en que se encuentra el archivo del audio
        void setUrl () ; /// generar ruta de la cancion
        void play( int type = 1 ) ; /// reproducir cancion cancion
        virtual ~Audio();



    private:
       string file ; /// nombre del audio
};

#endif // AUDIO_H
