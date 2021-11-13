#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char nombre[TAMNOMBRE];
	char sueldo[1000];
	char horasTrabajadas[1000];
	char id[1000];

	while(!feof(pFile))
	{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
		if(feof(pFile))
		{
			break;
		}
		Employee* unEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
		ll_add(pArrayListEmployee, unEmpleado);


		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* unEmpleado;

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			unEmpleado = employee_new();
			fread(unEmpleado, sizeof(Employee), 1, pFile);
			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListEmployee, unEmpleado);

			retorno = 0;
		}
		fclose(pFile);
	}
    return retorno;
}
