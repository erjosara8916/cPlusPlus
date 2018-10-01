#ifndef TARIFA_H
#define TARIFA_H

// declaracion de clase tarifa de las llamadas
class Tarifa
{
    private:
        float inicio ; // a partir de este valor se aplicara el cobro
        float cobro ; // precio de cada minuto hablado

    public:
        Tarifa( float , float );
        float getInicio() ; // consultar a partir de cuanto se aplicara el cobro
        float getCobro() ;  // consultar el precio de la tarifa

};



#endif // TARIFA_H
