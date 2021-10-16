/*
 * ArrayEmployees.h
 *
 *  Created on: 30 sep. 2021
 *      Author: brans
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

#define TAM 1000
#define VACIO 0
#define OCUPADO 1
#define TAMNOMBRE 51

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

/**
 * @fn void employee_showMenu(Employee[], int, int, char*, char*, float, int, int, int, int, int, int)
 * @brief this function allows access to the program options.
 *
 * @param employee receibe the employees array.
 * @param opcionMenu receibe the option number for the menu.
 * @param idIncrementado receibe the autoincrementable id for the employees
 * @param nameAux receibe the name auxiliar for the data charge.
 * @param lastNameAux receibe the last name auxiliar for the data charge.
 * @param salaryAux receibe the salary auxiliar for the data charge.
 * @param sectorAux receibe the sector auxiliar for the data charge.
 * @param idBaja receibe the id that was be eliminated.
 * @param contadorEmpleados receibe the number of employees charged or eliminated.
 * @param order receibe the order for the sort function.
 * @param subMenu receibe the option number for the sub menu.
 * @param tam receibe the length for the other functions.
 */
void employee_showMenu(Employee employee[], int opcionMenu, int idIncrementado, char* nameAux, char* lastNameAux, float salaryAux, int sectorAux, int idBaja, int contadorEmpleados, int order, int subMenu, int tam);
/**
 * @fn int employee_initEmployees(Employee*, int)
 * @brief this function init the employees in 0.
 *
 * @param employee receibe the employees array
 * @param len receibe the length of iterations.
 * @return returns -1 if the array is ocupied. or 0 if is empty.
 */
int employee_initEmployees(Employee* employee, int len);
/**
 * @fn int employee_searchSpace(Employee*, int)
 * @brief this function search a free space to add an employee.
 *
 * @param employee receibe the employees array.
 * @param tam receibe the length of iterations.
 * @return returns the index if is free or -1 if is ocupied.
 */
int employee_searchSpace(Employee* employee, int tam);
/**
 * @fn int employee_addEmployees(Employee*, int, int, char*, char*, float, int)
 * @brief
 *
 * @param employee receibe the employees array.
 * @param len receibe the length of iterations.
 * @param id receibe the autoincrementable id.
 * @param name receibe the name auxiliar.
 * @param lastName receibe the last name auxiliar.
 * @param salary receibe the salary auxiliar.
 * @param sector receibe the sector auxiliar.
 * @return returs 0 if the employee was charged or -1 if the employee can not be charged.
 */
int employee_addEmployees(Employee* employee, int len, int id, char* name, char* lastName, float salary, int sector);
/**
 * @fn int employee_findEmployeeById(Employee*, int, int)
 * @brief this function search an employee for his id.
 *
 * @param employee receibe the employees array.
 * @param len receibe the length of iterations.
 * @param id receibe the id for the employee.
 * @return returturn the index if is 0 or -1 if have an error.
 */
int employee_findEmployeeById(Employee* employee, int len, int id);
/**
 * @fn int employee_removeEmployee(Employee*, int, int)
 * @brief this function remove an employee from the array.
 *
 * @param employee receibe the employees array.
 * @param len receibe the length of iterations.
 * @param id receibe the id for the employee.
 * @return return 0 if the employee was removed or -1 if this can not be.
 */
int employee_removeEmployee(Employee* employee, int len, int id);
/**
 * @fn int employee_modifyEmployee(Employee*, int)
 * @brief this function modifies the selected parameter of the emplyoyee.
 *
 * @param employee receibe the employees array.
 * @param tam receibe the length of iterations.
 * @return returns 0 if the employee was modified or -1 if this can not be.
 */
int employee_modifyEmployee(Employee* employee, int tam);
/**
 * @fn int employee_sortEmployee(Employee*, int, int)
 * @brief this function order the employees in ascendent or descendent form.
 *
 * @param employee receibe the employees array.
 * @param len receibe the length of iterations.
 * @param order receibe the form of order.
 * @return returns 0 if all be right or -1 if this have an error.
 */
int employee_sortEmployee(Employee* employee, int len, int order);
/**
 * @fn int employee_printEmployees(Employee[], int)
 * @brief  this functions show multiple employees.
 *
 * @param employee receibe the employees array.
 * @param len receibe the length of iterations.
 * @return returns 0 if this have not errors or -1 if this have.
 */
int employee_printEmployees(Employee employee[], int len);
/**
 * @fn int employee_printOne(Employee)
 * @brief this functions shows only one employee.
 *
 * @param employee receibe the employees array.
 * @return returns 0 if this have not errors or -1 if this have.
 */
int employee_printOne(Employee employee);
/**
 * @fn int employee_verifyConfirmation(char*)
 * @brief this function verify that the user agreed the charge, remove or modification of the employee.
 *
 * @param mensaje receibe a mesage to show in the function
 * @return returns 0 if is TRUE or -1 if is FALSE.
 */
int employee_verifyConfirmation(char* mensaje);
/**
 * @fn void employee_showModification(Employee[], int, char*)
 * @brief this function shows the employee that was be modified.
 *
 * @param employee receibe the employees array.
 * @param index receibe the position of the employee.
 * @param mensaje receibe a mensage to show in the function.
 */
void employee_showModification(Employee employee[], int index, char* mensaje);
/**
 * @fn int employee_totalSalariesAndAverages(Employee*, int)
 * @brief the total of salaries and the average was calculated in this function.
 *
 * @param employee receibe the employees array.
 * @param len receibe the length of iterations.
 * @return return 0 if this have not errors or -1 if this have.
 */
int employee_totalSalariesAndAverages(Employee* employee, int len);




#endif /* ARRAYEMPLOYEES_H_ */
