#ifndef LLAMADA_H
#define LLAMADA_H

// declaracion de la clase llamada
class Llamada
{
    private:
        int minutos ; // minutos que a durado la llamada
        float cobro ; // cobro correspondiente a la llamada

    public:
        Llamada(  ) ;
        float calcularCobro() ;
        void setCobro() ; // definir el cobro
        void setMinutos( ) ; // definir duracion de la llamada
        float getCobro() ; // pedir el valor del costo de la llamada
        int getMinutos() ;  // pedir el valor de la duracion
        void init() ; // iniciar operaciones
        void show() ; // mostrar la informacion
};

#endif // LLAMADA_H
