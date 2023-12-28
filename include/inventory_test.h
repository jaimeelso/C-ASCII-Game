/** 
* @brief Modulo Inventory
*
* Declara los tests para el modulo Inventory
* 
* @file inventory_test.h
* @author SungPil Choi
* @version 14-03-2016 versión inicial 1.0	
* @date 14-03-2016
*/

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

#include "inventory.h"
#include "test.h"


#define MAX_TESTS 14 /*!< Número máximo de test */

/**
 * @brief Prueba la función de creación de un inventario
 * @pre No necesita ningún parámetro
 * @post Un puntero no nulo al inventario creado
 */
void test1_inventory_create();

/**
 * @brief Prueba la funcion de creacion de un inventario comprobando que realiza
 * la inicializacion de campos al crear el inventario
 * @pre Puntero al inventario
 * @post Numero máximo de objetos que puede tener el inventario creado
 */
void test2_inventory_create();

/**
 * @brief Prueba la funcion de creacion de un inventario comprobando
 * que realiza la inicializacion de campos al crear el inventario
 * @pre Puntero al inventario
 * @post Un puntero no nulo al conjunto de objetos que contiene el inventario
 */
void test3_inventory_create();

/**
 * @brief Prueba la funcion de destruir inventario comprobando
 * la liberacion de un inventario
 * @pre Puntero al inventario
 * @post Un OK que indique que se ha liberado correctamente
 */
void test1_inventory_destroy();

/**
 * @brief Prueba la funcion de destruir inventario comprobando la liberacion
 * de un inventario nulo
 * @pre Puntero nulo al inventario
 * @post Un ERROR que indique que no se ha podido liberar al ser un inventario nulo
 */
void test2_inventory_destroy();

/**
 * @brief Prueba la función de asignar objeto comprobando
 * que se puede añadir un objeto
 * @pre Puntero al inventario y un id del objeto
 * @post Un OK que indique que se ha podido añadir el objeto
 */
void test1_inventory_set_object();

/**
 * @brief Prueba la función de asignar objeto comprobando
 * que no se puede añadir un objeto a un inventario nulo
 * @pre Puntero nulo al inventario
 * @post Un ERROR que indique que no se ha podido añadir el objeto
 */
void test2_inventory_set_object();

/**
 * @brief Prueba la función de asignar objeto comprobando
 * que no se pueden añadir mas objetos de los que caben en el inventario
 * @pre Puntero al inventario y los ids de los objetos añadidos
 * @post Un OK que indique que se ha podido añadir el objeto
 */
void test3_inventory_set_object();

/**
 * @brief Prueba la funcion que devuelve el conjunto de objetos del inventario
 * @pre Puntero al inventario
 * @post Un puntero no nulo al conjunto de objetos
 */
void test1_inventory_get_object();

/**
 * @brief Prueba la funcion que devuelve el conjunto de objetos del inventario
 * @pre Puntero nulo al inventario
 * @post Un puntero nulo al conjunto de objetos
 */
void test2_inventory_get_object();

/**
 * @brief Prueba la funcion que devuelve el número máximo de objetos del inventario
 * @pre Puntero al inventario
 * @post El numero máximo de ids del inventario
 */
void test1_inventory_get_id_max();

/**
 * @brief Prueba la funcion que devuelve el número máximo de objetos del inventario
 * para comprobar que no devuelve el numero maximo de un inventario nulo
 * @pre Puntero al inventario
 * @post El numero -1 que indica error
 */
void test2_inventory_get_id_max();

/**
 * @brief Prueba la funcion que pinta el inventario
 * @pre Puntero nulo al inventario
 * @post ERROR que indica que no se ha podido pintar ya que el inventario es nulo 
 */
void test1_inventory_print();

/**
 * @brief Prueba la funcion que pinta el inventario
 * @pre Puntero al inventario
 * @post OK que indica que se ha podido pintar el inventario
 */
void test2_inventory_print();

#endif
