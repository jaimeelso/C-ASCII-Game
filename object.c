/**
 * @brief Modulo Object
 *
 * Contiene la implementación de las funciones asociadas a los objetos
 * 
 * @file object.c
 * @author Jaime Elso de Blas
 * @version 1.0 (version inicial)
 * @date 02-02-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"
#include "types.h"

/**
 * @brief struct _Object
 *
 * La estructura _Object contiene información sobre un objeto
 */

struct _Object {
	Id id;								/*!< id del objeto*/
	char name[WORD_SIZE];				/*!< nombre del objeto*/
	char description[DESCRIPTION_SIZE]; /*!< descripcion del objeto*/
	char alt_descrip[DESCRIPTION_SIZE];	/*!< descripcion alternativa del objeto para cuando no esta en su posicion original*/
	BOOL movable;						/*!< indica si el objeto es movible o no*/
	BOOL move;							/*!< indica di el objeto se ha movido o no se su posicion inicial*/
	BOOL visible;						/*!< indica si el objeto es visible o no*/
	BOOL illuminate;					/*!< indica si el objeto es capaz de iluminar espacios o no*/
	BOOL on;							/*!< indica si esta encendido o apagado si puede iluminar*/
	Id link;							/*!< contiene el link con el que puede iteractuar*/
	int n_objects;						/*!< numero de objetos*/
};

Object* object_create(Id id){
	Object* new_object = NULL;	/*Declaramos una nueva estructura para el objeto*/

    new_object = (Object*) malloc(sizeof(Object));
    if (new_object == NULL) {
        return NULL;
    }

    /*Inicializamos sus campos*/
    new_object->id = id;
    new_object->name[0] = '\0';
    new_object->description[0] = '\0';
    new_object->alt_descrip[0] = '\0';
    new_object->movable = TRUE;
    new_object->move = FALSE;
    new_object->visible = TRUE;
    new_object->link = NO_ID;
    new_object->illuminate = FALSE;
    new_object->n_objects = 0;
    new_object->on = FALSE;

    return new_object;		
} 

STATUS object_destroy(Object* object){
	if(!object){
		return ERROR;
	}

	free(object);
	object = NULL;

	return OK;
}

STATUS object_set_name(Object* object, char* name){
	if (!object || !name) {
        return ERROR;
    }

    if (!strcpy(object->name, name)) {
        return ERROR;
    }

    return OK;
}

STATUS object_set_description(Object* object, char* description){
	if (!object || !description) {
        return ERROR;
    }

    if (!strcpy(object->description, description)) {
        return ERROR;
    }

    return OK;
}

STATUS object_set_alt_descrip(Object* object, char* description){
	if (!object || !description) {
        return ERROR;
    }

    if (!strcpy(object->alt_descrip, description)) {
        return ERROR;
    }

    return OK;
}

STATUS object_set_movable(Object* object, BOOL movable){
	if(!object){
		return ERROR;
	}

	object->movable = movable;

	return OK;
}

STATUS object_set_move(Object* object, BOOL move){
	if(!object){
		return ERROR;
	}

	object->move = move;

	return OK;
}

STATUS object_set_visible(Object* object, BOOL visible){
	if(!object){
		return ERROR;
	}

	object->visible = visible;

	return OK;
}

STATUS object_set_illuminate(Object* object, BOOL illuminate){
	if(!object){
		return ERROR;
	}

	object->illuminate = illuminate;

	return OK;
}

STATUS object_set_on(Object* object, BOOL on){
	if(!object){
		return ERROR;
	}

	if(object_get_illuminate(object) == FALSE){
		return ERROR;
	}

	object->on = on;

	return OK;
}

STATUS object_set_link(Object* object, Id link){
	if(!object){
		return ERROR;
	}

	object->link = link;

	return OK;
}

char* object_get_name(Object* object){
	if(!object){
		return NULL;
	}

	return object->name;
}

char* object_get_description(Object* object){
	if(!object){
		return NULL;
	}

	return object->description;
}

char* object_get_alt_description(Object* object){
	if(!object){
		return NULL;
	}

	return object->alt_descrip;
}

Id object_get_id(Object* object){
	if(!object){
		return NO_ID;
	}

	return object->id;
}

BOOL object_get_movable(Object* object){
	if(!object){
		return FALSE;
	}

	return object->movable;
}

BOOL object_get_move(Object* object){
	if(!object){
		return FALSE;
	}

	return object->move;
}

BOOL object_get_visible(Object* object){
	if(!object){
		return FALSE;
	}

	return object->visible;
}

BOOL object_get_illuminate(Object* object){
	if(!object){
		return FALSE;
	}

	return object->illuminate;
}

BOOL object_get_on(Object* object){
	if(!object){
		return FALSE;
	}

	return object->on;
}

Id object_get_link(Object* object){
	if(!object){
		return NO_ID;
	}

	return object->link;
}

STATUS object_print(Object* object){
	if(!object){
		return ERROR;
	}

	fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

	return OK;
}

STATUS object_set_n_objects(Object* object, int n_objects){
	if(!object){
		return ERROR;
	}

	object->n_objects = n_objects;
	return OK;
}

int object_get_n_objects(Object* object){
	if(!object){
		return -1;
	}

	return object->n_objects;
}

STATUS 	object_change_n_objects(Object* object, int n_objects){
	if(!object){
		return ERROR;
	}

	object->n_objects = object->n_objects + n_objects;

	if(object->n_objects < 0){
		return ERROR;
	}
	
	return OK;
}