/*
 * calculos.c
 *
 *  Created on: 24 sep. 2021
 *      Author: brans
 */

#include "calculos.h"


int mostrarPrimerMenu(float numeroA, float numeroB)
{
	int opcionMenu;

	printf("-----------------MENU-----------------\n"
			 "1. Ingresar el primer operando (%.2f)\n"
			 "2. Ingresar el segundo operando (%.2f)\n"
			 "3. Calcular todas las operaciones:\n "
			 "      a) Calcular (A+B)\n"
			 "      b) Calcular (A-B)\n"
			 "      c) Calcular (A/B)\n"
			 "      d) Calcular (A*B)\n"
			 "      e) Calcular factorial de A (A!)\n"
			 "      f) Calcular factorial de B (B!)\n"
			 "4. Informar resultados:\n"
			 "5. Salir\n", numeroA, numeroB);

			printf("Ingrese la opcion:");
			fflush(stdin);
			scanf("%d", &opcionMenu);

			while(opcionMenu > 6 && opcionMenu < 1)
			{
				printf("Ingrese la opcion:");
				fflush(stdin);
				scanf("%d", &opcionMenu);
			}

			return opcionMenu;
}
float sumarNumeros(float numeroUno, float numeroDos)
{
	float resultado;

		resultado = numeroUno + numeroDos;

	return resultado;
}
float restarNumeros(float numeroUno, float numeroDos)
{
	float resultado;

		resultado = numeroUno - numeroDos;

	return resultado;
}
float dividirNumeros(float numeroUno, float numeroDos)
{
	float resultado;

	if(numeroUno != 0 || numeroDos != 0)
	{
		resultado = numeroUno / numeroDos;
	}
	else
	{
		resultado = 0;
	}

	return resultado;
}
float multiplicarNumeros(float numeroUno, float numeroDos)
{
	float resultado;

		resultado = numeroUno * numeroDos;

	return resultado;
}

unsigned long int sacarFactorial(int numero)
{
	unsigned long int factorial = 1;

	if(numero > 0 && numero < 13)
	{
		factorial = numero * sacarFactorial(numero - 1);
	}

	return factorial;
}
void mostrarMenuFinal(float numeroA, float numeroB, float suma, float resta, float division, float producto, int factorialUno, int factorialDos)
{
	printf("-----------------MENU-----------------\n"
			 "1. Ingresar el primer numero (%.2f)\n"
			 "2. Ingresar el segundo numero (%.2f)\n"
			 "3. Calcular todas las operaciones: \n "
			 "      a) Calcular  (A+B)\n"
			 "      b) Calcular (A-B)\n"
			 "      c) Calcular (A/B)\n"
			 "      d) Calcular (A*B)\n"
			 "      e) Calcular factorial de A (A!)\n"
			 "      f) Calcular factorial de B (B!)\n"
			 "4. Informar resultados:\n"
			 "      a) El resultado de A+B es: %.2f\n"
			 "      b) El resultado de A-B es: %.2f\n",numeroA, numeroB, suma, resta);
	if(division != 0)
	{
		printf("      c) El resultado de A/B es: %.2f\n", division);
	}
	else
	{
		printf("      No se puede dividir por ceros\n");
	}

	printf("      d) El resultado de A*B es: %.2f\n", producto);

	if(factorialUno != 1)
	{
		printf("      e) El factorial de A es: %d\n", factorialUno);
	}
	else
	{
		printf("      e) No se pudo calcular el factorial de A\n");
	}
	if(factorialDos != 1)
	{
		printf("      f) El factorial de B es: %d\n", factorialDos);
	}
	else
	{
		printf("     f) No se pudo calcular el factorial de B\n");
	}

	printf("5. Salir\n");
}


