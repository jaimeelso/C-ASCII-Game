/** 
* @brief Modulo OBJECT
*
* Declara los tests para el modulo object
* 
* @file object_test.h
* @author SungPil Choi
* @version 22-03-2016 versión inicial 1.0	
* @date 22-03-2016
*/

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

#define MAX_TESTS 46 /*!< Número máximo de test */

/**
 * @brief Prueba la función de creación de un objeto
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al objeto creado
 */
void test1_object_create();

/**
 * @brief Prueba la función de creación de un objeto
 * @pre Un identificador como parámetro
 * @post El identificador del objeto es el introducido
 */
void test2_object_create();

/**
 * @brief Prueba la función para destruir un objeto
 * @pre Un puntero al objeto
 * @post La salida debe ser OK
 */
void test1_object_destroy();

/**
 * @brief Prueba la función para destruir un objeto
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser ERROR
 */
void test2_object_destroy();

/**
 * @brief Prueba la función para establecer el nombre de un objeto
 * @pre Nombre que establecer al objeto
 * @post La salida debe ser OK
 */
void test1_object_set_name();

/**
 * @brief Prueba la función para establecer el nombre de un objeto
 * @pre El objeto al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_name();

/**
 * @brief Prueba la función para establecer el nombre de un objeto
 * @pre El objeto es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_object_set_name();

/**
 * @brief Prueba la función para establecer la descripcion de un objeto
 * @pre La descripcion que establecer al objeto
 * @post La salida debe ser OK
 */
void test1_object_set_description();

/**
 * @brief Prueba la función para establecer la descripcion de un objeto
 * @pre El objeto al que establecer la descripcion es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_description();

/**
 * @brief Prueba la función para establecer la descripcion de un objeto
 * @pre El objeto es un puntero no NULL, pero la descripcion a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_object_set_description();

/**
 * @brief Prueba la función para establecer la descripcion alterada de un 
 * objeto si se ha modificado del estado inicial
 * @pre La descripcion que establecer al objeto
 * @post La salida debe ser OK
 */
void test1_object_set_alt_descrip();

/**
 * @brief Prueba la función para establecer la descripcion alterada de un 
 * objeto si se ha modificado del estado inicial
 * @pre El objeto al que establecer la descripcion es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_alt_descrip();

/**
 * @brief Prueba la función para establecer la descripcion alterada de un 
 * objeto si se ha modificado del estado inicial
 * @pre El objeto es un puntero no NULL, pero la descripcion a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_object_set_alt_descrip();

/**
 * @brief Prueba la función para establecer si es movible o no un objeto
 * @pre Variable BOOL 
 * @post La salida debe ser OK
 */
void test1_object_set_movable();

/**
 * @brief Prueba la función para establecer si es movible o no un objeto
 * @pre Variable BOOL
 * @post La salida debe ser ERROR
 */
void test2_object_set_movable();

/**
 * @brief Prueba la función para establecer si el objeto se ha movido o 
 * no se su posicion inicial
 * @pre Variable BOOL 
 * @post La salida debe ser OK
 */
void test1_object_set_move();

/**
 * @brief Prueba la función para establecer si el objeto se ha movido o 
 * no se su posicion inicial
 * @pre Variable BOOL
 * @post La salida debe ser ERROR
 */
void test2_object_set_move();

/**
 * @brief Prueba la función para establecer si el objeto es visible
 * @pre Variable BOOL 
 * @post La salida debe ser OK
 */
void test1_object_set_visible();

/**
 * @brief Prueba la función para establecer si el objeto es visible
 * @pre Variable BOOL
 * @post La salida debe ser ERROR
 */
void test2_object_set_visible();

/**
 * @brief Prueba la función para establecer si el objeto puede iluminar
 * @pre Variable BOOL 
 * @post La salida debe ser OK
 */
void test1_object_set_illuminate();

/**
 * @brief Prueba la función para establecer si el objeto puede iluminar
 * @pre Variable BOOL
 * @post La salida debe ser ERROR
 */
void test2_object_set_illuminate();

/**
 * @brief Prueba la función para encender un objeto
 * @pre Variable BOOL 
 * @post La salida debe ser OK
 */
void test1_object_set_on();

/**
 * @brief Prueba la función para establecer si el objeto puede iluminar
 * @pre Variable BOOL
 * @post La salida debe ser ERROR
 */
void test2_object_set_on();

/**
 * @brief Prueba la función para establecer si el objeto puede iluminar
 * @pre Variable BOOL
 * @post La salida debe ser ERROR ya que es un objeto que no puede iluminar
 */
void test3_object_set_on();

/**
 * @brief Prueba la función para establecer el id del link del objeto
 * @pre Id del link 
 * @post La salida debe ser OK
 */
void test1_object_set_link();

/**
 * @brief Prueba la función para establecer el id del link del objeto
 * @pre Id del link
 * @post La salida debe ser ERROR
 */
void test2_object_set_link();

/**
 * @brief Prueba la función para obtener el nombre de un objeto
 * @pre Un puntero al objeto
 * @post La salida debe ser 0 al usar strcmp
 */
void test1_object_get_name();

/**
 * @brief Prueba la función para obtener el nombre de un objeto
 * @pre Un puntero nulo del objeto
 * @post La salida debe ser NULL
 */
void test2_object_get_name();

/**
 * @brief Prueba la función para obtener la descripcion de un objeto
 * @pre Un puntero al objeto
 * @post La salida debe ser 0 al usar strcmp
 */
void test1_object_get_description();

/**
 * @brief Prueba la función para obtener la descripcion de un objeto
 * @pre Un puntero nulo del objeto
 * @post La salida debe ser NULL
 */
void test2_object_get_description();

/**
 * @brief Prueba la función para obtener el id de un objeto
 * @pre Un puntero al objeto
 * @post La salida debe ser el id introducido
 */
void test1_object_get_id();

/**
 * @brief Prueba la función para obtener el id de un objeto
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser NO_ID
 */
void test2_object_get_id();

/**
 * @brief Prueba la función para averiguar si es movible un objeto
 * @pre Un puntero al objeto
 * @post La salida debe ser TRUE
 */
void test1_object_get_movable();

/**
 * @brief Prueba la función para averiguar si es movible un objeto
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser FALSE
 */
void test2_object_get_movable();

/**
 * @brief Prueba la función para averiguar si se ha movido un objeto
 * de su estado inicial
 * @pre Un puntero al objeto
 * @post La salida debe ser TRUE
 */
void test1_object_get_move();

/**
 * @brief Prueba la función para averiguar si se ha movido un objeto
 * de su estado inicial
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser FALSE
 */
void test2_object_get_move();

/**
 * @brief Prueba la función para averiguar si es visible un objeto
 * @pre Un puntero al objeto
 * @post La salida debe ser TRUE
 */
void test1_object_get_visible();

/**
 * @brief Prueba la función para averiguar si es visible un objeto
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser FALSE
 */
void test2_object_get_visible();

/**
 * @brief Prueba la función para averiguar si un objeto puede iluminar
 * @pre Un puntero al objeto
 * @post La salida debe ser TRUE
 */
void test1_object_get_illuminate();

/**
 * @brief Prueba la función para averiguar si un objeto puede iluminar
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser FALSE
 */
void test2_object_get_illuminate();

/**
 * @brief Prueba la función para averiguar si esta encendido un objeto
 * @pre Un puntero al objeto
 * @post La salida debe ser TRUE
 */
void test1_object_get_on();

/**
 * @brief Prueba la función para averiguar si esta encendido un objeto
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser FALSE
 */
void test2_object_get_on();

/**
 * @brief Prueba la función para obtener el id del link
 * @pre Un puntero al objeto
 * @post La salida debe ser TRUE
 */
void test1_object_get_link();

/**
 * @brief Prueba la función para obtener el id del link
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser FALSE
 */
void test2_object_get_link();

/**
 * @brief Prueba la función que imprime el objeto
 * @pre Un puntero nulo al objeto
 * @post La salida debe ser ERROR
 */
void test1_object_print();

/**
 * @brief Prueba la función que imprime el objeto
 * @pre Un puntero al objeto
 * @post La salida debe ser OK
 */
void test2_object_print();

#endif
