/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;


int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(Employee* this);

Employee* employee_new(void);
void employee_delete(Employee* this);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this);

int employee_setName(Employee* this, char* szName);
char* employee_getName(Employee* this);

int employee_setLastName(Employee* this, char* szLastName);
char* employee_getLastName(Employee* this);

int employee_setIsEmpty(Employee* this, int bIsEmpty);
int employee_getIsEmpty(Employee* this);
#endif // _EMPLOYEE_H



