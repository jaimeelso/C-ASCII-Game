/**
 * @brief Modulo Dialogue
 *
 * Archivo de cabecera de dialogue.c
 * 
 * @file dialogue.h
 * @author Jaime Elso de Blas 
 * @version 1.0 (version inicial)
 * @date 18-04-2016
 */

#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "types.h"

#define MAX_DIALOGUE 100 	/*!< Número máximo de diálogos */
#define ROWS 3				/*!< Número de filas */	

/**
 * @brief struct _Character
 *
 * Estructura Character almacena los datos de los personajes del juego
 */
typedef struct _Dialogue Dialogue;


/**
 * @date 18-04-2016
 * @author Jaime Elso de Blas
 * @brief Crea un diálogo, reservando memoria para su estructura.
 * @return Dialogue*: estructura de tipo Dialogue
 */
Dialogue* dialogue_create();

/**
 * @date 18-04-2016
 * @author Jaime Elso de Blas
 * @brief Destruye un diálogo, liberando la memoria reservada.
 * @param dialogue: estructura de tipo Dialogue
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS dialogue_destroy(Dialogue* dialogue);

/**
 * @date 18-04-2016
 * @author Jaime Elso de Blas
 * @brief Devuelve una linea concreta de un diálogo
 * @param dialogue: estructura de tipo Dialogue
 * @param num: número de fila
 * @return char*: diálogo
 */
char* dialogue_get_conv(Dialogue* dialogue, int num);

/**
 * @date 18-04-2016
 * @author Jaime Elso de Blas
 * @brief Modifica una linea concreta de un diálogo
 * @param dialogue: estructura de tipo Dialogue
 * @param num: número de fila
 * @param texto: texto a añadir
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS dialogue_set_conv(Dialogue* dialogue, int num, char* texto);

/**
 * @date 18-04-2016
 * @author Jaime Elso de Blas
 * @brief Resetea un diálogo
 * @param dialogue: estructura de tipo Dialogue
 * @return STATUS:  "OK" si todo ha ido correctamente
 *                  "ERROR" si ha habido algún problema
 */
STATUS dialogue_reset(Dialogue* dialogue);

/**
 * @date 18-04-2016
 * @author Jaime Elso de Blas
 * @brief Comprueba si un diálogo está vacío o no
 * @param dialogue: estructura de tipo Dialogue
 * @return BOOL: TRUE o FALSE
 */
BOOL dialogue_status(Dialogue* dialogue);

#endif