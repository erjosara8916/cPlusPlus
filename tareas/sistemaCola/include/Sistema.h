#ifndef SISTEMA_H
#define SISTEMA_H

#include<string> // para poder usar cadenas tipo "string"
#include <array> // para crear arreglos y usar el metodo size sobre ellos

using namespace std ;

class Sistema
{
    public:
        Sistema();
        virtual ~Sistema();


    protected:
        int answerUser ; // respuesta del usuario
        array < string , 4 > menu1 ; // opciones del menu
        array < int , 100 > tikets ; // espacio para guardar tikets maximo 100
        int cantTikets ; // cantidad de tikets en espera
        int ultimoNumero ; // numero del ultimo tiket emitido
        int proxAtender ; // numero del proximo tiket en ser llamado
        string msn ; // mensaje a mostrar en la consola
        bool atendiendo ; // si se esta atendiendo a alguien en ese momento
        bool llamando ; // si se esta llamanado a un cliente en ese momento
        void mostrarMenu1() ; //mostrar el menu principal
        void generarNumero() ; // genera un nuevo numero de tiket
        void llamarNumero() ;  // llamar a un numero
        void eliminarTiket() ; // elimina el ultimo tiket que se emitio
        void mostrarNumeroAtendido() ; // muestra el numero al que se atiende
        void repNumero( int ) ;  // reproducir el numero en voz
        void salir() ; // salir del sistema

    private:
};

#endif // SISTEMA_H
