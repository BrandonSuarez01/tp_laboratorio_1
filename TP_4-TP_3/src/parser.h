/*
 * parser.h
 *
 *  Created on: 5 nov. 2021
 *      Author: brans
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/// @fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// @brief  se encarga de parsear los datos obtenidos del archivo de texto
/// y agregarlos a la lista de empleados.
///
/// @param pFile es el archivo de texto del cual extrae los datos.
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorna 1 si pudo pasar los empleados correctamente.
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/// @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// @brief se encarga de parsear los datos obtenidos del archivo binario
/// y agregarlos a la lista de empleados.
///
/// @param pFile es el archivo de texto del cual extrae los datos.
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorna 1 si pudo pasar los empleados correctamente.
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
