/**
 * @brief Modulo Set
 *
 * Archivo que maneja todo lo relacionado con las estructuras de tipo Set
 * 
 * @file set.c
 * @author Jaime Elso de Blas
 * @version 1.0 (version inicial)
 * @date 05-02-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/set.h"

 /**
 * @brief struct _Set
 *
 * La estructura _Set contiene información sobre los tipo Set
 */
struct _Set{
	Id id[MAX_SET]; /*!< Array de id*/
	int num_id; /*!< número de ids almacenados en el array*/
};

Set* set_create(){
	int i; /*contador*/
	Set* set = NULL; /*declaración de puntero a Set*/

	set = (Set*) malloc(sizeof(Set));/*reserva de memoria*/
	if(!set){
		return NULL;
	}
	/*Inicializacion de sus campos*/
	for(i = 0; i < MAX_SET; i++){
		set->id[i] = NO_ID;
	}

	set->num_id = 0;

	return set;
}

STATUS set_destroy(Set* set){

	if(!set){
		return ERROR;
	}

	free(set);	/*liberacion de memoria*/
	set = NULL;

	return OK;
}

STATUS set_add_id(Set* set, Id id){
	int i; /*contador*/

	if(!set || id == NO_ID){
		return ERROR;
	}

	for(i = 0; i < MAX_SET; i++){
		if(set->id[i] == NO_ID){
			set->id[i] = id;
			(set->num_id)++;
			return OK;
		}
	}

	return ERROR;
}

STATUS set_del_id(Set* set, Id id){
	int i;/*contador*/

	if(!set || id == NO_ID){
		return ERROR;
	}

	for(i = 0; i < MAX_SET; i++){
		if(set->id[i] == id){
			set->id[i] = NO_ID;
			(set->num_id)--;
			return OK;
		}
	}

	return ERROR;
}

STATUS set_print(Set* set){
	int i;/*contador*/

	if(!set){
		return ERROR;
	}

	for(i = 0; i < MAX_SET; i++){
		if(set->id[i] != NO_ID){
			fprintf(stdout, "%ld ", (long)set->id[i]);
		}
	}

	return OK;
}

BOOL set_check_id(Set* set, Id id){
	int i;/*contador*/

	if(!set || id == NO_ID){
		return FALSE;
	}

	for (i = 0; i < MAX_SET; i++){
		if (id == set->id[i]){
			return TRUE;
		}
	}

	return FALSE;
}

int set_get_numId(Set* set){
	if(!set){
		return -1;
	}

	return set->num_id;
}

BOOL set_check_noId(Set* set){
	int i;/*contador*/

	if(!set){
		return FALSE;
	}

	for (i = 0; i < MAX_SET; i++){
		if (NO_ID != set->id[i]){
			return FALSE;
		}
	}

	return TRUE;
}

Id set_get_id(Set* set, Id id){
	int i;/*contador*/

	if(!set){
		return NO_ID;
	}

	for(i = 0; i < MAX_SET; i++){
		if(set->id[i] == id){
			return set->id[i];
		}
	}

	return NO_ID;
}