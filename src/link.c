/** 
 * @brief Implementa la funcionalidad de los links
 * 
 * @file link.c
 * @author Alfredo de Frutos Estebaranz 
 * @version 1.0 
 * @date 09-03-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/link.h"

/**
 * @brief struct _Link
 *
 * Esta estructura define un link
 */

struct _Link{
	Id id;                     /*!< Identificador del Link */
	char name[WORD_SIZE + 1];  /*!< Nombre del Link */
	Id linkA;                  /*!< Identificador del espacio contectado por el extremo linkA de Link */
	Id linkB;                  /*!< Identificador del espacio contectado por el extremo linkB de Link */
	int access;                /*!< Estado del Link (OPEN = 0, CLOSE = 1) */
	char clue[WORD_SIZE];	   /*!< Pista */
};

Link* link_create(Id id){

	Link* newLink = NULL; /* Declaramos un nuevo Link */

	newLink = (Link *) malloc(sizeof(Link)); /* Reservamos memoria para la estructura Link */

	if (newLink == NULL) {
    	return NULL;
    }
    /* Inicializamos los valores de los campos de la estructura Link */
    newLink->id = id;
    newLink->name[0] = '\0';
    newLink->linkA = NO_ID;
    newLink->linkB = NO_ID;
    newLink->access = 0;

    return newLink;
}

STATUS link_destroy(Link* link) {
    if (!link) {
    	return ERROR;
    }
    
    free(link); /* Liberamos la memoria de una estructura tipo Link */
    link = NULL;

    return OK;
}

STATUS link_set_name(Link* link, char* name){
	if (!link || !name) {
    	return ERROR;
    }

    if (!strcpy(link->name, name)) {    /*  Modificamos el campo name de la estructura 
                                            link recibida con el nombre recibido */
    	return ERROR;
    }

    return OK;
}

STATUS link_set_linkA(Link* link, Id id){
	if (!link || id == NO_ID) {
    	return ERROR;
    }
    link->linkA = id;                   /*  Modificamos el campo linkA de la estructura 
                                            link recibida con el id recibido */
    return OK;
}

STATUS link_set_linkB(Link* link, Id id){
	if (!link || id == NO_ID) {
    	return ERROR;
    }
    link->linkB = id;                   /*  Modificamos el campo linkB de la estructura 
                                            link recibida con el id recibido */
    return OK;
}

STATUS link_set_access(Link* link, int access){
	if (!link) {
    	return ERROR;
    }
    link->access = access;              /*  Modificamos el campo access de la estructura 
                                            link recibida con el valor recibido (OPEN = 0, CLOSE = 1*/
    return OK;
}

Id link_get_id(Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->id;
}

const char * link_get_name(Link* link) {
    if (!link) {
        return NULL;
    }
    return link->name;
}

Id link_get_linkA(Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->linkA;
}

Id link_get_linkB(Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->linkB;
}

STATUS link_set_clue(Link* link, char* clue){
	if (!link || !clue) {
    	return ERROR;
    }

    if (!strcpy(link->clue, clue)){                             
   		return ERROR;
    }

    return OK;
}

char* link_get_clue(Link* link) {
    if (!link) {
        return NULL;
    }
    return link->clue;
}

int link_get_access(Link* link){
	if (!link) {
        return -1;
    }
    
    return link->access;
}



STATUS link_print(Link* link){
	if (!link) {
        return ERROR;
    }

    fprintf(stdout, "--> Link (Id: %ld; Name: %s, LinkA: %ld, LinkB: %ld, ", link->id, link->name, link->linkA, link->linkB);

    if(link->access == OPEN){
    	fprintf(stdout, "Access: OPEN)\n");
    } else{
    	fprintf(stdout, "Access: CLOSE)\n");
    }

    return OK;
}