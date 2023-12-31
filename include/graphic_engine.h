/**
* @brief Modulo Graphic Engine
*
* Es el modulo que contiene todas las funciones necesarias para el 
* entorno grafico que se muestra por pantalla
* 
* @file graphic_engine.h
* @author Alfredo de Frutos Estebaranz
* @version 11-04-2016 version 1.0 (version inicial)
* @date 11-04-2016
*/

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"

#define MAX_ROWS 11 /*!< Máximo de filas para el espacio */

/**
 * @date 11-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Imprime los datos necesarios para la jugabilidad por pantalla
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param mycmd: recibe la dirección de una estructura de tipo MyCmd
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS graphic_engine_print_screen(Game* game, MyCmd* mycmd);

/**
 * @date 25-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Imprime la introducción del juego
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS graphic_engine_introduction();

/**
 * @date 25-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Imprime el mensaje de Oskar.ks
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS graphic_engine_message();


#endif
