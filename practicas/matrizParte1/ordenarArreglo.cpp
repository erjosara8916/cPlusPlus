/****************************************************************

    Autor : Erick Josue Saravia Aragon

    N° Carnet : SA18004

    Fecha : 02-10-2018

    Descripcion : ordenar los elementos de un arreglo

*****************************************************************/
#include <stdio.h>
 #include <conio.h>
 #include <iostream>

 using namespace std;
 void ordenar (int arreglo[])
 {
 int i, j, temporal;
 int arreglo[10] = {}; 
 for(j=1;j<=tam;j++)
 {
 for(i=0;i<tam-1;i++)
 {
 if(arreglo>arreglo[i+1])
 {
 temporal=arreglo;
 arreglo=arreglo[i+1];
 arreglo[i+1]=temporal;
 }
 }
 }
 }

 void imprimir(int arreglo[])
 {
 int i, j;
 int arreglo[tam];
 cout<<"\nArreglo ordenado de menor a mayor\n";
 for (i=0;i<tam;i++)
 {
 cout<<arreglo<<" ";
 cout <<endl; 
 }
 }

 int main()
 { 
 int arreglo[tam];
 int i,j, temporal; 
 for (i=0;i<tam;i++)
 {
 cout<<"Ingrese el numero "<<i+1<<":";
 cin>>arreglo;
 } 

 ordenar(arreglo);
 imprimir(arreglo);
 cout<<endl;
 imprimir(arreglo);
 getch(); 
 system("PAUSE"); 
 return 0;
 }
