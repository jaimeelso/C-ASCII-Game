/**
 * @brief Modulo Inventory
 *
 * Este modulo permite crear un inventario para el
 * jugador y que de esta manera lleve encima varios
 * objetos.
 * 
 * @file inventory.c
 * @author Jaime Elso de Blas
 * @version 1.0 (version inicial)
 * @date 09-03-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inventory.h"

/**
 * @brief struct _Inventory
 *
 * Esta estructura define un inventario
 */
struct _Inventory{
	int id_max;		/*!< Numero máximo de objetos en un inventario */
	Set* object;	/*!< Array de Id que contiene los objetos */
};

Inventory* inventory_create(){
	Inventory* inventory = NULL;	/*Declaramos una nueva estructura para el inventario*/

	inventory = (Inventory*) malloc(sizeof(Inventory));	/*Reserva de memoria*/
	if(!inventory){
		return NULL;
	}

	/*Inicializamos sus campos*/
	inventory->id_max = MAX_PLAYER_OBJECTS;

	inventory->object = set_create();

	return inventory;
}

STATUS inventory_destroy(Inventory* inventory){
	if(!inventory){
		return ERROR;
	}

	set_destroy(inventory->object);	/*Liberamos la memoria del set*/

	free(inventory);	/*Liberamos la memoria del inventario*/
	
	return OK;
}

STATUS inventory_set_object(Inventory* inventory, Id id){
	if(!inventory || id == NO_ID){
		return ERROR;
	}

	/*Comprobamos que haya sitio libre en el inventario*/
	if(set_get_numId(inventory->object) <= inventory_get_id_max(inventory)){
		/*Si lo hay añadimos el objeto al inventario*/
		if(set_add_id(inventory->object, id) == ERROR){
        	return ERROR;
    	}

    	return OK;
	}

    return ERROR;
}

Set* inventory_get_object(Inventory* inventory){
	if(!inventory){
		return NULL;
	}

	return inventory->object;
}

int inventory_get_id_max(Inventory* inventory){
	if(!inventory){
		return -1;
	}

	return inventory->id_max;
}

STATUS inventory_print(Inventory* inventory){
	if(!inventory){
		return ERROR;
	}

	fprintf(stdout, "Numero maximo de objetos posibles en la mochila: %d.\n", inventory_get_id_max(inventory));

	if(set_get_numId(inventory->object) > 0){
		fprintf(stdout, "Id de los objetos en el inventario:");
		if(set_print(inventory->object) == ERROR){
			return ERROR;
		}
	}
	else{
		fprintf(stdout, "No hay objetos en el inventario.\n");
	}
	
	return OK;
}

