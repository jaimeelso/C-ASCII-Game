/**
 * @brief Modulo Dialogue
 *
 * Módulo encargado de manejar todo lo relacionado con los diálogos de los personajes del juego
 * 
 * @file dialogue.c
 * @author Jaime Elso de Blas 
 * @version 1.0 (version inicial)
 * @date 18-04-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/dialogue.h"

/**
 * @brief struct _Character
 *
 * Estructura Character almacena los datos de los personajes del juego
 */
struct _Dialogue{
    char conv [ROWS][MAX_DIALOGUE]; /*!< Conversación */
};

Dialogue* dialogue_create(){
    int i;

    Dialogue* dialogue = NULL;

    dialogue = (Dialogue*) malloc(sizeof(Dialogue));
    if(!dialogue){
        return NULL;
    }

    for(i = 0 ; i < ROWS ; i++){
        dialogue->conv[i][0] = '\0';
    }

    return dialogue;
}

STATUS dialogue_destroy(Dialogue* dialogue){
    if(!dialogue){
        return ERROR;
    }

    free(dialogue);

    return OK;
}

char* dialogue_get_conv(Dialogue* dialogue, int num){
    if(!dialogue){
        return NULL;
    }

    return dialogue->conv[num];
}

STATUS dialogue_set_conv(Dialogue* dialogue, int num, char* texto){
    if(!dialogue){
        return ERROR;
    }

    strcpy(dialogue->conv[num], texto);

    return OK;
}

STATUS dialogue_reset(Dialogue* dialogue){
    int i;
    
    if(!dialogue){
        return ERROR;
    }

    for(i = 0 ; i < ROWS ; i++){
        dialogue->conv[i][0] = '\0';
    }

    return OK;
}

BOOL dialogue_status(Dialogue* dialogue){
    if(!dialogue){
        return FALSE;
    }

    if(dialogue->conv[0][0] == '\0'){
        return TRUE;
    }

    return FALSE;
}


