#ifndef METODOBURBUJA_H
#define METODOBURBUJA_H

#include <array>
#include <iostream>
#include <string>

using namespace std ;

class MetodoBurbuja
{
    public:
        MetodoBurbuja();
        void llenarNumeros () ; /// llenar el arreglo numeros
        void  mostrar () ; /// mostrar la serie de numeros original y ordenada

    private:
        int temp ; /// almacenamiento temporal de un dato ( a usar en el metodo de la burbuja
        array < int , 100 > numeros ; /// serie de numeros
        void ordenarNumeros () ; /// ordenar serie de numeros


};

#endif // METODOBURBUJA_H
