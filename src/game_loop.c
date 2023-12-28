/**
* @file game_loop.c
* @mainpage Proyecto de Programación | Iteración 3
* @brief
*
* Módulo Game Loop. 
*
* Contiene la función main del juego con el bucle desde el que se hacen 
* las llamadas al resto de las funciones del programa.
* @date 
* 3/04/2016
* @authors 
*
* Jaime Elso de Blas
*
* Sergio García Bordonado
*
* Alfredo de Frutos Estebaranz
*
* Sung Pil Choi
* @version 
*
* 02/02/2016 version 1.0 (version inicial)
* 	
* 05/03/2016 version 2.0: se crea una nueva estructura de comando
* que se utiliza para pasarselo a las funciones que lo requieran y una
* vez acabado el juego destruye la memoria para esa estructura, tambien
* hemos implementado el log para registrar los comandos
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/game.h"
#include "../include/game_managment.h"
#include "../include/graphic_engine.h"

#ifdef __WINDOWS_BUILD__
#define CLEAR "cls" 	/*!< Clear de la consola */
#else
#define CLEAR "clear"	/*!< Clear de la consola */
#endif

/**
 * @date 18-04-2016
 * @authors 
 *
 * Jaime Elso de Blas
 *
 * Alfredo de Frutos Estebaranz
 * @brief Implementa todo el desarrollo del juego
 * @param argc: número de argumentos
 * @param argv: array del nombre de los argumentos
 * @return int: devuelve números dependiendo del desarrollo del juego
 */
int main(int argc, char *argv[]){
	Game* game = NULL;	/*Declaramos una variable de tipo estructura Game*/
	MyCmd* command = NULL;	/*Variable para guardar el comando*/
	STATUS status = ERROR;	/*Variable que guarda el estado "OK o ERROR" del return*/
	FILE* file = NULL; 	/*Variable para llamar al fichero*/
	BOOL logg = FALSE;	/*Variable de habilitación del registro*/
	BOOL nv = FALSE;	/*Variable que habilita que se muestren por pantalla datos del programa*/
	int option = 0;
	char folder[WORD_SIZE] = "\0";
	char prueba;
	BOOL game_over = FALSE;
	
	/*Comprueba que se le pasen dos argumentos al ejecutar el programa
	en caso contrario muestra mensaje de error*/
	if (argc < 6){
		fprintf(stderr, "Use: %s <spaces_data_file> <objects_data_file> <links_data_file> <characters_data_file> <players_data_file>\n", argv[0]); 
		return 1;
	}

	if((argv[6] != NULL && !strcmp(argv[6], "-l") &&  argv[7] != NULL)){
		logg = TRUE;
		if(!strcmp(argv[7], "-l")){
			file = fopen(argv[8], "w");
		}else{
			file = fopen(argv[7], "w");
		}
		
		if(!file){
			return 1;
		}
	}

	if((argv[8] != NULL && !strcmp(argv[8], "-nv"))){
		nv = TRUE;
	}


  	while(option < 1 || option >3){
  		if(nv == FALSE){

	  		if (system(CLEAR)){
	  			return 1; 
	  		}

			printf("    __  ____                         __        ____                             \n");
			printf("   /  |/  (_)___  ____ ______   ____/ /__     / __ \\____  _________  _________  \n");
			printf("  / /|_/ / / __ \\/ __ `/ ___/  / __  / _ \\   / /_/ / __ \\/ ___/ __ \\/ ___/ __ \\ \n");
			printf(" / /  / / / / / / /_/ (__  )  / /_/ /  __/  / _, _/ /_/ / /__/ /_/ / /__/ /_/ / \n");
			printf("/_/  /_/_/_/ /_/\\__,_/____/   \\__,_/\\___/  /_/ |_|\\____/\\___/\\____/\\___/\\____/ \n\n\n");

			printf("                             __  ___ ____ _  __ __  __ \n");
			printf("                            /  |/  // __// |/ // / / / \n");
			printf("                           / /|_/ // _/ /    // /_/ /  \n");
			printf("                          /_/  /_//___//_/|_/ \\____/   \n\n\n");

			printf("                                1 - JUGAR\n");
			printf("                                2 - CARGAR PARTIDA\n");
			printf("                                3 - SALIR\n\n");
			printf("                                > ");
		}

		scanf("%d", &option);
		scanf("%c", &prueba);
	}

	switch(option){

		case 1:
			game = game_init();
			/*Carga el tablero y comprueba que no halla ningún error*/
			if (game_init_from_file(game, argv[1], argv[2], argv[3], argv[4], argv[5]) == ERROR){
				fprintf(stderr, "Error while initializing game.\n"); 
				return 1;
			}
			if (system(CLEAR)){
  				return 1; 
  			}
			if(nv == FALSE){
				graphic_engine_introduction();
			}
			break;

		case 2:
			game = game_init();
			printf("\nIntroduce la carpeta de donde guardaste partida\n");
			printf("> ");
			scanf("%s", folder);
			if(game_managment_load(game, folder) == ERROR){
				printf("Error al cargar la partida.\n");
				return 0;
			}
			break;
		case 3:
			return 0;
			break;

	}

	

	command = command_create();

	/*Bucle que ejecuta el juego hasta que el usuario decide salir o hasta
	el game over*/
	while ( ((command_get_cmd(command)) != QUIT) && game_over != TRUE ){
		if (nv == FALSE){
			graphic_engine_print_screen(game, command);
		}
		
		game_over = game_is_over(game);
		command = get_user_input(command);
		status = game_update(game, command);

		if(logg == TRUE){
			game_log(file, status, command);
		}
	} 
	
	if(logg == TRUE){
		fclose(file);
	}
	
	command_destroy(command);
	game_destroy(game);

	return 0;
}