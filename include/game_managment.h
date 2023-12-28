/**
* @brief Modulo Game managment
*
* Archivo de cabecera de "game_managment.c"
* 
* @file game_managment.h
* @author Jaime Elso de Blas
* @version 02-02-2016 version 1.0 (version inicial)
*   05 / 03 / 2016 Version 2.0 se añade game_managment_load_objects que se 
*   encarga de cargar objetos al juego, y se modifica load_spaces para 
*   que tambien carge la descripcion ASCII de cada casilla
* 
* @date 02-02-2016
*/

#ifndef GAME_managment_H
#define GAME_managment_H

#include "types.h"
#include "game.h"

/*Cabeceras de funciones*/

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Carga espacios. A partir de un documento de texto carga los espacios en el juego.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param filename: nombre del archivo
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS game_managment_load_spaces(Game* game, char* filename);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Carga objetos. A partir de un documento de texto carga los objetos en el juego.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param filename: nombre del archivo
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS game_managment_load_objects(Game* game, char* filename);

/**
 * @date 24-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Carga links. A partir de un documento de texto carga los links en el juego.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param filename: nombre del archivo
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS game_managment_load_links(Game* game, char* filename);

/**
 * @date 12-04-2016
 * @author Jaime Elso de Blas
 * @brief Carga personajes. A partir de un documento de texto carga los personajes en el juego.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param filename: nombre del archivo
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS game_managment_load_characters(Game* game, char* filename);

/**
 * @date 19-04-2016
 * @author Jaime Elso de Blas
 * @brief Carga jugadores. A partir de un documento de texto carga los jugadores en el juego.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param filename: nombre del archivo
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS game_managment_load_players(Game* game, char* filename);

/**
 * @date 19-04-2016
 * @author Jaime Elso de Blas
 * @brief Guarda una partida.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param save: nombre de la carpeta donde guardaremos la partida
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS game_managment_save(Game* game, char* save);

/**
 * @date 19-04-2016
 * @author Jaime Elso de Blas
 * @brief Carga una partida guardada anteriormente
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param save: nombre de la carpeta donde la partida está guardada
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS game_managment_load(Game* game, char save[]);

#endif