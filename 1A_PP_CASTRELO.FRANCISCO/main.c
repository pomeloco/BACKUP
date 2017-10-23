#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento.h"

#define TAM 2   //tamaño dueños max 20
#define TAMestacionamiento 3    //tamaño estacionamiento max 20

/**TRAERLO COMPLETO PERFECTO SEMANA Q VIENE**/

int main()
{
    eDuenio Duenios[TAM];
    eAutomovil Automoviles[TAMestacionamiento];
    eMarca Marcas[4];
    char cSeguir='s';
    int nOpcion,nSubOpcion;

    inicializarEstados(Duenios,TAM);
    inicializarEstadosAutomoviles(Automoviles, TAMestacionamiento);
    inicializarMarcas(Marcas);

    do{
        system("cls");
        printf("1.Dar alta duenio\n2.Modificar\n3.Ingresar automovil\n4.Egreso automovil\n5.Informar\n6.Salir\n- ");
        scanf("%d", &nOpcion);

        nOpcion=validarRangoEnteros(6,1,nOpcion);

        switch(nOpcion){

            case 1:
                        system("cls");
                        altaDeDuenio(Duenios, TAM);
                        break;


            case 2:
                        system("cls");
                        if(HayDueniosDeAlta(Duenios, TAM)!=-1){

                            modificarNumDeTarjetaDuenios(Duenios, TAM);
                            break;
                        }else{

                            printf("\nno hay duenios dados de alta\n");
                            break;
                        }

            case 3:
                        system("cls");
                        if(HayDueniosDeAlta(Duenios, TAM)!=-1){

                            altaDeAutomovil(Automoviles, TAMestacionamiento, Duenios);
                            break;
                        }else{

                            printf("\nno hay duenios dados de alta\n");
                            break;
                        }


            case 4:
                        system("cls");

                        if(HayAutosEstacionados(Automoviles, TAMestacionamiento)!=-1){

                        egresoDeAutomovil(Duenios, Automoviles, TAM, TAMestacionamiento, Marcas);
                        break;

                        }else{
                            printf("\nNo hay autos estacionados\n");
                            break;
                        }

            case 5:

                        system("cls");

                        if(HayAutosEstacionados(Automoviles, TAMestacionamiento)!=-1){

                            printf("1.listado de autos con sus duenios ordenados por horario y patente\n2.Todos los propietarios de audi\n3.Recaudacion total por marca\n4.Recaudacion total de estacionamiento\n");
                            scanf("%d", &nSubOpcion);
                            nSubOpcion=validarRangoEnteros(4,1,nSubOpcion);

                            switch(nSubOpcion){

                                case 1:
                                        ordenarPorHoraPatente(Automoviles,TAMestacionamiento);
                                        mostrarAutosEstacionadosConDueniosXHoraYPatente(Duenios, Automoviles, TAM, TAMestacionamiento);
                                        break;

                                case 2:
                                        mostrarDueniosDeAudi(Duenios, Automoviles, TAM, TAMestacionamiento);
                                        break;

                                case 3:
                                        mostrarRecaudacionTotalXMarca(Marcas);
                                        break;

                                case 4:
                                        mostrarRecaudacionTotalEstacionamiento(Marcas);
                                        break;
                            }

                        }else{

                            printf("\nNo hay autos estacionados\n");
                            break;
                        }
                       // break;//case 5

            case 6:
                    exit(1);
                    break;
        }

     printf("Desea seguir? S/N");
     fflush(stdin);
     cSeguir=tolower(getchar());

     cSeguir=validarSoloChar('s', 'n', cSeguir);

    }while( cSeguir == 's');

    return 0;
}
