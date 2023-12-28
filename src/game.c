/**
* @brief Modulo Game
*
* Es el modulo que contiene todas las funciones necesarias para la implementación
* de la jugabilidad y el entorno grafico que se muestra por pantalla
* 
* @file game.c
* @author Jaime Elso de Blas, Sergio García Bordonado
* @version 05-03-2016 version 1.0 (version inicial)
* @date 05-03-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/game.h"
#include "../include/game_managment.h"


#ifdef __WINDOWS_BUILD__
#define CLEAR "cls"     /*!< Clear de la consola */
#else
#define CLEAR "clear"   /*!< Clear de la consola */
#endif

/**
 * @brief struct _Game
 *
 * La estructura Game almacena información sobre el juego en general
 */
struct _Game {
  Player* player;                 /*!< Puntero a la estructura Player*/
  Object* object[MAX_OBJECTS];    /*!< Puntero a la estructura Object*/
  Space* spaces[MAX_SPACES + 1];  /*!< Array de punteros a la estructura Space*/
  Link* links[MAX_LINKS];         /*!< Array de punteros a la estructura Link*/
  Character* characters[MAX_CHARACTERS]; /*!< Personajes del juego*/
  Die*  die;                     /*!< Dado*/
  Dialogue* dialogue;             /*!< Dialogo*/
  char large_description[LARGE_DESCRIPTION_SIZE]; /*!< Descripción de espacio u objeto*/
  char info[LARGE_DESCRIPTION_SIZE]; /*!< Información adicional */
  int drunkenness;                /*!< Nivel de embriaguez */
};

/*Lista de callbacks para los comandos del juego*/ 

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Callback para comando desconocido. No hace nada.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_UNKNOWN(Game* game);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Callback para comando quitar. No hace nada, solo sirve para salir del bucle del juego.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_QUIT(Game* game);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Avanza una casilla al sur. Hace que una vez introducido el comando "avanzar sur" el jugador avance a 
 * la siguiente casilla hacia el sur en caso de que sea posible
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_GO_SOUTH(Game* game);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Avanza una casilla al norte. Hace que una vez introducido el comando "avanzar norte" el jugador avance a 
 * la siguiente casilla hacia el norte en caso de que sea posible
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_GO_NORTH(Game* game);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Avanza una casilla al este. Hace que una vez introducido el comando "avanzar este" el jugador avance a 
 * la siguiente casilla hacia el este en caso de que sea posible
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_GO_EAST(Game* game);

/**
 * @date 02-02-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Avanza una casilla al oeste. Hace que una vez introducido el comando "avanzar oeste" el jugador avance a 
 * la siguiente casilla hacia el oeste en caso de que sea posible
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_GO_WEST(Game* game);

/**
 * @date 02-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Avanza una casilla arriba. Hace que una vez introducido el comando "avanzar arriba" el jugador avance a 
 * la siguiente casilla hacia arriba en caso de que sea posible
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_GO_UP(Game* game);

/**
 * @date 02-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Avanza una casilla abajo. Hace que una vez introducido el comando "avanzar abajo" el jugador avance a 
 * la siguiente casilla hacia abajo en caso de que sea posible
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_GO_DOWN(Game* game);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Recoge un objeto. Hace que una vez introducido el comando "coger" y después el objeto
 * que desea coger, entonces, el jugador coge ese determinado objeto
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param name: nombre del objeto que desea coger
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_TAKE(Game* game, char* name);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Suelta un objeto. Hace que una vez introducido el comando "dejar" el jugador deje el 
 * objeto que lleva encima en la casilla
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param name: nombre del objeto que desea dejar
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_DROP(Game* game, char* name);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Tira el dado. Hace que una vez introducido el comando "lanzar" el jugador tire el dado
 * y se muestre por pantalla el resultado
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_ROLL(Game* game);

/**
 * @date 31-03-2016
 * @author Sergio Garcia Bordonado
 * @brief Inspeccionar objeto. Hace que una vez introducido el comando "inspeccionar + <nombre_objeto>" 
 * muestre por pantalla la descripcion de un objeto determinado
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param name: nombre del objeto que desea inspeccionar
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_INSPECT_OBJECT(Game* game, char* name);

/**
 * @date 31-03-2016
 * @author Sergio Garcia Bordonado
 * @brief Inspeccionar espacio. Hace que una vez introducido el comando "inspeccionar espacio" 
 * muestre por pantalla la descripcion de un espacio determinado
 * @param game: recibe la dirección de una estructura de tipo Game
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_INSPECT_SPACE(Game* game);

/**
 * @date 06-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Ilumina un objeto
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param obj_name: nombre del objeto que se desea modifcar el campo illuminate
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_TURNON(Game* game, char* obj_name);

/**
 * @date 06-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Oscurece un objeto
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param obj_name: nombre del objeto que se desea modifcar el campo illuminate
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_TURNOFF(Game* game, char* obj_name);

/**
 * @date 09-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Abre el acceso de un link
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param obj_name: nombre del objeto
 * @param link_name: nombre del link
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_OPEN(Game* game, char* obj_name, char* link_name);

/**
 * @date 09-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Guarda una partida.
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param save: nombre de la partida a guardar
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_SAVE(Game* game, char* save);

/**
 * @date 09-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Hablar con personajes
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param name: nombre del personaje con el que se desea hablar
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_TALK(Game* game, char* name);

/**
 * @date 09-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Comando para beber copas
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param obj_name: nombre del objeto
 * @return STATUS: "OK" cuando ha realizado el comando correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS callback_DRINK(Game* game, char* obj_name);

/*Funciones privadas*/

/**
 * @date 09-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el link mediante su nombre
 *
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param name: nombre del link
 * @return Link*: devuelve un puntero al link con ese nombre, en caso de error
 * devuelve NULL
 */
Link* game_get_link_by_name(Game* game, char* name);

/**
 * @date 02-02-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve el id de un espacio. Devuelve el id de un espacio es una posición determinada
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param position: posición del espacio que queremos que devuelva la función
 * @return Id: devuelve el id del espacio en esa posicion
 */
Id game_get_space_id_at(Game* game, int position);

/**
 * @date 29-03-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Devuelve el id de un espacio por el otro lado del link. Devuelve el id de un espacio conectado en
 * el otro extremo de un link
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id_link: id del link
 * @param current_space: id del espacio contrario en el link al que queremos que nos de
 * @return Id: devuelve el id del espacio 
 */
Id game_get_space_id_link(Game* game, Id id_link, Id current_space);

/**
 * @date 09-02-2016
 * @author Jaime Elso de Blas
 * @brief Selecciona la posición del jugador. Se encarga de seleccionar la posición del jugador 
 * @param game: recibe la dirección de una estructura de tipo Game
 * @param id: id del espacio que queremos que devuelva la función
 * @return STATUS: "OK" cuando ha añadido la localización correctamente, "ERROR"
 * si ha habido algun error
 */
STATUS game_set_player_location(Game* game, Id id);


/*Implementación de la interfaz del juego*/

Game* game_init() {
  Game* game = NULL;
  int i;   /*La utilizamos para el bucle for*/

  game = (Game*) malloc(sizeof(Game));
  if(!game){
    return NULL;
  }
  
  /*Recorremos el array spaces[] inicianizando todos a NULL*/
  for (i = 0; i < MAX_SPACES; i++) { 
    game->spaces[i] = NULL;
  }

  /*Recorremos el array links[] inicianizando todos a NULL*/
  for (i = 0; i < MAX_LINKS; i++) { 
    game->links[i] = NULL;
  }
  
  /*Inicializamos a NULL*/
  game->player = NULL;  

  /*Recorremos el array object[] inicianizando todos a NULL*/
  for (i = 0; i < MAX_OBJECTS; i++) { 
    game->object[i] = NULL;
  }

  /*LLamamos a la función para crear la estructura del dado*/
  game->die = die_create(1);
  if(!game->die){
    return NULL;
  }

  /*Recorremos el array characters[] inicianizando todos a NULL*/
  for (i = 0; i < MAX_CHARACTERS; i++) { 
    game->characters[i] = NULL;
  }

  game->dialogue = dialogue_create();

  game->large_description[0] = '\0';
  game->info[0] = '\0';
  game->drunkenness = 0;
  
  return game;
}

STATUS game_init_from_file(Game* game, char* filename1, char* filename2, char* filename3, char* filename4, char* filename5) {

  if (game_managment_load_spaces(game, filename1) == ERROR){
    return ERROR;
  }
  if (game_managment_load_objects(game, filename2) == ERROR){
    return ERROR;
  }
  if (game_managment_load_links(game, filename3) == ERROR){
    return ERROR;
  }
  if (game_managment_load_characters(game, filename4) == ERROR){
    return ERROR;
  }
  if (game_managment_load_players(game, filename5) == ERROR){
    return ERROR;
  }

  return OK;
}

STATUS game_destroy(Game* game) {
  int i = 0;  /*Contador para para los bucle for*/

  player_destroy(game->player); /*eliminamos la memoria para player*/

  /*Bucle eliminando la memoria para los objetos*/
  for (i = 0; (i < MAX_OBJECTS) && (game->object[i] != NULL); i++) {
    object_destroy(game->object[i]);
  }

  /*Bucle eliminando la memoria para los espacios*/
  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

  /*Bucle eliminando la memoria para los links*/
  for (i = 0; (i < MAX_LINKS) && (game->links[i] != NULL); i++) {
    link_destroy(game->links[i]);
  }

  die_destroy(game->die); /*eliminamos la memoria para el dado*/

  /*Bucle eliminando la memoria para los personajes*/
  for (i = 0; (i < MAX_CHARACTERS) && (game->characters[i] != NULL); i++) {
    character_destroy(game->characters[i]);
  }

  dialogue_destroy(game->dialogue);

  free(game);
      
  return OK;
}

char* game_get_large_description(Game* game){
  if(!game){
    return NULL;
  }

  return game->large_description;
}

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;  /*Lo utilizamos a modo de contador para el bucle while*/

  if (space == NULL) {
    return ERROR;
  }

  /*Continua el bucle hasta que en contramos una posicion libre en el
  array*/
  while ((i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
  game->spaces[i] = space;

  return OK;
}

STATUS game_add_object(Game* game, Object* object){
  int i = 0;  /*Lo utilizamos a modo de contador para el bucle while*/

  if (object == NULL) {
    return ERROR;
  }

  /*Continua el bucle hasta que en contramos una posicion libre en el
  array*/
  while ((i < MAX_OBJECTS) && (game->object[i] != NULL)){
    i++;
  }

  if (i >= MAX_OBJECTS) {
    return ERROR;
  }

  /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
  game->object[i] = object;

  return OK;
}

STATUS game_add_link(Game* game, Link* link){
  int i = 0;  /*Lo utilizamos a modo de contador para el bucle while*/

  if (link == NULL) {
    return ERROR;
  }

  /*Continua el bucle hasta que en contramos una posicion libre en el
  array*/
  while ((i < MAX_LINKS) && (game->links[i] != NULL)){
    i++;
  }

  if (i >= MAX_LINKS) {
    return ERROR;
  }

  /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
  game->links[i] = link;

  return OK;
}

STATUS game_add_character(Game* game, Character* character){
  int i = 0;  /*Lo utilizamos a modo de contador para el bucle while*/

  if (!character || !game) {
    return ERROR;
  }

  /*Continua el bucle hasta que en contramos una posicion libre en el
  array*/
  while ((i < MAX_CHARACTERS) && (game->characters[i] != NULL)){
    i++;
  }

  if (i >= MAX_CHARACTERS) {
    return ERROR;
  }

  /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
  game->characters[i] = character;

  return OK;
}

STATUS game_add_player(Game* game, Player* player) {
  if (!player) {
    return ERROR;
  }

  game->player = player;

  return OK;
}

int game_get_link_access(Game* game, Id id_link){
  int i;

  if(id_link == NO_ID || !game){
    return -1;
  }

  for(i=0; i<MAX_LINKS && game->links[i] != NULL; i++){
    if(link_get_id(game->links[i]) == id_link){
      return link_get_access(game->links[i]);
    }
  }

  return -1;
}

Link* game_get_link_by_id(Game* game, Id id_link){
  int i;

  if(id_link == NO_ID || !game){
    return NULL;
  }

  for(i=0; i<MAX_LINKS && game->links[i] != NULL; i++){
    if(link_get_id(game->links[i]) == id_link){
      return game->links[i];
    }
  }

  return NULL;
}

Id game_get_space_id_link(Game* game, Id id_link, Id current_space){
  int i;

  if(id_link == NO_ID){
    return NO_ID;
  }

  for(i=0; i<MAX_LINKS; i++){
    if(link_get_id(game->links[i]) == id_link){
      if(link_get_linkA(game->links[i]) != current_space){
        return link_get_linkA(game->links[i]);
      }

      else if(link_get_linkB(game->links[i]) != current_space){
        return link_get_linkB(game->links[i]);
      }
    }
  }

  return NO_ID;

}

Id game_get_space_id_at(Game* game, int position) {
  /*Comprobamos que sea una posición válida*/
  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id){
  int i = 0;  /*Contador para el bucle for*/

  if (id == NO_ID) {
    return NULL;
  }
  
  /*Recorremps el arrat spaces[] buscando la posicion en el array del espacio con ese id*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
    	return game->spaces[i];   
    }
  }
  
  return NULL;
}

Object* game_get_object(Game* game, Id id){
  int i = 0;  /*Contador para el bucle for*/

  if (id == NO_ID || !game) {
    return NULL;
  }
  
  /*Recorremos el arrat spaces[] buscando la posicion en el array del objeto con ese id*/
  for (i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++) {
    if (id == object_get_id(game->object[i])){
      /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
      return game->object[i];   
    }
  }
  return NULL;

}

Link* game_get_link(Game* game, Id id){
  int i = 0;  /*Contador para el bucle for*/

  if (id == NO_ID || !game) {
    return NULL;
  }
  
  /*Recorremos el arrat spaces[] buscando la posicion en el array del objeto con ese id*/
  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++) {
    if (id == link_get_id(game->links[i])){
      /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
      return game->links[i];   
    }
  }
  return NULL;

}

Character* game_get_character(Game* game, Id id){
  int i = 0;  /*Contador para el bucle for*/

  if (id == NO_ID || !game) {
    return NULL;
  }
  
  /*Recorremos el arrat spaces[] buscando la posicion en el array del objeto con ese id*/
  for (i = 0; i < MAX_CHARACTERS && game->characters[i] != NULL; i++) {
    if (id == character_get_id(game->characters[i])){
      /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
      return game->characters[i];   
    }
  }
  return NULL;

}

Object* game_get_object_by_name(Game* game, char* name){
  int i = 0;  /*Contador para el bucle for*/

  if(!game || !name){
    return NULL;
  }

  for(i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++){
    if(strcmp(name, object_get_name(game->object[i])) == 0){
      /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
      return game->object[i]; 
    }
  }

  return NULL;
}

Character* game_get_character_by_name(Game* game, char* name){
  int i = 0;
  
  if(!game || !name){
    return NULL;
  }
  
  for(i = 0; i < MAX_CHARACTERS && game->characters[i] != NULL; i++){
    if(strcmp(name, character_get_name(game->characters[i])) == 0){
      return game->characters[i];
    }
  }
  return NULL;
}

char* game_get_clue(Game* game, Id link){
  int i;

  if(link == NO_ID){
    return NULL;
  }

  for(i = 0; i < MAX_LINKS && game->links[i] != NULL; i++){
    if(link == link_get_id(game->links[i])){
      return link_get_clue(game->links[i]);
    }
  }
  
  return NULL;
}

Link* game_get_link_by_name(Game* game, char* name){
  int i = 0;  /*Contador para el bucle for*/

  if(!game || !name){
    return NULL;
  }

  for(i = 0; i < MAX_LINKS && game->links[i] != NULL; i++){
    if(!strcmp(name, link_get_name(game->links[i]))){
      /*Utilizamos el valor de la 'i' para seleccionar la posicion del array*/
      return game->links[i]; 
    }
  }

  return NULL;
}

char* game_get_info(Game* game){
  if(!game){
    return NULL;
  }

  return game->info;
}

STATUS game_set_info(Game* game, char* info){
  if(!game || !info){
    return ERROR;
  }

  strcpy(game->info, info);

  return OK;
}

char* game_get_object_name_by_id(Game* game, Id id){
  int i;

  if(!game || id == NO_ID){
    return NULL;
  }

  for(i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++){
    if(object_get_id(game->object[i]) == id){
      return object_get_name(game->object[i]);
    }
  }

  return NULL;
}

char* game_get_character_name_by_id(Game* game, Id id){
  int i;

  if(!game || id == NO_ID){
    return NULL;
  }

  for(i = 0; i < MAX_CHARACTERS && game->characters[i] != NULL; i++){
    if(character_get_id(game->characters[i]) == id){
      return character_get_name(game->characters[i]);
    }
  }

  return NULL;
}

char* game_print_inventory_object(Game* game, Id id){
  if(!game){
    return NULL;
  }


  if(set_check_id(inventory_get_object(player_get_inventory(game->player)), id) == TRUE){
    return game_get_object_name_by_id(game, id);
  }
  else{
    return NULL;
  }
}

STATUS game_set_player_location(Game* game, Id id) {

  if (id == NO_ID) {
    return ERROR;
  }

  if (player_set_location(game->player, id) == ERROR){
    return ERROR;
  }
  
  return OK;
}

STATUS game_set_object_location(Game* game, Id id_space, Id id_object) {

  if (!game || id_space == NO_ID || id_object == NO_ID) {
    return ERROR;
  }

  space_set_object(game_get_space(game, id_space), id_object);

  return OK;
}

Id game_get_player_location(Game* game) {

  if(!game){
    return NO_ID;
  }

  return player_get_location(game->player);
}

Id game_get_object_location(Game* game, Id id_object) {
  int i;  /*Contador psra el bucle for*/

  /*Recorremps el arrat spaces[] buscando si el id del objeto coincide 
  con alguno de los Id que hay en cada espacio en la estructura Set*/
  for (i = 0; i <= MAX_SPACES && game->spaces[i] != NULL; i++){
    if(set_check_id(space_get_object(game->spaces[i]), id_object) == TRUE){
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

int game_get_drunkenness(Game* game){
  if(!game){
    return -1;
  }

  return game->drunkenness;
}

STATUS game_update(Game* game, MyCmd* mycmd) {
  T_Command cmd, arg;  /*Almacenamos el comando*/
  STATUS status;
  cmd = command_get_cmd(mycmd);
  arg = command_get_arg(mycmd);

  switch (cmd){
    case UNKNOWN:
      status = callback_UNKNOWN(game);
      break;
    case QUIT:
      status = callback_QUIT(game);
      break;
    case GO:

      switch (arg){
        case NORTH:
          status = callback_GO_NORTH(game);
          break;
        case EAST:
          status = callback_GO_EAST(game);
          break;
        case WEST:
          status = callback_GO_WEST(game);
          break;
        case SOUTH:
          status = callback_GO_SOUTH(game);
          break;
        case UP:
          status = callback_GO_UP(game);
          break;
        case DOWN:
          status = callback_GO_DOWN(game);
          break;
        case UNKNOWN:
          break;
        case NO_CMD:
          break;
        default: /* Nunca debemos llegar a este caso*/
          return ERROR;
      }
      break;
    case TAKE:
      status = callback_TAKE(game, command_get_objname(mycmd));
      break;
    case DROP:
      status = callback_DROP(game, command_get_objname(mycmd));
      break;
    case ROLL:
      status = callback_ROLL(game);
      break;
    case INSPECT:
        if(arg == SPACE){
          status = callback_INSPECT_SPACE(game);
        }
        else if(arg == OBJECT){
          status = callback_INSPECT_OBJECT(game, command_get_objname(mycmd));
        }
      break;
    case TURNON:
      status = callback_TURNON(game, command_get_objname(mycmd));
      break;
    case TURNOFF:
      status = callback_TURNOFF(game, command_get_objname(mycmd));
      break;
    case OPENING:
      status = callback_OPEN(game, command_get_objname(mycmd), command_get_link(mycmd));
      break;
    case SAVE:
      status = callback_SAVE(game, command_get_objname(mycmd));
      break;
    case TALK:
      status = callback_TALK(game, command_get_charname(mycmd));
      break;
    case DRINK:
      status = callback_DRINK(game, command_get_objname(mycmd));
      break;
    case NO_CMD:
      break;
    default: /* Nunca debemos llegar a este caso*/
      return ERROR;
  }

  return status;
}

void game_log(FILE* file, STATUS status, MyCmd* command){
  char status_char[WORD_SIZE];
  char command_char[WORD_SIZE];

  if(status == OK){
    strcpy(status_char, "OK");
  }
  else{
    strcpy(status_char, "ERROR");
  }

  if(command_get_cmd(command) == TAKE){
    strcpy(command_char, "coger");

    fprintf(file, "Comando: %s %s, status: %s.\n", command_char, command_get_objname(command), status_char);
  }
  else if(command_get_cmd(command) == DROP){
    strcpy(command_char, "dejar");

    fprintf(file, "Comando: %s %s, status: %s.\n", command_char, command_get_objname(command), status_char);
  }
  else if(command_get_cmd(command) == GO){

    if(command_get_arg(command) == SOUTH){
      strcpy(command_char, "avanzar sur");

      fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
    }
    else if(command_get_arg(command) == NORTH){
      strcpy(command_char, "avanzar norte");

      fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
    }
    else if(command_get_arg(command) == WEST){
      strcpy(command_char, "avanzar oeste");

      fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
    }
    else if(command_get_arg(command) == EAST){
      strcpy(command_char, "avanzar este");

      fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
    }
    else if(command_get_arg(command) == UP){
      strcpy(command_char, "avanzar arriba");

      fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
    }
    else if(command_get_arg(command) == DOWN){
      strcpy(command_char, "avanzar abajo");

      fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
    }
  }

  else if(command_get_cmd(command) == INSPECT){

    if(command_get_arg(command) == SPACE){
      strcpy(command_char, "inspeccionar espacio");

      fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
    }
    else if(command_get_arg(command) == OBJECT){
      strcpy(command_char, "inspeccionar objeto");

      fprintf(file, "Comando: %s %s, status: %s.\n", command_char, command_get_objname(command), status_char);
    }

  }
  else if(command_get_cmd(command) == TURNON){
    strcpy(command_char, "turnon");

    fprintf(file, "Comando: %s %s, status: %s.\n", command_char, command_get_objname(command), status_char);
  }
  else if(command_get_cmd(command) == TURNOFF){
    strcpy(command_char, "turnoff");

    fprintf(file, "Comando: %s %s, status: %s.\n", command_char, command_get_objname(command), status_char);
  }
  else if(command_get_cmd(command) == ROLL){
    strcpy(command_char, "lanzar");

    fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
  }
  else if(command_get_cmd(command) == QUIT){
    strcpy(command_char, "quit");

    fprintf(file, "Comando: %s, status: %s.\n", command_char, status_char);
  }
  else if(command_get_cmd(command) == OPENING){
    strcpy(command_char, "abrir");

    fprintf(file, "Comando: %s %s con %s, status: %s.\n", command_char, command_get_link(command), command_get_objname(command), status_char);
  }
  else if(command_get_cmd(command) == SAVE){
    strcpy(command_char, "guardar");

    fprintf(file, "Comando: %s in file: %s , status: %s.\n", command_char, command_get_objname(command), status_char);
  }
  else if(command_get_cmd(command) == TALK){
    strcpy(command_char, "hablar");

    fprintf(file, "Comando: %s con %s, status: %s.\n", command_char, command_get_charname(command), status_char);
  }
  else if(command_get_cmd(command) == DRINK){
    strcpy(command_char, "beber");

    fprintf(file, "Comando: %s %s, status: %s.\n", command_char, command_get_objname(command), status_char);
  }
  else{
    fprintf(file, "Comando: DESCONOCIDO, status: %s.\n", status_char);
  }
}


Space* game_get_space_array_position(Game* game, int i){
  if(!game || i < 0){
    return NULL;
  }

  return game->spaces[i];
}

Object* game_get_object_array_position(Game* game, int i){
  if(!game || i < 0){
    return NULL;
  }

  return game->object[i];
}

Link* game_get_link_array_position(Game* game, int i){
  if(!game || i < 0){
    return NULL;
  }

  return game->links[i];
}

Character* game_get_character_array_position(Game* game, int i){
  if(!game || i < 0){
    return NULL;
  }

  return game->characters[i];
}

Player* game_get_player(Game* game){
  if(!game){
    return NULL;
  }

  return game->player;
}

BOOL game_is_over(Game* game) {

  if(game_get_player_location(game) == 14){
    return TRUE;
  }

  if(game_get_player_location(game) == 13){
    return TRUE;
  }

  if(game_get_player_location(game) == 10 && character_get_talk(game_get_character_by_name(game, "oscar.ks")) == TRUE && character_get_talk(game_get_character_by_name(game, "satanista")) == TRUE){
    return TRUE;
  }

  return FALSE;
}

/*Devoluciones de llamada para los diferentes comandos posibles*/

STATUS callback_UNKNOWN(Game* game) {
  return ERROR;
}

STATUS callback_QUIT(Game* game) {
  return OK;
}

STATUS callback_GO_SOUTH(Game* game) {
  Id current_id = NO_ID; /*Almacenamos el id del espacio*/
  Id space_id = NO_ID;   /*Almacenamos el id del espacio en el que esta el jugador*/
  Id link_id = NO_ID; /*Almacenamos el id del link*/

  if(!game){
    return ERROR;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  link_id = space_get_link_south(game_get_space(game, space_id));

  if(link_id == NO_ID){
    return ERROR;
  }

  if(game_get_link_access(game, link_id) == CLOSE){
    game_set_info(game, game_get_clue(game, link_id));
    return ERROR;
  }

  current_id = game_get_space_id_link(game, link_id, space_id);


  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return OK;
}

STATUS callback_GO_NORTH(Game* game) {
  Id current_id = NO_ID; /*Almacenamos el id del espacio*/
  Id space_id = NO_ID;   /*Almacenamos el id del espacio en el que esta el jugador*/
  Id link_id = NO_ID; /*Almacenamos el id del link*/

  if(!game){
    return ERROR;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  link_id = space_get_link_north(game_get_space(game, space_id));

  if(link_id == NO_ID){
    return ERROR;
  }

  if(game_get_link_access(game, link_id) == CLOSE){
    game_set_info(game, game_get_clue(game, link_id));
    return ERROR;
  }

  current_id = game_get_space_id_link(game, link_id, space_id);


  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return OK;
}

STATUS callback_GO_EAST(Game* game) {
  Id current_id = NO_ID; /*Almacenamos el id del espacio*/
  Id space_id = NO_ID;   /*Almacenamos el id del espacio en el que esta el jugador*/
  Id link_id = NO_ID; /*Almacenamos el id del link*/

  if(!game){
    return ERROR;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  link_id = space_get_link_east(game_get_space(game, space_id));

  if(link_id == NO_ID){
    return ERROR;
  }

  if(game_get_link_access(game, link_id) == CLOSE){
    game_set_info(game, game_get_clue(game, link_id));
    return ERROR;
  }

  current_id = game_get_space_id_link(game, link_id, space_id);


  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return OK;
}

STATUS callback_GO_WEST(Game* game) {
  Id current_id = NO_ID; /*Almacenamos el id del espacio*/
  Id space_id = NO_ID;   /*Almacenamos el id del espacio en el que esta el jugador*/
  Id link_id = NO_ID; /*Almacenamos el id del link*/

  if(!game){
    return ERROR;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  link_id = space_get_link_west(game_get_space(game, space_id));

  if(link_id == NO_ID){
    return ERROR;
  }

  if(game_get_link_access(game, link_id) == CLOSE){
    game_set_info(game, game_get_clue(game, link_id));
    return ERROR;
  }

  current_id = game_get_space_id_link(game, link_id, space_id);


  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return OK;
}

STATUS callback_GO_UP(Game* game) {
  Id current_id = NO_ID; /*Almacenamos el id del espacio*/
  Id space_id = NO_ID;   /*Almacenamos el id del espacio en el que esta el jugador*/
  Id link_id = NO_ID; /*Almacenamos el id del link*/

  if(!game){
    return ERROR;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  link_id = space_get_link_up(game_get_space(game, space_id));

  if(link_id == NO_ID){
    return ERROR;
  }

  if(game_get_link_access(game, link_id) == CLOSE){
    game_set_info(game, game_get_clue(game, link_id));
    return ERROR;
  }

  current_id = game_get_space_id_link(game, link_id, space_id);


  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return OK;
}

STATUS callback_GO_DOWN(Game* game) {
  Id current_id = NO_ID; /*Almacenamos el id del espacio*/
  Id space_id = NO_ID;   /*Almacenamos el id del espacio en el que esta el jugador*/
  Id link_id = NO_ID; /*Almacenamos el id del link*/

  if(!game){
    return ERROR;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  link_id = space_get_link_down(game_get_space(game, space_id));

  if(link_id == NO_ID){
    return ERROR;
  }

  if(game_get_link_access(game, link_id) == CLOSE){
    game_set_info(game, game_get_clue(game, link_id));
    return ERROR;
  }

  current_id = game_get_space_id_link(game, link_id, space_id);


  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return OK;
}

STATUS callback_TAKE(Game* game, char* name){
  Id space_id = NO_ID;  /*Almacenamos el id del espacio en el que esta el jugador*/

  if (!game || !name){
    return ERROR;
  }


  space_id = game_get_player_location(game);

  if(!strcmp(name, "jeringuilla") && space_id == 2){
    player_set_location(game_get_player(game), 14);
    return OK;
  }

  if(!strcmp(name, "lista_implicados") && space_id == 5){
    player_set_location(game_get_player(game), 13);
    return OK;
  }

  if (NO_ID == space_id){
    return ERROR;
  }

  if(set_check_noId(space_get_object(game_get_space(game, space_id))) == TRUE){
    return ERROR;
  }

  if(object_get_movable(game_get_object_by_name(game, name)) == FALSE){
    return ERROR;
  }

  object_set_move(game_get_object_by_name(game, name), TRUE);
  
  player_set_inventory(game->player, set_get_id(space_get_object(game_get_space(game, space_id)), object_get_id(game_get_object_by_name(game, name))));
  
  set_del_id(space_get_object(game_get_space(game, space_id)), object_get_id(game_get_object_by_name(game, name)));


  if(!strcmp(name,"telefono")){
    link_set_access(game_get_link_by_id(game, 1), OPEN);
    game_change_object_location(game, "telefono", 1);
  }
  return OK;
}

STATUS callback_DROP(Game* game, char* name){
  Id space_id = NO_ID;  /*Almacenamos el id del espacio en el que esta el jugador*/

  if (!game || !name){
    return ERROR;
  }

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  if(player_check_object(game->player, object_get_id(game_get_object_by_name(game, name))) == FALSE){
    return ERROR;
  }

  space_set_object(game_get_space(game, space_id), object_get_id(game_get_object_by_name(game, name))); 

  set_del_id(inventory_get_object(player_get_inventory(game->player)), object_get_id(game_get_object_by_name(game, name)));

  return OK;
}

STATUS callback_INSPECT_OBJECT(Game* game, char* name){

  if (!game || !name){
    return ERROR;
  }

  if(object_get_move(game_get_object_by_name(game, name)) == TRUE){
    strcpy(game->large_description , object_get_description(game_get_object_by_name(game, name)));
  }

  else{
    if(game_get_object_by_name(game, name) == NULL){
      return ERROR;
    }

    strcpy(game->large_description , object_get_alt_description(game_get_object_by_name(game, name)));
  }

  return OK;
}

STATUS callback_INSPECT_SPACE(Game* game){
  Id space_id = NO_ID;  /*Almacenamos el id del espacio en el que esta el jugador*/

  if (!game){
    return ERROR;
  }

  space_id = game_get_player_location(game);

  if(space_get_illuminated(game_get_space(game, space_id)) == TRUE){
    return ERROR;
  }

  strcpy(game->large_description, space_get_large_description(game_get_space(game, space_id)));
    
  return OK;
}

STATUS callback_ROLL(Game* game){
  if (!game){
    return ERROR;
  }

  die_roll(game->die);

  return OK;
}

STATUS callback_TURNON(Game* game, char* obj_name){
  Id object_id = NO_ID;

  if(!game){
    return ERROR;
  }

  object_id = object_get_id(game_get_object_by_name(game, obj_name));
  if(object_id == NO_ID){
    return ERROR;
  }

  object_set_on(game_get_object(game, object_id), TRUE);

  return OK;
}

STATUS callback_TURNOFF(Game* game, char* obj_name){
  Id object_id = NO_ID;

  if(!game){
    return ERROR;
  }

  object_id = object_get_id(game_get_object_by_name(game, obj_name));

  if(object_id == NO_ID){
    return ERROR;
  }

  object_set_on(game_get_object(game, object_id), FALSE);

  return OK;
}

STATUS callback_OPEN(Game* game, char* obj_name, char* link_name){
  Id link_id = NO_ID;
  Id object_id = NO_ID;

  if(!game){
    return ERROR;
  }

  link_id = link_get_id(game_get_link_by_name(game, link_name));
  object_id = object_get_link(game_get_object_by_name(game, obj_name));

  if(link_get_access(game_get_link_by_name(game, link_name)) == OPEN){
    return ERROR;
  }
  if(link_id == object_id){
    link_set_access(game_get_link_by_name(game, link_name), OPEN);
    return OK;
  }
  else{
    return ERROR;
  }

  return OK;
}

STATUS callback_DRINK(Game* game, char* obj_name){
  int object_id = NO_ID;

  if (!game || !obj_name){
    return ERROR;
  }

  if(strcmp(obj_name, "copa")){
    return ERROR;
  }

  if(object_get_n_objects(game_get_object_by_name(game, obj_name)) == 0){
    return ERROR;
  }

  object_id = object_get_id(game_get_object_by_name(game, obj_name));

  if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), object_id) == FALSE){
    return ERROR;
  }

  object_change_n_objects(game_get_object_by_name(game, obj_name), LOSE_COPA);
  game->drunkenness++;

  if(object_get_n_objects(game_get_object_by_name(game, obj_name)) == 0){
    callback_DROP(game, obj_name);
    game_change_object_location(game, obj_name, 3);
  }

  if(game->drunkenness == MAX_DRUNKENNESS){
    player_set_location(game_get_player(game), 14);
  }

  return OK;
}

STATUS callback_SAVE(Game* game, char* save){
  return game_managment_save(game, save);
}

STATUS callback_TALK(Game* game, char* name){
  Id character_id = NO_ID;
  Character* character = NULL;
  int aleatorio;
  
  if(!game || !name){
    return ERROR;
  }

  character = game_get_character_by_name(game, name);
  character_id = character_get_id(character);

  if(game_get_player_location(game) != character_get_location(character)){
    return ERROR;
  }

  if(character_get_talk(character) == TRUE){
    dialogue_set_conv(game->dialogue, PRIMERO, "Este personaje no tiene nada que decirte.");
    return OK;
  }
  
  if (character_id == PUERTA){
    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), FLYER) == FALSE){
      dialogue_set_conv(game->dialogue, PRIMERO, "¿Quieres pasar? pues necesitas un flyer VIP, ¿lo tienes?");
      dialogue_set_conv(game->dialogue, SEGUNDO, "No tienes ningún flyer, largo de aqui.");
      dialogue_set_conv(game->dialogue, TERCERO, "Sin flyer no puedes entrar, lo siento.");
    }
    else{
      dialogue_set_conv(game->dialogue, PRIMERO, "Espera... Oh!, tienes un flyer VIP");
      dialogue_set_conv(game->dialogue, SEGUNDO, "puedes pasar sin hacer fila cuando quieras,");
      dialogue_set_conv(game->dialogue, TERCERO, "como la lies dentro te las verás conmigo.");

      link_set_access(game_get_link_by_id(game, 2), OPEN);
      character_set_talk(character, TRUE);
    }
  }

  if (character_id == RELACIONES){
    dialogue_set_conv(game->dialogue, PRIMERO, "Hola buenas, ¿dices que quieres un flyer?");
    dialogue_set_conv(game->dialogue, SEGUNDO, "Cuesta 12€...");
    dialogue_set_conv(game->dialogue, TERCERO, "¡No acepto tarjeta! solo efectivo.");

    callback_TAKE(game, "flyer");
    object_change_n_objects(game_get_object_by_name(game, "dinero"), COST_FLYER);
    character_set_talk(character, TRUE);
  }

  if (character_id == CAMELLO){
    if(object_get_n_objects(game_get_object_by_name(game, "dinero")) >= 20){
      dialogue_set_conv(game->dialogue, PRIMERO, "Hey que pasa, ¿estás buscando mercancía?");
      dialogue_set_conv(game->dialogue, SEGUNDO, "aqui tienes lo mejor de la ciudad.");
      dialogue_set_conv(game->dialogue, TERCERO, "Son 20€ pero merece la pena.");
    
      callback_TAKE(game, "pastis");
      object_change_n_objects(game_get_object_by_name(game, "dinero"), COST_PASTIS);
      character_set_talk(character, TRUE);
    }
    else{
      dialogue_set_conv(game->dialogue, PRIMERO, "No tienes suficiente dinero para comprar");
      dialogue_set_conv(game->dialogue, SEGUNDO, "la mercancia, necesitas 20 euros, busca a");
      dialogue_set_conv(game->dialogue, TERCERO, "Bill Gates por la disco a ver si te da dinero.");
    }
  }

  if (character_id == CAMARERA){
    
    if(object_get_n_objects(game_get_object_by_name(game, "dinero")) >= 10){
      dialogue_set_conv(game->dialogue, PRIMERO, "Hola, ¿te apetece una copa?");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Marchando un Vodka con redbull.");
      dialogue_set_conv(game->dialogue, TERCERO, "Son 10 euros caballero.");

      if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), COPA) == FALSE){
        callback_TAKE(game, "copa");
      }

      object_change_n_objects(game_get_object_by_name(game, "dinero"), COST_COPA);
      object_change_n_objects(game_get_object_by_name(game, "copa"), GIVE_COPA);
    }
    else{
      dialogue_set_conv(game->dialogue, PRIMERO, "Lo siento no tienes suficiente dinero...");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Me han dicho que Bill Gates anda por la disco,");
      dialogue_set_conv(game->dialogue, TERCERO, "lo mismo es tu dia de suerte.");
    }
  }

  if (character_id == ROPERO){
    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), ABRIGO) == TRUE){
      dialogue_set_conv(game->dialogue, PRIMERO, "Hola buenas, ¿vienes a dejar un abrigo?");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Vale, Son dos euros.");

      callback_DROP(game, "abrigo");
      object_change_n_objects(game_get_object_by_name(game, "dinero"), COST_ABRIGO);
      link_set_access(game_get_link_by_id(game, 4), OPEN);
    }
    else{
      dialogue_set_conv(game->dialogue, PRIMERO, "No tienes ningun abrigo para dejar.");
    }
        
  }

  if (character_id == BORRACHO){
    die_roll(game->die);
    aleatorio = die_get_num(game->die);

    switch(aleatorio){
      case 1:
        dialogue_set_conv(game->dialogue, PRIMERO, "Esto con Windows Vista no pasaba.");
        break;
      case 2:
        dialogue_set_conv(game->dialogue, PRIMERO, "Pfff... al menos no voy tan mal como el chaval del reservado.");
        break;
      case 3:
        dialogue_set_conv(game->dialogue, PRIMERO, "Dobby el elfo doméstico muere...");
        break;
      case 4:
        dialogue_set_conv(game->dialogue, PRIMERO, "Al menos no programo en windows...");
        break;
      case 5:
        dialogue_set_conv(game->dialogue, PRIMERO, "if(tienes_cerveza){ damela();} else vete();");
        break;
      default:
        break;
    }
  }

  if (character_id == DJ){
    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), PASTIS) == FALSE){
      dialogue_set_conv(game->dialogue, PRIMERO, "¿Quieres que pinche reggeton? No me gusta esa musica...");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Lo quieres para poder ir a los reservados ¿verdad?");
      dialogue_set_conv(game->dialogue, TERCERO, "si me traes pastis del camello que hay al oeste segun sales a la calle lo hago.");
    
      link_set_access(game_get_link_by_id(game, 3), OPEN);
    }
    else{
      dialogue_set_conv(game->dialogue, PRIMERO, "Ohh ya veo que me traes buen material, esta bien");
      dialogue_set_conv(game->dialogue, SEGUNDO, "pondre reggeton para que la gente salga de los reservados");
      dialogue_set_conv(game->dialogue, TERCERO, "a bailar y puedas pasar.");

      link_set_access(game_get_link_by_id(game, 6), OPEN);
      callback_DROP(game, "pastis");
      game_change_object_location(game, "copa", 6);
    }
  }

  if (character_id == CHICA){
    dialogue_set_conv(game->dialogue, PRIMERO, "Hola guapo, estoy sedienta, ¿no tendrás por ahi una copa a la que invitarme?");

    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), COPA) == FALSE || object_get_n_objects(game_get_object_by_name(game, "copa")) < 1){
      dialogue_set_conv(game->dialogue, SEGUNDO, "No tienes copas... ya no me interesas.");
    }
    else{
      dialogue_set_conv(game->dialogue, SEGUNDO, "Ay, que mono, muchas gracias por la copa!");

      object_change_n_objects(game_get_object_by_name(game, "copa"), LOSE_COPA);
      if(object_get_n_objects(game_get_object_by_name(game, "copa")) == 0){
        callback_DROP(game, "copa");
        game_change_object_location(game, "copa", 3);
      }
    }
  }

  if (character_id == BILLGATES){
      dialogue_set_conv(game->dialogue, PRIMERO, "¿Como has entrado? Has burlado la seguridad de");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Windows, ¡no puede ser!, toma 300 euros y no le");
      dialogue_set_conv(game->dialogue, TERCERO, "cuentes a nadie como lo has hecho.");

      character_set_talk(character, TRUE);
      object_change_n_objects(game_get_object_by_name(game, "dinero"), MONEY_BILL);
  }

  if (character_id == PUERTA2){
    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), CARTERA) == FALSE){
      dialogue_set_conv(game->dialogue, PRIMERO, "Lo siento , este reservado es privado y está ocupado,");
      dialogue_set_conv(game->dialogue, SEGUNDO, "pertenece a Oscar.KS y sus acompañantes.");
    }
    else{
      dialogue_set_conv(game->dialogue, PRIMERO, "Esa es la cartera del gran Oskar.ks??");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Esta bien dejaré que pases a devolversela,");
      dialogue_set_conv(game->dialogue, TERCERO, "pero date prisa!");

      link_set_access(game_get_link_by_id(game, 9), OPEN);
      character_set_talk(character, TRUE);
    }
  }

  if (character_id == HOMBRE){
      dialogue_set_conv(game->dialogue, PRIMERO, "¿Qué pasa?, ¿Qué quieres?");
      dialogue_set_conv(game->dialogue, SEGUNDO, "¿No ves que estoy orinando?");
      character_set_talk(character, TRUE);
  }

  if (character_id == FIESTERO){
    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), CARTERA) == FALSE){
      dialogue_set_conv(game->dialogue, PRIMERO, "¡¡¡¡¡¡¡¡BUUAAAAAAAA!!!!!!!!! !QUÉ FIESTÓOOOOOOOON¡");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Me parecio ver antes por ahi una cartera perdida,");
      dialogue_set_conv(game->dialogue, TERCERO, "no se si te servira para algo...");
    }
    else{  
      dialogue_set_conv(game->dialogue, PRIMERO, "Esa cartera es del chaval que iba etilico.");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Puede que si el puertas te ve con ella te deje");
      dialogue_set_conv(game->dialogue, TERCERO, "entrar al reservado para darsela.");
    }  
  }

  if (character_id == SATANISTA){
    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), CRUCIFIJO) == FALSE){
      dialogue_set_conv(game->dialogue, PRIMERO, "No tienes ningun objecto con el que");
      dialogue_set_conv(game->dialogue, SEGUNDO, "derrotarme ¡Muajaja!");
      dialogue_set_conv(game->dialogue, TERCERO, "Oscar.KS es mio para siempre.");
    }
    else{
      dialogue_set_conv(game->dialogue, PRIMERO, "¡¡¡AAAAHHHHHH¡¡¡¡ Aleja ese objeto de mi.");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Renunciaré a Oskar.KS si hace falta ¡AAHH!");
      dialogue_set_conv(game->dialogue, TERCERO, "Ya has conseguido lo que querias maldito.");

      character_set_talk(character, TRUE);
      character_set_talk(game_get_character_by_name(game, "oscar.ks"), FALSE);
    }
  }

  if (character_id == OSCAR){
    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), ANTIDOTO) == FALSE){
      dialogue_set_conv(game->dialogue, PRIMERO, "Agg tiio.. Agg me han echado algo Agg");
      dialogue_set_conv(game->dialogue, SEGUNDO, "necesito el antidoto o morire pronto");
      dialogue_set_conv(game->dialogue, TERCERO, "AGG corre traemelo!");
    }
    else{
      dialogue_set_conv(game->dialogue, PRIMERO, "¡¡¡POR FIN SOY LIBRE!!!");
      dialogue_set_conv(game->dialogue, SEGUNDO, "Gracias por venir a buscarme amigo,");
      dialogue_set_conv(game->dialogue, TERCERO, "sabia que podia contar contigo.");

      character_set_talk(character, TRUE);
    }
  }
  
  return OK;
}

Dialogue* game_get_dialogue(Game* game){
  if(!game){
    return NULL;
  }

  return game->dialogue;
}

STATUS game_change_object_location(Game* game, char* name, Id location){
  Id space_id = NO_ID;  /*Almacenamos el id del espacio en el que esta el jugador*/

  if(!game || !name){
    return ERROR;
  }

  space_id = game_get_player_location(game);
  if (NO_ID == space_id){
    return ERROR;
  }

  if(set_check_noId(space_get_object(game_get_space(game, space_id))) == TRUE){
    return ERROR;
  }

  set_del_id(space_get_object(game_get_space(game, space_id)), object_get_id(game_get_object_by_name(game, name)));

  space_set_object(game_get_space(game, location), object_get_id(game_get_object_by_name(game, name)));

  return OK;
}