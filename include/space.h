/**
 * @brief Modulo Space
 *
 * Archivo de cabecera de space.c
 * 
 * @file space.h
 * @author Jaime Elso de Blas y Sergio García Bordonado
 * @version 1.0 (version inicial)
 *  versión 1.1: modificación de las funciones space_set_object
 * y space_get_object al cambiar el tipo de variable BOOL a Id de la variable
 *  version 2.0 modificacion del tipo de variable object pasando de ser de
 * tipo Id a Set, nuevo campo en la estructura (gdesc) nuevas funciones para manejar gdesc
 * @date 02-02-2016
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"
#include "link.h"

/**
 * @brief struct _Space
 *
 * Esta estructura almacena la información sobre un espacio, su
 * dirección, nombre y si hay algún objeto.
 */
typedef struct _Space Space; 

#define MAX_SPACES 100 /*!< Maximo de espacios posibles */
#define FIRST_SPACE 1	/*!< Primer espacio */

/*Cabeceras de funciones de space.c*/

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Crea espacio. Reserva memoria para un nuevo espacio, asigna todos sus campos
 * con valores iniciales NO_ID o FALSE para el caso del objeto, y 
 * le da un valor a id.
 * @param id: recibe el indentificador del espacio que va a crear
 * @return Space* : estructura que contiene los datos de el nuevo espacio
 */
Space* space_create(Id id);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Destruye el espacio que se le asigna liberando la 
 * memoria previamente reservada para ese espacio
 * @param space: El espacio que queremos destruir 
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_destroy(Space* space);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Comprueba si el espacio que le pasamos existe y en caso 
 * afirmativo nos devuelve el valor de su id
 * @param space: El espacio del cual queremos que nos devuelva la id
 * @return Id: El valor de la variable id de dicho espacio
 */
Id space_get_id(Space* space);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el campo name de un espacio en cuestión 
 * @param space: El espacio al que queremos dar un nombre
 * @param name: el nombre que vamos a asociarle al espacio en cuestión
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_name(Space* space, char* name);

/**
 * @date 31-03-2016
 * @author Jaime Elso de Blas
 * @brief Asigna una descripcion a el espacio en cuestión 
 * @param space: El espacio al que queremos dar un nombre
 * @param description: la descripcion que vamos a asociarle al espacio en cuestión
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_description(Space* space, char* description);

/**
 * @date 5-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica la descripcion detallada del espacio 
 * @param space: El espacio al que queremos dar un nombre
 * @param description: la descripcion detallada que vamos a asociarle al espacio en cuestión
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_large_description(Space* space, char* description);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Comprueba si el espacio que le pasamos existe 
 * y en caso afirmativo nos devuelve su nombre
 * @param space: El espacio del cual queremos que nos devuelva el nómbre
 * @return  char*: El valor de la variable name de dicho espacio
 */
const char* space_get_name(Space* space);

/**
 * @date 31-03-2016
 * @author Jaime Elso de Blas
 * @brief Comprueba si el espacio que le pasamos existe 
 * y en caso afirmativo nos devuelve su descripcion
 * @param space: El espacio del cual queremos que nos devuelva el nómbre
 * @return  char*: El valor de la variable description de dicho espacio
 */
const char* space_get_description(Space* space);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el Id del link que hay al norte del espacio
 * @param space: El espacio donde queremos modificar el campo link north
 * @param id: el valor que le vamos a asignar a la variable norte
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_link_north(Space* space, Id id);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el Id del link que hay en el norte del espacio
 * @param space: El espacio del cual queremos que nos devuelva la variable
 * @return Id: El valor de la variable link north de dicho espacio
 */
Id space_get_link_north(Space* space);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el Id del link que hay al sur del espacio
 * @param space: El espacio donde queremos modificar el campo link south
 * @param id: el valor que le vamos a asignar a la variable sur
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_link_south(Space* space, Id id);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el Id del link que hay en el sur del espacio
 * @param space: El espacio del cual queremos que nos devuelva la variable
 * @return Id: El valor de la variable link south de dicho espacio
 */
Id space_get_link_south(Space* space);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el Id del link que hay al este del espacio
 * @param space: El espacio donde queremos modificar el campo link east
 * @param id: el valor que le vamos a asignar a la variable este
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_link_east(Space* space, Id id);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el Id del link que hay en el este del espacio
 * @param space: El espacio del cual queremos que nos devuelva la variable
 * @return Id: El valor de la variable link east de dicho espacio
 */
Id space_get_link_east(Space* space);


/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el Id del link que hay al oeste del espacio
 * @param space: El espacio donde queremos modificar el campo link west
 * @param id: el valor que le vamos a asignar a la variable oeste
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_link_west(Space* space, Id id);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el Id del link que hay en el oeste del espacio
 * @param space: El espacio del cual queremos que nos devuelva la variable
 * @return Id: El valor de la variable link west de dicho espacio
 */
Id space_get_link_west(Space* space);

/**
 * @date 05-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el Id del link que hay encima del espacio
 * @param space: El espacio donde queremos modificar el campo link up
 * @param id: el valor que le vamos a asignar a la variable link up
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_link_up(Space* space, Id id);

/**
 * @date 05-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el Id del link que hay en el encima del espacio
 * @param space: El espacio del cual queremos que nos devuelva la variable
 * @return Id: El valor de la variable link up de dicho espacio
 */
Id space_get_link_up(Space* space);

/**
 * @date 05-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el Id del link que hay debajo del espacio
 * @param space: El espacio donde queremos modificar el campo link down
 * @param id: el valor que le vamos a asignar a la variable link down
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_link_down(Space* space, Id id);

/**
 * @date 05-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el Id del link que hay en el debajo del espacio
 * @param space: El espacio del cual queremos que nos devuelva la variable
 * @return Id: El valor de la variable link down de dicho espacio
 */
Id space_get_link_down(Space* space);

/**
 * @date 05-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modificar la iluminación de un espacio
 * @param space: El espacio del cual queremos modificar el campo illuminated
 * @param ill: estado de la iluminación
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_illuminated(Space* space, BOOL ill);

/**
 * @date 05-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Obtener el estado de la iluminación de un espacio
 * @param space: El espacio del cual queremos obtener el campo illuminated
 * @return  BOOL: estado de la iluminación del espacio
 */
BOOL space_get_illuminated(Space* space);

/**
 * @date 05-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Moficiar la descripción detallada de un espacio
 * @param space: El espacio del cual queremos modificar el campo large_description
 * @param description: descripción detallada del espacio a añadir en él
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_large_description(Space* space, char* description);

/**
 * @date 05-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Obtener la descripción detallada de un espacio
 * @param space: El espacio del cual queremos obtener el campo large_description
 * @return const char*: descripción detallada del espacio
 */
const char* space_get_large_description(Space* space);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Modificar los objetos del espacio. Asigna un valor a la variable object
 * @param space: El espacio en el que queremos dar un valor a object
 * @param id: el id que le vamos a asignar a la variable object
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_object(Space* space, Id id);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el Set de objects del espacio
 * @param space: El espacio del que queremos obtener los objetos
 * @return  Set*: devulve un puntero a un set
 */
Set* space_get_object(Space* space);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Asigna un gdesc al espacio en cuestión
 * @param space: El espacio en el que queremos establecer la descripcion ASCII
 * @param num: La posicion en la que va
 * @param string: Descripcion ASCII
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_set_gdesc(Space* space, int num, char* string);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve la gdesc de un espacio concreto
 * @param space: El espacio del que queremos obtener la descripcion ASCII
 * @param num: numero del cual queremos obtenerla
 * @return char*: Descripcion ASCII
 */
char* space_get_gdesc(Space* space, int num);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Comprueba si el espacio que le pasamos existe y 
 * en caso afirmativo va recorriendo nuestra estructura variable por variable 
 * comprobando si existe (la variable en cuestión) , si no existe lo dice ,y si
 * existe la imprime por pantalla.
 * @param space: El espacio del cual queremos que nos imprima las variables.
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS space_print(Space* space);

#endif
