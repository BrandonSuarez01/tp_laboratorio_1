#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Funciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		retorno = 1;
	}
	else
	{
		printf("Path o Array vacio");
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE* pFile;

		if(path != NULL && pArrayListEmployee != NULL)
		{
			pFile = fopen(path, "rb");
			parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			retorno = 1;
		}
		else
		{
			printf("Path o Array vacio");
		}

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int auxId = 0;
	char auxIdDos[1000];
	char auxNombre[TAMNOMBRE];
	int auxHorasTrabajadas;
	int auxSueldo;
	char horasTrabajadas[1000];
	char sueldo[1000];

	FILE* pFile = fopen("ultimaId.csv", "r");
	fgets(auxIdDos, 5, pFile);
	fclose(pFile);

	pedirString(auxNombre, "Ingrese el nombre del empleado: ", "ERROR - Ingrese correctamente el nombre(Sin simbolos o caracteres especiales): ", TAMNOMBRE);
	obtenerNumeroValido(&auxHorasTrabajadas,"Ingrese las horas trabajadas por el empleado: ", "ERROR - Ingrese una catidad de horas valida: ", 1, 600);
	obtenerNumeroValido(&auxSueldo, "Ingrese el sueldo del empleado(Sueldo en numero entero): ", "ERROR - Ingrese correctamente el sueldo(10000-50000): ", 10000, 50000);

	if(verificarConfirmacion("Desea cargar el empleado con los datos anteriores?, Presione 'S' para confirmar: ") == 0)
	{
		itoa(auxHorasTrabajadas, horasTrabajadas , 10);
		itoa(auxSueldo, sueldo, 10);

		Employee* unEmpleado = employee_newParametros(auxIdDos, auxNombre, horasTrabajadas, sueldo);
		ll_add(pArrayListEmployee, unEmpleado);

		auxId = atoi(auxIdDos);
		auxId++;

		systemPause("Añadiendo, espere... Presione cualquier tecla para continuar...\n");
		printf("\nEmpleado dado de alta correctamente...\n");

		fopen("ultimaId.csv", "w");
		fprintf(pFile, "%d", auxId);
		fclose(pFile);
		retorno = 1;

	}
	else
	{
		printf("\nSe cancelo el alta del empleado...\n");

	}


    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int auxOpcion = 0;
	int i;
	int auxIdDos;
	char auxNombre[TAMNOMBRE];
	int* auxId = (int*) malloc (sizeof(int));
	int* auxHoras = (int*) malloc (sizeof(int));
	int* auxSueldo = (int*) malloc (sizeof(int));
	int tam = ll_len(pArrayListEmployee);

	Employee* unEmpleado = NULL;

	obtenerNumeroValido(auxId, "Ingrese el el ID del empleado a modificar: ", "ERROR - Ingrese un ID existente: ", 1, tam);

	for(i = 0; i < tam; i++)
	{
		unEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
		employee_getId(unEmpleado, &auxIdDos);
		if(auxIdDos == *auxId)
		{
			break;
		}
	}

	while(*auxId != auxIdDos)
	{
		obtenerNumeroValido(auxId, "ERROR - Reingrese el el ID del empleado a modificar: ", "ERROR - Ingrese un ID existente: ", 1, tam);
	}

	do
	{
		employee_mostrarSeleccionado(unEmpleado);
		obtenerNumeroValido(&auxOpcion, "\nMENU MODIFICAR.\n"
										"1. Modificar el nombre.\n"
										"2. Modificar las horas trabajadas.\n"
										"3. Modificar el sueldo del empleado.\n"
										"4. Salir.\n"
										"\n--------------------------------------\n"
										"Ingrese la opcion del campo que desea modificar: ",
										"\nMENU MODIFICAR.\n"
										"1. Modificar el nombre.\n"
										"2. Modificar las horas trabajadas.\n"
										"3. Modificar el sueldo del empleado.\n"
										"4. Salir.\n"
										"--------------------------------------\n"
										"ERROR - Reingrese la opcion del campo que desea modificar: ", 1, 4);
		switch(auxOpcion)
		{
			case 1 :
				pedirString(auxNombre, "Ingrese el nuevo nombre del empleado(Hasta 30 caracteres): ", "ERROR - Reingrese correctamente el nombre(Hasta 30 caracteres): ", TAMNOMBRE);
				if(verificarConfirmacion("Desea cambiar el nombre antiguo? (Presione 'S' para confirmar): ") == 0)
				{
					systemPause("Modificando, espere... Presione cualquier tecla para continuar...\n");
					employee_setNombre(unEmpleado, auxNombre);
					retorno = 1;
				}
				else
				{
					printf("\nSe cancelo la moficacion del nombre...\n");
				}
			break;
			case 2 :
				obtenerNumeroValido(auxHoras, "Ingrese las nuevas horas del empleado(Hasta 600): ", "ERROR - Reingrese correctamente las horas(Mayor de 0 y hasta 600): ", 1, 600);
				if(verificarConfirmacion("Desea asignar estas nuevas horas? (Presione 'S' para confirmar): ") == 0)
				{
					systemPause("Modificando, espere... Presione cualquier tecla para continuar...\n");
					employee_setHorasTrabajadas(unEmpleado, *auxHoras);
					retorno = 1;
				}
				else
				{
					printf("\nSe cancelo la modificacion de las horas trabajadas...\n");
				}
			break;
			case 3 :
				obtenerNumeroValido(auxSueldo, "Ingrese el nuevo sueldo del empleado (Hasta 50000): ", "ERROR - Reingrese correctamente el sueldo(Mayor de 10000 y hasta 50000): ", 10000, 50000);
				if(verificarConfirmacion("Desea asignar este nuevo sueldo? (Presione 'S' para confirmar): ") == 0)
				{
					systemPause("Modificando, espere... Presione cualquier tecla para continuar...\n");
					employee_setSueldo(unEmpleado, *auxSueldo);
					retorno = 1;
				}
				else
				{
					printf("\nSe cancelo la modificacion del sueldo...\n");
				}
			break;
			case 4 :
				printf("\nHa cancelado la modificacion...\n");
			break;
		}

	}while(auxOpcion != 4);

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int auxId = 0;
	int tam = ll_len(pArrayListEmployee);
	int i;
	int auxIdDos;

	Employee* unEmpleado = NULL;
	obtenerNumeroValido(&auxId, "Ingrese el ID del empleado que desea eliminar: ", "ERROR - Ingrese un ID valido: ", 1, tam);

	for(i = 0; i < tam; i++)
	{
		unEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
		employee_getId(unEmpleado, &auxIdDos);
		if(auxIdDos == auxId)
		{
			break;
		}
	}
	while(auxId != auxIdDos)
	{
		obtenerNumeroValido(&auxId, "ERROR - Reingrese el el ID del empleado a eliminar(Existente): ", "ERROR - Ingrese un ID existente: ", 1, tam);
	}

	employee_mostrarSeleccionado(unEmpleado);

	if(verificarConfirmacion("Desea elimiar el empleado con la ID ingresada? Presione 'S' para confirmar: ") == 0)
	{
		systemPause("Eliminando, espere... Presione cualquier tecla para continuar...\n");
		ll_remove(pArrayListEmployee, auxId-1);
		printf("\nEmpleado dado de baja correctamente...\n");
		retorno = 1;
	}
	else
	{
		printf("\nSe cancelo la baja...\n");
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int i;
	int tam = ll_len(pArrayListEmployee);

	Employee* auxEmployee;

	printf("%-10s %-20s %-20s %-20s\n\n", "ID", "Nombre","Horas trabajadas", "Sueldo");
	for(i = 0; i < tam; i++)
	{
		auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
		printf("%-10d %-20s %-20d %-20d\n", (*(auxEmployee)).id,(*(auxEmployee)).nombre, (*(auxEmployee)).horasTrabajadas, (*(auxEmployee)).sueldo);

	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int (*pFuncionOrdenarNombre) (void* , void*);
	int (*pFuncionOrdenarId) (void* , void*);
	int (*pFuncionOrdenarHoras) (void* , void*);
	int (*pFuncionOrdenarSueldo) (void* , void*);
	int criterioDeOrden = 0;
	int opcionMenu = 0;

	pFuncionOrdenarNombre = employee_ordenarPorNombre;
	pFuncionOrdenarId = employee_ordenarPorId;
	pFuncionOrdenarHoras = employee_ordenarPorHoras;
	pFuncionOrdenarSueldo = employee_ordenarPorSueldo;

	obtenerNumeroValido(&criterioDeOrden, "Ingrese el orden en el que quiere ordenar(0 = Ascendente , 1 = Descendente): ",
										 "ERROR - Reingrese el orden en el que quiere ordenar(0 = Ascendente , 1 = Descendente): ", 0, 1);

	do
	{
		obtenerNumeroValido(&opcionMenu, "--------------ORDENAR--------------\n"
										 "1. Ordenar por ID,\n"
										 "2. Ordenar por NOMBRE.\n"
										 "3. Ordenar por HORAS TRABAJADAS. \n"
										 "4. Ordenar por SUELDO.\n"
										 "5. Salir.\n"
										 "----------------------------------\n"
										 "Ingrese la opcion deseada: ",
										 "--------------ORDENAR--------------\n"
										 "1. Ordenar por ID,\n"
										 "2. Ordenar por NOMBRE.\n"
										 "3. Ordenar por HORAS TRABAJADAS. \n"
										 "4. Ordenar por SUELDO.\n"
										 "5. Salir.\n"
										 "----------------------------------\n"
										 "ERROR - Reingrese la opcion deseada: ", 1, 5);
		switch(opcionMenu)
		{
			case 1 :
				systemPause("Ordenando, espere... Presione cualquier tecla para continuar...\n");
				ll_sort(pArrayListEmployee, pFuncionOrdenarId, criterioDeOrden);
				retorno = 1;
			break;
			case 2 :
				systemPause("Ordenando, espere... Presione cualquier tecla para continuar...\n");
				ll_sort(pArrayListEmployee, pFuncionOrdenarNombre, criterioDeOrden);
				retorno = 1;
			break;
			case 3 :
				systemPause("Ordenando, espere... Presione cualquier tecla para continuar...\n");
				ll_sort(pArrayListEmployee, pFuncionOrdenarHoras, criterioDeOrden);
				retorno = 1;
			break;
			case 4 :
				systemPause("Ordenando, espere... Presione cualquier tecla para continuar...\n");
				ll_sort(pArrayListEmployee, pFuncionOrdenarSueldo, criterioDeOrden);
				retorno = 1;
			break;
			case 5 :
				printf("Cerrando listado...\n");
			break;
		}

	}while(opcionMenu != 5);




    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int i;
	int tam = ll_len(pArrayListEmployee);
	int auxId;
	char auxNombre[TAMNOMBRE];
	int auxHoras;
	int auxSueldo;

	FILE* pFile = fopen(path, "w");
	Employee* unEmpleado;

	if(path != NULL)
	{
		for(i = 0; i < tam; i++)
		{
			unEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(unEmpleado, &auxId);
			employee_getNombre(unEmpleado, auxNombre);
			employee_getHorasTrabajadas(unEmpleado, &auxHoras);
			employee_getSueldo(unEmpleado, &auxSueldo);
			fprintf(pFile, "%d, %s, %d, %d\n", auxId, auxNombre, auxHoras, auxSueldo);
		}
		retorno = 1;
		fclose(pFile);
		pFile = NULL;
		printf("\nArchivo guardado con exito!\n");
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int i;
	int tam = ll_len(pArrayListEmployee);
	FILE* dataBinary = fopen(path, "wb");
	Employee* unEmpleado;


	if(path != NULL)
	{
		for(i = 0; i < tam; i++)
		{
			unEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			fwrite(unEmpleado, sizeof(Employee), 1, dataBinary);
		}
		retorno = 1;
		fclose(dataBinary);
		dataBinary = NULL;
		printf("\nArchivo guardado con exito!\n");

	}
    return retorno;
}

