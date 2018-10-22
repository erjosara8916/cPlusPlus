/***********************************************************************************
    Autor: Erick Josue Sravia Aragon
    N° Carnet: SA18004
    Fecha: 05-09-2018
    Descripcion: Calcular el total de la venta de cafe aplicando
                 un descuento acorde a la cantidad de sacos sumandole
                 el impuesto del IVA
************************************************************************************/

#include<iostream>
#include<stdlib.h>
#include"ventas.h"

using namespace std;

const float IVA = 0.13;

void fijarEntero ( string enunciado , int& var );


struct venta{
    int numSacos = 0;
    double precio = 100;
    double descuentos[5] = { 0 , 0.1 , 0.15 , 0.2 , 0.25 };
    double subtotal;
    double total;
    double descuento;
    double iva = 0.13;

// calcular el total aplicando el descuento correspondiente
    void calcularTotal(){
        subtotal = numSacos * precio;

        if(numSacos >= 300){
            descuento = descuentos[4];
        } else if ( numSacos > 250 ) {
            descuento = descuentos[3];
        } else if ( numSacos > 200 ) {
            descuento = descuentos[2];
        } else if ( numSacos > 100 ) {
            descuento = descuentos[1];
        } else {
            descuento = descuentos[0];
        }
        total = subtotal - ( subtotal * descuento );
        iva = total * iva;
        total += iva;
    }

// llevar a cabo la venta
    void hacerVenta(){
        while(numSacos <= 0){ // validar que se ingresen numeros psitivos
            fijarEntero( "Ingresa el numero de sacos correspondientes a esta venta : ", numSacos );
        }
        calcularTotal();
        cout<<"\n**************************************************************************"<<endl<<endl;
        cout<<"cantidad de sacos de cafe ........................ "<<numSacos<<endl;
        cout<<"Precio unitario ................................ $ "<<precio<<endl;
        cout<<"subtotal ....................................... $ "<<subtotal<<endl;
        cout<<"descuento ("<<descuento*100<<"%) ................................. $ "<<subtotal*descuento<<endl;
        cout<<"IVA (13%) ...................................... $ "<<iva<<endl;
        cout<<"Total .......................................... $ "<<total<<endl<<endl;
        cout<<"**************************************************************************"<<endl<<endl;
    }
};

struct programa{
    string title = "----------> CALCULA EL COSTO TOTAL DE VENTA DE CAFE APLICANDO DESCUENTOS E IVA <-----------";
    int opt = 0;

// iniciar el programa
    void init(){
        system("cls");     // limpiar el contenido de la consola
        cout<<title<<endl<<endl;
        opt = 0;
        venta v1;
        v1.hacerVenta();
        mostrarMenu();
    }

// mostrar menu de opciones
    void mostrarMenu(){

        while( opt != 1 && opt != 2 ){    // asegurar que el usuario escoja una de las 2 opciones
            fijarEntero( "\n Quieres realizar otra venta? \n 1. SI \n 2. NO \nEscribe un numero : " , opt );
        }
        if( opt == 1){
            cout<<endl<<endl;
            init();
        } else {
            cout<<" \n Adios ;) ";
        }
    }
};

// realizar la captura de un entero y validarla
void fijarEntero ( string enunciado, int& var ){
    cout<<enunciado;
    cin>>var;

    while( cin.fail() ){  // verificar si el buffer de entrada esta en estado de error
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"el valor no es valido"<<endl;
        cout<<enunciado;cin>>var;cout<<endl;
    }
}
int main(){

       programa prog;
       prog.init();
    return 0;
}
