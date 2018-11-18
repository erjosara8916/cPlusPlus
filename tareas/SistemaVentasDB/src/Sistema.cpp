#include "../include/Sistema.h" // inclusion del prototipo

#include <iostream> // para poder trabajar con los flujos de entrada y salida
#include <string> // para trabajar con cadenas de texto ( concatencion )
#include <array> // para poder trabajar con arreglos 
#include <mysql.h> // para poder realizar conexiones con bases de datos

#include "../include/OperacionesBasicas.h" // para poder realizar operaciones comunes



Sistema::Sistema()
{
	msn("	HOLA BIENVENIDO AL SISTEMA DE VENTAS	") ;
	// definir las opciones del menu principal
	mainMenu = {
		"Agregar " ,
		"Mostrar" ,
		"Hacer venta " ,
		"Salir"
	} ;
	
	// definir las opciones del menu "agregar"
	addMenu = {
		"Cliente" , 
		"Producto"
	} ;
	
	// definir las opciones del menu de mostrar
	mosMenu = {
		"Clientes" ,
		"Productos" ,
		"ventas"
	} ;
	
	
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
	mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","sysventas",0,0,0);
    
    if ( conn = NULL ) { // no se pudo realizar la conexion con la base de datos
    
    	msn( "no se a podido realizar la conexion con la base de datos" ) ;

	} else { // si se pudo realizar la conexion asi que prosigue con el sistema
		showMenu() ;
	}
    
	
}

// mostrar menu principal
void Sistema :: showMenu() {
    system("cls"); // borrar pantalla

    // Indicacion del menu
    cout << "que quieres hacer? \n \n" ;

    // mostrar el menu al usuario ( las opciones en el arreglo menu1 )
    for ( int i = 0 ; i < mainMenu.size()  ; i++ ) {

        cout << i + 1 << " -> " << mainMenu[i] << "\n" ;

    }

    // pedir la respuesta del usuario
    do{

        getInt( "\n Escoge una de la opciones : " , answerUser ) ;

    } while ( answerUser < 1 || answerUser > mainMenu.size() ) ; // asgura una respuesta coherente

    // Verificar que opcion escogio el usuario
    switch( answerUser ) {

        case 1 : // usuario quiere crear tiket
            showAddMenu() ; // mostrar el menu de "agregar"
            showMenu() ; // mostrar menu principal
            break ;
            
        case 2 :// usuario quiere llamar tiket
            showMosMenu() ; // mostrar el menu "mostrar informacion"
            showMenu() ; // mostrar menu principal
            break ;

        case 3 : // usuario quiere mostrar a persona atendida actualmente   
            sell() ; // realizar una venta
            showMenu() ; // mostrar menu principal
            break ;

        default : // usuario no quiere hacer mas en el sistema
			exit() ;            
            break ;
    }

}


// mostrar menu "agregar" 
void Sistema :: showAddMenu() {
    system("cls"); // borrar pantalla

    // Indicacion del menu
    cout << "que quieres agregar? \n \n" ;

    // mostrar el menu al usuario ( las opciones en el arreglo menu1 )
    for ( int i = 0 ; i < addMenu.size()  ; i++ ) {

        cout << i + 1 << " -> " << addMenu[i] << "\n" ;

    }

    // pedir la respuesta del usuario
    do{

        getInt( "\n Escoge una de la opciones : " , answerUser ) ;

    } while ( answerUser < 1 || answerUser > addMenu.size() ) ; // aseura una respuesta coherente

    // Verificar que opcion escogio el usuario
    switch( answerUser ) {

        case 1 : // usuario quiere crear tiket
            addClient() ;
           
            break ;

        case 2 :// usuario quiere llamar tiket
			addProduct() ;
            break ;
    }

}

// mostrar menu "mostrar" ( informacion de la base de datos )
void Sistema :: showMosMenu() {
    system("cls"); // borrar pantalla

    // Indicacion del menu
    cout << "que quieres hacer? \n \n" ;

    // mostrar el menu al usuario ( las opciones en el arreglo menu1 )
    for ( int i = 0 ; i < mosMenu.size()  ; i++ ) {

        cout << i + 1 << " -> " << mosMenu[i] << "\n" ;

    }

    // pedir la respuesta del usuario
    do{

        getInt( "\n Escoge una de la opciones : " , answerUser ) ;

    } while ( answerUser < 1 || answerUser > mosMenu.size() ) ; // aseura una respuesta coherente

    // Verificar que opcion escogio el usuario
    switch( answerUser ) {

        case 1 : // usuario quiere crear tiket

            showClients() ;
            break ;

        case 2 :// usuario quiere llamar tiket

			showProducts() ;
            break ;

        case 3 : // usuario quiere mostrar a persona atendida actualmente

           	showSells() ;
            break ;
    }

}

// agregar un nuevo cliente al sistema
void Sistema :: addClient() {
	
	system("cls") ; // borrar consola
	
	string name ; // nombre de cliente
	string lastName ; // apellido cliente
	string tel ; // telefono cliente


  	// pedir los datos del nuevo cliente
    getString( " ingresa el nombre del nuevo cliente : " , cin , name ) ;
    getString( " ingresa el apellido del nuevo cliente : " , cin , lastName ) ;
    getString( " ingresa el telefono del nuevo cliente : " , cin , tel ) ;
    
    // crear la sentencia sql
	sql = "INSERT INTO clientes  VALUES (NULL, '" ;
    sql += name + "','" + lastName + "','" + tel + "') ;" ;
	
	// conectar a base de datos y realizar la cosnsulta
	MYSQL *conn ;
    MYSQL  mysql ;
    mysql_init(&mysql) ;
    conn=mysql_real_connect(&mysql,"localhost","root","","sysventas",0,0,0);     
	mysql_query( conn , sql.c_str()  ) ;	
	mysql_close(conn); // cerrar la conxion con la base de datos
}

// agregar un nuevo producto a la base de datos
void Sistema :: addProduct () {
	
	system( "cls" ) ; // borrar consola
	
	string name ; // nombre de producto
	float price ; // precio del producto
  
  	//pedir los datos del nuevo producto
    getString( " ingresa el nombre del nuevo producto : " , cin , name ) ;
    getFloat( " ingresa el precio del nuevo producto : " , price ) ;
    
    // crar consulta sql
	sql = "INSERT INTO productos  VALUES (NULL, '" ;
    sql += name + "','" + to_string(price) +  "') ;" ;
    
    // conectar y hacer consulta a la base de datos
    MYSQL *conn ;
    MYSQL  mysql ;
    mysql_init( &mysql ) ;
    conn=mysql_real_connect( &mysql , "localhost" , "root" , "" , "sysventas" , 0 , 0 , 0 );     
	mysql_query( conn , sql.c_str() ) ;	
	mysql_close( conn ); // cerrar la conexion 
}

// mostrar clientes 
void Sistema :: showClients () {
	system("cls") ; // borrar consola
	
	
    string cod ; // codigo cliente
    string nomb ; // nombre cliente
    string lName ; // apellido cliente
    string telefono ; // telefono cliente
    
    // conexion y consulta a la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init( &mysql ) ;
    conn=mysql_real_connect( &mysql , "localhost" , "root" , "" , "sysventas" , 0 , 0 , 0 );
    mysql_query ( conn , "select * from clientes" ) ;
    res=mysql_store_result( conn );
    
    // trabajar con los resultados de la consulta
    while( ( row = mysql_fetch_row ( res ) ) != NULL )
    {
       // recoger datos del cliente y asignarlos a las varibles para mostrarlos
       cod = row[0] ; 
       nomb = row[1] ;
       lName = row[2] ;
       telefono = row[3] ;
       
       // generar mensaje a mostrar en pantalla
       string  s = "\n Codigo : " + cod + " \n" ;
       		   s += " Nombre : " + nomb + "\n" ;
       		   s += " Apellido : " + lName + "\n" ;
       		   s += " Telefono : " + telefono +"\n \n" ;
       cout << s ;
    }
    
	mysql_close(conn);	
	system("pause") ;
}

// mostrar productos disponibles 

void Sistema :: showProducts () {
	
	system("cls") ;
	
	
    string cod ; // codigo producto
    string nomb ; // nombre producto
    string prec ; // cliente producto
    
    // conexion y consulta a la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect( &mysql , "localhost" , "root" , "" , "sysventas" , 0 , 0 , 0 );
    mysql_query( conn , "select * from productos" ) ;
    res = mysql_store_result ( conn ) ;
    
    
    while((row=mysql_fetch_row(res))!=NULL)
    {
       cod = row[0] ;
       nomb = row[1] ;
       string prec = row[2] ;
       
       string  s = "\n Codigo : " + cod + " \n" ;
       		   s += " Nombre : " + nomb + "\n" ;
       		   s += " Precio : $" + prec + "\n" ;
       	/*
		   
       		   s += " Apellido : " + lName + "\n" ;
       		   s += " Telefono : " + telefono +"\n \n" ;
		   */
       cout << s ;
    }
	mysql_close( conn );	
	system( "pause" ) ;
	
}

// mostrar ventas
void Sistema :: showSells () {
	
	string cod ; // codigo de la venta
	string prod ; // nombre  del producto
	string cant ; // cantidad vendida
	string nom ; // nombre del cliente
	string ape ; // apellido del cliente
	string date ; // fecha de la venta ( y hora )
	string total ; // total de la venta
	/*  
		conexion con la base de datos
	*/
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","sysventas",0,0,0);
    
    // generar codigo sql para la consulta
    sql = "SELECT `ventas`.`codventa` , `productos`.`nombre` , `ventas`.`catidad` " ;
	sql += " , `clientes`.`nombre`, `clientes`.`apellido` , `ventas`.`fecha` , `ventas`.`total`  FROM `ventas` ";
	sql += ", `productos` , `clientes` WHERE `ventas`.`codpro` = `productos`.`codpro` ";
	sql += "AND `ventas`.`codcliente` = `clientes`.`codcliente` ; ";
	
	mysql_query ( conn , sql.c_str() ) ; // ejecutar consulta
	res = mysql_store_result( conn );
	
    while( ( row = mysql_fetch_row( res ) ) != NULL )
    {
    	// guardar datos de la venta
    	cod = row[0] ;
    	prod = row[1] ;
    	cant = row[2] ;
    	nom = row[3] ;
    	ape = row[4] ;
    	nom += " " + ape ;
    	date = row[5] ;
    	total = row[6] ;
    	str = "\n Codigo : " + cod + "\n" ;		
    	str += "\n Producto : " + prod + "\n" ;
		str += "\n Cantdad : " + cant + "\n" ;
		str += "\n comprador : " + nom + "\n" ;
		str += "\n fecha y hora : " + date + "\n" ;
		str += "\n total : $" + total + "\n" ;
		msn(str) ;
	} 
}

// realizar venta
void Sistema :: sell() {
	
	// conexion de la base de datos
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","sysventas",0,0,0);

    
    int product ; // codigo del producto a vender
    int client ; // codigo del cliente 
    int cant ; // cantidad de la venta
    float total ; // total de la venta

	
	product = selectProduct() ; // seleciona producti a vender
	client = selectClient() ; // selecciona quien es el comprador
	
	system("cls") ; 
	
	// preguntar cantidad a vender
	do{
		getInt( " Escribe la cantidad a vender : " , answerUser ) ;
	} while ( answerUser < 1 ) ;
	
	cant = answerUser ; // definir cantidad a a vender 
	total = totalSell( product , cant ) ; // calcular el total de la venta
	registerSell ( product , client , cant , total ) ; // regisrar venta en la base de datos
	
    mysql_close( conn ); // cerrar la conexion
}

// seleccionar un producto
int Sistema :: selectProduct() {

	system("cls") ;

	int id ; // identificador del producto

	// conexion  con la base de datos
	MYSQL *conn ;
    MYSQL  mysql ;
    MYSQL_RES *res ;
    MYSQL_ROW row ;
    mysql_init( &mysql ) ;
    conn = mysql_real_connect( &mysql , "localhost" , "root" , "" , "sysventas" , 0 , 0 , 0 ) ;

	string cod ; // almacena temporalmente cod de producto
    string nomb ; // almacena temporalmente nombre de producto
    string prec ; // almacena temporalmente precio de producto
	str = " que producto quieres vender" ;
    mysql_query(conn,"select * from productos");
    res=mysql_store_result(conn);
     
	// mostrar lsita de productos disponibles   
    while((row=mysql_fetch_row(res))!=NULL)
    {
      
       cod = row[0] ; 
       nomb = row[1] ; 
       string prec = row[2] ; 
       
       string  s = "\n "+ cod + ". " + nomb + " - $" + prec; 
       		        	
       cout << s ;
 
    }

	// solicitar al usuario escoger un producto
   	do{
   		 getInt( "\n\n Escribe un numero : ", answerUser ) ;
	} while ( !isInTable( answerUser , "productos" , "codpro" ) ) ;

    id = answerUser ; // definir que producto se vendera

	return id ; // retornar identificador del producto escogido

}

// seleccionar un cliente
int Sistema :: selectClient() {
	system("cls") ;

	int id ;

	// cnexion con la base de datos	
	MYSQL *conn ;
    MYSQL  mysql ;
    MYSQL_RES *res ;
    MYSQL_ROW row ;
    mysql_init(&mysql) ;
    conn=mysql_real_connect( &mysql , "localhost" , "root" , "" , "sysventas" , 0 , 0 , 0 ) ;
	
	string codCli ; // almacena temporalmente cod de cliente
    string nomCli ; // almacena temporalmente nombre de cliente
	string apeCli ; // almacena temporalmente apellido de cliente
	
	cout << "Que cliente realizara la compra?\n" ;
    
	mysql_query( conn , "select * from clientes" ) ;
    res = mysql_store_result( conn ) ;
    
	// mostrar lista de posibles clientes        
    while((row=mysql_fetch_row(res))!=NULL)
    {
 		codCli = row[0] ;
		nomCli = row[1] ;
		apeCli = row[2] ;         
       
	   string  s = "\n "+ codCli + ". " + nomCli + "  " + apeCli + "\n" ; 
       		        	
       cout << s ;
 
    }
    
    // solicitar el escoger a un cliente
    do{
    	getInt("Escribe un numero : " , answerUser ) ;
	} while ( !isInTable( answerUser , "clientes" , "codcliente" ) ) ;
	id = answerUser ;
	
	return id ; // retornarnel identificador del cliente escogido
}

// calcular el costo de una cantidad de productos
float Sistema :: totalSell ( int product , int cant ) {
	float total ;	
	string price ;
	
	//conexion con la base de datos
	// cnexion con la base de datos	
	MYSQL *conn ;
    MYSQL  mysql ;
    MYSQL_RES *res ;
    MYSQL_ROW row ;
    mysql_init(&mysql) ;
    conn=mysql_real_connect( &mysql , "localhost" , "root" , "" , "sysventas" , 0 , 0 , 0 ) ;
    
    // generar el codigo sql
    sql = "SELECT `productos`.`precio` FROM `productos` WHERE `productos`.`codpro` = " + to_string(product) + " ;" ;
    
    mysql_query( conn , sql.c_str() ) ; // ejecutar consulta
    
    // guardar el precio delprodcuto
    res = mysql_store_result(conn);
    while( ( row = mysql_fetch_row( res ) ) != NULL )
    {
    	price = row[0] ;
	}
	
	total = cant * ( ( float )atof( price.c_str() ) ) ; // multiplicar precio por cantidad 
	 
	return total ; // retornar el total
}

// registrar venta 
void Sistema :: registerSell ( int product , int client , int cant , float total ){
	
	// conexion con la base de datos
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init( &mysql );
    
	conn = mysql_real_connect( &mysql , "localhost" , "root" , "" , "sysventas" , 0 , 0 , 0 );
    
    sql = "INSERT INTO `ventas` VALUES ( NULL , " + to_string( product ) + " , " + to_string( cant )  ;
	sql += " , CURRENT_TIMESTAMP , " + to_string( client ) + " , " + to_string( total ) + "  ) ;" ;
	
	mysql_query( conn , sql.c_str() ); // ejecutar consulta
}

// verificar si un elemento se encuentra en la tabla seleccionada
bool Sistema :: isInTable ( int code , string table , string id) {
	
	bool exist = false ; // se asume que el dato no existe en la base de datos
    
    // conexion con la base de datos
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init( &mysql );
    
	conn = mysql_real_connect( &mysql , "localhost" , "root" , "" , "sysventas" , 0 , 0 , 0 );
    
	// generar consulta a la base de datos
    sql = "SELECT * FROM `" + table + "` where `" + id + "` = " + to_string(code) + ";";
    
    mysql_query( conn , sql.c_str() ) ; // ejecutar consulta
    res = mysql_store_result( conn ) ;
    
    // verificar si existe el elemento
	while((row=mysql_fetch_row(res))!=NULL)
    {
    	exist = true ;		
	}
    
    return exist ; // retornar el reultado de la comprobacion
}

// salir del sistema 
void Sistema :: exit () {
	msn("  			ADIOS ;)") ; // salir del sistema
}
