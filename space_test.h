/** 
* @brief Modulo SPACE
*
* Declara los tests para el modulo Space
* 
* @file space_test.h
* @author SungPil Choi
* @version 21-03-2016 versión inicial 1.0	
* @date 21-03-2016
*/

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

#include "space.h"
#include "test.h"

#define MAX_TESTS 68 /*!< Número máimo de test */

/**
 * @brief Prueba la función de creación de un espacio
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al espacio creado
 */
void test1_space_create();

/**
 * @brief Prueba la función de creación de un espacio
 * @pre Un identificador como parámetro
 * @post El identificador del espacio es el introducido
 */
void test2_space_create();

/**
 * @brief Prueba la función para establecer el nombre de un espacio
 * @pre Nombre que establecer al espacio
 * @post La salida debe ser OK
 */
void test1_space_set_name();

/**
 * @brief Prueba la función para establecer el nombre de un espacio
 * @pre El espacio al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_name();

/**
 * @brief Prueba la función para establecer el nombre de un espacio
 * @pre El espacio es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_space_set_name();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio y el id del enlace
 * @post La salida debe ser OK
 */
void test1_space_set_link_north();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero nulo del espacio y el id del enlace
 * @post La salida debe ser ERROR
 */
void test2_space_set_link_north();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio
 * @post La salida debe ser ERROR
 */
void test3_space_set_link_north();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio y el id del enlace
 * @post La salida debe ser OK
 */
void test1_space_set_link_south();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero nulo del espacio y el id del enlace
 * @post La salida debe ser ERROR
 */
void test2_space_set_link_south();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio
 * @post La salida debe ser ERROR
 */
void test3_space_set_link_south();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio y el id del enlace
 * @post La salida debe ser OK
 */
void test1_space_set_link_east();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero nulo del espacio y el id del enlace
 * @post La salida debe ser ERROR
 */
void test2_space_set_link_east();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio
 * @post La salida debe ser ERROR
 */
void test3_space_set_link_east();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio y el id del enlace
 * @post La salida debe ser OK
 */
void test1_space_set_link_west();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero nulo del espacio y el id del enlace
 * @post La salida debe ser ERROR
 */
void test2_space_set_link_west();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio
 * @post La salida debe ser ERROR
 */
void test3_space_set_link_west();

/**
 * @brief Prueba la función para establecer el id de un objeto en el espacio
 * @pre Un puntero al espacio y un id del objeto
 * @post La salida debe ser OK
 */
void test1_space_set_object();

/**
 * @brief Prueba la función para establecer el id de un objeto en el espacio
 * @pre Un puntero nulo al espacio y un id del objeto
 * @post La salida debe ser ERROR
 */
void test2_space_set_object();
/**
 * @brief Prueba la función para establecer el id de un objeto en el espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser ERROR
 */
void test3_space_set_object();

/**
 * @brief Prueba la función para obtener el nombre de un espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser 0 al usar strcmp
 */
void test1_space_get_name();

/**
 * @brief Prueba la función para obtener el nombre de un espacio
 * @pre Un puntero nulo del espacio
 * @post La salida debe ser NULL
 */
void test2_space_get_name();

/**
 * @brief Prueba la función para obtener el conjunto de objetos del espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser distinto de NULL
 */
void test1_space_get_object();

/**
 * @brief Prueba la función para obtener el conjunto de objetos del espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser NULL
 */
void test2_space_get_object();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser el id introducido
 */
void test1_space_get_link_north();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser NO_ID
 */
void test2_space_get_link_north();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser el id introducido
 */
void test1_space_get_link_south();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser NO_ID
 */
void test2_space_get_link_south();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser el id introducido
 */
void test1_space_get_link_east();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser NO_ID
 */
void test2_space_get_link_east();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser el id introducido
 */
void test1_space_get_link_west();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser NO_ID
 */
void test2_space_get_link_west();

/**
 * @brief Prueba la función para obtener el id de un espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser el id introducido
 */
void test1_space_get_id();

/**
 * @brief Prueba la función para obtener el id de un espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser NO_ID
 */
void test2_space_get_id();

/**
 * @brief Prueba la función para destruir un espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser OK
 */
void test1_space_destroy();

/**
 * @brief Prueba la función para destruir un espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser ERROR
 */
void test2_space_destroy();

/**
 * @brief Prueba la función que asigna un gdesc al espacio
 * @pre Un puntero al espacio, un id y una cadena de char
 * @post La salida debe ser OK
 */
void test1_space_set_gdesc();

/**
 * @brief Prueba la función que asigna un gdesc al espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser ERROR
 */
void test2_space_set_gdesc();

/**
 * @brief Prueba la función que asigna un gdesc al espacio
 * @pre Un puntero al espacio y un id
 * @post La salida debe ser ERROR
 */
void test3_space_set_gdesc();

/**
 * @brief Prueba la función que devuelve el gdesc de un espacio
 * @pre Un puntero al espacio y un id
 * @post La salida debe ser ERROR
 */
void test1_space_get_gdesc();

/**
 * @brief Prueba la función que devuelve el gdesc de un espacio
 * @pre Un puntero nulo al espacio y un id
 * @post La salida debe ser ERROR
 */
void test2_space_get_gdesc();

/**
 * @brief Prueba la función que imprime el espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser ERROR
 */
void test1_space_print();

/**
 * @brief Prueba la función que imprime el espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser OK
 */
void test2_space_print();

/**
 * @brief Prueba la función para establecer la descripcion de un espacio
 * @pre Descripcion que establecer al espacio
 * @post La salida debe ser OK
 */
void test1_space_set_description();

/**
 * @brief Prueba la función para establecer la descripcion de un espacio
 * @pre El espacio al que establecer la descripcion es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_description();

/**
 * @brief Prueba la función para establecer la descripcion de un espacio
 * @pre El espacio es un puntero no NULL, pero la descripcion a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_space_set_description();

/**
 * @brief Prueba la función para establecer la descripcion larga de un espacio
 * @pre Descripcion larga que establecer al espacio
 * @post La salida debe ser OK
 */
void test1_space_set_large_description();

/**
 * @brief Prueba la función para establecer la descripcion larga de un espacio
 * @pre El espacio al que establecer la descripcion larga es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_large_description();

/**
 * @brief Prueba la función para establecer la descripcion larga de un espacio
 * @pre El espacio es un puntero no NULL, pero la descripcion larga a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_space_set_large_description();

/**
 * @brief Prueba la función para establecer la iluminacion o visibilidad de un espacio
 * @pre Iluminacion que establecer al espacio
 * @post La salida debe ser OK
 */
void test1_space_set_illuminated();

/**
 * @brief Prueba la función para establecer la iluminacion o visibilidad de un espacio
 * @pre El espacio al que establecer la iluminacion es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_illuminated();

/**
 * @brief Prueba la función para establecer la iluminacion o visibilidad de un espacio
 * @pre El espacio es un puntero no NULL, pero la iluminacion a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_space_set_illuminated();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio y el id del enlace
 * @post La salida debe ser OK
 */
void test1_space_set_link_up();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio pero el id es nulo
 * @post La salida debe ser ERROR
 */
void test2_space_set_link_up();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio nulo
 * @post La salida debe ser ERROR
 */
void test3_space_set_link_up();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio y el id del enlace
 * @post La salida debe ser OK
 */
void test1_space_set_link_down();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio pero el id es nulo
 * @post La salida debe ser ERROR
 */
void test2_space_set_link_down();

/**
 * @brief Prueba la función para establecer el id del enlace
 * @pre Un puntero del espacio nulo
 * @post La salida debe ser ERROR
 */
void test3_space_set_link_down();

/**
 * @brief Prueba la función para obtener la descripcion de un espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser 0 al usar strcmp
 */
void test1_space_get_description();

/**
 * @brief Prueba la función para obtener la descripcion de un espacio
 * @pre Un puntero nulo del espacio
 * @post La salida debe ser NULL
 */
void test2_space_get_description();

/**
 * @brief Prueba la función para obtener la descripcion larga de un espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser 0 al usar strcmp
 */
void test1_space_get_large_description();

/**
 * @brief Prueba la función para obtener la descripcion larga de un espacio
 * @pre Un puntero nulo del espacio
 * @post La salida debe ser NULL
 */
void test2_space_get_large_description();

/**
 * @brief Prueba la función para obtener la iluminacion o visibilidad de un espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser 0 al usar strcmp
 */
void test1_space_get_illuminated();

/**
 * @brief Prueba la función para obtener la iluminacion o visibilidad de un espacio
 * @pre Un puntero nulo del espacio
 * @post La salida debe ser NULL
 */
void test2_space_get_illuminated();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser el id introducido
 */
void test1_space_get_link_up();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser NO_ID
 */
void test2_space_get_link_up();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero al espacio
 * @post La salida debe ser el id introducido
 */
void test1_space_get_link_down();

/**
 * @brief Prueba la función para obtener el id de un enlace del espacio
 * @pre Un puntero nulo al espacio
 * @post La salida debe ser NO_ID
 */
void test2_space_get_link_down();
#endif
