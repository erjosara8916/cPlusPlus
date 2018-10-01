#include "Tarifa.h" // acceso al prototipo de la clase
#include <iostream> // para poder realizar entrada y salida de datos

using namespace std;

// definir los valores de la clase
Tarifa::Tarifa( float men , float cob )
{
    inicio = men ;
    cobro = cob ;
}

// pedir el valor de la propiedad inicio
float Tarifa::getInicio(){
    return inicio ;
}

// pedir el valor de la propiedad cobro
float Tarifa :: getCobro (  )
{
    return cobro ;
}


