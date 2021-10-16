/*
 * ArrayEmployees.c
 *
 *  Created on: 30 sep. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArrayEmployees.h"

int employee_initEmployees(Employee* employee, int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		employee[i].isEmpty = VACIO;
	}

	return 0;
}
void employee_showMenu(Employee employee[], int opcionMenu, int idIncrementado, char* nameAux, char* lastNameAux, float salaryAux, int sectorAux, int idDeBaja, int contadorEmpleados, int order, int subMenu, int tam)
{

	do
	{
		pedirEntero(&opcionMenu,"------------------MENU------------------\n"
									"1.ALTA de un empleado.\n"
									"2.MODIFICAR un empleado.\n"
									"3.Dar BAJA a un empleado.\n"
									"4.INFORMAR listas.\n"
									"5.Salir.\n\n"
								"------------------------------------------\n"
									"Ingrese la opcion deseada: ",
								"------------------MENU------------------\n"
									"1.ALTA de un empleado.\n"
									"2.MODIFICAR un empleado.\n"
									"3.Dar BAJA a un empleado.\n"
									"4.INFORMAR listas.\n"
									"5.Salir.\n\n"
									"------------------------------------------\n"
									"ERROR - reingrese una opcion valida: \n" ,1 ,5);
		switch(opcionMenu)
		{
			case 1 :
				pedirString(nameAux,"Ingrese el nombre del empleado: ", "ERROR - reingrese correctamente el nombre(no mas de 20 caracteres): ", TAMNOMBRE);
				pedirString(lastNameAux, "Ingrese el apellido del empleado: ", "ERROR - reingrese correctamente el apellido(no mas de 20 caracteres): ", TAMNOMBRE);
				pedirFlotante(&salaryAux, "Ingrese el salario del empleado: ", "ERROR - reingrese correctamente el salario entre 15000 y 40000: ", 15000, 40000);
				pedirEntero(&sectorAux, "Ingrese el sector del empleado: ", "ERROR - reingrese el sector correctamente: ", 1, 10);
				if(employee_addEmployees(employee, tam, idIncrementado, nameAux, lastNameAux, salaryAux, sectorAux) == 0)
				{
					contadorEmpleados++;
					idIncrementado++;


					printf("-------------------------------------------\n"
							"Empleado dado de alta correctamente...\n");
				}
				else
				{
					printf("-------------------------------------------\n"
							"ERROR - No hay espacio disponible...\n");
				}

			break;
			case 2 :
				if(contadorEmpleados > 0)
				{
					employee_modifyEmployee(employee, tam);
				}
				else
				{
					printf("ERROR - Aun no se ah ingresado ningun empleado...");
				}
			break;
			case 3 :
				if(contadorEmpleados > 0)
				{
					pedirEntero(&idDeBaja, "Ingrese el ID de el empleado que desea dar de baja: ", "ERROR - Ese ID no existe, reingrese: ", 1000, 1999);
					employee_removeEmployee(employee, tam, idDeBaja);
				}
				else
				{
					printf("ERROR - Aun no se ah ingresado ningun empleado...");
				}
			break;
			case 4 :
				if(contadorEmpleados > 0)
				{
					pedirEntero(&subMenu,"\n--INGRESE EL NUMERO DE EL LISTADO QUE DESEA VER--\n"
											"1.Ver los listados.\n"
											"2.Ver el total y el promedio de los salarios.\n"
											"-------------------------------\n"
											"Ingrese la opcion deseada: ",
											"\n--INGRESE EL NUMERO DE EL LISTADO QUE DESEA VER--\n"
											"1.Ver los listados.\n"
											"2.Ver el total y el promedio de los salarios.\n"
											"-------------------------------\n"
											"ERROR - Reingrese la opcion correctamente: "
											"-------------------------------\n", 1, 2);
					switch(subMenu)
					{
						case 1 :
							pedirEntero(&order,"Ingrese el orden en el que quiere mostrar las listas ( 1 = DESCENDENTE o 0 = ASCENDENTE): ", "ERROR - Ese orden no existe, reingrese: ",0 , 1);
							printf("Ordenando, espere...");
							system("pause");
							employee_sortEmployee(employee, tam, order);

						break;
						case 2 :
							printf("Calculando, espere...");
							system("pause");
							employee_totalSalariesAndAverages(employee, tam);
						break;
					}
				}
				else
				{
					printf("ERROR - Aun no se ah ingresado ningun empleado...");
				}
			break;
			case 5 :
				printf("Fin del ingreso de empleados...");
			break;
		}

	}while(opcionMenu != 5);

}
int employee_addEmployees(Employee* employee, int len, int id, char* name, char* lastName, float salary, int sector)
{
	int retorno = -1;
	int i = employee_searchSpace(employee, len);

		if(i != -1)
		{
			employee[i].id = id;
			strcpy(employee[i].name, name);
			strcpy(employee[i].lastName, lastName);
			employee[i].id = id;
			employee[i].salary = salary;
			employee[i].sector = sector;
			employee[i].isEmpty = OCUPADO;
			retorno = 0;
		}

	return retorno;
}
int employee_searchSpace(Employee employee[], int tam)
{
	int i;
	int index = -1;

	for(i = 0; i < tam; i++)
	{
		if(employee[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}
int employee_printEmployees(Employee employee[], int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		if(employee[i].isEmpty == OCUPADO)
		{
			employee_printOne(employee[i]);
		}

	}
	return 0;
}
int employee_printOne(Employee employee)
{
	printf("%-10d - %-20s - %-20s - %-20.2f - %-20d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);

	return 0;
}
int employee_findEmployeeById(Employee* employee, int len, int id)
{
	int i;
	int index = -1;

	for(i = 0; i < len; i++)
	{
		if(employee[i].isEmpty == OCUPADO && employee[i].id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
int employee_removeEmployee(Employee* employee, int len, int id)
{
	int retorno = -1;
	int index;

	index = employee_findEmployeeById(employee, len, id);

	if(index != -1)
	{
		employee_showModification(employee, index, "Desea dar de baja al siguiente empleado: \n");
		if(employee_verifyConfirmation("Ingrese 'S' para confirmar la baja de el empleado: ") == 0)
		{
			employee[index].isEmpty = VACIO;
			printf("\nEmpleado %s dado de baja correctamente!\n", employee[index].name);
		}
		else
		{
			printf("\nSe cancelo la baja de el empleado\n");
		}
		retorno = 0;

	}
	else
	{
		printf("\nERROR - Empleado no encontrado...\n");
	}


	return retorno;
}
int employee_modifyEmployee(Employee* employee, int tam)
{
	int retorno = -1;
	int opcionSubMenu;
	int idIngresada;
	int index;

	pedirEntero(&idIngresada, "Ingrese el ID de el empleado a modificar: ", "ERROR - Esa ID no existe, reingrese: ", 1000, 1999);
	index = employee_findEmployeeById(employee, tam, idIngresada);

	pedirEntero(&opcionSubMenu, "---------------------------\n"
								"1. Modificar el nombre.\n"
								"2. Modificar el apellido.\n"
								"3. Modificar el salario.\n"
								"4. Modificar el sector.\n"
								"---------------------------\n"
								"Ingrese la opcion deseada: ",
								"---------------------------\n"
								"1. Modificar el nombre.\n"
								"2. Modificar el apellido.\n"
								"3. Modificar el salario.\n"
								"4. Modificar el sector.\n"
								"---------------------------\n"
								"ERROR - reingrese la opcion deseada: "
								"---------------------------\n", 1, 4);
	switch(opcionSubMenu)
	{
		case 1 :
			if(index != -1)
			{
				employee_showModification(employee, index, "Desea modificar el siguiente empleado?: \n");
				if(employee_verifyConfirmation("Ingrese 'S' para confirmar: ") == 0)
				{
					pedirString(employee[index].name, "Ingrese el nuevo nombre del empleado: ", "ERROR - Esos no son caracteres validos, reingrese: ", TAMNOMBRE);
					printf("Nombre modificado correctamente...\n");
				}
				else
				{
					printf("Se cancelo la modificacion del nombre...\n");
				}
			retorno = 0;
			}
			system("pause");
		break;
		case 2 :
			if(index != -1)
			{
				employee_showModification(employee, index, "Desea modificar el apellido del siguiente empleado?: \n");
				if(employee_verifyConfirmation("Ingrese 'S' para confirmar: ") == 0)
				{
					pedirString(employee[index].lastName, "Ingrese el nuevo apellido del empleado: ", "ERROR - Esos no son caracteres validos, reingrese: ", TAMNOMBRE);
					printf("Apellido del empleado modificado correctamente...\n");
				}
				else
				{
					printf("Se cancelo la modificacion de el apellido del empleado...\n");
				}
			}
			system("pause");
		break;
		case 3 :
			if(index != -1)
			{
				employee_showModification(employee, index, "Desea modificar el salario del siguiente empleado?: \n");
				if(employee_verifyConfirmation("Ingrese 'S' para confirmar: ") == 0)
				{
					pedirFlotante(&employee[index].salary, "Ingrese el nuevo salario de el empleado: ", "ERROR - Ese no es un salario valido, reingrese: ", 15000, 40000);
					printf("Salario del empleado modificado correctamente...\n");
				}
				else
				{
					printf("Se cancelo la modificacion del salario...\n");
				}
			}
		break;
		case 4 :
			if(index != -1)
			{
				employee_showModification(employee, index, "Desea modificar el sector de el siguiente empleado?: \n");
				if(employee_verifyConfirmation("Ingrese 'S' para confirmar: ") == 0)
				{
					pedirEntero(&employee[index].sector, "Ingrese el nuevo sector de el empleado: ", "ERROR - Ese no es un sector valido, reingrese: ", 1, 10);
					printf("Sector de el empleado modificado correctamente...\n");
				}
				else
				{
					printf("Se cancelo la modificacion de el sector...\n");
				}
			}
		break;
	}

	return retorno;

}
int employee_verifyConfirmation(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

return retorno;
}
void employee_showModification(Employee employee[], int index, char* mensaje)
{
	printf("%s", mensaje);
	printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
	printf("%-10d - %-20s - %-20s - %-20.2f - %-20d\n", employee[index].id, employee[index].name, employee[index].lastName, employee[index].salary, employee[index].sector);
}
int employee_sortEmployee(Employee* employee, int len, int order)
{
	int retorno = -1;
	int flagSwap;
	int i;
	int nuevoLimite;
	Employee auxEmployee;

	switch(order)
	{
		case 0 :
			do
			{
				nuevoLimite = len - 1;
				flagSwap = 0;

				for(i = 0; i < nuevoLimite; i++)
				{
					if(strcmp(employee[i].lastName, employee[i+1].lastName) == 1 && employee[i].sector > employee[i+1].sector)
					{
						auxEmployee = employee[i];
						employee[i] = employee[i+1];
						employee[i+1] = auxEmployee;
						flagSwap = 1;
						retorno = 0;
					}
				}
			}while(flagSwap);
			printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
			employee_printEmployees(employee, len);
		break;
		case 1 :
			do
			{
				nuevoLimite = len - 1;
				flagSwap = 0;

				for(i = 0; i < nuevoLimite; i++)
				{
					if(strcmp(employee[i].lastName, employee[i+1].lastName) == -1 && employee[i].sector < employee[i+1].sector)
					{
						auxEmployee = employee[i];
						employee[i] = employee[i+1];
						employee[i+1] = auxEmployee;
						flagSwap = 1;
						retorno = 0;
					}
				}
			}while(flagSwap);
			printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
			employee_printEmployees(employee, len);
		break;

	}
	return retorno;
}
int employee_totalSalariesAndAverages(Employee* employee, int len)
{
	int retorno = -1;
	int i;
	float acumuladorSalarios = 0;
	int contador = 0;
	float promedio;
	int masQueElPromedio = 0;

	for(i = 0; i < len; i++)
	{
		if(employee[i].isEmpty == OCUPADO)
		{
			acumuladorSalarios += employee[i].salary;
			contador++;
		}
	}

	promedio = acumuladorSalarios / (float)contador;
	for(i = 0; i < len; i++)
	{
		if(employee[i].salary > promedio && employee[i].isEmpty == OCUPADO)
		{
			masQueElPromedio++;
		}
	}

	printf("El total de los salarios es: %.2f\n", acumuladorSalarios);
	printf("El promedio de los salarios es: %.2f\n", promedio);
	printf("La cantidad de empleados que gana mas que el promedio son %d empleados.\n", masQueElPromedio);

	return retorno;
}


