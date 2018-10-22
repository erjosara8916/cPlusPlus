/****************************************************************

    Autor : Erick Josue Saravia Aragon

    N° Carnet : SA18004

    Fecha : 04-10-2018

    Descripcion : realizar la suma de los elementos de dos matrices


*****************************************************************/

#include <iostream>
#include<math.h>
#include<time.h>

using namespace std;

int main()
{
    int numero ;
    srand(time(NULL)) ;
    numero = rand() / 100 % 10 + 1 ;
    cout << numero << endl;
    return 0;
}
