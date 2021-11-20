#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define TAMNOMBRE 128

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
/// @fn Employee employee_new*()
/// @brief Se encarga de crear un espacio en memoria para una estructura de tipo empleado.
///
/// @return retorna el espacio en memoria encontrado.
Employee* employee_new();
/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief Se encarga de asignar los valores de los campos de la estructura empleado, recibiendo strings y convirtirndolos en enteros.
///
/// @param idStr recibe el string del id
/// @param nombreStr recibe el nombre
/// @param horasTrabajadasStr recibe el string de las horas trabajadas
/// @param sueldoStr recibe el string del sueldo
/// @return retorna un empleado.
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/// @fn void employee_delete(Employee*)
/// @brief se encarga de eliminar un empleado.
///
/// @param this el empleado que va a eliminar.
void employee_delete(Employee* this);
/// @fn int employee_setId(Employee*, int)
/// @brief se encarga de poner el valor al del id.
///
///
/// @param this la estructura a la cual se le asignara el id.
/// @param id el id que sera asignado a la estructura.
/// @return devielve 1 si se pudo cargar o 0 sino se pudo.
int employee_setId(Employee* this,int id);
/// @fn int employee_getId(Employee*, int*)
/// @brief se encarga de conseguir el id de la estructura recibida.
///
///
/// @param this recibe la estructura de la cual se quiere el id.
/// @param id el puntero al cual retornara la id.
/// @return retorna 0 si consiguio la id.
int employee_getId(Employee* this,int* id);
/// @fn int employee_setNombre(Employee*, char*)
/// @brief se encarga de poner el nombre en la estructura.
///
/// @param this recibe la estructura a la cual se le debe asignar el nombre.
/// @param nombre recibe el nombre que sera asignado.
/// @return devuelve 1 si pudo asignar el nombre.
int employee_setNombre(Employee* this,char* nombre);
/// @fn int employee_getNombre(Employee*, char*)
/// @brief se encarga de obtener el nombre de la estrctura que recibe.
///
/// @param this la estructura de la cual se quiere el nombre.
/// @param nombre es nombre que devuelve por puntero.
/// @return devuleve 1 si pudo encontrar el nombre.
int employee_getNombre(Employee* this,char* nombre);
/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief se encarga de poner las horas trabajadas en la estructura.
///
///
/// @param this recibe la estructura de la cual recibira las horas.
/// @param horasTrabajadas son la horas que recibira la estructura.
/// @return devuelve 1 si pudo colocar el nombre en la estructura.
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief obtiene las horas trabajadas de la estructura que recibe.
///
/// @param this la estructura de la que se quiere obtener las horas.
/// @param horasTrabajadas son las horas devueltas por puntero.
/// @return devuelve 1 se pudo obtener el nombre.
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/// @fn int employee_setSueldo(Employee*, int)
/// @brief se encarga de poner el sueldo en la estructura.
///
/// @param this la estructura que recibe el sueldo.
/// @param sueldo recibe el sueldo que se va a poner en la estructura.
/// @return devuelve 1 si pudo colocar el sueldo.
int employee_setSueldo(Employee* this,int sueldo);
/// @fn int employee_getSueldo(Employee*, int*)
/// @brief se encarga de obtener el sueldo de una estrctura.
///
/// @param this recibe la estructura de la cual se quiere obtener el sueldo.
/// @param sueldo es el sueldo devuelto por puntero.
/// @return devuelve 1 si pudo obtener
int employee_getSueldo(Employee* this,int* sueldo);
/// @fn int employee_ordenarPorId(void*, void*)
/// @brief se encarga de dar los parametros para ordenar en base al ID.
///
/// @param punteroUno recibe un puntero en void.
/// @param punteroDos recibe un segundo puntero en void.
/// @return retorna el metodo de orden.
int employee_ordenarPorId(void* punteroUno, void* punteroDos);
/// @fn int employee_ordenarPorNombre(void*, void*)
/// @brief  se encarga de dar los parametros para ordenar en base al nombre.
///
/// @param punteroUno recibe un puntero en void.
/// @param punteroDos recibe un segundo puntero en void.
/// @return devuelve lo que de la funcion strcmp.
int employee_ordenarPorNombre(void* punteroUno, void* punteroDos);
/// @fn int employee_ordenarPorHoras(void*, void*)
/// @brief se encarga de dar los parametros para ordenar por horas.
///
/// @param punteroUno recibe un puntero en void.
/// @param punteroDos recibe un segundo puntero en void.
/// @return devulve el metodo de ordenamiento.
int employee_ordenarPorHoras(void* punteroUno, void* punteroDos);
/// @fn int employee_ordenarPorSueldo(void*, void*)
/// @brief se encarga de dar los parametros para ordenar por sueldo.
///
/// @param punteroUno recibe un puntero en void.
/// @param punteroDos recibe un segundo puntero en void.
/// @return devulve el metodo de ordenamiento.
int employee_ordenarPorSueldo(void* punteroUno, void* punteroDos);
/// @fn void employee_mostrarSeleccionado(Employee*)
/// @brief se encarga de mostrar el empleado seleccionado para modificar o eliminar.
///
/// @param unEmpleado recibe el empleado a mostrar.
void employee_mostrarSeleccionado(Employee* unEmpleado);

#endif // employee_H_INCLUDED
