/*
 * calculos.h
 *
 *  Created on: 24 sep. 2021
 *      Author: brans
 */
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef CALCULOS_H_
#define CALCULOS_H_
/**
 * @fn int mostrarPrimerMenu(float, float)
 * @brief La funcion muestra el primer menu de la calculadora y da orden al menu.
 *
 *
 * @param numeroA Este parametro toma la inicializacion de la variable numeroA del main.
 * @param numeroB Este parametro toma la inicializacion de la variable numeroB del main.
 * @return devuelve la opcion que hace trabajar al switch del main.
 */
int mostrarPrimerMenu(float numeroA, float numeroB);
/**
 * @fn float sumarNumeros(float, float)
 * @brief toma los numeros de la opcion 1 y 2 del menu y los suma.
 *
 *
 * @param numeroUno Este parametro pasa el primer numero a sumar.
 * @param numeroDos Este parametro pasa el segundo numero a sumar.
 * @return Devuelve la suma entre los dos parametros anteriores.
 */
float sumarNumeros(float numeroUno, float numeroDos);
/**
 * @fn float restarNumeros(float, float)
 * @brief toma los numeros de la opcion 1 y 2 del menu y los resta.
 *
 * @param numeroUno Este parametro pasa el primer numero a restar.
 * @param numeroDos Este parametro pasa el segundo numero a restar.
 * @return  Devuelve la resta entre los dos parametros anteriores.
 */
float restarNumeros(float numeroUno, float numeroDos);
/**
 * @fn float dividirNumeros(float, float)
 * @brief toma los numeros de la opcion 1 y 2 del menu y los divide.
 *
 * @param numeroUno Este parametro pasa el primer numero a dividir.
 * @param numeroDos Este parametro pasa el segundo numero a dividir.
 * @return Devuelve la divicion entre los dos parametros anteriores.
 */
float dividirNumeros(float numeroUno, float numeroDos);
/**
 * @fn float multiplicarNumeros(float, float)
 * @brief toma los numeros de la opcion 1 y 2 del menu y los multiplica.
 *
 * @param numeroUno Este parametro pasa el primer numero a multiplicar.
 * @param numeroDos Este parametro pasa el segundo numero a multiplicar.
 * @return Devuelve el producto entre los dos parametros anteriores.
 */
float multiplicarNumeros(float numeroUno, float numeroDos);
/**
 * @fn unsigned long int sacarFactorial(int)
 * @brief toma cualquier numero y da el factorial de este.
 *
 * @param numero Este parametro es el numero para factorizar.
 * @return Devuelve el factorial del numero ingresado.
 */
unsigned long int sacarFactorial(int numero);
/**
 * @fn void mostrarMenuFinal(float, float, float, float, float, float, int, int)
 * @brief Muestra el menu con los calculos realizados y ordenados.
 *
 * @param numeroA Este parametro toma el numero de la opcion 1 y lo muestra.
 * @param numeroB Este parametro toma el numero de la opcion 2 y lo muestra.
 * @param suma Este parametro recibe el retorno de la funcion sumarNumeros.
 * @param resta Este parametro recibe el retorno de la funcion restarNumeros.
 * @param division Este parametro recibe el retorno de la funcion dividirNumeros.
 * @param producto Este parametro recibe el retorno de la funcion multiplicarNumeros.
 * @param factorialUno Este parametro recibe el factorial del primer numero de la funcion sacarFactorial.
 * @param factorialDos Este parametro recibe el factorial del segundo numero de la funcion sacarFactorial.
 */
void mostrarMenuFinal(float numeroA, float numeroB, float suma, float resta, float division, float producto, int factorialUno, int factorialDos);


#endif /* CALCULOS_H_ */
