/*
 * Funciones.c
 *
 *  Created on: 30 sep. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "ArrayEmployees.h"

int pedirEntero(int* enteroDevuelto, char* mensaje, char* mensajeError, int min, int max)
{
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	*enteroDevuelto = numeroIngresado;

	return 0;
}
void pedirString(char* nombre, char* primerMensaje, char* mensajeError, int max)
{
	char nombreSinValidar[100];
	int tam;

	printf("%s", primerMensaje);
	fflush(stdin);
	scanf("%[^\n]", nombreSinValidar);
	tam = strlen(nombreSinValidar);

	while(nombreSinValidar == NULL || tam > max || validarSigno(nombreSinValidar) == 0)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%[^\n]", nombreSinValidar);
		tam = strlen(nombreSinValidar);
	}

	strcpy(nombre, nombreSinValidar);

}
int pedirFlotante(float* flotanteDevuelto, char* mensaje, char* mensajeError, int min, int max)
{
	float numeroIngresado;

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotanteDevuelto = numeroIngresado;

	return 0;
}
void pedirCaracter(char* caracter, char* mensaje)
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", caracter);
}
int validarSigno(char* string)
{
	int i;
	int tam;
	int retorno = -1;
	int devolucion;

	if(string != NULL)
	{
		tam = strlen(string);

		for(i = 0; i < tam; i++)
		{
			devolucion = isdigit(string[i]);

			if(devolucion == 1 || string[i] == '/' || string[i] == '.' || string[i] == '?'
				|| string[i] == '{' || string[i] == '}' || string[i] == '[' || string[i] == ']'
				|| string[i] == '_' || string[i] =='-'  || string[i] == ';' || string[i] == ':'
				|| string[i] == '*' || string[i] == '+' || string[i] == '¿' || string[i] == '"'
				|| string[i] == '!' || string[i] == '|' || string[i] ==  '#'|| string[i] == '<'
				|| string[i] == '>' || string[i] == '=' || string[i] == '@' || string[i] == ','
				|| string[i] == '(' || string[i] == ')' || string[i] == '%' || string[i] == '&')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


