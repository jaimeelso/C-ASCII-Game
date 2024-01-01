/**
* @brief Modulo dialogue test
*
* Es el modulo que prueba el modulo dialogue para confirmar su correcto funcionamiento
* 
* @file dialogue_test.c
* @author SungPil Choi
* @version 14-03-2016 versión inicial 1.0	
* @date 18-04-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "../include/dialogue_test.h"

/** 
 * @brief Funcion principal de pruebas para el modulo Dialogue. 
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
        printf("Running all test for module Dialogue:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_dialogue_create();
	if (todas || test == 2) test1_dialogue_destroy();
	if (todas || test == 3) test2_dialogue_destroy();
    if (todas || test == 4) test1_dialogue_get_conv();
    if (todas || test == 5) test2_dialogue_get_conv();
    if (todas || test == 6) test1_dialogue_set_conv();
    if (todas || test == 7) test2_dialogue_set_conv();
	if (todas || test == 8) test1_dialogue_reset();
    if (todas || test == 9) test2_dialogue_reset();
    if (todas || test == 10) test1_dialogue_status();
    if (todas || test == 11) test2_dialogue_status();

    PRINT_PASSED_PERCENTAGE;

    return 0;
}

void test1_dialogue_create() {
    Dialogue* dialogue = NULL;
    int result;

    dialogue = dialogue_create();

    result = (dialogue != NULL);

	PRINT_TEST_RESULT(result);

    dialogue_destroy(dialogue);
}

void test1_dialogue_destroy() {
    Dialogue* dialogue = NULL;
    STATUS result;

    dialogue = dialogue_create(1);

    result = dialogue_destroy(dialogue);

    PRINT_TEST_RESULT(result == OK);
}

void test2_dialogue_destroy() {
    Dialogue* dialogue = NULL;

    PRINT_TEST_RESULT(dialogue_destroy(dialogue) == ERROR);
}

void test1_dialogue_get_conv() {
    Dialogue* dialogue = NULL;

    dialogue = dialogue_create();

    PRINT_TEST_RESULT(dialogue_get_conv(dialogue, 0) != NULL);

    dialogue_destroy(dialogue);
}

void test2_dialogue_get_conv() {
    Dialogue* dialogue = NULL;

    PRINT_TEST_RESULT(dialogue_get_conv(dialogue, 1) == NULL);
}

void test1_dialogue_set_conv() {
    Dialogue* dialogue = NULL;

    dialogue = dialogue_create();

    PRINT_TEST_RESULT(dialogue_set_conv(dialogue, 1, "Hola") == OK);

    dialogue_destroy(dialogue);
}

void test2_dialogue_set_conv() {
    Dialogue* dialogue = NULL;

    PRINT_TEST_RESULT(dialogue_set_conv(dialogue, 1, "Hola") == ERROR);
}

void test1_dialogue_reset() {
    Dialogue* dialogue = NULL;

    dialogue = dialogue_create();

    dialogue_set_conv(dialogue, 1, "Hola");

    PRINT_TEST_RESULT(dialogue_reset(dialogue) == OK);
    
    dialogue_destroy(dialogue);
}

void test2_dialogue_reset() {
    Dialogue* dialogue = NULL;

    PRINT_TEST_RESULT(dialogue_reset(dialogue) == ERROR);
}

void test1_dialogue_status() {
    Dialogue* dialogue = NULL;

    dialogue = dialogue_create();

    PRINT_TEST_RESULT(dialogue_status(dialogue) == TRUE);

    dialogue_destroy(dialogue);
}

void test2_dialogue_status() {
    Dialogue* dialogue = NULL;

    PRINT_TEST_RESULT(dialogue_status(dialogue) == FALSE);
}
