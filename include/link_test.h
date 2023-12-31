/** 
* @brief Modulo Link
*
* Declara los tests para el modulo link
* 
* @file link_test.h
* @author SungPil Choi
* @version 15-03-2016 versión inicial 1.0	
* @date 15-03-2016
*/

#ifndef LINK_TEST_H
#define LINK_TEST_H

#include "link.h"
#include "test.h"

#define MAX_TESTS 27 /*!< Número máximo de test */

/**
 * @brief Prueba la función de creación de un enlace
 * @pre Un puntero a un enlace y un id para el enlace
 * @post Un puntero no nulo al enlace creado
 */
void test1_link_create();

/**
 * @brief Prueba la funcion de destruir enlace comprobando
 * la liberacion de un enlace
 * @pre Puntero al enlace
 * @post Un OK que indique que se ha liberado correctamente
 */
void test1_link_destroy();

/**
 * @brief Prueba la funcion de destruir enlace comprobando la liberacion
 * de un enlace nulo
 * @pre Puntero nulo al enlace
 * @post Un ERROR que indique que no se ha podido liberar al ser un enlace nulo
 */
void test2_link_destroy();

/**
 * @brief Prueba la función de asignar un nombre comprobando
 * que se puede nombrar al enlace
 * @pre Puntero al enlace y un nombre
 * @post Un OK que indique que se ha podido nombrar al enlace
 */
void test1_link_set_name();

/**
 * @brief Prueba la función de asignar un nombre comprobando
 * que no se puede nombrar un enlace nulo
 * @pre Puntero nulo al enlace
 * @post Un ERROR que indique que no se ha podido nombrar al enlace
 */
void test2_link_set_name();

/**
 * @brief Prueba la función de asignar un nombre comprobando
 * que no se puede nombrar un enlace sin proporcionar un nombre
 * @pre Un puntero nulo al nombre que se quiere asignar
 * @post Un ERROR que indique que no se ha podido nombrar al enlace
 */
void test3_link_set_name();

/**
 * @brief Prueba la función de asignar un id a un extremo del enlace
 * @pre Un puntero al enlace y un id
 * @post Un OK que indique que se ha podido asignar el id
 */
void test1_link_set_linkA();

/**
 * @brief Prueba la función de asignar un id a un extremo del enlace
 * comprobando que no se puede asignar un id no existente
 * @pre Un puntero al enlace
 * @post Un ERROR que indique que no se ha podido asignar el id
 */
void test2_link_set_linkA();

/**
 * @brief Prueba la función de asignar un id a un extremo del enlace
 * comprobando que no se puede asignar un id a un enlace nulo
 * @pre Un puntero nulo al enlace
 * @post Un ERROR que indique que no se ha podido asignar el id
 */
void test3_link_set_linkA();

/**
 * @brief Prueba la función de asignar un id a un extremo del enlace
 * @pre Un puntero al enlace y un id
 * @post Un OK que indique que se ha podido asignar el id
 */
void test1_link_set_linkB();

/**
 * @brief Prueba la función de asignar un id a un extremo del enlace
 * comprobando que no se puede asignar un id no existente
 * @pre Un puntero al enlace
 * @post Un ERROR que indique que no se ha podido asignar el id
 */
void test2_link_set_linkB();

/**
 * @brief Prueba la función de asignar un id a un extremo del enlace
 * comprobando que no se puede asignar un id a un enlace nulo
 * @pre Un puntero nulo al enlace
 * @post Un ERROR que indique que no se ha podido asignar el id
 */
void test3_link_set_linkB();

/**
 * @brief Prueba la función de abrir o cerrar el enlace
 * @pre Un puntero al enlace y un id
 * @post Un OK que indique que se ha podido abrir el enlace
 */
void test1_link_set_access();

/**
 * @brief Prueba la función de abrir o cerrar el enlace
 * @pre Un puntero al enlace y un id
 * @post Un OK que indique que se ha podido cerrar el enlace
 */
void test2_link_set_access();

/**
 * @brief Prueba la función de abrir o cerrar el enlace comprobando
 * que no se puede abrir ni cerrar con un enlace nulo
 * @pre Un puntero nulo al enlace
 * @post Un ERROR que indique que no se ha podido cerrar ni abrir el enlace
 */
void test3_link_set_access();

/**
 * @brief Prueba la funcion que devuelve el id del enlace
 * @pre Puntero al enlace y un id
 * @post El id asignado al crear el enlace
 */
void test1_link_get_id();

/**
 * @brief Prueba la funcion que devuelve el id del enlace
 * comprobando que no devuelve el id si el enlace es nulo
 * @pre Puntero nulo al enlace
 * @post Un NO_ID que indica que no se ha podido objener el id
 */
void test2_link_get_id();

/**
 * @brief Prueba la función que obtiene el nombre de un enlace
 * @pre Puntero al enlace y un nombre
 * @post Un 0 que devuelve al comparar el nombre que hemos puesto
 * al enlace al crearlo con el que ha obtenido
 */
void test1_link_get_name();

/**
 * @brief Prueba la función que obtiene el nombre de un enlace
 * comprobando que no devuelve el nombre si el enlace es nulo
 * @pre Puntero nulo al enlace
 * @post Un NULL que indica que no se ha podido realizar
 */
void test2_link_get_name();

/**
 * @brief Prueba la función que obtiene el id de un extremo del enlace
 * @pre Un puntero al enlace y un id
 * @post Un mismo id al id que hemos introducido al crear enlace
 */
void test1_link_get_linkA();

/**
 * @brief Prueba la función que obtiene el id de un extremo del enlace
 * comprobando que no se puede obtener el id de un enlace nulo
 * @pre Un puntero nulo al enlace
 * @post Un NO_ID que indique que no se ha podido obtener el id
 */
void test2_link_get_linkA();

/**
 * @brief Prueba la función que obtiene el id de un extremo del enlace
 * @pre Un puntero al enlace y un id
 * @post Un mismo id al id que hemos introducido al crear enlace
 */
void test1_link_get_linkB();

/**
 * @brief Prueba la función que obtiene el id de un extremo del enlace
 * comprobando que no se puede obtener el id de un enlace nulo
 * @pre Un puntero nulo al enlace
 * @post Un NO_ID que indique que no se ha podido obtener el id
 */
void test2_link_get_linkB();

/**
 * @brief Prueba la función de comprobar si esta abierto o cerrado un enlace
 * @pre Un puntero al enlace y un id
 * @post Un 0 que indica que esta abierto
 */
void test1_link_get_access();

/**
 * @brief Prueba la función de comprobar si esta abierto o cerrado un enlace
 * comprobando que no se puede ver si esta abierto o cerrado un enlace nulo
 * @pre Un puntero nulo al enlace
 * @post Un -1 que indique que no se ha podido comprobar
 */
void test2_link_get_access();

/**
 * @brief Prueba la funcion que pinta el enlace
 * @pre Puntero nulo al enlace
 * @post ERROR que indica que no se ha podido pintar ya que el enlace es nulo 
 */
void test1_link_print();

/**
 * @brief Prueba la funcion que pinta el enlace
 * @pre Puntero al enlace y un id
 * @post OK que indica que se ha podido pintar el enlace creado
 */
void test2_link_print();

#endif
