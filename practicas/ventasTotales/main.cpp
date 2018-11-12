/***
nombre : erick josue saravia asragon
carnet : sa18004
**/

#include <iostream>
#include <string>
#include<fstream> // trabajo con ficheros
#include<windows.h>

using namespace std;

struct venta {
    string producto ;
    double precio ;
    double cantidad ;
    double totalVenta ;
};

int main()
{
    int n ;
    venta temp ;
    string msn = "REPORTE DE ENTAS \n";
    msn += "-------------------------------------------------\n" ;
    cout << "escribe el numero de ventas que se han realizado : " ;
    cin >> n ;
    while( cin.fail() ){
        cin.clear() ;
        cin.ignore( 1000 , '\n' );
        cout << "El valor no es correcto vuelve a ingresarlo: " ;
        cin >> n ;
        cout << endl ;
    }

    venta listaVentas[n] ;

    //llenar arreglo
    for ( int i = 0 ; i < n ; i++ ){
        system("cls") ;
        cout << "ingresa los datos de la venta " << i + 1 << endl;
        cout << "nombre del producto : ";
        cin >> listaVentas[i].producto ;
        cout << "precio del producto : ";
        cin >> listaVentas[i].precio ;
        cout << "cantidad del producto vendida : " ;
        cin >> listaVentas[i].cantidad ;

        listaVentas[i].totalVenta = listaVentas[i].precio * listaVentas[i].cantidad ;

        cout << "\nel total de esta venta es : " << listaVentas[i].totalVenta << endl;
        system("pause") ;
    }
    for ( int i = 0 ; i <= n  ; i++ ){

        for ( int j = i+ 1 ; j < n  ; j++ ){
            //  ordenar
            if ( listaVentas[j].totalVenta < listaVentas[i].totalVenta  ){
                temp = listaVentas[j] ;
                listaVentas[j] = listaVentas[i];
                listaVentas[i] = temp ;
            }
        }
    }


    //mostrar las ventas
    for ( int i = 0 ; i < n  ; i++ ){
        system("cls") ;
/*         cout << "producto : " << listaVentas[i].producto << endl;
 *         cout << "precio : " << listaVentas[i].precio << endl;
 *         cout << "cantidad : " << listaVentas[i].cantidad << endl;
 *         cout << "total : " << listaVentas[i].totalVenta << endl;
 */
        msn += " VENTA " + to_string(i+1) + "\n" ;
        msn += " producto : " + listaVentas[i].producto + "\n" ;
        msn += " precio : " + to_string(listaVentas[i].precio) + "\n" ;
        msn += " cantidad : " + to_string(listaVentas[i].cantidad) + "\n" ;
        msn += " total : " + to_string(listaVentas[i].totalVenta) + "\n" ;
        msn += "-----------------------------------------------------\n"  ;
        system("pause") ;
    }


    ofstream fs("reporte.txt") ;
    fs<< msn<<endl ;
    fs.close();
    return 0;
}
