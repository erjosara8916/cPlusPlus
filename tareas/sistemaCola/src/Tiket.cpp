#include "Tiket.h"
#include"BasicOperations.h"
#include <iostream>
#include<winbgim.h>

using namespace std ;
Tiket::Tiket()
{
    msn = " " ;
}

/**  */
void Tiket :: setId ( int num )
{

    id = num ;

}

/**  */
void Tiket :: setCliente ()
{
    getString("escribe el nombre del cliente : " , cin , cliente ) ;
    mostrar() ;
}

/**  */
void Tiket :: mostrar ()
{
    msn += "numero de tiket : " + to_string(id) + "\n" ;
    msn += "cliente : " + cliente ;

/*      char mensaje[150] ;
 *     string strId = to_string(id) ;
 *     char charId[1] ;
 *
 *     //convertir la cadena a tipo char
 *     for ( int i = 0 ; i < strId.size() ; i++ ){
 *         charId[i] = strId[i] ;
 *     }
 *
 *     initwindow(600,400) ;
 *     setbkcolor(24);
 *     settextstyle(0,0,7) ;
 *     outtextxy(100,150,charId) ;
 *     getch() ;
 */
   // closegraph() ;
   system("cls");
   cout << msn << endl;
   system("pause") ;


}

int Tiket :: getId (  )
{
    return id ;
}
Tiket::~Tiket()
{
    //dtor
}
