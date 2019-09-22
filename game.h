/**
* @brief Modulo Game
*
* Es el modulo que contiene los archivos de cabecera de "game.c"
* 
* @file game.h
* @author Jaime Elso de Blas, Sergio García Bordonado
* @version 1.0 (versión inicial)
* @date 02-02-2016
*/

#ifndef GAME_H
#define GAME_H

#define MAX_DRUNKENNESS 4 /*!< Número máximo de copas */


#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "die.h"
#include "character.h"
#include "dialogue.h"

/**
 * @brief struct _Game
 *
 * La estructura Game almacena información sobre el juego en general
 */
typedef struct _Game Game;

/*Cabeceras de funciones*/

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Inicializa la estructura Game. Inicializa todos los campos de la estructura Game, el array de punteros
 * de tipo Space y Object a NULL y player y die los iguala a las funciones 
 * correspondientes que inicializan die y player
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
Game* game_init();

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Carga la partida. Carga la partida llamando a diferentes funciones y establece la
 * localización del jugador
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param filename1: recibe el nombre del archivo de texto de los espacios
 * @param filename2: recibe el nombre del archivo de texto de los objetos
 * @param filename3: recibe el nombre del archivo de texto de los links
 * @param filename4: recibe el nombre del archivo de texto de los personajes
 * @param filename5: recibe el nombre del archivo de texto de los jugadores
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_init_from_file(Game* game, char* filename1, char* filename2, char* filename3, char* filename4, char* filename5);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Ejecuta los comandos mediante la funcion de dicho comando. Según el comando introducido por el usuario se encarga de llamar
 * a una función que realiza ese comando
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param mycmd: recibe la estructura del comando introducido por el usuario 
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_update(Game* game, MyCmd* mycmd);

/**
 * @date 20-04-2016
 * @author Jaime Elso de Blas
 * @brief Imprime un objeto desde su ID
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id: id del objeto
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
char* game_print_inventory_object(Game* game, Id id);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el espacio pedido. Devuelve un espacio con el id que le hayamos indicado
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id: id del espacio que queremos que devuelva la función
 * @return Space*: devuelve un puntero al espacio con ese id, en caso de error
 * devuelve null
 */
Space* game_get_space(Game* game, Id id);

/**
 * @date 20-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el espacio pedido. Devuelve un espacio según su posición en el array
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param i: posición  en el array del espacio que queremos que devuelva la función
 * @return Space*: devuelve un puntero al espacio con ese id, en caso de error
 * devuelve null
 */
Space* game_get_space_array_position(Game* game, int i);

/**
 * @date 20-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el objeto pedido. Devuelve un objeto según su posición en el array
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param i: posición  en el array del objeto que queremos que devuelva la función
 * @return Object*: devuelve un puntero al objeto, en caso de error
 * devuelve null
 */
Object* game_get_object_array_position(Game* game, int i);

/**
 * @date 20-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el link pedido. Devuelve un link según su posición en el array
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param i: posición  en el array del objeto que queremos que devuelva la función
 * @return Link*: devuelve un puntero al link, en caso de error
 * devuelve null
 */
Link* game_get_link_array_position(Game* game, int i);

/**
 * @date 20-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el personaje pedido. Devuelve un personaje según su posición en el array
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param i: posición  en el array del personaje que queremos que devuelva la función
 * @return Character*: devuelve un puntero al personaje, en caso de error
 * devuelve null
 */
Character* game_get_character_array_position(Game* game, int i);

/**
 * @date 20-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el jugador
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return Player*: devuelve un puntero al jugador, en caso de error
 * devuelve null
 */
Player* game_get_player(Game* game);

/**
 * @date 13-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el nombre pedido. Devuelve el nombre del objeto que le hayamos indicado
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id: id del objeto que queremos que devuelva la función
 * @return char*: devuelve un puntero al nombre
 */
char* game_get_object_name_by_id(Game* game, Id id);

/**
 * @date 09-02-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el id del espacio del jugador. Devuelve el id de la localización del jugador
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return Id: devuelve el id del espacio en esa posicion
 */
Id game_get_player_location(Game* game);

/**
 * @date 31-03-2016
 * @author Jaime Elso de Blas
 * @brief Crea un registro de los comandos introducidos.
 * @param file: archivo donde escribir el registro
 * @param status: estado del comando
 * @param command: recibe la estructura del comando introducido por el usuario 
 * @return void: no devuelve nada
 */
void game_log(FILE* file, STATUS status, MyCmd* command);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Selecciona la localización del objeto. Se encarga de seleccionar la posición del objeto 
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id_space: id del espacio en el que se ha de situar el objeto
 * @param  id_object: id del objeto que se va a establecer su localizacion
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_set_object_location(Game* game, Id id_space, Id id_object);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Borra la partida. Libera memoria de todo el juego
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_destroy(Game* game);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Añade un espacio. Se encarga de añadir spacios al array spaces[] en orden
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param space: recibe una estructura de tipo Space
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_add_space(Game* game, Space* space);

/**
 * @date 03-03-2016
 * @author Jaime Elso de Blas
 * @brief Añade un objeto. Se encarga de añadir objetos al array objects[] en orden
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param object: recibe una estructura de tipo Object
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_add_object(Game* game, Object* object);

/**
 * @date 24-03-2016
 * @author Jaime Elso de Blas
 * @brief Añade un link. Se encarga de añadir links al array links[] en orden
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param link: recibe una estructura de tipo Link
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_add_link(Game* game, Link* link);

/**
 * @date 12-04-2016
 * @author Jaime Elso de Blas
 * @brief Añade un personaje. Se encarga de añadir personajes al array links[] en orden
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param character: recibe una estructura de tipo Character
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_add_character(Game* game, Character* character);

/**
 * @date 19-04-2016
 * @author Jaime Elso de Blas
 * @brief Añade un jugador. Se encarga de añadir al jugador 
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param player: recibe una estructura de tipo Player
 * @return STATUS: "OK" si se ha añadido correctamente, "ERROR" si ha habido 
 * algun problema
 */
STATUS game_add_player(Game* game, Player* player);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Finaliza el juego. En un futuro comprobará si el juego se ha acabado, de momento solo
 * devuelve FALSE para que continue el juego
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return BOOL: devuelve FALSE siempre de momento
 */
BOOL game_is_over(Game* game);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el objeto pedido. Devuelve un objeto mediante su nombre
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param name: nombre del objeto
 * @return Object*: devuelve un puntero al objeto con ese nombre, en caso de error
 * devuelve null
 */
Object* game_get_object_by_name(Game* game, char* name);

/**
 * @date 09-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el personaje pedido. Devuelve un personaje mediante su nombre
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param name: nombre del objeto
 * @return Object*: devuelve un puntero al objeto con ese nombre, en caso de error
 * devuelve null
 */
Character* game_get_character_by_name(Game* game, char* name);

/**
 * @date 22-02-2016
 * @author Sergio García Bordonado
 * @brief Devuelve el espacio pedido. Devuelve un espacio con el id que le hayamos indicado
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id: id del espacio que queremos que devuelva la función
 * @return Object*: devuelve un puntero al objeto con ese nombre, en caso de error
 * devuelve null
 */
Object* game_get_object(Game* game, Id id);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el id de la localización del objeto.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id_object: id del objeto que quieres saber su localizacion
 * @return Id: devuelve el id del espacio en esa posicion
 */
Id game_get_object_location(Game* game, Id id_object);

/**
 * @date 18-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve un link mediante su ID
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id: id del link que queremos que devuelva la función
 * @return Link*: devuelve un puntero al link con ese id. En caso de error
 * devuelve null
 */
Link* game_get_link(Game* game, Id id);

/**
 * @date 18-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve un personaje mediante su ID
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id: id del personaje que queremos que devuelva la función
 * @return Character*: devuelve un puntero al personaje con ese id. En caso de error
 * devuelve null
 */
Character* game_get_character(Game* game, Id id);

/**
 * @date 18-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el campo large descriptión de la estructura Game
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return char*: devuelve la descripción
 */
char* game_get_large_description(Game* game);

/**
 * @date 15-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Indica si un link está abierto o cerrado
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id_link: id del link que queremos que nos diga si está abierto o cerrado
 * @return int: devuelve 0 si está abierto y 1 si está cerrado
 */
int game_get_link_access(Game* game, Id id_link);


/**
 * @date 15-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve un puntero a un link mediante su ID
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id_link: id del link
 * @return Link*: devuelve un puntero al link, en caso de error
 * devuelve null
 */
Link* game_get_link_by_id(Game* game, Id id_link);

/**
 * @date 18-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve un diálogo
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return Dialogue*: devuelve un puntero a la estructura Diálogo
 */
Dialogue* game_get_dialogue(Game* game);

/**
 * @date 23-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el nombre de un personaje mediante su ID
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id: ID del personaje
 * @return char*: nombre del personaje
 */
char* game_get_character_name_by_id(Game* game, Id id);

/**
 * @date 23-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica la localización de un objeto
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param name: nombre del objeto
 * @param location: ID de la localización próxima
 * @return char*: nombre del personaje
 */
STATUS game_change_object_location(Game* game, char* name, Id location);

/**
 * @date 25-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el campo info de una estructura Game
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return char*: info
 */
char* game_get_info(Game* game);

/**
 * @date 25-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Modifica el campo info de una estructura Game
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param info: información a añadir en el campo de la estructura
 * @return char*: info
 */
STATUS game_set_info(Game* game, char* info);

/**
 * @date 25-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve una pista concreta mediante el ID del link cerrado
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param link: ID del link cerrado
 * @return char*: pista
 */
char* game_get_clue(Game* game, Id link);

/**
 * @date 28-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el campo drunkenness de una estructura de tipo Game
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return int: grado de embriaguez
 */
int game_get_drunkenness(Game* game);

#endif