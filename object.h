/**
 * @brief Modulo Object
 *
 * Contiene la implementación de las funciones asociadas a los objetos
 * 
 * @file object.h
 * @author Jaime Elso de Blas
 * @version 1.0 (version inicial)
 * @date 02-02-2016
 */

#ifndef OBJECT_H
#define OBJECT_H 

#include "types.h"

#define MAX_OBJECTS 100 /*!< Número máximo de objetos */

/**
 * @brief struct _Object
 *
 * La estructura _Object contiene información sobre un objeto
 */
typedef struct _Object Object;	/*Reenombramos "struct _Object" por "Object"*/

/*Cabeceras de las funciones*/

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Crea un nuevo objeto. Reserva memoria para una estructura de tipo object
 * @param id: recibe el Id del objeto a crear
 * @return Object *: devuelve una estructura de tipo Object con sus campos creados
 */
Object* object_create(Id id);

/**
 * @date 15-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el campo n_objects de una estructura Object
 * @param object: recibe un puntero a la estructura object
 * @param n_objects: número de objetos
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS 	object_change_n_objects(Object* object, int n_objects);

/**
 * @date 15-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve la descripción alternativa de un objeto
 * @param object: recibe un puntero a la estructura object
 * @return char*: devuelve la descripción alternativa
 */
char* object_get_alt_description(Object* object);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Crea un nuevo objeto. Reserva memoria para una estructura de tipo die
 * @param object: recibe un puntero a la estubtura object que tiene que destruir
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_destroy(Object* object);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el nombre de un objeto
 * @param object: recibe un puntero a la estubtura object en la que cambiar el nombre
 * @param name: nombre que queremos pasar.
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_name(Object* object, char* name);

/**
 * @date 31-03-2016
 * @author Jaime Elso de Blas
 * @brief Modifica la descripción de un objeto
 * @param object: recibe un puntero a la estubtura object en la que cambiar la descripcion
 * @param description: descripcion que queremos pasar.
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_description(Object* object, char* description);

/**
 * @date 31-03-2016
 * @author Jaime Elso de Blas
 * @brief Modifica la descripción alternativa de un objeto. Da una descripcion a un objeto para cuando este se ha movido de 
 * su posición original
 * @param object: recibe un puntero a la estubtura object en la que cambiar la descripcion
 * @param description: descripcion que queremos pasar.
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_alt_descrip(Object* object, char* description);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica la caracteristica de un objeto de poder moverse o no
 * @param object: recibe un puntero a la estubtura object 
 * @param movable: TRUE o FALSE
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_movable(Object* object, BOOL movable);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el campo que indica si se ha movido o no el objeto de su posicion original
 * @param object: recibe un puntero a la estubtura object 
 * @param move: TRUE o FALSE
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_move(Object* object, BOOL move);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica si el objeto es visible o no
 * @param object: recibe un puntero a la estubtura object 
 * @param visible: TRUE o FALSE
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_visible(Object* object, BOOL visible);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica si el objeto es capaz de iluminar o no
 * @param object: recibe un puntero a la estubtura object 
 * @param illuminate: TRUE o FALSE
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_illuminate(Object* object, BOOL illuminate);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica si el objeto esta encendido o apagado
 * @param object: recibe un puntero a la estubtura object 
 * @param on: TRUE o FALSE
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_on(Object* object, BOOL on);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el link con el que puede iteractuar
 * @param object: recibe un puntero a la estubtura object 
 * @param link: id del link
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_link(Object* object, Id link);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el nombre de un objeto
 * @param object: recibe un puntero a la estubtura object
 * @return char*: el nombre del objeto
 */
char* object_get_name(Object* object);

/**
 * @date 31-03-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve la descripcion de un objeto
 * @param object: recibe un puntero a la estubtura object
 * @return char*: la descripcion del objeto
 */
char* object_get_description(Object* object);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el "id" de un objeto ya establecido anteriormente.
 * @param object: recibe un puntero a la estubtura object
 * @return Id: el Id del objeto
 */
Id object_get_id(Object* object);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve la informacion de si se puede o no se puede mover
 * @param object: recibe un puntero a la estubtura object 
 * @return BOOL: TRUE o FALSE
 */
BOOL object_get_movable(Object* object);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve la informacion de si se ha movido o no
 * @param object: recibe un puntero a la estubtura object 
 * @return BOOL: TRUE o FALSE
 */
BOOL object_get_move(Object* object);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve la informacion de si un onjeto es visible o no
 * @param object: recibe un puntero a la estubtura object 
 * @return BOOL: TRUE o FALSE
 */
BOOL object_get_visible(Object* object);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve si puede iluminar o no
 * @param object: recibe un puntero a la estubtura object 
 * @return BOOL: TRUE o FALSE
 */
BOOL object_get_illuminate(Object* object);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve si esta encendido o no
 * @param object: recibe un puntero a la estubtura object 
 * @return BOOL: TRUE o FALSE
 */
BOOL object_get_on(Object* object);

/**
 * @date 05-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el id del link con el que puede iteractuar el objeto
 * @param object: recibe un puntero a la estubtura object 
 * @return Id: id del link
 */
Id object_get_link(Object* object);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Pinta por pantalla el "id" y nombre del objeto.
 * @param object: recibe un puntero a la estubtura object
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_print(Object* object);

/**
 * @date 20-04-2016
 * @author SungPil Choi
 * @brief Establece un valor al campo n_objects.
 * @param object: recibe un puntero a la estubtura object
 * @param n_objects: recibe el valor del campo
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS object_set_n_objects(Object* object, int n_objects);

/**
 * @date 20-04-2016
 * @author SungPil Choi
 * @brief Devuelve el número de objetos
 * @param object: recibe un puntero a la estubtura object 
 * @return int: número de objetos 
 */
int object_get_n_objects(Object* object);

#endif