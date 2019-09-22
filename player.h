/**
 * @brief Modulo Player
 *
 * Es el módulo que contiene todas las cabeceras de las
 * funciones que controlan al jugdor
 * 
 * @file player.h
 * @author Sergio García Bordonado
 * @version 1.0 (version inicial)
 *  versión 1.1: corrección de errores en la función player_create al
 *  no asignar un Id al crearlo
 *  version 2.0: Nuevos prototipos de funciones y cambios en antiguos
 * @date 03-02-2016
 */

#ifndef PLAYER_H
#define PLAYER_H 

#include <stdio.h>
#include <string.h>

#include "inventory.h"
#include "types.h"

/**
 * @brief struct _Player
 *
 * La estructura Player almacena información sobre el jugador
 */
typedef struct _Player Player;	/*Reenombramos "struct _Player" por "Player"*/

/*Cabeceras de las funciones*/

/**
 * @date 03-02-2016
 * @author Sergio Garía Bordonado
 * @brief Crea un nuevo jugador. Reserva memoria para una estructura de tipo player
 * @param id: recibe el Id del jugador 
 * @return Player*: devuelve una estructura de tipo Player con sus campos creados
 */
Player* player_create(Id id);

/**
 * @date 03-02-2016
 * @author Sergio Garía Bordonado
 * @brief Destruir jugador. Destruye la estructura de player que le pasamos
 * @param player: estructura Player del jugador
 * @return STATUS: OK / ERROR
 */
STATUS player_destroy(Player* player);

/**
 * @date 03-02-2016
 * @author Sergio Garía Bordonado
 * @brief Obtener nombre. Devuelve el nombre de un jugador ya establecido anteriormente. 
 * @param player: estructura Player del jugador
 * @return char*: Nombre del jugador.
 */
const char* player_get_name(Player* player);

/**
 * @date 03-02-2016
 * @author Sergio Garía Bordonado
 * @brief Dar nombre. Le da nombre a un jugador previamente creado.
 * 
 * @param player: estructura Player del jugador
 * @param name: Nombre que queremos darle
 * @return STATUS: OK / ERROR
 */
STATUS player_set_name(Player* player, char* name);

/**
 * @date 03-02-2016
 * @author Sergio Garía Bordonado
 * @brief Obtener id. Devuelve el "id" de un jugador ya establecido anteriormente.
 * @param player: estructura Player del jugador
 * @return Id: valor de la variable "id" contenida en _Player
 */
Id player_get_id(Player* player);

/**
 * @date 03-02-2016
 * @author Sergio Garía Bordonado
 * @brief Dar nueva Id. Nos permite darle una identificación a un jugador ya creado
 * @param player: estructura Player del jugador
 * @param id: nuevo id que le damos al jugador
 * @return STATUS: OK / ERROR
 */
STATUS player_set_id(Player* player, Id id);

/**
 * @date 13-03-2016
 * @author Jaime Elso de Blas
 * @brief Nos devuelve el inventario del jugador. 
 * @param player: estructura Player del jugador
 * @return Inventory*: devuelve la estructura de tipo inventory con los objetos
 */
Inventory* player_get_inventory(Player* player);

/**
 * @date 13-03-2016
 * @author Jaime Elso de Blas
 * @brief Añade un objeto al inventario del jugador.
 * @param player: La estructura en el que queremos dar un valor a object
 * @param id: el valor que le vamos a asignar a la variable object
 * @return STATUS: "OK" o "ERROR"
 */
STATUS player_set_inventory(Player* player, Id id);

/**
 * @date 13-03-2016
 * @author Jaime Elso de Blas
 * @brief Comprueba si el id de un objeto esta contenido en un inventario
 * @param player: La estructura en el que queremos ver si esta el object
 * @param id: el valor del object que buscamos
 * @return BOOL: "TRUE" o "FALSE"
 */
BOOL player_check_object(Player* player, Id id);

/**
 * @date 03-02-2016
 * @author Sergio Garía Bordonado
 * @brief Obtener localización. Devuelve la localización del jugador
 * @param player: estructura Player del jugador
 * @return Id: valor de la variable "id" del espacio en el que se encuentra
 */
Id player_get_location(Player* player);

/**
 * @date 03-02-2016
 * @author Sergio Garía Bordonado
 * @brief Dar localización. Nos permite darle una localización de nuestro jugador.
 * @param player: La estructura en el que queremos dar un valor a object
 * @param id: el id de la localización que le vamos a asignar
 * @return STATUS: "OK" o "ERROR"
 */
STATUS player_set_location(Player* player, Id id);

/**
 * @date 03-02-2016
 * @author Sergio García Bordonado
 * @brief Imprime por pantalla los datos del jugador.
 * @param player: recibe un puntero a la estubtura Player
 * @return STATUS: OK / ERROR
 */
STATUS player_print(Player* player);

#endif