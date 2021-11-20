#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"

int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int flagControlerUno = 0;//controla si el usuario accedio a la opcion uno
    int flagControlerDos = 0;//controla si el usuario accedio a la opcion dos

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	obtenerNumeroValido(&option, "\nMenu: \n\n"
									 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    								 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    								 "3. Alta de empleado.\n"
    								 "4. Modificar datos de empleado.\n"
    								 "5. Baja de empleado.\n"
    								 "6. Listar empleados.\n"
    								 "7. Ordenar empleados.\n"
    								 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    								 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    								 "10. Salir\n"
    								 "---------------------------------------------------------------------------\n"
    								 "Ingrese la opcion deseada: ",
									 "---------------------------------------------------------------------------\n"
									 "\nMenu: \n\n"
									 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
									 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
									 "3. Alta de empleado.\n"
									 "4. Modificar datos de empleado.\n"
									 "5. Baja de empleado.\n"
									 "6. Listar empleados.\n"
									 "7. Ordenar empleados.\n"
									 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
									 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
									 "10. Salir\n"
									 "---------------------------------------------------------------------------\n"
									 "ERROR - Opcion no valida, reingrese: ", 1, 10);
        switch(option)
        {
            case 1 :
            	if(flagControlerUno == 0 && flagControlerDos != 1)
            	{
            		if(controller_loadFromText("src\\data.csv", listaEmpleados) == 1)
					{
            			systemPause("\nCargando, espere... Presione cualquier tecla para continuar...\n");
						printf("Se cargaron los datos del texto correctamente.\n");
					}
					else
					{
						printf("ERROR - No se cargaron los datos.\n");
					}
            		flagControlerUno = 1;
            	}
            	else
            	{
            		printf("\nYa cargo la lista de empleados desde el archivo en binario...\n");
            	}
			break;
            case 2 :
            	if(flagControlerDos == 0 && flagControlerUno != 1)
            	{
            		if(controller_loadFromBinary("src\\dataBinary.csv", listaEmpleados)== 1)
					{
            			systemPause("\nCargando, espere... Presione cualquier tecla para continuar...\n");
						printf("Se cargaron los datos en binario correctamente.\n");
					}
					else
					{
						printf("ERROR - No se cargaron los datos.\n");
					}
            		flagControlerDos = 1;
            	}
            	else
				{
					printf("\nYa cargo la lista de empleados desde el archivo en texto...\n");
				}
			break;
            case 3 :
            	if(flagControlerUno == 1 || flagControlerDos == 1)
            	{
            		controller_addEmployee(listaEmpleados);
            	}
            	else
				{
					printf("\nERROR - Aun no ah cargado ninguna lista...\n");
				}
			break;
            case 4 :
            	if(flagControlerUno == 1 || flagControlerDos == 1)
            	{
            		controller_ListEmployee(listaEmpleados);
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nERROR - Aun no ah cargado ninguna lista...\n");
            	}
			break;
            case 5 :
            	if(flagControlerUno == 1 || flagControlerDos == 1)
				{
            		controller_ListEmployee(listaEmpleados);
            		controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("\nERROR - Aun no ah cargado ninguna lista...\n");
				}
			break;
            case 6 :
            	if(flagControlerUno == 1 || flagControlerDos == 1)
				{
            		systemPause("Listando, espere... Presione cualquier tecla para continuar...\n");
            		controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("\nERROR - Aun no ah cargado ninguna lista...\n");
				}
			break;
            case 7 :
            	if(flagControlerUno == 1 || flagControlerDos == 1)
				{
            		controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("\nERROR - Aun no ah cargado ninguna lista...\n");
				}
			break;
            case 8 :
            	if(flagControlerUno == 1 || flagControlerDos == 1)
				{
            		controller_saveAsText("src\\data.csv" , listaEmpleados);
            		systemPause("Guardando, espere... Presione cualquier tecla para continuar...\n");
				}
				else
				{
					printf("\nERROR - Aun no ah cargado ninguna lista...\n");
				}
			break;
            case 9 :
            	if(flagControlerUno == 1 || flagControlerDos == 1)
				{
            		controller_saveAsBinary("src\\dataBinary.csv", listaEmpleados);
            		systemPause("Guardando, espere... Presione cualquier tecla para continuar...\n");
				}
				else
				{
					printf("\nERROR - Aun no ah cargado ninguna lista...\n");
				}
			break;
            case 10 :
            	ll_deleteLinkedList(listaEmpleados);
            	printf("Fin del programa....");
			break;

        }
    }while(option != 10);
    return 0;
}
