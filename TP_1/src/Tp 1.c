/*
Suarez Brandon:

Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)

2. Ingresar 2do operando (B=y)

3. Calcular todas las operaciones:

a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)

4. Informar resultados:

a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”

5. Salir.
*/
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"

int main(void)
{
	setbuf(stdout, NULL);
	//opciones 1 y 2
	float numeroA = 0;
	float numeroB = 0;
	float suma;
	float resta;
	float division;
	float producto;
	int factorialUno;
	int factorialDos;
	int opcionMenu;

	do
	{
		opcionMenu = mostrarPrimerMenu(numeroA, numeroB);

		switch(opcionMenu)
		{
			case 1 :
				printf("Ingrese el numero x: ");
				fflush(stdin);
				scanf("%f", &numeroA);
			break;
			case 2 :
				printf("Ingrese el numero y: ");
				fflush(stdin);
				scanf("%f", &numeroB);
			break;
			case 3 :
				suma = sumarNumeros(numeroA, numeroB);
				resta = restarNumeros(numeroA, numeroB);
				division = dividirNumeros(numeroA, numeroB);
				producto = multiplicarNumeros(numeroA, numeroB);
				factorialUno = sacarFactorial(numeroA);
				factorialDos = sacarFactorial(numeroB);

				printf("Calculando... ");
				system("pause");
			break;
			case 4 :

				mostrarMenuFinal(numeroA, numeroB, suma, resta, division, producto, factorialUno, factorialDos);

				numeroA = 0;
				numeroB = 0;
				system("pause");
			break;
			case 5 :
				printf("\nFin de la calculadora");
			break;
		}

	}while(opcionMenu != 5);

	return EXIT_SUCCESS;
}

