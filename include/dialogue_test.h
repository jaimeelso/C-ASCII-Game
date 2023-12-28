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

#include "dialogue.h"
#include "test.h"

#define MAX_TESTS 11 /*!< Máximo de test */

/**
 * @brief Prueba la función de creación de un dialogo
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al dialogo creado
 */
void test1_dialogue_create();

/**
 * @brief Prueba la función de la eliminacion de un dialogo
 * @pre Un identificador como parámetro
 * @post OK
 */
void test1_dialogue_destroy();

/**
 * @brief Prueba la función de la eliminacion de un dialogo
 * @pre Un identificador como parámetro
 * @post ERROR
 */
void test2_dialogue_destroy();

/**
 * @brief Prueba la función para obtener una conversacion de un dialogo
 * @pre Un identificador como parámetro
 * @post El dialogo buscado
 */
void test1_dialogue_get_conv();

/**
 * @brief Prueba la función para obtener una conversacion de un dialogo
 * @pre Un identificador como parámetro
 * @post NULL
 */
void test2_dialogue_get_conv();

/**
 * @brief Prueba la función para introducir una conversacion a un dialogo
 * @pre Un identificador como parámetro
 * @post OK
 */
void test1_dialogue_set_conv();

/**
 * @brief Prueba la función para introducir una conversacion a un dialogo
 * @pre Un identificador como parámetro
 * @post ERROR
 */
void test2_dialogue_set_conv();

/**
 * @brief Prueba la función para vaciar un dialogo
 * @pre Un identificador como parámetro
 * @post OK
 */
void test1_dialogue_reset();

/**
 * @brief Prueba la función para vaciar un dialogo
 * @pre Un identificador como parámetro
 * @post ERROR
 */
void test2_dialogue_reset();

/**
 * @brief Prueba la función para comprobar si un dialogo esta vacio o no
 * @pre Un identificador como parámetro
 * @post TRUE
 */
void test1_dialogue_status();

/**
 * @brief Prueba la función para comprobar si un dialogo esta vacio o no
 * @pre Un identificador como parámetro
 * @post FALSE porque no esta vacia
 */
void test2_dialogue_status();

#endif
