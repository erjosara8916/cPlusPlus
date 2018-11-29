#ifndef TORREHANOI_H
#define TORREHANOI_H

#include <array>
#include <iostream>
#include <string>

using namespace std ;
typedef array < int , 3 > col ;

class TorreHanoi
{
    public:
        TorreHanoi();
        void jugar () ;

    private:
        int tem ;
        int tem2 ;
        int n ; /// almacena el numero de discos a utilizar
        int i ; /// contador a usar en arreglos
        int j ; /// contador para los bucles anidados
        int desde ; /// almacena desde que torre se movera el disco
        int hacia ; /// almacena hasta que torre se movera el disco
        int con ; /// contador de turnos
        int tam ; /// tamaño del tablero
        int tamDisco ; /// almacena el tamaño de un disco
        int espacios ;
        int k ;
        array < col , 100 > matriz ;
        char cr ; /// caracter
        char fondo ; /// define el fondo del tablero
        void linea ( int ) ;

        void moverDisco () ; /// permite mover el disco a una posicion

};

#endif // TORREHANOI_H
