#ifndef TIKET_H
#define TIKET_H

#include<string> // para usar tipos de dato string

using namespace std ;
class Tiket
{
    public:
        Tiket();
        void setId( int num ) ;
        int getId() ;
        void setCliente() ;
        void mostrar() ;
        virtual ~Tiket();

    protected:
        int id ; // numero del tiket
        string cliente ; // nombre del cliente
        string msn ;


    private:
};

#endif // TIKET_H
