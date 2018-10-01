/****************************************************************
    Autor : Erick Josue Saravia Aragon

    N° Carnet : SA18004

    Fecha : 24-09-2018

    Descripcion : calcular la produccion diaria de bebidas y los
                  insumos requeridos para la elaboracion de refrescos :

                          Agua     Azucar
                  soda    500ml.    800g
                  jugo    600ml.    700g

*****************************************************************/

#include <iostream> // para poder usar "cin" y "cout"
#include <string.h> // para crear datos de tipo "string"
#include <array> // para poder crear arreglos de datos

using namespace std; // para abrebiar el uso de "cin" y "cout"

// declaracion de la prototipo de la clase bebida
class Bebida
{
    private :
        string nombre ; // nombre de le bebida
        unsigned int cantAgua ; // cantidad de agua necesaria para fabricar una bebida
        unsigned int cantAzucar ;// cantidad de agua necesaria para fabricar una bebida
        int cantidad ; // cantidad de bebidas que se fabricaran
        int totalAgua ; // total de agua necesaria para fabricar la cantidad de bebidas
        int totalAzucar ; // total de azucar necesaria para fabricar la cantidad de bebidas

    public :
        Bebida( string , int , int ); // definir las caracteristicas basicas de la bebida
        string getNombre() ; // obtener el nombre  nombre de la bebida
        int getCantAgua() ; // obtener la cantidad de agua necesaria para una bebida
        int getCantAzucar() ; // obtener la cantidad de azucar necesaria para una bebida
        void setCantidad() ; // pedir la cantidad de bebidas sobre la que quiere calcular insumos
        void calcularInsumos() ; // calcular el total de insumos necesarios para hacer la bebida
        void showInfo() ; // mostrar la informacion de la bebida

};

//declaracion de la clase empresa

// la empresa que realiza el calculo
class Empresa
{
    public :
        Empresa() ;
        void init() ; // iniciar operaciones
        void showMenu() ; // mostrar menu
} ;

Empresa :: Empresa (  ) {}

// bebidas que procude la empresa
    array< Bebida , 2 > bebidas = {
       Bebida( "soda" , 500 , 800 ) ,
       Bebida( "jugo" , 600 , 700 )
    } ;

int main()
{

    system("color 1f") ;
    // mostrar descripcion general
    cout << "------------------------------------------------------------------------------- \n" ;
    cout << "calcula la cantidad de insumos necesarios para la produccion de  estas bebidas \n" ;
    cout << "ingredientes de las bebidas : \n \n" << endl;

    //mostrar detalles sobre bebidas
    for ( unsigned i = 0 ; i < bebidas.size() ; i++ ){
        cout << bebidas[i].getNombre() << " : " << bebidas[i].getCantAgua() << " ml de agua" ;
        cout << ", " << bebidas[i].getCantAzucar() << " g de azucar \n \n" ;

    }
    cout << "------------------------------------------------------------------------------- \n" ;
    system("pause") ; // esperar a que el usuario vea la descripcion general
    system("cls") ; // borrar consola

    int r; // para recibir la respuesta al menu

    Empresa e = Empresa() ; // crear objeto empresa para tener acceso a las operaciones
    e.init() ; // iniciar operaciones de la empresa

    // menu para saber si se realizara nuevamente las operaciones


    return 0;
}

// definicion de los metods de bebida
Bebida :: Bebida ( string nom , int agua , int azucar ) {
    // dar valor a las propiedades principales
    nombre = nom ;
    cantAgua = agua ;
    cantAzucar = azucar ;
}

string Bebida :: getNombre (  ) // obtener el nombre de la bebida
{
    return nombre ;
}

int Bebida :: getCantAgua ( ) // obtener la cantidad de agua para hacer la bebida
{
    return cantAgua ;
}

int Bebida :: getCantAzucar ( )  // obtener la cantidad de azucar para hacer la bebida
{
    return cantAzucar ;
}

void Bebida :: setCantidad( ) // definir la cantidad de bebidas que se quieren realizar
{
    cout << " Ingresa la cantidad de " << nombre << "s que se planean producir : " ; // mensaje para indicar al usuario que debe ingresar
    cin >> cantidad ;

    while( cin.fail() || cantidad < 1 ){  // si ingresa un valor no valido
        cin.clear() ;
        cin.ignore(1000,'\n') ;
        cout << " Ingresa la cantidad de " << nombre << "s que se planean producir : "  ;
        cin >> cantidad ;
        cout << endl ;
    }

    calcularInsumos() ; // calcular los insumos necesarios para hacer las bebidas
}

void Bebida :: calcularInsumos () // calcular los insumos necesarios para hacer las bebidas
{
    totalAgua = cantidad * cantAgua ; // calcular el total de agua
    totalAzucar = cantidad * cantAzucar ; // calcular el total de azucar
}

// mostrar la informacion de la bebida
void Bebida :: showInfo()
{
    cout << "La cantidad de insumos necesarios para producir una cantidad de " ;
    cout << cantidad << " " << nombre ;
    if ( cantidad > 1 ) {
        cout << "s " ;
    }
    cout << " es : \n" ;
    cout << " Agua   : " << totalAgua << " ml \n" ;
    cout << " Azucar : " << totalAzucar << " g \n \n " ;
}


// declaracion de metodos de la Empresa
void Empresa :: init ()  // iniciar las operaciones de la empresa
{
    system("cls") ; // borrar la pantalla

    // calcular cantidad de insumos
    for ( unsigned i = 0 ; i < bebidas.size() ; i++ ){
        bebidas[i].setCantidad() ;
    }

    system("cls"); // borrar pantalla

    // mostrar la informacion de todas las bebidas
    for ( unsigned i = 0 ; i < bebidas.size() ; i++ ){
        bebidas[i].showInfo() ; //
    }

    system("pause") ;  // esperar a que el usuario vea la informacion
    system("cls") ; // borrar la pantalla
    showMenu() ;
}

void Empresa :: showMenu ()
{
    int r;
    cout << "quieres realizar otro calculo? \n" << endl;
    cout << " 1. Si" << endl;
    cout << " 2. No \n" << endl;
    cout << "Escoge una opcion : " ;
    cin >> r ;
    while( cin.fail() || ( r < 1 || r > 2 ) ){ // si lo que ingresa el usuario no es valido
        cin.clear() ;
        cin.ignore( 1000 , '\n' ) ;
        cout << "Escoge una opcion : " ;
        cin >> r ;
        cout << endl ;
    }

    if ( r == 1 ) {  // si quiere volver a ejecutar las operaciones
        init() ; // volver a operar
    }
}
