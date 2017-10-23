
                        /*********** ESTRUCTURAS **********/

typedef struct{

    int intIdDuenio;
    char szNombreApellido[50];
    char szDireccion[30];
    char szNumeroTarjetaCredito[30];
    int bEstado;

}eDuenio;

typedef struct{

    char szPatente[6];
    int intMarca;
    int intDuenio;
    int intHoraDeEntrada;
    int bEstado;

}eAutomovil;


typedef struct{

    int intIdMarca;
    float fDineroAcumulado;

}eMarca;

                        /*********** PROTOTIPOS **********/
void inicializarEstados(eDuenio[], int); //inicializar estados en 0
int buscarMismoId(eDuenio[], int, int); //-1 si no hay igual, si no devuelve index
void altaDeDuenio(eDuenio[],int); //Da de alta un duenio
int buscarEspacioLibreDuenios(eDuenio[], int); //busca primer espacio libre y lo devuelve si no devuelve -1

void altaDeAutomovil(eAutomovil[], int, eDuenio[]); //dar alta automovil
int buscarMismaPatente(eAutomovil[], int, char[]); //-1 si no hay igual, si no devuelve index
void inicializarEstadosAutomoviles(eAutomovil[], int); //inicializa estados de autos
int buscarEspacioLibreAutomoviles(eAutomovil[], int); //busca primer espacio libre y lo devuelve si no -1

void mostrarRecaudacionTotalXMarca(eMarca[]); //muestra recaudad por cada marca
void mostrarRecaudacionTotalEstacionamiento(eMarca[]); //muestro ganancia total de estacionamiento
void mostrarDueniosDeAudi(eDuenio[], eAutomovil[], int, int); //mostrar todos los que tienen audi
void mostrarAutosEstacionadosConDueniosXHoraYPatente(eDuenio[], eAutomovil[], int, int); //muestro autos estacionados con sus dueños ordenado por hora de entrada y patente


                        /*********** HARCODEO **********/

void harcodearDuenios(eDuenio[]);
void harcodearAutomoviles(eAutomovil[]);

                        /*********** VALIDAR **********/

int validarRangoEnteros (int, int, int);   //validar si un entero esta en rango
char validarSoloChar (char ,char ,char);      // validar si el char es uno de los deseados
void validarArray(char[], int);                 // validar tamaño de array


                        /*********** MODIFICACION **********/

void modificarNumDeTarjetaDuenios(eDuenio[], int); //modificar numero de tarjeta de dueño


                        /*********** ORDENAR **********/

void ordenarPorHoraPatente(eAutomovil[], int);//ordenar por hora de entrada y patente


                        /*********** EGRESO **********/

/*  egreso de automovil:
    calcular el tiempo de estadia, apartir del ingreso del horario de salida (misma forma q el hs de entrada tener en
    cuenta que el auto no puede permanecer de un dia para el otro dentro del estacionamiento) al mismo tiempo del egreso
    se debe emitir un tiket por pantalla informando: NOMBRE Y APELLIDO del dueño, PATENTE,MARCA y VALOR de estadia

 *   ALPHA ROMEO ___________ 150h
 *   FERRARI _______________ 175h
 *   AUDI __________________ 200h
 *   OTROS _________________ 250h                                                                                                                                                        )
*/

void egresoDeAutomovil(eDuenio[], eAutomovil[], int, int, eMarca[]);


                        /*********** MARCAS **********/

void inicializarMarcas(eMarca[]);


                        /*********** OCUPADO? **********/

int HayAutosEstacionados(eAutomovil[], int); //-1 no hay ningun auto estacionado, 1 si hay
int HayDueniosDeAlta(eDuenio[], int); //-1 si no hay ningun duenio de alta, 1 si hay
