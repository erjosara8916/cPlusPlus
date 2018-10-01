#include "llamada.h" // tener acceso al prototipo de la clase llamada
#include "Tarifa.h"  // poder usar la clase Tarifa
#include <iostream>  // poder hacer uso de "cin" y "cout"
#include <array> // para poder crear arreglos y usar el metodo size()

using namespace std ;

// definir tarifas que seran aplicada a las llamadas
array< Tarifa , 3 > tarifas = {
   Tarifa( 0  , 0.05 ) ,
   Tarifa( 11 , 0.08 ) ,
   Tarifa( 15 , 0.10 )
} ;

// definicion de los metodos de la llamada
Llamada::Llamada( ) { }

// realizar las operaciones de la llamada
void Llamada :: init ()
{
    setMinutos() ; // definir minutos
    setCobro() ; // calcular y definir el costo
    show() ; // mostrar info
}

// definir minutos
void Llamada :: setMinutos(  )
{
   cout << "ingresa el numero de minutos que duro la llamada : " ;
   cin >> minutos ;
   while( cin.fail() || minutos < 1 ){  // validar minutos
       cin.clear() ;
       cin.ignore( 1000 , '\n' ) ;
       cout << "ingresa el numero de minutos que duro la llamada :" ;
       cin >> minutos ;
       cout << endl ;
   }
}

// definir el cobro
void Llamada :: setCobro ()
{
    cobro = calcularCobro() ;
}

float Llamada :: calcularCobro ()
{
    float total;
    for ( int  i = tarifas.size() - 1 ; i >= 0  ; i-- ){
        if ( minutos > tarifas[i].getInicio() ) {
            total = minutos * tarifas[i].getCobro() ;
            return total ;
        }
    }
}



int Llamada :: getMinutos (  )
{
    return minutos ;
}

float Llamada :: getCobro()
{
    return cobro ;
}



// mostrar en pantalla el costo y calcular una nueva llamada de ser necesario
void Llamada :: show ()
{
    int r ; // respuesta del usuario

    cout << "la tarifa de la llamada es de : $ " << cobro ;

    // verificar si se termina o no la ejecucion de la aplicacion
    cout << "\n\n quieres calcular otra tarifa? \n" ;
    cout << " 1. Si" << endl;
    cout << " 2. No \n" << endl;
    cout << "Escoge una opcion : " ;
    cin >> r ;

    while( cin.fail() || ( r < 1 || r > 2 ) ){ // si la respuesta no es valida
        cin.clear() ;
        cin.ignore( 1000 , '\n' );
        cout << "El valor no es correcto vuelve a ingresarlo: " ;
        cin >> r ;
        cout << endl ;
    }

    if ( r == 1 ){ // si quiere calcular nuevamente
        system("cls") ; // borrar pantalla
        init() ; // iniciar operecione nuevamente
    }
}
