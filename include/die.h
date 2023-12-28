/**
 * @brief Modulo Die
 *
 * Este módulo contiene las cabeceras de las funciones para manejar die
 * 
 * @file die.h
 * @author Jaime Elso de Blas y Sergio García Bordonado
 * @version 1.0 (version inicial)
 * @date 05-03-2016
 */

#ifndef DIE_H
#define DIE_H


#include "types.h"

/**
 * @brief struct _Die
 *
 * Estructura Die almacena los datos del dado
 */
typedef struct _Die Die;

/*Cabeceras de funciones*/


/**
 * @date 05-03-2016
 * @author Sergio García Bordonado
 * @brief Crea un nuevo dado. Reserva memoria para una estructura de tipo die.
 * @param id: recibe el Id del dado a crear
 * @return Die*: devuelve una estructura de tipo Die con sus campos creados
 */
Die * die_create(Id id);

/**
 * @date 05-03-2016
 * @author Sergio García Bordonado
 * @brief Destruye un dado. Destruye el dado que recibe.
 * @param die: recibe un puntero a la estructura Die
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS die_destroy(Die * die);

/**
 * @date 05-03-2016
 * @author Sergio García Bordonado
 * @brief Lanzar el dado. Lanza el dado y actualiza el num.
 * @param die: recibe un puntero a ls estructura Die
 * @return Die*: devuelve una estructura de tipo Die con el nuevo num
 */
Die * die_roll(Die * die);

/**
 * @date 05-03-2016
 * @author Sergio García Bordonado
 * @brief Devuelve el número del ultmo lanzamiento. Devuelve el número que tiene guardado como último
 * resultado la estructura.
 * @param die: recibe un puntero a ls estructura Die
 * @return int: devuelve el valor de num
 */
int die_get_num(Die* die);

/**
 * @date 05-03-2016
 * @author Sergio García Bordonado
 * @brief Devuelve la Id. Devuelve el número de id del dado
 * @param die: recibe un puntero a ls estructura Die
 * @return Id: devuelve el id
 */
Id die_get_id(Die* die);

/**
 * @date 05-03-2016
 * @author Sergio García Bordonado
 * @brief Imprimir dado. Imprime los datos de dado
 * @param die: recibe un puntero a ls estructura Die
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS die_print(Die * die);

#endif