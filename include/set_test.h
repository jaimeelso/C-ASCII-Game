/** 
* @brief Modulo set
*
* Declara los tests para el modulo set
* 
* @file set_test.h
* @author SungPil Choi
* @version 14-03-2016 versión inicial 1.0	
* @date 18-04-2016
*/

#ifndef SET_TEST_H
#define SET_TEST_H

#include "set.h"
#include "test.h"

#define MAX_TESTS 31 /*!< Número máximo de test */

/**
 * @brief Prueba la función de creación de un conjunto
 * @pre Puntero a un conjunto
 * @post Un puntero no nulo al conjunto creado
 */
void test1_set_create();

/**
 * @brief Prueba la función de creación de un conjunto
 * @pre Un id para buscar
 * @post NO_ID al obtener un id en el conjunto ya que este
 * id buscado no existe en el conjunto
 */
void test2_set_create();

/**
 * @brief Prueba la función de creación de un conjunto
 * @pre Puntero a un conjunto
 * @post el numero de ids que tiene el conjunto guardado
 */
void test3_set_create();

/**
 * @brief Prueba la función de destruir un conjunto
 * @pre Puntero a un conjunto
 * @post OK
 */
void test1_set_destroy();

/**
 * @brief Prueba la función de destruir un conjunto
 * @pre Puntero a un conjunto
 * @post ERROR
 */
void test2_set_destroy();

/**
 * @brief Prueba la función de añadir id a un conjunto
 * @pre Puntero a un conjunto y un id
 * @post OK
 */
void test1_set_add_id();

/**
 * @brief Prueba la función de añadir id a un conjunto
 * @pre Puntero nulo a un conjunto y un id
 * @post ERROR
 */
void test2_set_add_id();

/**
 * @brief Prueba la función de añadir id a un conjunto
 * @pre Puntero a un conjunto y un id nulo
 * @post ERROR
 */
void test3_set_add_id();

/**
 * @brief Prueba la función de añadir id a un conjunto
 * @pre Puntero a un conjunto y un numero mayor que MAX_SET de ids 
 * @post ERROR ya que no entran mas ids
 */
void test4_set_add_id();

/**
 * @brief Prueba la función de borrar un id especifico de un conjunto
 * @pre Puntero a un conjunto y un id
 * @post OK
 */
void test1_set_del_id();

/**
 * @brief Prueba la función de borrar un id especifico de un conjunto
 * @pre Puntero a un conjunto y un id
 * @post ERROR ya que el id buscado no esta en el conjunto
 */
void test2_set_del_id();

/**
 * @brief Prueba la función de borrar un id especifico de un conjunto
 * @pre Puntero nulo a un conjunto y un id
 * @post ERROR
 */
void test3_set_del_id();

/**
 * @brief Prueba la función de borrar un id especifico de un conjunto
 * @pre Puntero a un conjunto y un id
 * @post ERROR ya que el id buscado no esta en el conjunto
 */
void test4_set_del_id();

/**
 * @brief Prueba la función de borrar un id especifico de un conjunto
 * @pre Puntero a un conjunto y un id nulo
 * @post ERROR
 */
void test5_set_del_id();

/**
 * @brief Prueba la función de imprimir un conjunto
 * @pre Puntero nulo a un conjunto
 * @post ERROR
 */
void test1_set_print();

/**
 * @brief Prueba la función de imprimir un conjunto
 * @pre Puntero a un conjunto con id dentro
 * @post OK
 */
void test2_set_print();

/**
 * @brief Prueba la función de imprimir un conjunto
 * @pre Puntero a un conjunto vacio
 * @post OK
 */
void test3_set_print();

/**
 * @brief Prueba la función busca un id concreto dentro de un conjunto
 * @pre Puntero a un conjunto y un id que pertenece al conjunto
 * @post TRUE
 */
void test1_set_check_id();

/**
 * @brief Prueba la función busca un id concreto dentro de un conjunto
 * @pre Puntero a un conjunto y un id nulo
 * @post FALSE
 */
void test2_set_check_id();

/**
 * @brief Prueba la función busca un id concreto dentro de un conjunto
 * @pre Puntero nulo a un conjunto y un id
 * @post FALSE
 */
void test3_set_check_id();

/**
 * @brief Prueba la función busca un id concreto dentro de un conjunto
 * @pre Puntero a un conjunto y un id que no se encuentra en el conjunto
 * @post FALSE
 */
void test4_set_check_id();

/**
 * @brief Prueba la función busca un id concreto dentro de un conjunto
 * @pre Puntero a un conjunto vacio y un id
 * @post FALSE
 */
void test5_set_check_id();

/**
 * @brief Prueba la función que devuelve el numero
 * de ids que almacena un conjunto
 * @pre Puntero a un conjunto y un id
 * @post 1 que es el numero de id introducido
 */
void test1_set_get_numId();

/**
 * @brief Prueba la función que devuelve el numero
 * de ids que almacena un conjunto
 * @pre Puntero a un conjunto vacio
 * @post -1 ya que no hay ids
 */
void test2_set_get_numId();

/**
 * @brief Prueba la función que comprueba si esta vacia un conjunto
 * @pre Puntero a un conjunto y un id que introducimos en el conjunto
 * @post FALSE ya que no esta vacia
 */
void test1_set_check_noId();

/**
 * @brief Prueba la función que comprueba si esta vacia un conjunto
 * @pre Puntero a un conjunto nulo
 * @post FALSE pero que indica fallo de ejecucion
 */
void test2_set_check_noId();

/**
 * @brief Prueba la función que comprueba si esta vacia un conjunto
 * @pre Puntero a un conjunto vacio
 * @post TRUE ya que esta vacia
 */
void test3_set_check_noId();

/**
 * @brief Prueba la función que te duvuelve un id especifico de
 * un conjunto
 * @pre Puntero a un conjunto y un id que introducimos en el
 * conjunto y otro igual que queremos obtener
 * @post el id buscado
 */
void test1_set_get_id();

/**
 * @brief Prueba la función que te duvuelve un id especifico de
 * un conjunto
 * @pre Puntero a un conjunto y un id que introducimos en el
 * conjunto y otro diferente que queremos obtener
 * @post NO_ID
 */
void test2_set_get_id();

/**
 * @brief Prueba la función que te duvuelve un id especifico de
 * un conjunto
 * @pre Puntero a un conjunto vacio y un id que queremos obtener
 * @post NO_ID ya que esta vacio
 */
void test3_set_get_id();

/**
 * @brief Prueba la función que te duvuelve un id especifico de
 * un conjunto
 * @pre Puntero nulo a un conjunto y un id que queremos obtener
 * @post NO_ID
 */
void test4_set_get_id();

#endif
