/**
* @brief Modulo inventory test
*
* Es el modulo que prueba el modulo inventory para confirmar su correcto funcionamiento
* 
* @file inventory_test.c
* @author SungPil Choi
* @version 14-03-2016 versión inicial 1.0	
* @date 14-03-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "inventory_test.h"

/** 
 * @brief Funcion principal de pruebas para el modulo Inventory. 
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
        printf("Running all test for module Inventory:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_inventory_create();
	if (todas || test == 2) test2_inventory_create();
	if (todas || test == 3) test3_inventory_create();
    if (todas || test == 4) test1_inventory_destroy();
    if (todas || test == 5) test2_inventory_destroy();
    if (todas || test == 6) test1_inventory_set_object();
    if (todas || test == 7) test2_inventory_set_object();
	if (todas || test == 8) test3_inventory_set_object();
    if (todas || test == 9) test1_inventory_get_object();
    if (todas || test == 10) test2_inventory_get_object();
    if (todas || test == 11) test1_inventory_get_id_max();
    if (todas || test == 12) test2_inventory_get_id_max();
	if (todas || test == 13) test1_inventory_print();
	if (todas || test == 14) test2_inventory_print();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_inventory_create() {
    Inventory* inventory = NULL;

    inventory = inventory_create();

    int result = inventory != NULL;

	PRINT_TEST_RESULT(result);

    inventory_destroy(inventory);
}

void test2_inventory_create() {
	Inventory* inventory = NULL;

	inventory = inventory_create();

	PRINT_TEST_RESULT(inventory_get_id_max(inventory) == MAX_PLAYER_OBJECTS);

    inventory_destroy(inventory);
}

void test3_inventory_create() {
	Inventory* inventory = NULL;

	inventory = inventory_create();

	PRINT_TEST_RESULT(inventory_get_object(inventory) != NULL);

    inventory_destroy(inventory);
}

void test1_inventory_destroy() {
    Inventory* inventory = NULL;
    STATUS result;

    inventory = inventory_create();

    result = inventory_destroy(inventory);

    PRINT_TEST_RESULT(result == OK);
}

void test2_inventory_destroy() {
    Inventory* inventory = NULL;

    PRINT_TEST_RESULT(inventory_destroy(inventory) == ERROR);
}

void test1_inventory_set_object() {
    Inventory* inventory = NULL;

    inventory = inventory_create();

    PRINT_TEST_RESULT(inventory_set_object(inventory, 1) == OK);

    inventory_destroy(inventory);
}

void test2_inventory_set_object() {
    Inventory* inventory = NULL;

    PRINT_TEST_RESULT(inventory_set_object(inventory, 1) == ERROR);
}

void test3_inventory_set_object() {
    Inventory* inventory = NULL;

	inventory = inventory_create();

	while (set_get_numId(inventory_get_object(inventory)) <= inventory_get_id_max(inventory)) {
		inventory_set_object(inventory, 1);
	}

    PRINT_TEST_RESULT(inventory_set_object(inventory, 5) == ERROR);

    inventory_destroy(inventory);
}

void test1_inventory_get_object() {
    Inventory* inventory = NULL;

    inventory = inventory_create();

    PRINT_TEST_RESULT(inventory_get_object(inventory) != NULL);
    
    inventory_destroy(inventory);
}

void test2_inventory_get_object() {
    Inventory* inventory = NULL;

    PRINT_TEST_RESULT(inventory_get_object(inventory) == NULL);
}

void test1_inventory_get_id_max() {
    Inventory* inventory = NULL;

    inventory = inventory_create();

    PRINT_TEST_RESULT(inventory_get_id_max(inventory) == MAX_PLAYER_OBJECTS);

    inventory_destroy(inventory);
}

void test2_inventory_get_id_max() {
    Inventory* inventory = NULL;

    PRINT_TEST_RESULT(inventory_get_id_max(inventory) == -1);
}

void test1_inventory_print() {
    Inventory* inventory = NULL;

    PRINT_TEST_RESULT(inventory_print(inventory) == ERROR);
}

void test2_inventory_print() {
    Inventory* inventory = NULL;

	inventory = inventory_create();

	inventory_set_object(inventory, 1);

    PRINT_TEST_RESULT(inventory_print(inventory) == OK);

    inventory_destroy(inventory);
}