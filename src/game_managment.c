/**
* @brief Modulo Game managment
*
* Es el archivo que contiene todas la funciónes para leer y cargar los 
* espacios de juego.
* 
* @file game_managment.c
* @author Jaime Elso de Blas
* @version 02-02-2016 version 1.0 (version inicial)
*   05 / 03 / 2016 Version 2.0 se añade game_managment_load_objects que se 
*   encarga de cargar objetos al juego, y se modifica load_spaces para 
*   que tambien carge la descripcion ASCII de cada casilla
* 
* @date 02-02-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../include/game.h"
#include "../include/game_managment.h"

STATUS game_managment_load_spaces(Game* game, char* filename) {
	FILE* file = NULL;  /* Puntero para el archivo de texto */

	char line[WORD_SIZE] = "";  /* Cadena de caracteres */
	char name[WORD_SIZE] = "";  /* Cadena de caracteres */
	char paints[PRINT_LINES][DESC_SIZE]; /* Array de strings que contienen lineas del arte de ASCII */
	int i; /* Variable para el bucle for */
	char description[DESCRIPTION_SIZE] = ""; /* Cadena de caracteres */
	char large_description[LARGE_DESCRIPTION_SIZE] = ""; /* Cadena de caracteres */
	BOOL illuminated = TRUE;
	char* toks = NULL;  /* Puntero a char */

	Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;  /* Almacenamiento de diferentes ID */

	Space* space = NULL;  /* Puntero a la estructura Space */

	STATUS status = OK; /* variable a devolver por la función para ver si a salido todo bien */
  
	if (!filename) {
		return ERROR;
	}
  
	file = fopen(filename, "r");
	if (file == NULL) {
		return ERROR;
	}
  
	while (fgets(line, WORD_SIZE, file)) {
		if (strncmp("#s:", line, 3) == 0) {
			toks = strtok(line + 3, SPACES_DELIMITER);
			id = atol(toks);
			toks = strtok(NULL, SPACES_DELIMITER);
			if(toks){
				strcpy(name, toks);
			}
			toks = strtok(NULL, SPACES_DELIMITER);
			north = atol(toks);
			toks = strtok(NULL, SPACES_DELIMITER);
			east = atol(toks);
			toks = strtok(NULL, SPACES_DELIMITER);
			south = atol(toks);
			toks = strtok(NULL, SPACES_DELIMITER);
			west = atol(toks);
			toks = strtok(NULL, SPACES_DELIMITER);
			up = atol(toks);
			toks = strtok(NULL, SPACES_DELIMITER);
			down = atol(toks);
			toks = strtok(NULL, SPACES_DELIMITER);
			illuminated = atoi(toks);
			for (i = 0; i < PRINT_LINES; i++) {
				toks = strtok(NULL, SPACES_DELIMITER);
				if(toks){
					strcpy(paints[i], toks);
				}
			}
			toks = strtok(NULL, SPACES_DELIMITER);
			if(toks){
				strcpy(description, toks);
			}
			toks = strtok(NULL, SPACES_DELIMITER);
			if(toks){
				strcpy(large_description, toks);
			}
#ifdef DEBUG 
			printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%d|%s|%s|%s|%s|%s\n", id, name, north, east, south, west, up, down, illuminated, paints[0], paints[1], paints[2], description, large_description);
#endif
			space = space_create(id);
			if (space != NULL) {
				space_set_name(space, name);
				space_set_link_north(space, north);
				space_set_link_east(space, east);
				space_set_link_south(space, south);
				space_set_link_west(space, west);
				space_set_link_up(space, up);
				space_set_link_down(space, down);
				space_set_illuminated(space, illuminated);
				for (i = 0; i < PRINT_LINES; i++) {
					space_set_gdesc(space, i, paints[i]);
				}
				space_set_description(space, description);
				space_set_large_description(space, large_description);
			
				game_add_space(game, space);
			}
		}
	}
  
	if (ferror(file)) {
		status = ERROR;
	}
	
	fclose(file);
	
	return status;
}

STATUS game_managment_load_objects(Game* game, char* filename){
  FILE* file = NULL;  /*Puntero para el archivo de texto*/

  char line[WORD_SIZE] = "";  /*Cadena de caracteres*/
  char name[WORD_SIZE] = "";  /*Cadena de caracteres*/
  char description[DESCRIPTION_SIZE] = ""; /*Cadena de caracteres*/
  char alt_description[DESCRIPTION_SIZE] = ""; /*Cadena de caracteres*/
  BOOL movable = TRUE, move = TRUE, visible = TRUE, illuminated = TRUE, on = TRUE;
  Id link = NO_ID;
  int n_objects;
  char* toks = NULL;  /*Puntero a char*/

  Id id = NO_ID, location = NO_ID;  /*Almacenamiento de ID*/

  Object* object = NULL;  /*Puntero a la estructura Object*/

  STATUS status = OK; /*variable a devolver por la función para ver si a salido todo bien*/
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, DELIMITER);
      id = atol(toks);
      toks = strtok(NULL, DELIMITER);
      if(toks){
        strcpy(name, toks);
      }
      toks = strtok(NULL, DELIMITER);
      location = atol(toks);
      toks = strtok(NULL, DELIMITER);
      movable = atoi(toks);
      toks = strtok(NULL, DELIMITER);
      move = atoi(toks);
      toks = strtok(NULL, DELIMITER);
      visible = atoi(toks);
      toks = strtok(NULL, DELIMITER);
      illuminated = atoi(toks);
      toks = strtok(NULL, DELIMITER);
      on = atoi(toks);
      toks = strtok(NULL, DELIMITER);
      link = atol(toks);
      toks = strtok(NULL, DELIMITER);
      n_objects = atoi(toks);
      toks = strtok(NULL, DELIMITER);
      if(toks){
       strcpy(description, toks);
      }
      toks = strtok(NULL, DELIMITER);
      if(toks){
        strcpy(alt_description, toks);
      }
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld\n", id, name, location);
#endif
      object = object_create(id);
      if (object != NULL) {
        object_set_name(object, name);
        game_set_object_location(game, location, id);
        object_set_movable(object, movable);
        object_set_move(object, move);
        object_set_visible(object, visible);
        object_set_illuminate(object, illuminated);
        object_set_on(object, on);
        object_set_link(object, link);
        object_set_n_objects(object, n_objects);
        object_set_description(object, description);
        object_set_alt_descrip(object, alt_description);
        game_add_object(game, object);
      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

STATUS game_managment_load_links(Game* game, char* filename) {
  FILE* file = NULL;  /*Puntero para el archivo de texto*/

  char line[WORD_SIZE] = "";  /*Cadena de caracteres*/
  char name[WORD_SIZE] = "";  /*Cadena de caracteres*/
  char clue[WORD_SIZE] = "";

  char* toks = NULL;  /*Puntero a char*/

  Id id = NO_ID, linkA = NO_ID, linkB = NO_ID;  /*Almacenamiento de diferentes ID*/

  int access;

  Link* link = NULL;  /*Puntero a la estructura Link*/

  STATUS status = OK; /*variable a devolver por la función para ver si a salido todo bien*/
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#l:", line, 3) == 0) {
      toks = strtok(line + 3, DELIMITER);
      id = atol(toks);
      toks = strtok(NULL, DELIMITER);
      if(toks){
        strcpy(name, toks);
      }
      toks = strtok(NULL, DELIMITER);
      linkA = atol(toks);
      toks = strtok(NULL, DELIMITER);
      linkB = atol(toks);
      toks = strtok(NULL, DELIMITER);
      access = atol(toks);
      toks = strtok(NULL, DELIMITER);
      if(toks){
        strcpy(clue, toks);
      }
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld|%d|%ld\n", id, name, linkA, linkB, access);
#endif
      link = link_create(id);
      if (link != NULL) {
        link_set_name(link, name);
        link_set_linkA(link, linkA);
        link_set_linkB(link, linkB);
        link_set_access(link, access);
        link_set_clue(link, clue);

        game_add_link(game, link);

      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

STATUS game_managment_load_characters(Game* game, char* filename) {
  FILE* file = NULL;  /*Puntero para el archivo de texto*/

  char line[WORD_SIZE] = "";               /*Cadena de caracteres*/
  char name[WORD_SIZE] = "";               /*Cadena de caracteres*/
  char description[DESCRIPTION_SIZE] = ""; /*Cadena de caracteres*/

  char* toks = NULL;  /*Puntero a char*/

  Id id = NO_ID, location = NO_ID, object = NO_ID;  /*Almacenamiento de diferentes ID*/

  BOOL talk;  /*Booleno para saber si puede hablar el personaje o no*/

  Character* character = NULL;  /*Puntero a la estructura Link*/

  STATUS status = OK; /*variable a devolver por la función para ver si a salido todo bien*/
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#c:", line, 3) == 0) {
      toks = strtok(line + 3, DELIMITER);
      id = atol(toks);
      toks = strtok(NULL, DELIMITER);
      if(toks){
        strcpy(name, toks);
      }
      toks = strtok(NULL, DELIMITER);
      location = atol(toks);
      toks = strtok(NULL, DELIMITER);
      object = atol(toks);
      toks = strtok(NULL, DELIMITER);
      talk = atol(toks);
      toks = strtok(NULL, DELIMITER);
      if(toks){
      strcpy(description, toks);
    }
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld|%d|%ld|%s\n", id, name, location, object, talk, description);
#endif
      character = character_create(id);
      if (character != NULL) {
        character_set_name(character, name);
        character_set_description(character, description);
        character_set_location(character, location);
        character_set_object(character, object);
        character_set_talk(character, talk);

        game_add_character(game, character);

      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

STATUS game_managment_load_players(Game* game, char* filename) {
  FILE* file = NULL;  /*Puntero para el archivo de texto*/

  char line[WORD_SIZE] = "";               /*Cadena de caracteres*/
  char name[WORD_SIZE] = "";               /*Cadena de caracteres*/

  char* toks = NULL;  /*Puntero a char*/

  Id id = NO_ID, location = NO_ID;  /*Almacenamiento de diferentes ID*/
  Id object1 = NO_ID, object2 = NO_ID, object3 = NO_ID, object4 = NO_ID, object5 = NO_ID, object6 = NO_ID; /*Almacenamiento de diferentes ID*/

  Player* player = NULL;  /*Puntero a la estructura Link*/

  STATUS status = OK; /*variable a devolver por la función para ver si a salido todo bien*/
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#p:", line, 3) == 0) {
      toks = strtok(line + 3, DELIMITER);
      id = atol(toks);
      toks = strtok(NULL, DELIMITER);
      if(toks){
       strcpy(name, toks);
      }
      toks = strtok(NULL, DELIMITER);
      location = atol(toks);
      toks = strtok(NULL, DELIMITER);
      object1 = atol(toks);
      toks = strtok(NULL, DELIMITER);
      object2 = atol(toks);
      toks = strtok(NULL, DELIMITER);
      object3 = atol(toks);
      toks = strtok(NULL, DELIMITER);
      object4 = atol(toks);
      toks = strtok(NULL, DELIMITER);
      object5 = atol(toks);
      toks = strtok(NULL, DELIMITER);
      object6 = atol(toks);
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld|%d|%ld|%ld|%ld|%ld\n", id, name, location, object1, object2, object3, object4, object5, object6);
#endif
      player = player_create(id);
      if (player != NULL) {
        player_set_name(player, name);
        player_set_location(player, location);
        player_set_inventory(player, object1);
        player_set_inventory(player, object2);
        player_set_inventory(player, object3);
        player_set_inventory(player, object4);
        player_set_inventory(player, object5);
        player_set_inventory(player, object6);

        game_add_player(game, player);
      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

STATUS game_managment_save(Game* game, char* save){
  int i;

  FILE* file = NULL;

  Space* space = NULL;
  Object* object = NULL;
  Link* link = NULL;
  Character* character = NULL;
  Player* player = NULL;
  int j, n;

  Id id_inv[MAX_PLAYER_OBJECTS];

  char save_aux[] = "";


  mkdir(save, 0777);

  strcpy(save_aux, save);
  strcat(save_aux, "/spaces.dat");
  
  file = fopen(save_aux, "w");
  if(!file){
    return ERROR;
  }

  for(i = 0; game_get_space_array_position(game, i) != NULL; i++){
    space = game_get_space(game, space_get_id(game_get_space_array_position(game, i)));
    fprintf(file, "#s:%ldç", space_get_id(space));
    fprintf(file, "%sç",     space_get_name(space));
    fprintf(file, "%ldç",    space_get_link_north(space));
    fprintf(file, "%ldç",    space_get_link_east(space));
    fprintf(file, "%ldç",    space_get_link_south(space));
    fprintf(file, "%ldç",    space_get_link_west(space));
    fprintf(file, "%ldç",    space_get_link_up(space));
    fprintf(file, "%ldç",    space_get_link_down(space));
    fprintf(file, "%dç",     space_get_illuminated(space));
    fprintf(file, "%sç",     space_get_gdesc(space, 0));
    fprintf(file, "%sç",     space_get_gdesc(space, 1));
    fprintf(file, "%sç",     space_get_gdesc(space, 2));
    fprintf(file, "%sç",     space_get_gdesc(space, 3));
    fprintf(file, "%sç",     space_get_gdesc(space, 4));
    fprintf(file, "%sç",     space_get_gdesc(space, 5));
    fprintf(file, "%sç",     space_get_gdesc(space, 6));
    fprintf(file, "%sç",     space_get_gdesc(space, 7));
    fprintf(file, "%sç",     space_get_gdesc(space, 8));
    fprintf(file, "%sç",     space_get_gdesc(space, 9));
    fprintf(file, "%sç",     space_get_gdesc(space, 10));
    fprintf(file, "%sç",     space_get_description(space));
    fprintf(file, "%sç\n",   space_get_large_description(space));
  }

  fclose(file);

  strcpy(save_aux, save);
  strcat(save_aux, "/objects.dat");
  
  file = fopen(save_aux, "w");
  if(!file){
    return ERROR;
  }

  for(i = 0; game_get_object_array_position(game, i) != NULL; i++){
    object = game_get_object(game, object_get_id(game_get_object_array_position(game, i)));
    fprintf(file, "#o:%ld|", object_get_id(object));
    fprintf(file, "%s|",     object_get_name(object));
    fprintf(file, "%ld|",    game_get_object_location(game, object_get_id(object)));
    fprintf(file, "%d|",     object_get_movable(object));
    fprintf(file, "%d|",     object_get_move(object));
    fprintf(file, "%d|",     object_get_visible(object));
    fprintf(file, "%d|",     object_get_illuminate(object));
    fprintf(file, "%d|",     object_get_on(object));
    fprintf(file, "%ld|",    object_get_link(object));
    fprintf(file, "%d|",    object_get_n_objects(object));
    fprintf(file, "%s|",     object_get_description(object));
    fprintf(file, "%s|\n",   object_get_alt_description(object));
  }

  fclose(file);

  strcpy(save_aux, save);
  strcat(save_aux, "/links.dat");
  
  file = fopen(save_aux, "w");
  if(!file){
    return ERROR;
  }

  for(i = 0; game_get_link_array_position(game, i) != NULL; i++){
    link = game_get_link(game, link_get_id(game_get_link_array_position(game, i)));
    fprintf(file, "#l:%ld|", link_get_id(link));
    fprintf(file, "%s|",     link_get_name(link));
    fprintf(file, "%ld|",    link_get_linkA(link));
    fprintf(file, "%ld|",    link_get_linkB(link));
    fprintf(file, "%d|\n",   link_get_access(link));
  }

  fclose(file);

  strcpy(save_aux, save);
  strcat(save_aux, "/characters.dat");
  
  file = fopen(save_aux, "w");
  if(!file){
    return ERROR;
  }

  for(i = 0;  game_get_character_array_position(game, i) != NULL; i++){
    character = game_get_character(game, character_get_id(game_get_character_array_position(game, i)));
    fprintf(file, "#c:%ld|", character_get_id(character));
    fprintf(file, "%s|",     character_get_name(character));
    fprintf(file, "%ld|",    character_get_location(character));
    fprintf(file, "%ld|",    character_get_object(character));
    fprintf(file, "%d|",     character_get_talk(character));
    fprintf(file, "%s|\n",   character_get_description(character));
  }

  fclose(file);

  strcpy(save_aux, save);
  strcat(save_aux, "/players.dat");
  
  file = fopen(save_aux, "w");
  if(!file){
    return ERROR;
  }

  for(n=0; n<MAX_PLAYER_OBJECTS; n++){
    id_inv[n] = NO_ID;
  }

  for(j=0, n=0; j<MAX_OBJECTS && n<MAX_PLAYER_OBJECTS; j++){
    if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), j) == TRUE){
      id_inv[n] = j;
      n++;
    }
  }

  player = game_get_player(game);
  fprintf(file, "#p:%ld|", player_get_id(player));
  fprintf(file, "%s|",     player_get_name(player));
  fprintf(file, "%ld|",    game_get_player_location(game));
  fprintf(file, "%ld|",    id_inv[0]);
  fprintf(file, "%ld|",    id_inv[1]);
  fprintf(file, "%ld|",    id_inv[2]);
  fprintf(file, "%ld|",    id_inv[3]);
  fprintf(file, "%ld|",    id_inv[4]);
  fprintf(file, "%ld|\n",  id_inv[5]);

  fclose(file);


  return OK;
}

STATUS game_managment_load(Game* game, char save[]){
  char save_aux1[WORD_SIZE] = "";
  char save_aux2[WORD_SIZE] = "";
  char save_aux3[WORD_SIZE] = "";
  char save_aux4[WORD_SIZE] = "";
  char save_aux5[WORD_SIZE] = "";

  strcpy(save_aux1, save);

  strcat(save_aux1, "/spaces.dat");

  strcpy(save_aux2, save);

  strcat(save_aux2, "/objects.dat");

  strcpy(save_aux3, save);

  strcat(save_aux3, "/links.dat");

  strcpy(save_aux4, save);

  strcat(save_aux4, "/characters.dat");

  strcpy(save_aux5, save);

  strcat(save_aux5, "/players.dat");

  if(game_init_from_file(game, save_aux1, save_aux2, save_aux3, save_aux4, save_aux5) == ERROR){
    return ERROR;
  }

  return OK;
}
