
#include <iostream>
using namespace std;

int factorial( int num ) {
    int fact = 1 ;
    for (i = 1; i <= num; i++){
         fact = fact*i;
    }
    return fact ;
}

int main(void){

   int i;
   int fact=1;
   int numero;
   cout<<"ingresa un numero: ";
   cin>>numero;

   if(numero<0){
        fact =0;
   }
   else if(numero==0){
        fact=1;
   }
   else{
      fact = factorial(numero) ;
   }
   cout << "Factorial de " << numero << " es : " << fact;
   system("pause");
}
