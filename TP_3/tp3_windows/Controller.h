/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief se encarga de cargar el archivo de texto csv.
///
/// @param path recibe el nombre del archivo.
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorna 1 si pudo cargar la lista.
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief se encarga de cargar el archivo desde binario.
///
/// @param path recibe el nombre del archivo.
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorno 1 si pudo cargar la lista.
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/// @fn int controller_addEmployee(LinkedList*)
/// @brief añade un empleado al array.
///
/// @param pArrayListEmployee recibe la lista de empleados-
/// @return retorna 1 si pudo añadir el empleado.
int controller_addEmployee(LinkedList* pArrayListEmployee);
/// @fn int controller_editEmployee(LinkedList*)
/// @brief se encarga de editar editar los campos del empleado seleccionado.
///
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorna 1 si pudo moodificar el empleado.
int controller_editEmployee(LinkedList* pArrayListEmployee);
/// @fn int controller_removeEmployee(LinkedList*)
/// @brief se encarga de remover un empleado de la lista.
///
/// @param pArrayListEmployee recibe la lista de empleados
/// @return retorna 1 si pudo eliminar el empleado seleccionado.
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/// @fn int controller_ListEmployee(LinkedList*)
/// @brief se encarga de listar los empleados previamente cargados
///
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorna 1 si pudo listar correctamente.
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/// @fn int controller_sortEmployee(LinkedList*)
/// @brief se encarga de traer las fuciones que ordenan los empleados.
///
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorna 1 si pudo ordenar.
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief se encarga de guardar la lista de empleados en un archivo de texto.
///
/// @param path recibe el nombre del archivo.
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorna 1 si pudo guardar el texto.
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief se encarga de guardar la lista de empleados en un archivo de tecto binario.
///
/// @param path recibe el nombre del archivo.
/// @param pArrayListEmployee recibe la lista de empleados.
/// @return retorna 1 si pudo guardar los datos.
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


