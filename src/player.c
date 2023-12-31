/**
 * @brief Modulo Player
 *
 * Es el módulo que contiene todos los campos y funcioalidades 
 * relacionados con el jugador
 * 
 * @file player.c
 * @author Sergio García Bordonado
 * @version 1.0 (version inicial)
 *  versión 1.1: corrección de errores en la función player_create al
 *  no asignar un Id al crearlo
 *  versión 2.0: Implementacion del modulo Inventory en el player para
 *  que el jugador disponga de un inventario en vez de un solo objeto
 * @date 03-02-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/player.h"

/**
 * @brief struct _Player
 *
 * La estructura Player almacena información sobre el jugador
 */
struct _Player {
    char name[WORD_SIZE + 1];	/*!< Nombre del jugador*/
    Id id;	                    /*!< identificación del jugador*/
    Inventory* inventory;	    /*!< Identificación del objeto que posee el jugador*/
    Id location;	            /*!< localización del jugador*/
};

Player* player_create(Id id){
	Player* new_player = NULL;	/*Declaramos una nueva estructura para el jugador*/

    new_player = (Player*) malloc(sizeof(Player));
    if (new_player == NULL) {
        return NULL;
    }

    /*Inicializamos sus campos*/
    new_player->id = id;
    new_player->inventory = inventory_create();
    new_player->location = NO_ID;
    new_player->name[0] = '\0';

    return new_player;		
}

STATUS player_destroy(Player* player){
	if(!player){
		return ERROR;
	}

    inventory_destroy(player->inventory);

	free(player);
	player = NULL;

	return OK;
}

const char* player_get_name(Player* player){
	if(!player){
		return NULL;
	}

	return player->name;
}

STATUS player_set_name(Player* player, char* name){
    if (!player || !name) {
        return ERROR;
    }

    if (!strcpy(player->name, name)) {
        return ERROR;
    }

    return OK;
}

Id player_get_id(Player* player){
	if(!player){
		return NO_ID;
	}

	return player->id;
}

STATUS player_set_id(Player* player, Id id){
    if (!player){
    	return ERROR;
    }

    player->id = id;

    return OK;
}


Inventory* player_get_inventory(Player* player) {
    if (!player) {
        return NULL;
    }
    return player->inventory;
}

STATUS player_set_inventory(Player* player, Id id) {
    if (!player) {
        return ERROR;
    }

    inventory_set_object(player->inventory, id);

    return OK;
}

BOOL player_check_object(Player* player, Id id){
    if (!player || id == NO_ID){
        return FALSE;
    }

    return set_check_id(inventory_get_object(player->inventory), id);
}

Id player_get_location(Player* player){
    if (!player){
    	return NO_ID;
    }

    return player->location;
}

STATUS player_set_location(Player* player, Id id){
    if (!player){
    	return ERROR;
    }

    player->location = id;

    return OK;
}

STATUS player_print(Player* player){
    if (!player){
            return ERROR;
    }

    fprintf(stdout, "Player (Id: %ld; Name: %s; Location:%ld )\n", player->id, player->name, player->location);
    fprintf(stdout, "Player objects:");
    set_print(inventory_get_object(player->inventory));
    
    return OK;
}
