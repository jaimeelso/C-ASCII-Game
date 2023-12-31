/**
 * @brief Modulo Die
 *
 * Módulo encargado de manejar todo lo relacionado con el dado
 * 
 * @file die.c
 * @author Jaime Elso de Blas y Sergio García Bordonado
 * @version 1.0 (version inicial)
 * @date 05-03-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/die.h"
 
/**
 * @brief struct _Die
 *
 * Estructura Die almacena los datos del dado
 */
struct _Die{
	Id id; 		/*!< id del dado*/
	int num; 	/*!< número obtenido en la ultima tirada */
};

Die* die_create(Id id){
	Die* die = NULL; /*declaramos un nuevo puntero a Die*/

	die = (Die*) malloc(sizeof(Die)); /* reservamos memoria para el puntero*/
	if (die == NULL){ /*comprobamos que se haya resrvado la memoria correctamente*/
		return NULL; /*devolvemos NULL en caso de error al alignar memoria*/
	}

	die->id = id;
	die->num = 0; /*asignamos como último resultado "0" ya que todavia no se ha lanzado*/

	return die; 
}

STATUS die_destroy(Die* die){

	if(die == NULL){ /*comprobamos que die exista*/
		return ERROR;
	}

	free (die);/*liberamos la memoria que ocupa la estructura*/

	return OK;
}

Die* die_roll(Die * die){

	if(die == NULL){ /*comprobamos que die exista*/
		return NULL;
	}

	srand(time(NULL));

	die->num = rand () % (5) + 1;   /* Devuelve un valor entre 1 y 5 */

	return die;
}

int die_get_num(Die* die){
	if(die == NULL){ /*comprobamos que die exista*/
		return -1;
	}

	return die->num; /*devolvemos el ultimo resultado del dado*/
}

Id die_get_id(Die* die){
	if(die == NULL){ /*comprobamos que die exista*/
		return NO_ID;
	}

	return die->id;
}

STATUS die_print(Die * die){
	if(!die){ /*comprobamos que die exista*/
		return ERROR;
	}

	fprintf(stdout, "--> Die (Id: %ld; Número: %d)\n", die->id, die->num);

	return OK;
}
