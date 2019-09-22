/** 
* @brief Modulo CHARACTER
*
* Declara los tests para el modulo character
* 
* @file character_test.h
* @author SungPil Choi
* @version 22-03-2016 versión inicial 1.0	
* @date 22-03-2016
*/

#ifndef CHARACTER_TEST_H
#define CHARACTER_TEST_H

#include "character.h"
#include "test.h"

#define MAX_TESTS 29 /*!< Máximo de test */

/**
 * @brief Prueba la función de creación de un personaje
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al personaje creado
 */
void test1_character_create();

/**
 * @brief Prueba la función de creación de un personaje
 * @pre Un identificador como parámetro
 * @post El identificador del personaje que es introducido
 */
void test2_character_create();

/**
 * @brief Prueba la función para destruir un personaje
 * @pre Un puntero al personaje
 * @post La salida debe ser OK
 */
void test1_character_destroy();

/**
 * @brief Prueba la función para destruir un personaje
 * @pre Un puntero nulo al personaje
 * @post La salida debe ser ERROR
 */
void test2_character_destroy();

/**
 * @brief Prueba la función para obtener el id de un personaje
 * @pre Un puntero al personaje
 * @post La salida debe ser el id introducido
 */
void test1_character_get_id();

/**
 * @brief Prueba la función para obtener el id de un personaje
 * @pre Un puntero nulo al personaje
 * @post La salida debe ser NO_ID
 */
void test2_character_get_id();

/**
 * @brief Prueba la función para establecer la localizacion de un personaje
 * @pre El id de la localizacion que establecer al personaje
 * @post La salida debe ser OK
 */
void test1_character_set_location();

/**
 * @brief Prueba la función para establecer la localizacion de un personaje
 * @pre El id de la localizacion y un puntero nulo al personaje
 * @post La salida debe ser ERROR
 */
void test2_character_set_location();

/**
 * @brief Prueba la función para obtener la localizacion de un personaje
 * @pre Un puntero al personaje
 * @post Id de la localizacion
 */
void test1_character_get_location();

/**
 * @brief Prueba la función para obtener la localizacion de un personaje
 * @pre Un puntero nulo del personaje
 * @post La salida debe ser NO_ID
 */
void test2_character_get_location();

/**
 * @brief Prueba la función para dar un objeto a un personaje
 * @pre Id del objeto
 * @post La salida debe ser OK
 */
void test1_character_set_object();

/**
 * @brief Prueba la función para dar un objeto a un personaje
 * @pre NO_ID es decir un id nulo del objeto
 * @post La salida debe ser ERROR
 */
void test2_character_set_object();

/**
 * @brief Prueba la función para dar un objeto a un personaje
 * @pre puntero nulo al objeto
 * @post La salida debe ser ERROR
 */
void test3_character_set_object();

/**
 * @brief Prueba la función para obtener el objeto de un personaje
 * @pre Un puntero al personaje
 * @post La salida debe ser el id del objeto
 */
void test1_character_get_object();

/**
 * @brief Prueba la función para obtener el objeto de un personaje
 * @pre Un puntero nulo al personaje
 * @post La salida debe ser NO_ID
 */
void test2_character_get_object();

/**
 * @brief Prueba la función para establecer el nombre de un personaje
 * @pre Nombre que establecer al personaje
 * @post La salida debe ser OK
 */
void test1_character_set_name();

/**
 * @brief Prueba la función para establecer el nombre de un personaje
 * @pre El personaje al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_character_set_name();

/**
 * @brief Prueba la función para establecer el nombre de un personaje
 * @pre El personaje es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_character_set_name();

/**
 * @brief Prueba la función para obtener el nombre de un personaje
 * @pre Un puntero al personaje
 * @post La salida debe ser 0 al usar strcmp
 */
void test1_character_get_name();

/**
 * @brief Prueba la función para obtener el nombre de un personaje
 * @pre Un puntero nulo del personaje
 * @post La salida debe ser NULL
 */
void test2_character_get_name();

/**
 * @brief Prueba la función para establecer la descripcion de un personaje
 * @pre La descripcion que establecer al personaje
 * @post La salida debe ser OK
 */
void test1_character_set_description();

/**
 * @brief Prueba la función para establecer la descripcion de un personaje
 * @pre El personaje al que establecer la descripcion es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_character_set_description();

/**
 * @brief Prueba la función para establecer la descripcion de un personaje
 * @pre El personaje es un puntero no NULL, pero la descripcion a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_character_set_description();

/**
 * @brief Prueba la función para obtener la descripcion de un personaje
 * @pre Puntero al personaje
 * @post La salida debe ser la descripcion del personaje
 */
void test1_character_get_description();

/**
 * @brief Prueba la función para obtener la descripcion de un personaje
 * @pre Puntero nulo al personaje
 * @post La salida debe ser ERROR
 */
void test2_character_get_description();

/**
 * @brief Prueba la función para establecer si el personaje puede hablar o no
 * @pre Variable BOOL 
 * @post La salida debe ser OK
 */
void test1_character_set_talk();

/**
 * @brief Prueba la función para establecer si el personaje puede hablar o no
 * @pre Variable BOOL
 * @post La salida debe ser ERROR
 */
void test2_character_set_talk();

/**
 * @brief Prueba la función para averiguar si el personaje puede hablar o no
 * @pre Puntero al personaje 
 * @post La salida debe ser TRUE
 */
void test1_character_get_talk();

/**
 * @brief Prueba la función para averiguar si el personaje puede hablar o no
 * @pre Puntero nulo al personaje
 * @post La salida debe ser FALSE
 */
void test2_character_get_talk();

#endif
