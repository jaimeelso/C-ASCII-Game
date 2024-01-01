/**
* @brief Modulo player test
*
* Es el modulo que prueba el modulo player para confirmar su correcto funcionamiento
* 
* @file player_test.c
* @author SungPil Choi
* @version 22-03-2016 versión inicial 1.0	
* @date 22-03-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#include "../include/player.h"
#include "../include/player_test.h"
#include "../include/test.h"

/** 
 * @brief Funcion principal de pruebas para el modulo player. 
 * 
 * Dos modos de ejecucion:
 *   1.-Si se ejecuta sin parametros se ejecutan todas las pruebas 
 *   2.-Si se ejecuta con un numero entre 1 y el numero de pruebas solo ejecuta 
 *      la prueba indicada  
 *  
 */
int main(int argc, char** argv) {

    int test = 0;
    int todas = 1;

    if (argc < 2) {
        printf("Running all test for module Player:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_player_create();
    if (todas || test == 2) test2_player_create();
    if (todas || test == 3) test1_player_destroy();
    if (todas || test == 4) test2_player_destroy();
    if (todas || test == 5) test1_player_get_name();
    if (todas || test == 6) test2_player_get_name();
    if (todas || test == 7) test1_player_set_name();
	if (todas || test == 8) test2_player_set_name();
    if (todas || test == 9) test3_player_set_name();
    if (todas || test == 10) test1_player_get_id();
	if (todas || test == 11) test2_player_get_id();
    if (todas || test == 12) test1_player_set_id();
    if (todas || test == 13) test2_player_set_id();
	if (todas || test == 14) test1_player_get_inventory();
    if (todas || test == 15) test2_player_get_inventory();
    if (todas || test == 16) test1_player_set_inventory();
	if (todas || test == 17) test2_player_set_inventory();
	if (todas || test == 18) test1_player_check_object();
	if (todas || test == 19) test2_player_check_object();
	if (todas || test == 20) test3_player_check_object();
    if (todas || test == 21) test1_player_get_location();
    if (todas || test == 22) test2_player_get_location();
    if (todas || test == 23) test1_player_set_location();
    if (todas || test == 24) test2_player_set_location();
    if (todas || test == 25) test1_player_print();
    if (todas || test == 26) test2_player_print();

    PRINT_PASSED_PERCENTAGE;

    return 0;
}

void test1_player_create() {
	Player* player = NULL;
	int result;

	player = player_create(5);
	result = (player != NULL);

	PRINT_TEST_RESULT(result);

	player_destroy(player);
}

void test2_player_create() {
    Player* player = NULL;

    player = player_create(4);

    PRINT_TEST_RESULT(player_get_id(player) == 4);

	player_destroy(player);
}

void test1_player_destroy() {
    Player* player = NULL;
    STATUS result;

    player = player_create(1);

    result = player_destroy(player);

    PRINT_TEST_RESULT(result == OK);
}

void test2_player_destroy() {
    Player*  player = NULL;
    STATUS result;

    result = player_destroy(player);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_player_get_name() {
    Player* player = NULL;

    player = player_create(1);

    player_set_name(player, "adios");

    PRINT_TEST_RESULT(strcmp(player_get_name(player), "adios") == 0);

	player_destroy(player);
}

void test2_player_get_name() {
    Player* player = NULL;

    PRINT_TEST_RESULT(player_get_name(player) == NULL);
}

void test1_player_set_name() {
    Player* player = NULL;  
    STATUS result;

    player = player_create(5);
    result = player_set_name(player, "hola");

    PRINT_TEST_RESULT(result == OK);

	player_destroy(player);
}

void test2_player_set_name() {
    Player* player = NULL;
    STATUS result;

    result = player_set_name(player, "hola");

    PRINT_TEST_RESULT(result == ERROR);
}

void test3_player_set_name() {
    Player* player = NULL;
    STATUS result;

    player = player_create(5);
    result = player_set_name(player, NULL);

    PRINT_TEST_RESULT(result == ERROR);

	player_destroy(player);
}

void test1_player_get_id() {
    Player* player = NULL;

    player = player_create(25);

    PRINT_TEST_RESULT(player_get_id(player) == 25);
	player_destroy(player);
}

void test2_player_get_id() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_id(player) == NO_ID);
}

void test1_player_set_id() {
    Player *player = NULL;
    player = player_create(25);
    PRINT_TEST_RESULT(player_set_id(player, 1) == 1);
	player_destroy(player);
}

void test2_player_set_id() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_id(player, 2) == ERROR);
}

void test1_player_get_inventory() {
    Player *player = NULL;
    player = player_create(1);
    player_set_inventory(player,1);
    PRINT_TEST_RESULT(player_get_inventory(player) != NULL);
	player_destroy(player);
}

void test2_player_get_inventory() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_inventory(player) == NULL);
}

void test1_player_set_inventory() {
    Player *player = NULL;
    player = player_create(1);
    PRINT_TEST_RESULT(player_set_inventory(player, 2) == OK);
	player_destroy(player);
}

void test2_player_set_inventory() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_inventory(player, 1) == ERROR);
}

void test1_player_check_object() {
    Player *player = NULL;
    player = player_create(1);
	player_set_inventory(player, 2);
    PRINT_TEST_RESULT(player_check_object(player, 2) == TRUE);
	player_destroy(player);
}

void test2_player_check_object() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_check_object(player, 2) == FALSE);
}

void test3_player_check_object() {
    Player *player = NULL;
    player = player_create(1);
	player_set_inventory(player, 2);
    PRINT_TEST_RESULT(player_check_object(player, NO_ID) == FALSE);
	player_destroy(player);
}

void test1_player_get_location() {
    Player *player = NULL;
    player = player_create(1);
	player_set_location(player, 1);
    PRINT_TEST_RESULT(player_get_location(player) == 1);
	player_destroy(player);
}

void test2_player_get_location() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_location(player) == NO_ID);
}

void test1_player_set_location() {
    Player *player = NULL;
    player = player_create(1);
    PRINT_TEST_RESULT(player_set_location(player, 1) == OK);
	player_destroy(player);
}

void test2_player_set_location() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_location(player, 1) == ERROR);
}

void test1_player_print() {
    Player *player = NULL;

    PRINT_TEST_RESULT(player_print(player) == ERROR);
}

void test2_player_print() {
    Player *player = NULL;

    player = player_create(1);
	player_set_id(player, 1);
	player_set_name(player, "hola");
	player_set_location(player, 2);
	player_set_inventory(player, 3);
	player_set_inventory(player, 4);

    PRINT_TEST_RESULT(player_print(player) == OK);

    player_destroy(player);
}
