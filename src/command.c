/**
* @brief Modulo Command
*
* Modulo encargado de manejar los comandos introducidos por el 
* usuario e interpretarlos
* 
* @file command.c
* @author Jaime Elso de Blas y Sergio García Bordonado
* @version 1.0 (version inicial)
* 	versión 1.1: Dos nuevos comandos (TAKE y DROP)
* 	versión 2.0: Dos nuevos comandos (ROLL y JUMP) y estructura para el comando (MyCmd)
*	versión 3.0: Nuevos comandos: GO, INSPECT, TURNON y TURNOFF
* @date 06-04-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/command.h"

/**
 * @brief struct _MyCmd
 *
 * Estructura con nuestro comando y el argumento que recibe.
 */
struct _MyCmd{
	T_Command cmd;	/*!< Primer comando introducido por el usuario*/
	T_Command arg;	/*!< Segundo comando introducido por el usuario*/
	Id obj;			/*!< ID del objeto introducido por el usuario*/
	char objname[CMD_LENGHT];  /*!< Nombre del objeto introducido por el usuario*/
	char link[CMD_LENGHT];  /*!< Nombre del link introducido por el usuario*/
	char charname[CMD_LENGHT]; /*!< Nombre del personaje introducido por el usuario*/
};

MyCmd* get_user_input(MyCmd* mycmd){
	char input[CMD_LENGHT] = "\0";  /*Guardamos el comando (sin incluir objeto) que introduce el usuario*/
	char input_ini[CMD_LENGHT] = "\0";	/*cadena de caracteres (comando y posible objeto) introducido por el usuario*/
	char* toks = NULL;	/*se utiliza para llamar a la función strtok*/
	char input_nd[CMD_LENGHT] = "\0"; /*segundo argumento escrito*/
	char input_rd[CMD_LENGHT] = "\0"; /*segundo argumento escrito*/
	char input_lt[CMD_LENGHT] = "\0"; /*segundo argumento escrito*/
	

	mycmd->cmd = NO_CMD;
	mycmd->arg = NO_CMD;
	mycmd->obj = NO_ID;

	
	if (fgets(input_ini, CMD_LENGHT, stdin) != NULL){
		toks = strtok(input_ini, " \n");
		if(toks != NULL){
			strcpy(input, toks);
		}
		toks = strtok(NULL, " \n");
		if(toks != NULL){
			strcpy(input_nd, toks);
		}
		toks = strtok(NULL, " \n");
		if(toks != NULL){
			strcpy(input_rd, toks);
		}
		toks = strtok(NULL, " \n");
		if(toks != NULL){
			strcpy(input_lt, toks);
		}

		if (!strcmp(input, "q") || !strcmp(input, "quit")){
			mycmd->cmd = QUIT;
		}	
		else if (!strcmp(input, "a") || !strcmp(input, "avanzar")){
			mycmd->cmd = GO;

			if(!strcmp(input_nd, "n") || !strcmp(input_nd, "norte")){
				mycmd->arg = NORTH;
			}
			else if (!strcmp(input_nd, "s") || !strcmp(input_nd, "sur")){
				mycmd->arg = SOUTH;
			}
			else if (!strcmp(input_nd, "o") || !strcmp(input_nd, "oeste")){
				mycmd->arg = WEST;
			}
			else if (!strcmp(input_nd, "e") || !strcmp(input_nd, "este")){
				mycmd->arg = EAST;
			}
			else if (!strcmp(input_nd, "ar") || !strcmp(input_nd, "arriba")){
				mycmd->arg = UP;
			}
			else if (!strcmp(input_nd, "aba") || !strcmp(input_nd, "abajo")){
				mycmd->arg = DOWN;
			}
			else{
				mycmd->arg = UNKNOWN;
			}
		}
		else if (!strcmp(input, "c") || !strcmp(input, "coger")){
			mycmd->cmd = TAKE;
			strcpy(mycmd->objname, input_nd);
		}
		else if (!strcmp(input, "d") || !strcmp(input, "dejar")){
			mycmd->cmd = DROP;
			strcpy(mycmd->objname, input_nd);
		}
		else if (!strcmp(input, "l") || !strcmp(input, "lanzar")){
			mycmd->cmd = ROLL;
		}
		else if (!strcmp(input, "i") || !strcmp(input, "inspeccionar")){
			mycmd->cmd = INSPECT;

			if(!strcmp(input_nd, "e") || !strcmp(input_nd, "espacio")){
				mycmd->arg = SPACE;
			}
			else{
				strcpy(mycmd->objname, input_nd);
				mycmd->arg = OBJECT;
				strcpy(mycmd->objname, input_nd);
			}
			
		}
		else if (!strcmp(input, "ton") || !strcmp(input, "turnon")){
			mycmd->cmd = TURNON;
			strcpy(mycmd->objname, input_nd);
			
		}
		else if (!strcmp(input, "toff") || !strcmp(input, "turnoff")){
			mycmd->cmd = TURNOFF;
			strcpy(mycmd->objname, input_nd);
		}
		else if (!strcmp(input, "ab") || !strcmp(input, "abrir")){
			mycmd->cmd = OPENING;
			if(!strcmp(input_rd, "c") || !strcmp(input_rd, "con")){
				strcpy(mycmd->link, input_nd);
				strcpy(mycmd->objname, input_lt);
			}
		}
		else if(!strcmp(input, "g") || !strcmp(input, "guardar")){
			mycmd->cmd = SAVE;
			strcpy(mycmd->objname, input_nd);
		}
		else if(!strcmp(input, "h") || !strcmp(input, "hablar")){
			mycmd->cmd = TALK;
			strcpy(mycmd->charname, input_nd);
		}
		else if (!strcmp(input, "b") || !strcmp(input, "beber")){
			mycmd->cmd = DRINK;
			strcpy(mycmd->objname, input_nd);
		}
		else{
			mycmd->cmd = UNKNOWN;
		}
	}
	return mycmd;
}

MyCmd* command_create(){
	MyCmd* mycmd = NULL; /*declaración de puntero MyCmd*/

	mycmd = (MyCmd*) malloc(sizeof(MyCmd)); /*reserva de memoria*/
	if(!mycmd){
		return NULL;
	}
	/*asignación de valores por defecto*/
	mycmd->cmd = NO_CMD;
	mycmd->arg = NO_CMD;
	mycmd->obj = NO_ID;

	return mycmd; 
}

void command_destroy(MyCmd* mycmd){
	if(!mycmd){
		return;
	}

	free(mycmd);/*liberación de memoria*/
	mycmd = NULL;
}

T_Command command_get_cmd(MyCmd* mycmd){
	if(!mycmd){
		return NO_CMD;
	}

	return mycmd->cmd;
}

T_Command command_get_arg(MyCmd* mycmd){
	if(!mycmd){
		return NO_CMD;
	}

	return mycmd->arg;
}

Id command_get_obj(MyCmd* mycmd){
	if(!mycmd){
		return NO_ID;
	}

	return mycmd->obj;
}

char* command_get_objname(MyCmd* mycmd){
	if(!mycmd){
		return NULL;
	}

	return mycmd->objname;
}

char* command_get_link(MyCmd* mycmd){
	if(!mycmd){
		return NULL;
	}

	return mycmd->link;
}

char* command_get_charname(MyCmd* mycmd){
	if(!mycmd){
		return NULL;
	}

	return mycmd->charname;
}