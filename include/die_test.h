/** 
* @brief Modulo die
*
* Declara los tests para el modulo die
* 
* @file die_test.h
* @author SungPil Choi
* @version 14-03-2016 versión inicial 1.0	
* @date 18-04-2016
*/

#ifndef DIE_TEST_H
#define DIE_TEST_H

#include "die.h"
#include "test.h"

#define MAX_TESTS 14 /*!< Máximo de test */

/**
 * @brief Prueba la función de creación de un dado
 * @pre Id del dado
 * @post Un puntero no nulo al dado creado
 */
void test1_die_create();

/**
 * @brief Prueba la funcion de creacion de un dado comprobando que realiza
 * la inicializacion de campos al crear el inventario
 * @pre Id del dado
 * @post Id del dado intorducido
 */
void test2_die_create();

/**
 * @brief Prueba la funcion de creacion de un dado comprobando
 * que realiza la inicializacion de campos al crear el inventario
 * @pre Id del dado
 * @post El valor de la ultima tirada del dado que al haber sido
 * inicializada solo debe ser 0
 */
void test3_die_create();

/**
 * @brief Prueba la funcion de destruir dado comprobando
 * la liberacion del dado
 * @pre Puntero al dado
 * @post Un OK que indique que se ha liberado correctamente
 */
void test1_die_destroy();

/**
 * @brief Prueba la funcion de destruir dado comprobando la liberacion
 * de un dado nulo
 * @pre Puntero nulo al dado
 * @post Un ERROR que indique que no se ha podido liberar al ser un dado nulo
 */
void test2_die_destroy();

/**
 * @brief Prueba la función de tirar dado
 * @pre Puntero al dado
 * @post Un OK que indique que se ha podido añadir el objeto
 */
void test1_die_roll();

/**
 * @brief Prueba la función de tirar dado
 * @pre Puntero nulo al dado
 * @post Un NULL que indica que no se ha podido tirar un dado nulo
 */
void test2_die_roll();

/**
 * @brief Prueba la función de obtener el valor de la última tirada
 * @pre Puntero al dado
 * @post Un 0 ya que el dado no ha sido tirado
 */
void test1_die_get_num();

/**
 * @brief Prueba la funcion de obtener el valor de la última tirada
 * @pre Puntero al dado
 * @post valor aleatorio de 1 a 6 es decir mayor a 0
 */
void test2_die_get_num();

/**
 * @brief Prueba la funcion de obtener el valor de la última tirada
 * @pre Puntero nulo al dado
 * @post Un -1 que indica que no se ha podido realizar la acción
 */
void test3_die_get_num();

/**
 * @brief Prueba la funcion que devuelve el id del dado
 * @pre Puntero al dado
 * @post El id del dado
 */
void test1_die_get_id();

/**
 * @brief Prueba la funcion que devuelve id del dado
 * @pre Puntero nulo al dado
 * @post NO_ID que indica que no se ha podido realizar la acción
 */
void test2_die_get_id();

/**
 * @brief Prueba la funcion que pinta el dado
 * @pre Puntero nulo al dado
 * @post ERROR que indica que no se ha podido pintar ya que el dado es nulo 
 */
void test1_die_print();

/**
 * @brief Prueba la funcion que pinta el dado
 * @pre Puntero al dado
 * @post OK que indica que se ha podido pintar el dado
 */
void test2_die_print();

#endif
