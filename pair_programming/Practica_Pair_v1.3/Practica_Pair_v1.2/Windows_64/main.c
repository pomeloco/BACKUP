#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int intAux;
    Employee* eAuxEmpleado;

    ArrayList* alLista; //declaracion arraylist
    alLista = al_newArrayList(); //constructor!


    Employee* eEmpleado; //estructura empleado
    eEmpleado= employee_new(); //espacio en memoria para empleado
    Employee* eEmpleadoDos; //estructura empleado
    eEmpleadoDos = employee_new(); //espacio en memoria para empleado

    /*****cargar estructura*****/
    employee_setId(eEmpleado, 666);
    strcpy(eEmpleado->name,"Juan");
    strcpy(eEmpleado->lastName,"Gomez");
    eEmpleado->isEmpty=1;

    employee_setId(eEmpleadoDos, 777);
    strcpy(eEmpleadoDos->name,"Carlos");
    strcpy(eEmpleadoDos->lastName,"Gimenez");
    eEmpleadoDos->isEmpty=1;

    /***************************/

    /************ agregar elementos **********/
    al_add(alLista, eEmpleado); //Agregar un elemento al arrayList
    al_add(alLista,eEmpleadoDos);//agregar un elemento al arraylist
    /*****************************************/

    /************ mostrar cantidad de elementos **************/
    intAux = al_len(alLista); //devuelve cantidad de elementos guardados en arraylist
    printf("cantidad de elementos: %d\n",intAux); //muestro cantidad de elementos guardados en arraylist
    /*********************************************************/

    /******************** Agarrar un elemento del array *******/
    for(int i=0; i<al_len(alLista);i++){

    eAuxEmpleado = (Employee*)al_get(alLista,i); //agarra un elemento del array (copia la direccion de memoria del elemento)
    employee_print(eAuxEmpleado); //muestro el empleado que agarré
    }
    /**********************************************************/

    /***************** ordenar elementos **********************/
    printf("---------------------------------------------\n");
    al_sort(alLista,employee_compare,1);

    for(int i=0; i<al_len(alLista);i++){

    eAuxEmpleado = (Employee*)al_get(alLista,i); //agarra un elemento del array (copia la direccion de memoria del elemento)
    employee_print(eAuxEmpleado); //muestro el empleado que agarré
    }
    /**********************************************************/


    return 0;
}
