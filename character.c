/**
 * @brief Modulo Character
 *
 * Módulo encargado de manejar todo lo relacionado con los personajes del juego
 * 
 * @file character.c
 * @author Jaime Elso de Blas 
 * @version 1.0 (version inicial)
 * @date 09-04-2016
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "character.h"
 
/**
 * @brief struct _Character
 *
 * Estructura Character almacena los datos de los personajes del juego
 */
struct _Character{
	Id id; 								/*!< id del personaje*/
	Id location;						/*!< id del espacio en el que se encuentra el personaje*/
	Id object;							/*!< id del objeto que tiene para darnos (NO_ID si no da objetos el personaje)*/
	char name[WORD_SIZE];				/*!< nombre del personaje*/
	char description[DESCRIPTION_SIZE]; /*!< descripcion del personaje*/
	BOOL talk;							/*!< indica si se puede hablar con el personaje o no*/
};

Character* character_create(Id id){
	Character* character = NULL;

	character = (Character*) malloc(sizeof(Character));
	if(!character){
		return NULL;
	}

	/*Inicializamos sus campos*/
	character->id = id;
	character->location = NO_ID;
	character->object = NO_ID;
	character->name[0] = '\0'; 
	character->description[0] = '\0';
	character->talk = TRUE;

	return character;
}

STATUS character_destroy(Character* character){
	if(!character){
		return ERROR;
	}

	free(character);

	return OK;
}

Id character_get_id(Character* character){
	if(!character){
		return NO_ID;
	}

	return character->id;
}

STATUS character_set_location(Character* character, Id id){
	if(!character || id == NO_ID){
		return ERROR;
	}

	character->location = id;

	return OK;
}

Id character_get_location(Character* character){
	if(!character){
		return NO_ID;
	}

	return character->location;
}

STATUS character_set_object(Character* character, Id id){
	if(!character || id == NO_ID){
		return ERROR;
	}

	character->object = id;

	return OK;
}

Id character_get_object(Character* character){
	if(!character){
		return NO_ID;
	}

	return character->object;
}

STATUS character_set_name(Character* character, char* name){
	if (!character || !name) {
        return ERROR;
    }

    if (!strcpy(character->name, name)) {
        return ERROR;
    }

    return OK;
}

char* character_get_name(Character* character){
	if(!character){
		return NULL;
	}

	return character->name;
}

STATUS character_set_description(Character* character, char* description){
	if (!character || !description) {
        return ERROR;
    }

    if (!strcpy(character->description, description)) {
        return ERROR;
    }

    return OK;
}

char* character_get_description(Character* character){
	if(!character){
		return NULL;
	}

	return character->description;
}

STATUS character_set_talk(Character* character, BOOL talk){
	if(!character){
		return ERROR;
	}

	character->talk = talk;

	return OK;
}

BOOL character_get_talk(Character* character){
	if(!character){
		return FALSE;
	}

	return character->talk;
}
