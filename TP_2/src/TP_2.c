/*

Brandon Suarez:



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArrayEmployees.h"

int main(void)
{
	setbuf(stdout, NULL);

	int idIncrementado = 1000;
	int opcionMenu = 0;
	char nameAux[TAMNOMBRE];
	char lastNameAux[TAMNOMBRE];
	float salaryAux = 0;
	int sectorAux = 0;
	int idDeBaja = 0;
	int contadorEmpleados = 0;
	int order = 0;
	int subMenu = 0;

	Employee employee[TAM];

	employee_initEmployees(employee, TAM);
	employee_showMenu(employee, opcionMenu, idIncrementado, nameAux, lastNameAux, salaryAux, sectorAux, idDeBaja, contadorEmpleados, order, subMenu, TAM);

	return EXIT_SUCCESS;
}

