/**
* @brief Modulo Character
*
* Archivo de cabecera de character.c
* 
* @file character.h
* @author Jaime Elso de Blas
* @version 1.0 (version inicial)
* @date 09-04-2016
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "types.h"

/**
 * @brief struct _Character
 *
 * Estructura Character almacena los datos de los personajes del juego
 */
typedef struct _Character Character; 


#define MAX_CHARACTERS 100 /*!< Máximo de personajes */

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Crea un personaje, reservando memoria para su estructura.
 * @param id: id del personaje a crear
 * @return Character*: estructura de tipo Character
 */
Character* character_create(Id id);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Destruye un personaje, liberando la memoria reservada.
 * @param character: estructura de tipo Character
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS character_destroy(Character* character);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el Id de una estructura Character
 * @param character: estructura de tipo Character
 * @return Id: id del personaje
 */
Id character_get_id(Character* character);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el campo location de una estructura Character
 * @param character: estructura de tipo Character
 * @param id: id de la localización
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS character_set_location(Character* character, Id id);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el campo location de una estructura Character
 * @param character: estructura de tipo Character
 * @return Id: Id de la localización
 */
Id character_get_location(Character* character);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el campo object de una estructura Character
 * @param character: estructura de tipo Character
 * @param id: id del objeto
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS character_set_object(Character* character, Id id);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el campo object de una estructura Character
 * @param character: estructura de tipo Character
 * @return Id: id del objeto
 */
Id character_get_object(Character* character);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el campo name de una estructura Character
 * @param character: estructura de tipo Character
 * @param name: nombre del personaje
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS character_set_name(Character* character, char* name);


/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el campo name de una estructura Character
 * @param character: estructura de tipo Character
 * @return char*: nombre del personaje
 */
char* character_get_name(Character* character);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el campo description de una estructura Character
 * @param character: estructura de tipo Character
 * @param description: descripción del personaje
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS character_set_description(Character* character, char* description);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el campo description de una estructura Character
 * @param character: estructura de tipo Character
 * @return char*: descripción del personaje
 */
char* character_get_description(Character* character);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el campo talk de una estructura Character
 * @param character: estructura de tipo Character
 * @param talk: indica si se ha hablado con este personaje en algún momento o no
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS character_set_talk(Character* character, BOOL talk);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el campo talk de una estructura Character
 * @param character: estructura de tipo Character
 * @return BOOL: indica si se ha hablado con este personaje en algún momento o no
 */
BOOL character_get_talk(Character* character);

#endif