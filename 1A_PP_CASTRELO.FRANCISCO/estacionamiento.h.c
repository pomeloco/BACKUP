#include "estacionamiento.h"
#include <stdio.h>
#include <stdlib.h>

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4


                                /**desarrolllos**/



                        /*********** DUENIOS **********/

void altaDeDuenio(eDuenio Duenios[],int tam){

    int intAux;
    char szAuxString[80];
    int intIndex;

    intIndex = buscarEspacioLibreDuenios(Duenios, tam);

    printf("Ingrese ID duenio: ");
    scanf("%d", &intAux);
    intAux = validarRangoEnteros(1000,1,intAux);

    if(intIndex!=-1){

        if(buscarMismoId(Duenios,tam,intAux)==-1){

            Duenios[intIndex].intIdDuenio=intAux;

            printf("Ingrese nombre y apellido: ");
            fflush(stdin);
            gets(szAuxString);
            //scanf("%s", &Duenios[intIndex].szNombreApellido);
            //gets(Duenios[intIndex].szNombreApellido);

            //VALIDAR
            validarArray(szAuxString,50);

            strcpy(Duenios[intIndex].szNombreApellido, szAuxString);

            printf("Ingrese su direccion: ");
            fflush(stdin);
            gets(szAuxString);
            //scanf("%s", &Duenios[intIndex].szDireccion);
            //gets(Duenios[intIndex].szDireccion);

            //VALIDAR
            validarArray(szAuxString,30);

            strcpy(Duenios[intIndex].szDireccion, szAuxString);

            printf("Ingrese su numero de tarjeta de credito: ");
            fflush(stdin);
            gets(szAuxString);

            //VALIDAR
            validarArray(szAuxString,30);


            strcpy(Duenios[intIndex].szNumeroTarjetaCredito, szAuxString);

            Duenios[intIndex].bEstado = 1;

        }else{

            printf("la id ya existe!");
        }

    }else{

            printf("no hay espacio!");
    }

}//alta duenio

int buscarMismoId(eDuenio Duenios[], int tam, int intAuxId){

    int bEsValido=-1;

    for(int i=0;i<tam;i++){

        if(intAuxId==Duenios[i].intIdDuenio){

            bEsValido=i;
        }
    }

    return bEsValido;
}//buscar mismo id

void inicializarEstados(eDuenio Duenios[], int tam){

    for(int i=0;i<tam;i++){

        Duenios[i].bEstado=0;
    }

}//inicializar estados

int buscarEspacioLibreDuenios(eDuenio Duenios[], int tam){

    int intIndex=-1;

    for(int i=0;i<tam;i++){

        if(Duenios[i].bEstado==0){

            intIndex=i;
            break;
        }
    }

    return intIndex;
}//buscar espacio libre duenios



                        /*********** AUTOMOVILES **********/

void altaDeAutomovil(eAutomovil Automovil[], int tam, eDuenio Duenios[]){

    char szAuxString[20];
    int intAux;
    int intIndex;


    intIndex = buscarEspacioLibreAutomoviles(Automovil, tam);

    printf("Ingrese la patente: ");
    fflush(stdin);
    scanf("%s", &szAuxString);

    validarArray(szAuxString,6);

    if(intIndex!=-1){

        if(buscarMismaPatente(Automovil,tam,szAuxString) == -1){

            strcpy(Automovil[intIndex].szPatente,szAuxString);

            printf("Ingrese marca del auto:\n\t1Alpha romeo\n\t2.Ferrari\n\t3.Audi\n\t4.Otro\n");
            scanf("%d", &intAux);
            //VALIDAR
            intAux=validarRangoEnteros(4,1,intAux);

            Automovil[intIndex].intMarca=intAux;

            printf("Ingrese ID del duenio: ");
            fflush(stdin);
            scanf("%d", &intAux);

            while(buscarMismoId(Duenios,tam, intAux)==-1){


            printf("el id no existe!\n reingrese:");
            fflush(stdin);
            scanf("%d", &intAux);

            }

            Automovil[intIndex].intDuenio=intAux;

            printf("ingrese hora de entrada (formato 24hs): ");
            //scanf("%d", &Automovil[intIndex].intHoraDeEntrada);
            scanf("%d", &intAux);

            //VALIDAR
            intAux=validarRangoEnteros(23,0,intAux);

            Automovil[intIndex].intHoraDeEntrada = intAux;

            Automovil[intIndex].bEstado=1;
        }else{

            printf("la patente ya existe!");
        }

    }else{

        printf("no hay lugar!");
    }


}//dar alta Automovil

int buscarMismaPatente(eAutomovil Automoviles[], int tam, char szAuxString[]){

    int bEsValido=-1;

    for(int i=0;i<tam;i++){

        if(strcmp(Automoviles[i].szPatente,szAuxString)==0 && Automoviles[i].bEstado==1){

            bEsValido=i;
        }
    }

    return bEsValido;
}

void inicializarEstadosAutomoviles(eAutomovil Automoviles[], int tam){

    for(int i=0;i<tam;i++){

        Automoviles[i].bEstado=0;
    }
}

int buscarEspacioLibreAutomoviles(eAutomovil Automoviles[], int tam){

    int intIndex=-1;

    for(int i=0;i<tam;i++){

        if(Automoviles[i].bEstado==0){

            intIndex=i;
            break;
        }
    }

    return intIndex;
}


                        /*********** MOSTRAR **********/

void mostrarAutosEstacionadosConDueniosXHoraYPatente(eDuenio Duenios[], eAutomovil Automoviles[], int tamDuenios, int tamAutomoviles){

    printf("*************************************************\n************DATOS AUTO y DATOS DUENIO************\n*************************************************\n\n\n");
    for(int i=0;i<tamAutomoviles;i++){

        for(int j=0;j<tamDuenios;j++){

            if(Automoviles[i].bEstado==1 && Duenios[j].bEstado==1){
                if(Automoviles[i].intDuenio == Duenios[j].intIdDuenio){

                    //printf("DATOS AUTO:\n");
                    printf("Patente: %s\t\tHorario de entrada: %dhs.\n", Automoviles[i].szPatente, Automoviles[i].intHoraDeEntrada);

                    switch(Automoviles[i].intMarca){

                        case ALPHA_ROMEO:
                                            printf("Marca: Alpha romeo");
                                            break;

                        case FERRARI:
                                            printf("Marca: Ferrari");
                                            break;

                        case AUDI:
                                            printf("Marca: Audi");
                                            break;

                        case OTRO:
                                            printf("Marca: Otra");
                                            break;

                    }//switch

                    //printf("\n\nDATOS DEL DUENIO: \n");
                    printf("\n\nNombre y Apellido: %s\nDireccion: %s\nNumero de tarjeta de credito: %s", Duenios[j].szNombreApellido, Duenios[j].szDireccion, Duenios[j].szNumeroTarjetaCredito);
                    printf("\n-------------------------------------------------------------------------------\n");
                }
        }

        }//for dueños

    }//for automoviles


}// mostrar Autos con dueños

void mostrarDueniosDeAudi(eDuenio Duenios[], eAutomovil Automoviles[], int nTamDuenios, int nTamAutomoviles){

    printf("**Duenios de Automoviles Audi**\n ");

    for(int i=0; i<nTamAutomoviles; i++){

        for(int j=0; j<nTamDuenios; j++){

            if(Automoviles[i].intMarca == AUDI && Automoviles[i].bEstado == 1 && Duenios[j].bEstado == 1){

                printf("\n----------------------------------------\n");
                printf("Patente: %s\t\tHorario de entrada: %dhs.\n", Automoviles[i].szPatente, Automoviles[i].intHoraDeEntrada);
                printf("\nNombre y Apellido: %s\nDireccion: %s\nNumero de tarjeta de credito: %s", Duenios[j].szNombreApellido, Duenios[j].szDireccion, Duenios[j].szNumeroTarjetaCredito);
                printf("\n----------------------------------------\n");
            }

        }//for dueños
    }//for automoviles

}

void mostrarRecaudacionTotalXMarca(eMarca Marcas[]){

    printf("*************RECAUDACION POR MARCA*********\n");

    for(int i=0;i<4;i++){

        switch(Marcas[i].intIdMarca){

        case 1:
                printf("Marca: Alpha Romeo\tRecaudado:%.2f",Marcas[i].fDineroAcumulado);
                break;


        case 2:
                printf("\nMarca: Ferrari\tRecaudado:%.2f",Marcas[i].fDineroAcumulado);
                break;

        case 3:
                printf("\nMarca: Audi\tRecaudado:%.2f",Marcas[i].fDineroAcumulado);
                break;

        case 4:
                printf("\nMarca: Otro\tRecaudado:%.2f\n",Marcas[i].fDineroAcumulado);
                break;
        }

    }

}

void mostrarRecaudacionTotalEstacionamiento(eMarca Marcas[]){

    float fGananciaTotal=0;

    for(int i=0 ; i<4; i++){

        fGananciaTotal = Marcas[i].fDineroAcumulado+fGananciaTotal;
    }

    printf("\nGanancia Acumulada: %.2f\n", fGananciaTotal);

}

                        /*********** HARCODEAR **********/

void harcodearDuenios(eDuenio Duenios[]){

    Duenios[0].intIdDuenio=123;
    strcpy(Duenios[0].szNombreApellido,"Juan Gimenez");
    strcpy(Duenios[0].szDireccion, "Av mitre 700");
    strcpy(Duenios[0].szNumeroTarjetaCredito,"1234");
    Duenios[0].bEstado=1;

    Duenios[1].intIdDuenio=124;
    strcpy(Duenios[1].szNombreApellido,"Carlos Rodriguez");
    strcpy(Duenios[1].szDireccion, "Av roca 700");
    strcpy(Duenios[1].szNumeroTarjetaCredito,"12345");
    Duenios[1].bEstado=1;
}

void harcodearAutomoviles(eAutomovil Automoviles[]){

    Automoviles[0].intDuenio=123;
    Automoviles[0].intMarca = AUDI;
    Automoviles[0].intHoraDeEntrada=15;
    Automoviles[0].bEstado=1;
    strcpy(Automoviles[0].szPatente, "123ABC");

    Automoviles[1].intDuenio=123;
    Automoviles[1].intMarca = FERRARI;
    Automoviles[1].intHoraDeEntrada=18;
    Automoviles[1].bEstado=1;
    strcpy(Automoviles[1].szPatente, "123ABD");

    Automoviles[2].intDuenio=124;
    Automoviles[2].intMarca = ALPHA_ROMEO;
    Automoviles[2].intHoraDeEntrada=23;
    Automoviles[2].bEstado=1;
    strcpy(Automoviles[2].szPatente, "253ABC");


}


                        /*********** VALIDACIONES **********/

int validarRangoEnteros(int nMaximo, int nMinimo, int nNumero){

//int bEsValido =0;

        while(nNumero < nMinimo || nNumero > nMaximo){
            printf("rango erroneo %d - %d, reingrese:", nMinimo, nMaximo);
            fflush(stdin);
            scanf("%d", &nNumero);
        }

return nNumero;

}// validar rango enteros

char validarSoloChar(char cOpcUno, char cOpcDos, char cCharUsuario){

        while(cCharUsuario != cOpcUno && cCharUsuario != cOpcDos){

            printf("rta erronea, reingrese %c/%c:", cOpcUno, cOpcDos);
            fflush(stdin);
            cCharUsuario = tolower(getchar());
        }

return cCharUsuario;
}

void validarArray(char szArray[], int nTamMaximo){

    while(strlen(szArray)> nTamMaximo){

        printf("cadena demasiado larga, reingrese: ");
        fflush(stdin);
        gets(szArray);
    }

}//validar un array


                        /*********** MODIFICACION **********/
void modificarNumDeTarjetaDuenios(eDuenio Duenios[], int tam){

int nAuxInt,nIgual;
char szAuxNewTarjeta[50], cOpcionModif; //tarjeta max 30

    printf("Ingrese ID a modificar: ");
    fflush(stdin);
    scanf("%d", &nAuxInt);

    nIgual = buscarMismoId(Duenios, tam, nAuxInt);

    if(nIgual != -1){

        printf("***Duenio encontrado***\n.Nombre y Apellido: %s\n.Numero de tarjeta: %s", Duenios[nIgual].szNombreApellido, Duenios[nIgual].szNumeroTarjetaCredito);

        printf("\nIngrese nuevo numero de tarjeta: ");
        fflush(stdin);
        gets(szAuxNewTarjeta);

        validarArray(szAuxNewTarjeta,30);

        printf("\nSeguro que desea modificar? s/n: ");
        fflush(stdin);
        cOpcionModif=tolower(getchar());

        validarSoloChar('s','n',cOpcionModif);

        if(cOpcionModif == 's'){

            strcpy(Duenios[nIgual].szNumeroTarjetaCredito, szAuxNewTarjeta);
        }else{

            printf("\nNo se realizaron los cambios");
        }

    }else{

        printf("\nID no encontrada");
    }

}//modificacion

                        /*********** ORDENAR **********/
void ordenarPorHoraPatente(eAutomovil Automoviles[], int nTamEstacionamiento){

eAutomovil eAutomovilAux;

    for(int i=0; i<nTamEstacionamiento-1; i++){

        for(int j=i+1; j<nTamEstacionamiento; j++){

            if(Automoviles[i].intHoraDeEntrada > Automoviles[j].intHoraDeEntrada || strcmp(Automoviles[i].szPatente ,Automoviles[j].szPatente)>0){

                eAutomovilAux = Automoviles[i];
                Automoviles[i] = Automoviles[j];
                Automoviles[j] = eAutomovilAux;
            }


        }//for J
    }//for I

}//ordenar por hora de entrada y patente



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

void egresoDeAutomovil(eDuenio Duenios[],eAutomovil Automoviles[],int tamDuenios,int tamEstacionamiento, eMarca Marca[]){

int nPrecioAlphaRomeoXHora=150 ,nPrecioFerrariXHora=175, nPrecioAudiXHora=200, nPrecioOtroXHora=250;
int nHorarioEgresoAutomovil, nIndex, nDiferenciaHorarioEgresoIngreso;
float fPrecioDeSalida;
char szAuxString[10];

    printf("Ingrese patente de auto a egresar: ");
    fflush(stdin);
    gets(szAuxString);

    validarArray(szAuxString,6);

    nIndex = buscarMismaPatente(Automoviles, tamEstacionamiento, szAuxString); //-1 si no encuentra

    if(nIndex!=-1){

        printf("Ingrese horario de egreso: ");
        scanf("%d", &nHorarioEgresoAutomovil);
        nHorarioEgresoAutomovil = validarRangoEnteros(23,0,nHorarioEgresoAutomovil);

        while(nHorarioEgresoAutomovil < Automoviles[nIndex].intHoraDeEntrada){

            printf("No puede pasar mas de un dia, reingrese: ");
            scanf("%d", &nHorarioEgresoAutomovil);
            nHorarioEgresoAutomovil = validarRangoEnteros(23,0,nHorarioEgresoAutomovil);

        }//no puede ser menor a la hora de ingreso

        nDiferenciaHorarioEgresoIngreso = nHorarioEgresoAutomovil - Automoviles[nIndex].intHoraDeEntrada;

        switch(Automoviles[nIndex].intMarca){

            case 1:
                    fPrecioDeSalida= (float)nDiferenciaHorarioEgresoIngreso*nPrecioAlphaRomeoXHora;
                    Marca[0].fDineroAcumulado = Marca[0].fDineroAcumulado+fPrecioDeSalida;
                    break;

            case 2:
                    fPrecioDeSalida= (float)nDiferenciaHorarioEgresoIngreso*nPrecioFerrariXHora;
                    Marca[1].fDineroAcumulado = Marca[1].fDineroAcumulado+fPrecioDeSalida;
                    break;

            case 3:
                    fPrecioDeSalida= (float)nDiferenciaHorarioEgresoIngreso*nPrecioAudiXHora;
                    Marca[2].fDineroAcumulado = Marca[2].fDineroAcumulado+fPrecioDeSalida;
                    break;

            case 4:
                    fPrecioDeSalida= (float)nDiferenciaHorarioEgresoIngreso*nPrecioOtroXHora;
                    Marca[3].fDineroAcumulado = Marca[3].fDineroAcumulado+fPrecioDeSalida;
                    break;
        }//switch tarifa

        for(int i=0 ; i < tamDuenios ; i++){

            if(Duenios[i].intIdDuenio == Automoviles[nIndex].intDuenio){

                printf("\t***TICKET FINAL***");
                printf("\n\tNombre y Apellido: %s\n\tPatente: %s\t", Duenios[i].szNombreApellido, Automoviles[nIndex].szPatente);

                switch(Automoviles[nIndex].intMarca){

                    case 1:
                            printf("Marca: Alpha Romeo");
                            break;

                    case 2:
                             printf("Marca:Ferrari");
                            break;

                    case 3:
                             printf("Marca:Audi");
                            break;

                    case 4:
                             printf("Marca:Otro");
                            break;
                }

                printf("\n\tTotal a pagar: %.2f\n\t******************\n", fPrecioDeSalida);

                break;
            }

        }//for dueños

        Automoviles[nIndex].bEstado=0; //se va el auto
    }else{

        printf("no se encontraron patentes iguales!");
    }

}// egreso de automoviles


                        /*********** MARCAS **********/

void inicializarMarcas(eMarca Marcas[]){

    for(int i=0;i<4;i++){

        Marcas[i].intIdMarca=i+1;
        Marcas[i].fDineroAcumulado=0;
    }


}


                        /*********** OCUPADO? **********/

int HayAutosEstacionados(eAutomovil Automoviles[], int nTam){


int bAutos=-1;   //no hay ningun auto

    for(int i=0;i<nTam;i++){


        if(Automoviles[i].bEstado == 1){

            bAutos=1;
            break;
        }

    }

return bAutos;
}

int HayDueniosDeAlta(eDuenio Duenio[], int nTam){

int bDuenio =-1;   //no hay ningun auto

    for(int i=0;i<nTam;i++){


        if(Duenio[i].bEstado == 1){

            bDuenio=1;
            break;
        }

    }

return bDuenio;

}
