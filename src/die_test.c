/**
* @brief Modulo die test
*
* Es el modulo que prueba el modulo die para confirmar su correcto funcionamiento
* 
* @file die_test.c
* @author SungPil Choi
* @version 14-03-2016 versión inicial 1.0	
* @date 18-04-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "../include/die_test.h"


/** 
 * @brief Funcion principal de pruebas para el modulo Die. 
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
        printf("Running all test for module Die:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_die_create();
	if (todas || test == 2) test2_die_create();
	if (todas || test == 3) test3_die_create();
    if (todas || test == 4) test1_die_destroy();
    if (todas || test == 5) test2_die_destroy();
    if (todas || test == 6) test1_die_roll();
    if (todas || test == 7) test2_die_roll();
	if (todas || test == 8) test1_die_get_num();
    if (todas || test == 9) test2_die_get_num();
    if (todas || test == 10) test3_die_get_num();
    if (todas || test == 11) test1_die_get_id();
    if (todas || test == 12) test2_die_get_id();
	if (todas || test == 13) test1_die_print();
	if (todas || test == 14) test2_die_print();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_die_create() {
    Die* die = NULL;

    die = die_create(1);

    int result = die != NULL;

	PRINT_TEST_RESULT(result);

    die_destroy(die);
}

void test2_die_create() {
	Die* die = NULL;

	die = die_create(2);

	PRINT_TEST_RESULT(die_get_id(die) == 2);

    die_destroy(die);
}

void test3_die_create() {
	Die* die = NULL;

	die = die_create(1);

	PRINT_TEST_RESULT(die_get_num(die) == 0);

    die_destroy(die);
}

void test1_die_destroy() {
    Die* die = NULL;
    STATUS result;

    die = die_create(1);

    result = die_destroy(die);

    PRINT_TEST_RESULT(result == OK);
}

void test2_die_destroy() {
    Die* die = NULL;

    PRINT_TEST_RESULT(die_destroy(die) == ERROR);
}

void test1_die_roll() {
    Die* die = NULL;

    die = die_create(1);

    die_roll(die);

    PRINT_TEST_RESULT(die_get_num(die) != 0);

    die_destroy(die);
}

void test2_die_roll() {
    Die* die = NULL;

    PRINT_TEST_RESULT(die_roll(die) == NULL);
}

void test1_die_get_num() {
    Die* die = NULL;

    die = die_create(1);

    PRINT_TEST_RESULT(die_get_num(die) == 0);
    
    die_destroy(die);
}

void test2_die_get_num() {
    Die* die = NULL;

    die = die_create(1);

    die_roll(die);

    PRINT_TEST_RESULT(die_get_num(die) > 0);
    
    die_destroy(die);
}

void test3_die_get_num() {
    Die* die = NULL;

    PRINT_TEST_RESULT(die_get_num(die) == -1);
}

void test1_die_get_id() {
    Die* die = NULL;

    die = die_create(1);

    PRINT_TEST_RESULT(die_get_id(die) == 1);

    die_destroy(die);
}

void test2_die_get_id() {
    Die* die = NULL;

    PRINT_TEST_RESULT(die_get_id(die) == NO_ID);
}

void test1_die_print() {
    Die* die = NULL;

    PRINT_TEST_RESULT(die_print(die) == ERROR);
}

void test2_die_print() {
    Die* die = NULL;

	die = die_create(1);

    PRINT_TEST_RESULT(die_print(die) == OK);

    die_destroy(die);
}
