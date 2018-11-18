# DESCRIPCION DEL TRABAJO
***
     Sistema conectado a una base de datos con la cual interactua en todas sus operaciones. 
La aplicacion cuenta con las siguientes opciones : 
* **Agregar** ( agregar nuevos registros de clientes y productos a la base de datos )
    * Cliente
    * Producto
* **Mostrar** ( mostrar los registros en la base de datos )
    * Clientes 
    * Productos
    * Ventas
* **Hacer Venta** ( Realizar la venta de un producto )
* **Salir** ( Salir de el sistema ) 
***
# ENTORNO DE DESARROLLO
***
* **herramientas**
    * dev-c++ 5.11
    * wampserver64x


* **generales**

![ configuraciones del compilador](
        cPlusPlus/tareas/SistemaVentasDB/img/cofig.jpg "imgen")
    ![ configuracion de loibrerias](
        cPlusPlus/tareas/SistemaVentasDB/img/config2.jpg "imgen")
    ![ configuracion de cabeceras](cPlusPlus/tareas/SistemaVentasDB/img/config3.jpg "imgen")

* **Del proyecto**
![ configuracion de cabeceras](cPlusPlus/tareas/SistemaVentasDB/img/config4.jpg "imgen")

***
# PREPARANDO EL ENTORNO
***
* Inicie los servicios de wamp server
* Ingrese desde el navegador a phpMyAdmin
* Seleccione la opcion de importar, tomando el archivo sysventas.sql como objetivo
* Ahora puede revisar y ejecutar la aplicacion 