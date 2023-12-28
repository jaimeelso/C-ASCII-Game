/**
 * @brief Modulo Space
 *
 * Es el archivo que se encarga de comprobar los epacios del juego
 * para los objeos y el jugador
 * 
 * @file space.c
 * @author Jaime Elso de Blas y Sergio García Bordonado
 * @version 1.0 (version inicial)
 *  versión 1.1: modificación de las funciones space_set_object
 * y space_get_object al cambiar el tipo de variable BOOL a Id de la variable
 *  version 2.0 implementacion del modulo Set para el manejo de objetos
 * en cada espacio, implementacion de la descripción ASCII de cada espacio.
 * @date 02-02-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/space.h"

/**
 * @brief struct _Space
 *
 * Esta estructura almacena la información sobre un espacio, su
 * dirección, nombre y si hay algún objeto.
 */
 
struct _Space {
    Id id;                                              /*!< id del espacio*/
    char name[WORD_SIZE + 1];                           /*!< nombre del espacio*/
    Id link_north;                                      /*!< norte*/
    Id link_south;                                      /*!< sur*/
    Id link_east;                                       /*!< este*/
    Id link_west;                                       /*!< oeste*/
    Id link_up;                                         /*!< arriba*/
    Id link_down;                                       /*!< abajo*/
    Set* object;                                        /*!< id del objeto del espacio*/
    char gdesc[11][DESC_SIZE];                          /*!< Descripcion ASCII del espacio*/
    char description[DESCRIPTION_SIZE];                 /*!< Descripcion del espacio*/
    char large_description[LARGE_DESCRIPTION_SIZE];     /*!< Descripcion detallada del espacio*/
    BOOL illuminated;                                   /*!< Iluminación del espacio */
};

Space* space_create(Id id) {
  Space* new_space = NULL;  /*variable estructura sapce*/

  if (id == NO_ID){
      return NULL;
  }

  new_space = (Space*) malloc(sizeof(Space));  /*reserva de memoria*/
  if (new_space == NULL) {
      return NULL;
  }

  /*Establecemos su id*/
  new_space->id = id;

  /*Inicializamos el resto de campos*/
  new_space->name[0] = '\0';
  new_space->link_up = NO_ID;
  new_space->link_down = NO_ID;
  new_space->link_north = NO_ID;
  new_space->link_south = NO_ID;
  new_space->link_east = NO_ID;
  new_space->link_west = NO_ID;
  new_space->object = set_create();
  new_space->gdesc[0][0] = '\0';
  new_space->gdesc[1][0] = '\0';
  new_space->gdesc[2][0] = '\0';
  new_space->gdesc[3][0] = '\0';
  new_space->gdesc[4][0] = '\0';
  new_space->gdesc[5][0] = '\0';
  new_space->gdesc[6][0] = '\0';
  new_space->gdesc[7][0] = '\0';
  new_space->gdesc[8][0] = '\0';
  new_space->gdesc[9][0] = '\0';
  new_space->gdesc[10][0] = '\0';
  new_space->description[0] = '\0';
  new_space->illuminated = TRUE;

  return new_space;
}

STATUS space_destroy(Space* space) {
    if (!space) {
        return ERROR;
    }

    set_destroy(space->object);

    free(space);    /*liberacion de memoria*/

    return OK;
}

STATUS space_set_name(Space* space, char* name) {
    if (!space || !name) {
        return ERROR;
    }

    if (!strcpy(space->name, name)) {
        return ERROR;
    }

    return OK;
}

STATUS space_set_description(Space* space, char* description) {
    if (!space || !description) {
        return ERROR;
    }

    if (!strcpy(space->description, description)) {
        return ERROR;
    }

    return OK;
}

STATUS space_set_large_description(Space* space, char* description) {
    if (!space || !description) {
        return ERROR;
    }

    if (!strcpy(space->large_description, description)) {
        return ERROR;
    }

    return OK;
}

STATUS space_set_link_north(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }

    space->link_north = id;
    return OK;
}

STATUS space_set_link_south(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }

    space->link_south = id;
    return OK;
}

STATUS space_set_link_east(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }

    space->link_east = id;
    return OK;
}

STATUS space_set_link_west(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }

    space->link_west = id;
    return OK;
}

STATUS space_set_link_up(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }

    space->link_up = id;
    return OK;
}

STATUS space_set_link_down(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }

    space->link_down = id;
    return OK;
}

STATUS space_set_object(Space* space, Id id) {
    if (!space) {
        return ERROR;
    }

    if(set_add_id(space->object, id) == ERROR){
        return ERROR;
    }

    return OK;
}

STATUS space_set_illuminated(Space* space, BOOL ill) {
    if (!space) {
        return ERROR;
    }

    space->illuminated = ill;

    return OK;
}

const char* space_get_name(Space* space) {
    if (!space) {
        return NULL;
    }

    return space->name;
}

const char* space_get_description(Space* space) {
    if (!space) {
        return NULL;
    }

    return space->description;
}

const char* space_get_large_description(Space* space) {
    if (!space) {
        return NULL;
    }

    return space->large_description;
}

Id space_get_id(Space* space) {
    if (!space) {
        return NO_ID;
    }

    return space->id;
}

Id space_get_link_north(Space* space) {
    if (!space) {
        return NO_ID;
    }

    return space->link_north;
}

Id space_get_link_south(Space* space) {
    if (!space) {
        return NO_ID;
    }

    return space->link_south;
}
    
Id space_get_link_east(Space* space) {
    if (!space) {
        return NO_ID;
    }

    return space->link_east;
}

Id space_get_link_west(Space* space) {
    if (!space) {
        return NO_ID;
    }

    return space->link_west;
}

Id space_get_link_up(Space* space) {
    if (!space) {
        return NO_ID;
    }

    return space->link_up;
}

Id space_get_link_down(Space* space) {
    if (!space) {
        return NO_ID;
    }

    return space->link_down;
}

Set* space_get_object(Space* space) {
    if (!space) {
        return FALSE;
    }

    return space->object;
}

STATUS space_set_gdesc(Space* space, int num, char* string){
    if(!space || !string){
        return ERROR;
    }

    strcpy(space->gdesc[num], string);

    return OK;
}

char* space_get_gdesc(Space* space, int num){
    if(!space){
        return NULL;
    }

    return space->gdesc[num];
}

BOOL space_get_illuminated(Space* space) {
    if (!space) {
        return FALSE;
    }

    return space->illuminated;
}

STATUS space_print(Space* space) {
    Id id_aux = NO_ID;  /*id auxiliar*/
  
    if (!space) {
        return ERROR;
    }

    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
    
    id_aux = space_get_link_north(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> North link: %ld.\n", id_aux);
    } 
    else {
        fprintf(stdout, "---> No north link.\n");
    }
    
    id_aux = space_get_link_south(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> South link: %ld.\n", id_aux);
    } 
    else {
        fprintf(stdout, "---> No south link.\n");
    }
    
    id_aux = space_get_link_east(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> East link: %ld.\n", id_aux);
    } 
    else {
        fprintf(stdout, "---> No east link.\n");
    }
    
    id_aux = space_get_link_west(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> West link: %ld.\n", id_aux);
    } 
    else {
        fprintf(stdout, "---> No west link.\n");
    }

    id_aux = space_get_link_up(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> Up link: %ld.\n", id_aux);
    } 
    else {
        fprintf(stdout, "---> No up link.\n");
    }

    id_aux = space_get_link_down(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> Down link: %ld.\n", id_aux);
    } 
    else {
        fprintf(stdout, "---> No down link.\n");
    }
    
   if (set_get_numId(space->object) > 0) {
        fprintf(stdout, "---> Object in the space.\n");
    } 
    else {
        fprintf(stdout, "---> No object in the space.\n");
    }

    if (space_get_illuminated(space) == TRUE){
    	fprintf(stdout, "---> Space is illuminated.\n");
    }
    else{
    	fprintf(stdout, "---> Space is darked.\n");
    }

    return OK;
}