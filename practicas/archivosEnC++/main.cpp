/****************************************************************

    Autor : Erick Josue Saravia Aragon

    N° Carnet : SA18004

    Fecha : 2018-11-06

    Descripcion : trabajar con ficheros en c++

*****************************************************************/

#include<iostream> // para usar "cout" y "cin"
#include<cstdlib> // para algo
#include<fstream> // para trabajar con el flujo de archivos

using namespace std;

int main(){

    char cadena[128];
    ofstream fs("nombre.txt") ;
    fs << "hola mundo" ;
    fs.close();
    system("pause") ;
    return 0;

}
