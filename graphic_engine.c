/**
* @brief Modulo Graphic Engine
*
* Es el modulo que contiene todas las funciones necesarias para el 
* entorno grafico que se muestra por pantalla
* 
* @file graphic_engine.c
* @author Alfredo de Frutos Estebaranz
* @version 11-04-2016 version 1.0 (version inicial)
* @date 11-04-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphic_engine.h"

#ifdef __WINDOWS_BUILD__
#define CLEAR "cls" 	/*!< Clear de la consola */
#else
#define CLEAR "clear"	/*!< Clear de la consola */
#endif

STATUS graphic_engine_print_screen(Game* game, MyCmd* mycmd){
	Id id_act = NO_ID, id_inv[MAX_PLAYER_OBJECTS];
	Space* space_act = NULL;  /*Puntero a estructura space, almacenamos el espacio actual*/
	int i,j, n = 0;

	id_act = game_get_player_location(game);
  
	if (id_act == NO_ID){
	    return ERROR;
	}
	  
	space_act = game_get_space(game, id_act);

	if (system(CLEAR)){
  		return ERROR; 
  	}
  	for(n=0; n<MAX_PLAYER_OBJECTS; n++){
  		id_inv[n] = NO_ID;
  	}

  	for(j=0, n=0; j<MAX_OBJECTS && n<MAX_PLAYER_OBJECTS; j++){
  		if(set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), j) == TRUE){
  			id_inv[n] = j;
  			n++;
  		}
  	}

  	if(game_get_link_access(game, 1) == OPEN && id_act == 1){
  		graphic_engine_message();
  	}

  	else{
  		if(space_get_illuminated(space_act) == FALSE || (set_check_id(inventory_get_object(player_get_inventory(game_get_player(game))), LINTERNA) == TRUE && object_get_on(game_get_object_by_name(game, "linterna")) == TRUE)){
	  		for(i=0; i < MAX_ROWS; i++){

				printf("%s     ", space_get_gdesc(space_act, i));
				if(i == 0)
					printf("\n");
				else if(i == 1)
					printf("Estás en: %s\n", space_get_name(space_act));
				else if(i == 2)
					printf("\n");
				else if(i == 3)
					printf("Tu inventario:\n");
				else if(i == 4){
					if(id_inv[0] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[0]));
						if(object_get_n_objects(game_get_object(game, id_inv[0])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[0])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 5){
					if(id_inv[1] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[1]));
						if(object_get_n_objects(game_get_object(game, id_inv[1])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[1])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 6){
					if(id_inv[2] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[2]));
						if(object_get_n_objects(game_get_object(game, id_inv[2])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[2])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 7){
					if(id_inv[3] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[3]));
						if(object_get_n_objects(game_get_object(game, id_inv[3])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[3])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 8){
					if(id_inv[4] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[4]));
						if(object_get_n_objects(game_get_object(game, id_inv[4])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[4])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 9){
					if(id_inv[5] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[5]));
						if(object_get_n_objects(game_get_object(game, id_inv[5])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[5])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 10){
					printf("Nivel de embriaguez: %d%%\n", ((game_get_drunkenness(game)*100)/4));
				}
				else if(i > 10 && i < 12){
					printf("\n");
				}

			}

			if(dialogue_status(game_get_dialogue(game)) == FALSE){
				printf("\nDiálogo: \n");
				printf("%s\n", dialogue_get_conv(game_get_dialogue(game), 0));
				printf("%s\n", dialogue_get_conv(game_get_dialogue(game), 1));
				printf("%s\n", dialogue_get_conv(game_get_dialogue(game), 2));

				dialogue_reset(game_get_dialogue(game));
			}

			printf("\nInformación: \n");
			if(command_get_cmd(mycmd) == INSPECT && command_get_arg(mycmd) == SPACE){
				printf("   Espacio: %s\n", space_get_large_description(space_act));
			}else{
				printf("   Espacio: %s\n", space_get_description(space_act));
			}

			if(strcmp(game_get_info(game), "\0")){
				printf("   Pistas: %s\n", game_get_info(game));
				game_set_info(game, "\0");
			}

			if(command_get_cmd(mycmd) == INSPECT && command_get_arg(mycmd) == OBJECT){
				printf("   Objeto: %s\n", game_get_large_description(game));
			}

			printf("\nPersonajes en este espacio:\n");
			for(i=0; i<MAX_CHARACTERS; i++){
				if(character_get_location(game_get_character(game, i)) == space_get_id(space_act)){
					printf("   - %s \n", game_get_character_name_by_id(game, i));
				}
			}


			printf("\nObjetos disponibles:\n");

			for(i=0; i<MAX_OBJECTS; i++){
				if(game_get_object_location(game, i) == space_get_id(space_act) && object_get_visible(game_get_object(game, i)) == TRUE){
					printf("   - %s ", game_get_object_name_by_id(game, i));
					if(object_get_movable(game_get_object(game, i)) == TRUE){
						printf("(movible)");
						if(object_get_n_objects(game_get_object(game, i)) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, i)));
						}
						else{
							printf("\n");
						}
					}
					else{
						printf("\n");
					}
				}
			}
		}
		else{
			for(i=0; i < MAX_ROWS; i++){
				printf("<////////////////////////////////////     ");
				if(i == 0)
					printf("\n");
				else if(i == 1)
					printf("Estás en: %s\n", space_get_name(space_act));
				else if(i == 2)
					printf("\n");
				else if(i == 3)
					printf("Tu inventario:\n");
				else if(i == 4){
					if(id_inv[0] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[0]));
						if(object_get_n_objects(game_get_object(game, id_inv[0])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[0])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 5){
					if(id_inv[1] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[1]));
						if(object_get_n_objects(game_get_object(game, id_inv[1])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[1])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 6){
					if(id_inv[2] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[2]));
						if(object_get_n_objects(game_get_object(game, id_inv[2])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[2])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 7){
					if(id_inv[3] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[3]));
						if(object_get_n_objects(game_get_object(game, id_inv[3])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[3])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 8){
					if(id_inv[4] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[4]));
						if(object_get_n_objects(game_get_object(game, id_inv[4])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[4])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 9){
					if(id_inv[5] != NO_ID){
						printf("    - %s", game_print_inventory_object(game, id_inv[5]));
						if(object_get_n_objects(game_get_object(game, id_inv[5])) > 0){
							printf(" %d\n", object_get_n_objects(game_get_object(game, id_inv[5])));
						}
						else{
							printf("\n");
						}
					}else{
						printf("\n");
					}
				}
				else if(i == 10){
					printf("Nivel de embriguez: %d%%\n", ((game_get_drunkenness(game)*100)/4));
				}
				else if(i > 10 && i < 12){
					printf("\n");
				}

			}

			printf("\n\nParece que esta apagada la luz... Necesitare algo con lo que iluminar.\n");
		}

		printf("\nComandos: ");
		printf("\navanzar + norte ó sur ó este u oeste o arriba o abajo;");
		printf("\ncoger + <nombre_objeto>; dejar + <nombre_objeto>; hablar + <nombre_personaje>");
		printf("\nturnon + <nombre_objeto>; turnoff + <nombre_objeto>; beber + <nombre_objeto>");
		printf("\ninspeccionar + espacio ó <nombre_objeto>; abrir <link> con <nombre_objeto>");
		printf("\nguardar + <nombre_partida>");
	  	printf("\n\n> ");
  	}

  	return OK;
}

STATUS graphic_engine_introduction(){
	
	printf("\n\n                 Habéis salido de fiesta para celebrar que habéis\n");
	printf("                      sacado un 10 en Proyecto de programación"".\n");
	printf("          La fiesta se os va un poco de las manos y acabais descontrolando...\n");

	printf("\n                         Pulsa intro para continuar\n");
	
	fflush(stdin);
	getchar(); 

	return OK;
}


STATUS graphic_engine_message(){
	printf("                ____________________________________________________ \n");
	printf("               |                                                    | \n");
	printf("               |  Oskar.KS:                                         | \n");
	printf("               |         Tú , tío, estoy con unas orcos que me      |\n");
	printf("               |         han invitado a su reservado , pero no      | \n");
	printf("               |         pasa nada, soy un warrior jajaja. Por      | \n");
	printf("               |         cierto, me encuentro bastante mareado.     | \n");
	printf("               |         Creo que me han echado algo en la bebida.  | \n");
	printf("               |         Si no te pongo ningún mensaje después      | \n");
	printf("               |         de este es que me ha pasado algo...        | \n");
	printf("               |                                                    | \n");
	printf("               |____________________________________________________| \n\n");

	printf("Parece que le ha pasado algo a Oscar.ks... deben de haberlo secuestrado ¡tienes que rescatarlo!\n");

	printf("\nAvanza hacia cualquier dirección para desplazarte a Rococo: ");

  	return OK;
}
