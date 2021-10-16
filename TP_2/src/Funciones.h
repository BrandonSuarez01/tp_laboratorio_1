/*
 * Funciones.h
 *
 *  Created on: 30 sep. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief da valor de un numero entero a una varible que recibe por referencia y valida en un rango determinado.
 *
 * @param enteroDevuelto es el numero entero que devulve por referencia.
 * @param mensaje recibe un mensaje para mostrar dentro de la funcion.
 * @param mensajeError recibe el mensaje a mostrar en caso de error.
 * @param min el rango minimo del entero a ingresar.
 * @param max el rango maximo del entero a ingresar.
 * @return devulve 0 si se pudo cargar un numero correctamente, en caso contrario devulve -1.
 */
int pedirEntero(int* enteroDevuelto, char* mensaje, char* mensajeError, int min, int max);
/// @fn void pedirString(char*, char*, char*, int)
/// @brief permite el ingreso de una cadena de caracteres y la copia en una varible que recibe por referencia
///
/// @param nombre es la variable que recibe la cadena de caracteres.
/// @param primerMensaje recibe un mensaje para mostrar dentro de la funcion.
/// @param mensajeError recibe el mensaje a mostrar en caso de error.
/// @param max recibe el tamaño maximo del array de caracteres.
void pedirString(char* nombre, char* primerMensaje, char* mensajeError, int max);
/// @fn int pedirFlotante(float*, char*, char*, int, int)
/// @brief da valor de un numero flotante a una varible que recibe por referencia y valida en un rango determinado.
///
/// @param flotanteDevuelto es el numero flotante que devulve por referencia.
/// @param mensaje recibe un mensaje para mostrar dentro de la funcion.
/// @param mensajeError recibe el mensaje a mostrar en caso de error.
/// @param min el rango minimo del flotante a ingresar.
/// @param max el rango maximo del flotante a ingresar.
/// @return devulve 0 si se pudo cargar un numero correctamente, en caso contrario devulve -1.
int pedirFlotante(float* flotanteDevuelto, char* mensaje, char* mensajeError, int min, int max);
/// @fn void pedirCaracter(char*, char*)
/// @brief pide un unico caracter.
///
/// @param caracter es la varible que recibe y devulve por referencia.
/// @param mensaje recibe un mensaje para mostrar dentro de la funcion.
void pedirCaracter(char* caracter, char* mensaje);
/// @fn int validarSigno(char*)
/// @brief valida un array de caracteres para que no tenga signos, ademas de validar que tampoco tenga un numero.
///
/// @param string es el array de caracteres a validar que recibe por parametro.
/// @return devulve 0 si completo la validacion sin errores, en caso contrario devuelve -1.
int validarSigno(char* string);

//int validarEntero(char* cadena);



#endif /* FUNCIONES_H_ */
