/**
 * @brief Modulo Set
 *
 * Archivo de cabeceras de "set.c"
 * 
 * @file set.h
 * @author Jaime Elso de Blas
 * @version 1.0 (version inicial)
 * @date 05-02-2016
 */


#ifndef SET_H
#define SET_H

#include "types.h"

#define MAX_SET 100 /*!< Número de máximo de IDs */

 /**
 * @brief struct _Set
 *
 * La estructura _Set contiene información sobre los tipo Set
 */
typedef struct _Set Set;

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Crea un Set. Reserva memoria para una estructura set e inicializa sus ids a NO_ID
 * @return Set*: estructura Set
 */
Set* set_create();

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Destruye un Set. Destruye una estructua de tipo Set liberando su memoria
 * @param set: estructura Set 
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS set_destroy(Set* set);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Añade una id nueva al array de ids
 * @param set: estructura Set 
 * @param id: id que queremos añadir
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS set_add_id(Set* set, Id id);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Borra una id del array de ids
 * @param set: estructura Set 
 * @param id: id que queremos borrar
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS set_del_id(Set* set, Id id);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Imprime los datos de la estructura Set
 * @param set: estructura Set que vamos a imprimir
 * @return STATUS:  "OK" cuando ha terminado de liberar la memoria
 *                  "ERROR" si ha habido algún problema
 */
STATUS set_print(Set* set);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Comprueba si una id concreta se encuentra en una estructura Set
 * @param set: estructura Set 
 * @param id: id que queremos comprobar
 * @return BOOL: devuelve "TRUE" si se encuentra en sea estructura
 */
BOOL set_check_id(Set* set, Id id);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el número de la id de una estructura Set
 * @param set: estructura Set 
 * @return int: número entero con el valor de la id
 */
int set_get_numId(Set* set);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @param set: estructura Set 
 * @return BOOL: devuelve "TRUE" si no se encuentran ids en sea estructura
 */
BOOL set_check_noId(Set* set);

/**
 * @date 05-02-2016
 * @author Jaime Elso de Blas
 * @brief Comprueba si una id concreta se encuentra en un Set , en caso afirmativo
 * la devuelve
 * @param set: estructura Set 
 * @param id: id que queremos obtenet
 * @return Id: devuelve la id en cuestión
 */
Id set_get_id(Set* set, Id id);

#endif