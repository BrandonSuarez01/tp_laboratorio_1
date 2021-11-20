#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"


Employee* employee_new()
{
	Employee* employeeRt = NULL;
	employeeRt = (Employee*) malloc (sizeof(Employee));
	return employeeRt;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* employee = NULL;
	employee = employee_new();

	int auxId = atoi(idStr);
	int auxHoras = atoi(horasTrabajadasStr);
	int auxSueldo = atoi(sueldoStr);

	if(employee != NULL)
	{
		employee_setId(employee, auxId);
		employee_setNombre(employee, nombreStr);
		employee_setHorasTrabajadas(employee, auxHoras);
		employee_setSueldo(employee, auxSueldo);
	}
	return employee;
}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}
int employee_setId(Employee* this,int id)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->id = id;
		seCargo = 1;
	}
	return seCargo;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		seCargo = 1;
	}
	return seCargo;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->sueldo = sueldo;
		seCargo = 1;
	}
	return seCargo;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}
int employee_ordenarPorId(void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	int auxIdUno;
	int auxIdDos;
	Employee* auxEmpleado = (Employee*)punteroUno;
	Employee* auxEmpleadoDos = (Employee*)punteroDos;

	employee_getId(auxEmpleado, &auxIdUno);
	employee_getId(auxEmpleadoDos, &auxIdDos);

	if(auxIdUno > auxIdDos)
	{
		retorno = 1;
	}
	else
	{
		if(auxIdUno < auxIdDos)
		{
			retorno = -1;
		}
	}

	auxEmpleado = NULL;
	auxEmpleadoDos = NULL;

	return retorno;
}
int employee_ordenarPorNombre(void* punteroUno, void* punteroDos)
{
	int retorno = -2;
	char auxNombreUno[TAMNOMBRE];
	char auxNombreDos[TAMNOMBRE];
	Employee* auxEmpleado = (Employee*)punteroUno;
	Employee* auxEmpleadoDos = (Employee*)punteroDos;

	employee_getNombre(auxEmpleado, auxNombreUno);
	employee_getNombre(auxEmpleadoDos, auxNombreDos);
	retorno = strcmp(auxNombreUno, auxNombreDos);

	auxEmpleado = NULL;
	auxEmpleadoDos = NULL;

	return retorno;
}
int employee_ordenarPorHoras(void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	int auxHorasUno;
	int auxHorasDos;
	Employee* auxEmpleado = (Employee*)punteroUno;
	Employee* auxEmpleadoDos = (Employee*)punteroDos;

	employee_getHorasTrabajadas(auxEmpleado, &auxHorasUno);
	employee_getHorasTrabajadas(auxEmpleadoDos, &auxHorasDos);

	if(auxHorasUno > auxHorasDos)
	{
		retorno = 1;
	}
	else
	{
		if(auxHorasUno < auxHorasDos)
		{
			retorno = -1;
		}
	}

	auxEmpleado = NULL;
	auxEmpleadoDos = NULL;

	return retorno;
}
int employee_ordenarPorSueldo(void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	int auxSueldoUno;
	int auxSueldoDos;
	Employee* auxEmpleado = (Employee*)punteroUno;
	Employee* auxEmpleadoDos = (Employee*)punteroDos;

	employee_getSueldo(auxEmpleado, &auxSueldoUno);
	employee_getSueldo(auxEmpleadoDos, &auxSueldoDos);

	if(auxSueldoUno > auxSueldoDos)
	{
		retorno = 1;
	}
	else
	{
		if(auxSueldoUno < auxSueldoDos)
		{
			retorno = -1;
		}
	}

	auxEmpleado = NULL;
	auxEmpleadoDos = NULL;

	return retorno;
}
void employee_mostrarSeleccionado(Employee* unEmpleado)
{
	int auxId;
	int auxHoras;
	int auxSueldo ;
	char auxNombre[TAMNOMBRE];

	employee_getId(unEmpleado, &auxId);
	employee_getNombre(unEmpleado, auxNombre);
	employee_getHorasTrabajadas(unEmpleado, &auxHoras);
	employee_getSueldo(unEmpleado, &auxSueldo);
	printf("\n%-10s %-20s %-20s %-20s\n", "ID", "Nombre","Horas trabajadas", "Sueldo");
	printf("%-10d %-20s %-20d %-20d\n", auxId, auxNombre, auxHoras, auxSueldo);

}
