/****************************************************************

    Autor : Erick Josue Saravia Arargon

    N° Carnet : SA18004

    Fecha : 24-09-2018

    Descripcion : Calcular el costo a una llamada telefonica

*****************************************************************/

#include <iostream> // para usar "cin" y "cout"
#include <Tarifa.h> // tarifas disponibles
#include <llamada.h> // tener acceso a la clase llamada
#include <windows.h> // para poder ejecutar comandos de la consola

using namespace std; // abrebiar el uso de "cin" y "cout"

int main()
{
    system("color 1f"); // dar estilo a la pantalla
    cout << "------------------------------------------------------------------------------- \n\n";
    cout << "calcula la tarifa de una llamada telefonica en base a los siguientes creiterios\n" ;
    cout << "        Minutos                                costo por min" << endl;
    cout << "        1  - 10                                      $ 0.05 " << endl;
    cout << "        11 - 15                                      $ 0.08 " << endl;
    cout << "        16...                                        $ 0.10 " << endl;
    cout << "--------------------------------------------------------------------------------\n\n" ;

    system( "pause" ) ;
    system( "cls" ) ;

    Llamada llamada = Llamada( ) ; // crear una nueva llamada
    llamada.init(); // iniciar operaciones respecto a las llamadas

    return 0;
}
