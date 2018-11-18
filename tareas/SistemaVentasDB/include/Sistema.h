#ifndef SISTEMA_H
#define SISTEMA_H

#include <string> // para trabajar con cadenas de texto ( concatencion )
#include <array> // para poder trabajar con arreglos 
#include <mysql.h> // para poder realizar conexiones con bases de datos


using namespace std ; 

class Sistema
{
	public:
		Sistema(); // constructor de la clase 
		
	private:
		int answerUser ; // respuestas del usuario
		array < string , 4 > mainMenu ; // menu principal
		array < string , 2 > addMenu ; // menu para agregar elementos a la base de datos
		array < string , 3 > mosMenu ; // menu para mostrar datos
		string str ; // cadena de texto a utilizar para mensajes
		
		string sql ; // cadena para la creacion de sentencias sql
		MYSQL *conn ; // conexion con la base de datos
		
		void showMenu ( ) ; // mostrar menu principal
		void showAddMenu () ; // mostrar menu de adiciones
		void showMosMenu () ; // mostrar el menu mostrar
 		void addClient () ; // nuevo registro de cliente
		void addProduct () ; // nuevo registro de producto
		void showClients () ; // mostrar clientes
		void showProducts () ; // mostrar productos
		void showSells () ; // mostrar cotizaciones
		void sell () ; // realizar venta de producto
		void registerSell ( int product , int client , int cant ,  float total ) ; 
		void exit() ; // salir del sistema
		
		bool isInTable ( int code , string table , string id  ) ; // verificar si existe el producto
		int selectProduct () ; // seleccionar un producto ( validado )
		int selectClient () ; // seleccionar cliente ( validado )
		float totalSell ( int product , int cant ) ; // calcular el costo de una cantidad de productos 
		
		
};

#endif
