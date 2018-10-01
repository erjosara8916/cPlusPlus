/****************************************************************
    Autor : Erick Josue Saravia Aragon

    N° Carnet : SA18004

    Fecha : 24-09-2018

    Descripcion : Calcular el salario de los empleados de una
                  empresa en base a las ventas realizadas por estos

    Nota :  La clase cansiones tiene dicho nombre ya que la version
            original contaba con la opcion de reproducir musica
            de fondo y esta ser cambiada a gusto del usuario
            sin embargo debido a que el peso de los archivos de
            audio era exageradamente elevado ( 60 Mb por cansion )
            aumentando considerablemente el peso de la aplicacion,
            por lo que estas canciones fueron reemplazadas por
            sonidos mas livianos, modificando la aplicacion para
            su uso sin embargo por cuestiones de tiempo los nombres
            que antes hacian referencia a las canciones aun se conservan
            aunque cumplan la funcion de referenciar pequeños sonidos.

*****************************************************************/

#include <iostream> // para el uso de entradas y salidas
#include<windows.h> // para usar system(comando de cmd) y PlaySound() ejecutar un sonido
#include<string.h> // para manejo de datos tipo string
#include<array> // para el manejo de arreglos
#include<iomanip> // para la manipulacion de salidas
#include<fstream> // uso de flujo de salida para ficheros


using namespace std; // para abreviar el uso cout y cin

// hacer la peticion de un dato decimal validado
void getDouble ( string msn , double& var )
{
    cout << msn ; // mensaje para indicar al usuario que debe ingresar
    cin >> var ;  // obtencion del dato
    while( cin.fail() ){ // en caso de no ser un valor valido
        cin.clear() ;
        cin.ignore(1000,'\n') ;
        cout << msn ;
        cin >> var ;
        cout << endl ;
    }
}

// obtener un dato entero validado
void getInt ( string msn , int& var )
{
    cout << msn ;// mensaje para indicar al usuario que debe ingresar
    cin >> var ;
    while( cin.fail() ){  // si ingresa un valor no valido
        cin.clear() ;
        cin.ignore(1000,'\n') ;
        cout << msn ;
        cin >> var ;
        cout << endl ;
    }
}

// obtener una cadena de caracteres con espacios
inline void getString ( string msn , istream& ent , string& var )
{
    cout << msn ;
    ent >> ws ;
    getline( ent , var );
}


// Declaracion de la clase de temas (color de fondo y fuente)

class Tema
{
    private :
        string name ; // nombre del tema
        char background ; // color de fondo
        char color ; // color de fuente

    public :
        char code[15] ; // codigo a ejecutar en la terminal de comandos
        Tema ( string , char , char) ;
        string getName () ;
        char getBackground () ;
        char getColor () ;
        void setCode () ; // generar comando que sera ejecutado en la terminal
        void implement () ;  // ejecutar el comando de cambio de color
};

// Definicion de los metodos de la clase Tema
Tema :: Tema ( string nam , char bg , char c )  // valores iniciales
{
    name = nam ;
    background = bg ;
    color = c ;
    setCode();
}

string Tema :: getName ()
{
    return name ;
}

char Tema :: getBackground ( )
{
    return background ;
}

char Tema :: getColor ( )
{
    return color ;
}

void Tema :: setCode ()
{
/*
    convertir dato string a tipo char[] ya que "system()" no acepta valores
    de tipo string
*/
    string comand = "color ";
    for ( unsigned i = 0 ; i <= comand.size() ; i++ ){
        code[i] = comand[i];
    }
    code[6] = background ;
    code[7] = color ;
}

void Tema :: implement()
{
    system(code); // ejecutar comande dentro de "code"
}


// ....................TEMAS DISPONIBLES
const array<Tema,5> TEMAS = {{
    Tema ( " Negro sobre verde " , '2' , '0' ),
    Tema ( " Rojo sobre blanco brillante " , 'f' , 'c' ),
    Tema ( " Blanco sobre Azule " , '1' , '7' ),
    Tema ( " Verde sobre negro " , '0' , '2' ),
    Tema ( " Negro sobre blanco " , '7' , '0' )
}}  ;

// ....................DECLARACION DE LA CLASE EMPLEADO

class Empleado
{
    private :
        string name; // nombre del empleado
        double sales  = 0; // ventas realizadas
        double salary; // salario correspondiente

    public:
        Empleado () ;
        void setName () ;
        void setSales () ;
        void setSalary () ;
        string getName () ;
        double getSales () ;
        double getSalary () ;
} ;

// ............. DEFINICION DE LOS METODOS DE CLASE EMPLEADO
Empleado :: Empleado ( ) {}

void Empleado :: setName ()
{
    getString ( " Ingresa el nombre del empleado : " , cin , name );

}

void Empleado :: setSales ()
{
/*
    dar valor a total de ventas de empleado validado
*/
    do {
        getDouble( " Ingresa las ventas de el empleado : $" , sales );
    } while( sales < 0 ) ;
}

void Empleado :: setSalary ()
{
/*
    asignar el salario correspondiente acorde a sus ventas
*/
    if ( sales > 4000000 ){
            salary = sales * 0.2;
        } else if ( sales > 2500000 ){
            salary = 550000;
        } else if ( sales > 1500000 ){
            salary = 450000;
        } else if ( sales > 1000000 ){
            salary = 320000;
        } else if ( sales > 500000 ){
            salary = 160000;
        } else{
            salary = 80000;
        }
}

string Empleado :: getName ()
{
    return name ;
}

double Empleado :: getSales (  )
{
    return sales ;
}

double Empleado :: getSalary (  )
{
    return salary ;
}

// ..................DECLARACION DE LA CLASE CANCION

class Cancion
{
    private :
        string name ; // nombre de la cancion
        string file ; // nombre del archivo
        string autor ; // autor de la cancion
    public :
        char url[52] ; // ruta de cancion
        Cancion ( string , string , string ) ;
        void setUrl () ; // generar ruta de la cancion
        string getName () ;
        string getAutor () ;
        string getFile() ;
        void play () ; // ejecutar cancion
};

// ........ DEFINICION DE LOS METODOS DE LA CLASE CANCION
Cancion :: Cancion ( string nam , string aut , string fil)
{
    name = nam ;
    autor = aut ;
    file = fil ;
    setUrl () ;

}

/* metodos getter */
string Cancion :: getName ()
{
    return name;
}

string Cancion :: getAutor ( )
{
    return autor ;
}

string Cancion :: getFile ( )
{
    return file ;
}

/* Fin de metodos getter */

void Cancion :: setUrl ()
{
/*
    generar la ruta del archivo que se reproducira
*/
    string PREF = "music\\";
    file = PREF + file;

//  convertir la ruta a tipo char[]
    for ( unsigned i = 0 ; i <= file.size()  ; i++ ){
        url[ i ] = file[ i ];
    }
}

void Cancion :: play ()
{
    PlaySound(TEXT(url),NULL,SND_ASYNC); // reproducir cancion
}

// ......................CANCIONES DISPONIBLES
const array<Cancion,4> CANCIONES = {{
    Cancion( "alerta 1" , "..." , "SD_ALERT_8.wav" ),
    Cancion( "alerta 2" , "..." , "SD_ALERT_9.wav" ),
    Cancion( "alerta 3" , "..." , "SD_ALERT_21.wav" ),
    Cancion( "alerta 4" , "..." , "SD_ALERT_29.wav" )
}} ;

// ...................... DEFINICION DE CLASE SISTEMA
class Programa
{
    private :
        int style; // posicion del tema de colores en la constante COLORES
        int song;// posicion de la cancion de fondo en la constante CANCIONES
        unsigned numEmployees; // numero de empleados ingresados al sistema
        array<Empleado,100> employee; // empleados de la empresa maximo 100
        int answerUser; // respuesta del usuario
        string nameReport;

    public :
        Programa () ;
        void playSong ( int ); // colocar de fondo cancion seleccionada
        void showMenu() ;  // mostrar menu principal
        void setStyle () ; // cambiar colores segun el tema seleccionado
        void changeStyle () ; // seleccionar otro tema
       // void changeSong () ;  // cambiar cancion de fondo
        void addEmployee () ; // agregar un empleado
        void viewEmployee () ; // ver empleado
        void closeProgram () ; // cerrar programa
        void makeReport () ; // hacer reporte
};

Programa :: Programa ()
{
    style = 0; // tema por defecto = el primer elemento en la constante TEMA

    numEmployees = 0 ; // iniciar en cero el numero de empleados registrados ( al iniciar no se a ingresado a nadie )
    playSong( 2 ); // ejecutar cancion de fondo por defecto
    setStyle(); // aplicar tema por defecto
    nameReport = "reporte.txt" ;

    // mostrar la descripcion del sistema
    cout << "............................................................\n \n" ;
    cout << "CALCULA EL SALARIO DE LOS EMPLEADOS DE LA EMPRESA EN BASE \n";
    cout << "AL TOTAL DE VENTAS REALIZADAS \n \n";
    cout << "     Ventas ($)                              Sueldos($) \n";
    cout << "----------------------------------------------------------" << endl;
    cout << "  0 - 500 000 ........................... 80 000\n";
    cout << "  500 001 - 1 000 000 ................... 160 000" << endl;
    cout << "  1 000 001 - 1 500 000 ................. 320 000" << endl;
    cout << "  1 500 001 - 2 500 000 ................. 450 000" << endl;
    cout << "  2 500 001 - 4 000 000 ................. 550 000" << endl;
    cout << "  Mas de 4 000 001 ...................... 20% de las ventas" << endl;
    cout << "---------------------------------------------------------- \n" << endl;
    cout << "..............................................................\n \n" << endl;

    system("pause"); // pausa para que el usuario lea la descripcion
    showMenu(); // mostrar el menu principal
}

// ejecutar cancion seleccionada
void Programa :: playSong ( int n )
{
    song = n ;
    Cancion c = CANCIONES[song]; // definir cual cancion sera ejecutada ( tomado de CANCIONES )
    c.play(); // ejecutar cancion
}

// ejeccutar tema seleccionado
void Programa :: setStyle ()
{
    Tema t = TEMAS[style];// definir cual tema sera implementado ( tomado de TEMAS )
    t.implement(); // implementar el tema
}

// mostrar el menu principal
void Programa :: showMenu ()
{
    system("cls"); // borrar consola

    // opciones del menu
    array<string,5> opciones = {{
        "Agregar empleado" ,
        "Cambiar tema" ,
        "Ver empleado" ,
        "Crear Reporte" ,
        "Salir"
}} ;

    cout << "Que quieres hacer? \n" << endl;

    //mostrar opciones
    for ( unsigned i = 0 ; i < opciones.size() ; i++ ){

        cout << i + 1 << ". " << opciones[i] << endl;
    }

    // pedir respuesta al usuario
    do{
        getInt( "\nElige una opcion : " , answerUser );
    } while ( answerUser < 1 || answerUser > opciones.size() ) ;

    // identificar que quiere el usuario y ejecutar accion correspondiente
    switch ( answerUser ) {
        case 1 :
            addEmployee() ;  //  quiere agregar un nuevo empleado
        case 2 :
            changeStyle() ; //  quiere cambiar el tema de la aplicacion
            break;
        case 3 :
            viewEmployee() ;  // quiere ver el sueldo de un empleado
            break;
        case 4 :
            makeReport() ;
            break;
        case 5 :
            closeProgram() ;
            break;
    }
}

// cambiar tema de la aplicacion
void Programa :: changeStyle ()
{
    system("cls") ;
    cout << "Que tema prefieres? \n" << endl;

    // Mostrar lista de temas disponibles ( elementos en TEMAS )
    for ( unsigned i = 0 ; i < TEMAS.size() ; i++ ){
        Tema t = TEMAS[i];
        cout << i + 1 << ". " << t.getName() << endl;
    }

    // solicitar opcion al usuario
    do{
        getInt( "\nElige un tema : " , answerUser );
    } while ( answerUser < 1 || answerUser > TEMAS.size() ) ;

    style = answerUser - 1; // colocar respuesta en forma de indice ( restar ya que los indices comienzan en 0 )
    setStyle() ; // implementar estilo seleccionado
    playSong(0);
    showMenu () ; // mostrar menu principal
}

// cambiar cancion en reproduccion


// agregar un nuevo empleado
void Programa :: addEmployee ()
{
    system("cls"); // borrar consola

    // definir los datos del empleado
    employee[numEmployees].setName();
    employee[numEmployees].setSales();
    employee[numEmployees].setSalary();
    numEmployees++; // sumar en 1 la cantidad de empleados registrados
    playSong(0) ;
    showMenu() ; // mostrar menu principal
}

// ver el sueldo de un empleado
void Programa :: viewEmployee ()
{
    system("cls"); // borrar consola

    if(numEmployees == 0){ // si no hay empleados que mostrar
        cout << "Aun no has registrado a ningun empleado por favor haslo antes de tomar esta opcion" << endl << endl ;

    } else {

        cout << "De cual empleado quieres saber el sueldo? \n" << endl;

        /*
            mostrar lista de empleados registrados
            ( la cantidad de elementos a mostrar sera igual a numEmployees )
        */
        for ( unsigned i = 0 ; i < numEmployees ; i++ ){
            Empleado e = employee[i];
            cout << i + 1 << ". " << e.getName() << endl;
        }

        // pedir respuesta a usuario
        do{
            getInt("\nElige a un empleado : " , answerUser );
        } while ( answerUser < 1 || answerUser > numEmployees ) ;

        playSong(0) ;
        // colocar respuesta en forma de indice ( restar ya que los indices comienzan en 0
        Empleado e = employee[answerUser-1] ;

        system("cls") ;
        // mostar sueldo de empleado seleccionado
        cout << e.getName() << " vendio : $" << fixed << setprecision(2) << e.getSales();
        cout << "\nSu salario es : $";
        cout << e.getSalary() << endl ;  //


    }
    system("pause"); // pausa para ver la info
    showMenu(); // mostrar menu principal
}

// crear un archivo de texto con la informacion de los empleados
void Programa :: makeReport ()
{

    ofstream report;
    report.open( nameReport.c_str() ) ;
    //si no hubo probleamas al crear el archivo
    if ( ! report.fail() ){

        // cabecera del reporte
        report << " **************************************************************** " << endl ;
        report << "                     SUELDO DE EMPLEADOS                          " << endl ;
        report << " **************************************************************** " << endl << endl ;

        //ingresar todos los registros de los empleados en el reporte
        for ( unsigned i = 0 ; i  < numEmployees ; i++ ){
            report << " Nombre : " << employee[i].getName() << endl ;
            report << " Total de ventas : $ " << fixed << setprecision(2) << employee[i].getSales() << endl ;
            report << " Salario : $ " << employee[i].getSalary() << endl  << endl ;

            if ( i != numEmployees - 1 )    // no colocar tras el ultimo elemento
                report << "----------------------------------------------------------------" << endl << endl ;
        }
    }

    system("cls") ;
    cout << "reporte creado" << endl ;

    playSong(0) ;
    system("pause") ;
    report.close() ;
    showMenu() ;
}
// salir del programa
void Programa :: closeProgram ()
{
    system("cls"); // borrar consola
    cout << "\n Adios ;) \n \n"; // despedida
}


int main()
{
    Programa s = Programa() ; // crear  un nuevo programa
    return 0;
}
