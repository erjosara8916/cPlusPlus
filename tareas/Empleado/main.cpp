/****************************************************************

    Autor : Erick Josue Saravia Aragon

    N� Carnet : SA18004

    Fecha : 2018-10-20

    Descripcion : operar con la informacion del empleado de una empresa

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
    system("cls") ;
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
    system("cls") ;
}

// obtener una cadena de caracteres con espacios
inline void getString ( string msn , istream& ent , string& var )
{
    cout << msn ;
    ent >> ws ;
    getline( ent , var );
    system("cls") ;

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
        string codigo;
        string name ; // nombre del empleado
        int edad ;
        string departamento ;
        string puesto ;
        double salary ; // salario correspondiente
        double isss ; // porcentaje de iss
        double afp ; // porcentaje de afp
        double renta ; // porcentaje de renta
        double salLiquido ; // salario liquido
        double totImpuestos ; // porcentaje de los impuestos respecto al salario
        int nPrestamos = 0;
        void calIsss () ; // calcular isss
        void calAfp () ;  // calcular afp
        void calRenta () ;  // calcular renta
        void calImpuestos () ;

        double totPrestamos = 0 ; // calcular el total de las cuotas de los prestamos

    public:
        Empleado () ;
        void setCodigo() ;
        void setName () ;
        void setAge () ;
        void setDepartamento() ;
        void setPuesto() ;
        void setSalary () ;
        string getName () ;
        double getSalary () ;
        void calSalLiquido () ;  // calcular salario liquido
        void pedPrestamo () ;  // pedir un prestamo
        void showInfo () ; // mostrar la informacion del empleado
} ;

// ............. DEFINICION DE LOS METODOS DE CLASE EMPLEADO
Empleado :: Empleado ( ) {


}

void Empleado :: setName ()
{
    getString ( " Ingresa el nombre del empleado : " , cin , name );

}

void Empleado :: setCodigo ()
{
    getString ( " Ingresa el codigo del empleado : " , cin , codigo );

}

void Empleado :: setDepartamento ()
{
    getString ( " Ingresa el departamento del empleado : " , cin , departamento );

}

void Empleado :: setPuesto ()
{
    getString ( " Ingresa el puesto del empleado : " , cin , name );

}
/**
    colocar la edad del empleado
*/
void Empleado :: setAge() {

    do{
        getInt( " cual es la edad del empleado? : " , edad ) ;
    } while (edad < 18 || edad > 70 ) ; // verificar que el dato ingresado es coherente
}




void Empleado :: pedPrestamo() {
    if (nPrestamos < 2) {
        double pres ;
        do{
            getDouble( " Ingresa el prestamo : $ " , pres ) ;
        } while( pres < 1 ) ;
        double limit = salary * 0.2 ;
        double total = pres + totPrestamos ;
        cout << limit << " " <<total << endl;
        if ( limit > total ){  // si pasa del 20%
            totPrestamos += pres;
            nPrestamos++;
            calSalLiquido() ; // actualizar salario liquido
        } else {
            cout << "No es posible que puedas cobrar este prestamo ya que excede el limite permitido " << endl;
        system("pause") ;
        }
    } else {
        cout << "Ya tienes 5 prestamos no puedes realizar mas" << endl;
        system("pause") ;
    }


}

void Empleado :: setSalary ()
{
/*
    dar valor a total de ventas de empleado validado
*/
    do {
        getDouble( " Ingresa el salario de el empleado : $" , salary );
    } while( salary < 0 ) ;
}

void Empleado :: calIsss () {
    if( salary < 1000 ) {
        isss = salary * 0.03 ;
    } else {
        isss = 30 ;
    }
}

void Empleado :: calAfp () {
    afp = salary * 0.0725 ;
}

void Empleado :: calRenta() {

    if ( salary < 487.61 ) {
        renta = 0 ;
    } else if ( salary < 642.86 ) {
        renta = 17.48 ;
    } else if ( salary < 915.82 ) {
        renta = 32.7 ;
    } else if ( salary < 2058.68 ) {
        renta = 60.00 ;
    } else {
        renta = 288.57 ;
    }
}

void Empleado :: calSalLiquido () {
    calIsss () ;
    calAfp () ;
    calRenta () ;

    // calcular en porcentaje de los impuestos respecto al salario
    totImpuestos =  isss + afp + renta + totPrestamos;

    // calcular salario liquido
    salLiquido = salary - totImpuestos ;
}

string Empleado :: getName ()
{
    return name ;
}



double Empleado :: getSalary (  )
{
    return salary ;
}


/** mostra informacion del empleado */
void Empleado :: showInfo () {
    string msn = "\n\n" ;
        msn += " codigo : " + codigo + "\n" ;
        msn += " nombre : " + name + "\n" ;
        msn += " edad : " + to_string(edad) + "\n" ;
        msn += " departamento : " + departamento + "\n" ;
        msn += " puesto : " + puesto + "\n" ;
        msn += " salario : " + to_string(salary) + "\n" ;
        msn += " isss : " + to_string(isss) + "\n" ;
        msn += " afp : " + to_string(afp) + "\n" ;
        msn += " renta : " + to_string(renta) + "\n" ;
        msn += " numero de prestamos : " + to_string(nPrestamos) + "\n" ;
        msn += " deuda por prestamos : " + to_string(totPrestamos) + "\n" ;
        msn += " descuento total : " + to_string( totImpuestos ) + "\n" ;
        msn += " salario liquido : " + to_string(salLiquido) + "\n" ;
        cout << msn << endl ;
        system("pause") ;
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
        void menuEmployee () ;
};

Programa :: Programa ()
{
    style = 0; // tema por defecto = el primer elemento en la constante TEMA

    numEmployees = 0 ; // iniciar en cero el numero de empleados registrados ( al iniciar no se a ingresado a nadie )
    playSong( 2 ); // ejecutar cancion de fondo por defecto
    setStyle(); // aplicar tema por defecto
    nameReport = "reporte.txt" ;

    // mostrar la descripcion del sistema
    string msn = "\n";
    msn += "--------------------------------------------------------\n\n" ;
    msn += " Gestiona el salario de los empleados de una empresa   \n" ;
    msn += " aplicando el descuento del isss, afp, renta  \n" ;
    msn += " ademas se aplica descuento acorde a los prestamos \n" ;
    msn += " por el empleado. \n\n" ;
    msn += "--------------------------------------------------------\n" ;
    cout << msn << endl;
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
    array<string,4> opciones = {{
        "Agregar empleado" ,
        "Cambiar tema" ,
        "Ver empleado" ,
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
    employee[numEmployees].setCodigo();
    employee[numEmployees].setName();
    employee[numEmployees].setAge();
    employee[numEmployees].setDepartamento();
    employee[numEmployees].setPuesto();
    employee[numEmployees].setSalary();
    employee[numEmployees].calSalLiquido() ;
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
        menuEmployee() ;

        system("cls") ;
        // mostar sueldo de empleado seleccionado



    }
    system("pause"); // pausa para ver la info
    showMenu(); // mostrar menu principal
}

// menu para gestion de empleado
void Programa :: menuEmployee () {
    int e = answerUser-1 ;
    // Indicacion del menu
    cout << "Escoge una opcion \n \n" ;

    // definicion de las opciones disponibles para el menu
    array< string , 2 > opcEmp = {
        "Ver informacion" ,
        "Hacer Prestamo"
    } ;

    // mostrar el menu al usuario
    for ( int i = 0 ; i < opcEmp.size() ; i++ ) {
        cout << i + 1 << " " << opcEmp[i] << "\n" ;
    }

    // pedir la respuesta del usuario
    do{
        getInt( "\n Escoge una de la opciones " , answerUser ) ;
    } while ( answerUser < 1 || answerUser > opcEmp.size() ) ;

    // Verificar que opcion escogi el usuario
    switch( answerUser ) {
        case 1 :
            employee[e].showInfo() ;
            showMenu() ;
            break ;
        case 2 :
            employee[e].pedPrestamo() ;
            showMenu() ;
            break ;
    }
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

