#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno;

    Employee* empleadoUno;
    Employee* empleadoDos;
    empleadoUno= (Employee*)pEmployeeA;
    empleadoDos=(Employee*)pEmployeeB;

    if(strcmp(empleadoUno->name ,empleadoDos->name) == 0){

        retorno= 0;
    }else if(strcmp(empleadoUno->name ,empleadoDos->name) < 0){

        retorno= -1;
    }else{

         retorno= 1;
        }

    return retorno;
}


void employee_print(Employee* this)
{

    printf("%d, %s, %s\n", this->id, this->name, this->lastName);

}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;

     returnAux = (Employee*)malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this, int id)

{
    this->id = id;

    return 0;
}

int employee_getId(Employee* this)
{
    int retorno=-1;

    if(this->isEmpty !=0){

        this->id = retorno;
    }

    return retorno;

}


int employee_setName(Employee* this, char* szName)

{
    strcpy(this->name,szName);

    return 0;
}

char* employee_getName(Employee* this)
{
    char* retorno;

    if(this->isEmpty !=0){

        strcpy(retorno,this->name);
    }

    return retorno;
}

int employee_setLastName(Employee* this, char* szLastName)

{
    strcpy(this->lastName,szLastName);

    return 0;
}

char* employee_getLastName(Employee* this)
{
    char* retorno;

    if(this->isEmpty !=0){

        strcpy(retorno,this->lastName);
    }

    return retorno;

}

int employee_setIsEmpty(Employee* this, int bIsEmpty)

{
    this->isEmpty = bIsEmpty;

    return 0;
}

int employee_getIsEmpty(Employee* this)
{
    int retorno;

    this->isEmpty = retorno;

    return retorno;

}
