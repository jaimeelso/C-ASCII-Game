/** 
* @brief Modulo PLAYER
*
* Declara los tests para el modulo player
* 
* @file player_test.h
* @author SungPil Choi
* @version 22-03-2016 versión inicial 1.0	
* @date 22-03-2016
*/

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#define MAX_TESTS 26 /*!< Número máximo de test */

/**
 * @brief Prueba la función de creación de un jugador
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al jugador creado
 */
void test1_player_create();

/**
 * @brief Prueba la función de creación de un jugador
 * @pre Un identificador como parámetro
 * @post El identificador del jugador es el introducido
 */
void test2_player_create();

/**
 * @brief Prueba la función para destruir un jugador
 * @pre Un puntero al jugador
 * @post La salida debe ser OK
 */
void test1_player_destroy();

/**
 * @brief Prueba la función para destruir un jugador
 * @pre Un puntero nulo al jugador
 * @post La salida debe ser ERROR
 */
void test2_player_destroy();

/**
 * @brief Prueba la función para obtener el nombre de un jugador
 * @pre Un puntero al jugador
 * @post La salida debe ser 0 al usar strcmp
 */
void test1_player_get_name();

/**
 * @brief Prueba la función para obtener el nombre de un jugador
 * @pre Un puntero nulo del jugador
 * @post La salida debe ser NULL
 */
void test2_player_get_name();

/**
 * @brief Prueba la función para establecer el nombre de un jugador
 * @pre Nombre que establecer al jugador
 * @post La salida debe ser OK
 */
void test1_player_set_name();

/**
 * @brief Prueba la función para establecer el nombre de un jugador
 * @pre El jugador al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_player_set_name();

/**
 * @brief Prueba la función para establecer el nombre de un jugador
 * @pre El jugador es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_player_set_name();

/**
 * @brief Prueba la función para obtener el id de un jugador
 * @pre Un puntero al jugador
 * @post La salida debe ser el id introducido
 */
void test1_player_get_id();

/**
 * @brief Prueba la función para obtener el id de un jugador
 * @pre Un puntero nulo al jugador
 * @post La salida debe ser NO_ID
 */
void test2_player_get_id();

/**
 * @brief Prueba la función para obtener el id de un jugador
 * @pre Un puntero al jugador
 * @post La salida debe ser el id introducido
 */
void test1_player_set_id();

/**
 * @brief Prueba la función para obtener el id de un jugador
 * @pre Un puntero nulo al jugador
 * @post La salida debe ser NO_ID
 */
void test2_player_set_id();

/**
 * @brief Prueba la función para obtener el inventario de un jugador
 * @pre Un puntero al jugador
 * @post La salida debe ser distinto de NULL
 */
void test1_player_get_inventory();

/**
 * @brief Prueba la función para obtener el inventario de un jugador
 * @pre Un puntero nulo al jugador
 * @post La salida debe ser NULL
 */
void test2_player_get_inventory();

/**
 * @brief Prueba la función para establecer el id de un objeto del inventario
 * de un jugador
 * @pre Un puntero al jugador y un id del objeto
 * @post La salida debe ser OK
 */
void test1_player_set_inventory();

/**
 * @brief Prueba la función para establecer el id de un objeto del inventario
 * de un jugador
 * @pre Un puntero nulo al jugador y un id del objeto
 * @post La salida debe ser ERROR
 */
void test2_player_set_inventory();

/**
 * @brief Prueba la función que comprueba si el id de un objeto esta contenido
 * en el inventario de un jugador
 * @pre Un puntero al jugador y un id
 * @post La salida debe ser TRUE
 */
void test1_player_check_object();

/**
 * @brief Prueba la función que comprueba si el id de un objeto esta contenido
 * en el inventario de un jugador
 * @pre Un puntero nulo al jugador
 * @post La salida debe ser FALSE
 */
void test2_player_check_object();

/**
 * @brief Prueba la función que comprueba si el id de un objeto esta contenido
 * en el inventario de un jugador
 * @pre Un puntero al jugador y un id nulo
 * @post La salida debe ser FALSE
 */
void test3_player_check_object();

/**
 * @brief Prueba la función que obtiene el id del espacio en el que se encuentra
 * el jugador
 * @pre Un puntero al jugador y un id del espacio
 * @post La salida debe ser el id 
 */
void test1_player_get_location();

/**
 * @brief Prueba la función que obtiene el id del espacio en el que se encuentra
 * el jugador
 * @pre Un puntero nulo al jugador
 * @post La salida debe ser NO_ID
 */
void test2_player_get_location();

/**
 * @brief Prueba la función que asigna el id del espacio del jugador
 * @pre Un puntero al jugador y un id del espacio
 * @post La salida debe ser OK
 */
void test1_player_set_location();

/**
 * @brief Prueba la función que asigna el id del espacio del jugador
 * @pre Un puntero nulo al jugador
 * @post La salida debe ser ERROR
 */
void test2_player_set_location();

/**
 * @brief Prueba la función que imprime el jugador
 * @pre Un puntero nulo al jugador
 * @post La salida debe ser ERROR
 */
void test1_player_print();

/**
 * @brief Prueba la función que imprime el jugador
 * @pre Un puntero al jugador
 * @post La salida debe ser OK
 */
void test2_player_print();

#endif