#ifndef PANEL_H
#define PANEL_H

#include<iostream>
#include <array>
#include <string.h>
#include "TorreHanoi.h"
#include "MetodoBurbuja.h"

using namespace std;

class Panel
{
    public:
        Panel(); /// constructor


    private:
        TorreHanoi juego ; /// juego de torres de hanoi
        MetodoBurbuja burbuja ;
        array < string , 3 > menu ; /// opciones del menu
        int answerUser ; /// guarda las respuestas del usuario
        void showMenu ( ) ; /// muestra el menu
        void salir ( ) ; /// salir del sistema
};

#endif // PANEL_H
