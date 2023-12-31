/**
* @brief Modulo Inventory
*
* Este modulo contiene los prototipos de las
* funciones para manejar un inventario
* 
* @file inventory.h
* @author Jaime Elso de Blas
* @version 1.0 (version inicial)
* @date 09-03-2016
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "set.h"

#define MAX_PLAYER_OBJECTS 6 /*!< Máximo número de objetos que puede llevar un jugador */

/**
 * @brief struct _Inventory
 *
 * Esta estructura define un inventario
 */
typedef struct _Inventory Inventory;

/**
 * @date 09-03-2016
 * @author Jaime Elso de Blas
 * @brief Inicializa un inventario nuevo. Reserva memoria para una estructura de 
 * tipo Inventory e inicializa todos sus campos
 * @return Inventory*: devuelve un puntero a Inventory
 */
Inventory* inventory_create();

/**
 * @date 09-03-2016
 * @author Jaime Elso de Blas
 * @brief Libera un inventario. Libera la memoria previamente reservada 
 * para el inventario
 * @param inventory: recibe un puntero a Inventory
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS inventory_destroy(Inventory* inventory);

/**
 * @date 09-03-2016
 * @author Jaime Elso de Blas
 * @brief Añade un objeto al inventario. A partir del id que recibe lo añade en el 
 * set contenido en la estructura inventory
 * @param inventory: recibe un puntero a Inventory
 * @param id: recibe el id del objeto que se desea incorporar al inventario
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS inventory_set_object(Inventory* inventory, Id id);

/**
 * @date 09-03-2016
 * @author Jaime Elso de Blas
 * @brief Nos dice los objetos que tiene un inventario. Nos dice los objetos que hay en el inventario 
 * previamente incluidos ahí
 * @param inventory: recibe un puntero a Inventory
 * @return Set*: devuelve el array de Id de los objetos
 */
Set* inventory_get_object(Inventory* inventory);

/**
 * @date 09-03-2016
 * @author Jaime Elso de Blas
 * @brief Nos dice el maximo de objetos que puede tener el inventario
 * @param inventory: recibe un puntero a Inventory
 * @return int: devuelve un entero
 */
int inventory_get_id_max(Inventory* inventory);

/**
 * @date 09-03-2016
 * @author Jaime Elso de Blas
 * @brief Pinta un inventario
 * @param inventory: recibe un puntero a Inventory
 * @return STATUS: "OK" si se ha pintado correctamente, "ERROR" si
 * ha habido algun error
 */
STATUS inventory_print(Inventory* inventory);

#endif
