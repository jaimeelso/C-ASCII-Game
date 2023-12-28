/** 
 * @brief Implementa la funcionalidad de los links
 * 
 * @file link.h
 * @author Alfredo de Frutos Estebaranz 
 * @version 1.0 
 * @date 09-03-2016
 */

#ifndef LINK_H
#define LINK_H

#define OPEN 0 /*!< Estado del acceso: abierto*/
#define CLOSE 1 /*!< Estado del acceso: cerrado*/

#include "types.h"

/**
 * @brief struct _Link
 *
 * Esta estructura define un link
 */
typedef struct _Link Link;

#define MAX_LINKS 100 /*!< Maximo de links posibles*/

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Crea un link reservando memoria para la estructura Link
 * @param id: id del nuevo link
 * @return Link*: devuelve un puntero a Link
 */

Link* link_create(Id id);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Destruye la estructura Link y libera su memoria
 * @param link: recibe un puntero a Link
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */

STATUS link_destroy(Link* link);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el campo name de una estructura de tipo Link
 * @param link: recibe un puntero a Link
 * @param name: dato que se incluirá en el campo a modificar
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */

STATUS link_set_name(Link* link, char* name);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el campo linkA de una estructura de tipo Link
 * @param link: recibe un puntero a Link
 * @param id: dato que se incluirá en el campo a modificar
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */

STATUS link_set_linkA(Link* link, Id id);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el campo linkB de una estructura de tipo Link
 * @param link: recibe un puntero a Link
 * @param id: dato que se incluirá en el campo a modificar
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */

STATUS link_set_linkB(Link* link, Id id);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el campo access de una estructura de tipo Link
 * @param link: recibe un puntero a Link
 * @param access: dato que se incluirá en el campo a modificar 
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */

STATUS link_set_access(Link* link, int access);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve la id de una estructura Link
 * @param link: recibe un puntero a Link
 * @return Id:  devuelve la id del Link
 */

Id link_get_id(Link* link);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el nombre de una estructura Link
 * @param link: recibe un puntero a Link
 * @return const char*:  devuelve un puntero al nombre del link
 */

const char * link_get_name(Link* link);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el linkA de una estructura Link
 * @param link: recibe un puntero a Link
 * @return Id:  devuelve la id del espacio con el que está conectado el linkA
 */

Id link_get_linkA(Link* link);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el linkB de una estructura Link
 * @param link: recibe un puntero a Link
 * @return Id:  devuelve la id del espacio con el que está conectado el linkB
 */

Id link_get_linkB(Link* link);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el acceso de una estructura Link: abierto o cerrado
 * @param link: recibe un puntero a Link
 * @return int: devuelve 0 (OPEN) si está abierto y 1 (CLOSE) si está cerrado
 */

int link_get_access(Link* link);

/**
 * @date 09-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Imprime los datos de una estructura de tipo Link
 * @param link: recibe un puntero a Link
 * @return STATUS:  "OK" cuando ha terminado de imprimir la estructura
 *                  "ERROR" si ha habido algún problema
 */
STATUS link_print(Link* link);

/**
 * @date 27-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el campo clue de una estructura Link
 * @param link: recibe un puntero a Link
 * @param clue: pista del juego
 * @return STATUS:  "OK" cuando ha terminado de imprimir la estructura
 *                  "ERROR" si ha habido algún problema
 */
STATUS link_set_clue(Link* link, char* clue);

/**
 * @date 27-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve la pista de un link concreto
 * @param link: recibe un puntero a Link
 * @return STATUS:  "OK" cuando ha terminado de imprimir la estructura
 *                  "ERROR" si ha habido algún problema
 */
char* link_get_clue(Link* link);

#endif

