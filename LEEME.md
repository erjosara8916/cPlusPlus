#ACLARACIONES SOBRE LOS PROYECTOS

 ### 1. ESTRUCTURA
 Los proyectos an sido creado en __CodeBlocks__ por lo que todos tienen la siguiente estructura
* **Proyecto**
    * **bin**
        * **debug** ; Aqui se  guarda la aplicacion ya compilada y los recursos que esta necesite
            * **proyecto.exe**
            * ...
            
    * **include** : ubicacion de los prototipos
        * **cabecera.h**
        * ...
    * **obj** : generada por el editor 
        * **debug**
            * **src**
                * **Proyecto.o**
            * **main.o**
            * ...
    * **src** : ubicacion de las implementaciones
        * **cabecera.cpp**
    * **proyecto.cbp** : configuraciones del proyecto ( codeblocks )
    * **proyecto.depend**
    * **proyecto.layout**
    * **main.cpp** : archivo principal de la aplicacion

### 2. EDICION
El codigo puede ser visto en cualquier editor sin embargo se recomienda el uso de **codeblocks** ya que podras ver y editar el codigo sin hacer configuracion alguna