/**
* @brief Modulo set test
*
* Es el modulo que prueba el modulo set para confirmar su correcto funcionamiento
* 
* @file set_test.c
* @author SungPil Choi
* @version 14-03-2016 versión inicial 1.0	
* @date 19-04-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "set_test.h"


/** 
 * @brief Funcion principal de pruebas para el modulo Set. 
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
        printf("Running all test for module Set:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_set_create();
	if (todas || test == 2) test2_set_create();
	if (todas || test == 3) test3_set_create();
    if (todas || test == 4) test1_set_destroy();
    if (todas || test == 5) test2_set_destroy();
    if (todas || test == 6) test1_set_add_id();
    if (todas || test == 7) test2_set_add_id();
    if (todas || test == 8) test3_set_add_id();
    if (todas || test == 9) test4_set_add_id();
    if (todas || test == 10) test1_set_del_id();
    if (todas || test == 11) test2_set_del_id();
    if (todas || test == 12) test3_set_del_id();
    if (todas || test == 13) test4_set_del_id();
    if (todas || test == 14) test5_set_del_id();
    if (todas || test == 15) test1_set_print();
    if (todas || test == 16) test2_set_print();
    if (todas || test == 17) test3_set_print();
    if (todas || test == 18) test1_set_check_id();
    if (todas || test == 19) test2_set_check_id();
    if (todas || test == 20) test3_set_check_id();
    if (todas || test == 21) test4_set_check_id();
    if (todas || test == 22) test5_set_check_id();
    if (todas || test == 23) test1_set_get_numId();
    if (todas || test == 24) test2_set_get_numId();
    if (todas || test == 25) test1_set_check_noId();
    if (todas || test == 26) test2_set_check_noId();
    if (todas || test == 27) test3_set_check_noId();
    if (todas || test == 28) test1_set_get_id();
    if (todas || test == 29) test2_set_get_id();
    if (todas || test == 30) test3_set_get_id();
    if (todas || test == 31) test4_set_get_id();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_set_create() {
    Set* set = NULL;

    set = set_create();

    int result = set != NULL;

	PRINT_TEST_RESULT(result);

    set_destroy(set);
}

void test2_set_create() {
	Set* set = NULL;

	set = set_create();

	PRINT_TEST_RESULT(set_get_id(set, 1) == NO_ID);

    set_destroy(set);
}

void test3_set_create() {
	Set* set = NULL;

	set = set_create();

	PRINT_TEST_RESULT(set_get_numId(set) == 0);

    set_destroy(set);
}

void test1_set_destroy() {
    Set* set = NULL;
    STATUS result;

    set = set_create();

    result = set_destroy(set);

    PRINT_TEST_RESULT(result == OK);
}

void test2_set_destroy() {
    Set* set = NULL;

    PRINT_TEST_RESULT(set_destroy(set) == ERROR);
}

void test1_set_add_id() {
    Set* set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_add_id(set, 1) == OK);

    set_destroy(set);
}

void test2_set_add_id() {
    Set* set = NULL;

    PRINT_TEST_RESULT(set_add_id(set, 1) == ERROR);
}

void test3_set_add_id() {
    Set* set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_add_id(set, NO_ID) == ERROR);

    set_destroy(set);
}

void test4_set_add_id() {
    Set* set = NULL;

    int i;

    set = set_create();

    for (i=0; i<MAX_SET; i++){
    	set_add_id(set, 1);
    }

    PRINT_TEST_RESULT(set_add_id(set, 100) == ERROR);

    set_destroy(set);
}

void test1_set_del_id() {
    Set* set = NULL;

    set = set_create();

    set_add_id(set, 1);

    PRINT_TEST_RESULT(set_del_id(set, 1) == OK);
    
    set_destroy(set);
}

void test2_set_del_id() {
    Set* set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_del_id(set, 1) == ERROR);
    
    set_destroy(set);
}

void test3_set_del_id() {
    Set* set = NULL;

    PRINT_TEST_RESULT(set_del_id(set, 1) == ERROR);
}

void test4_set_del_id() {
    Set* set = NULL;

    set = set_create();

    set_add_id(set, 1);

    PRINT_TEST_RESULT(set_del_id(set, 2) == ERROR);
    
    set_destroy(set);
}

void test5_set_del_id() {
    Set* set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_del_id(set, NO_ID) == ERROR);
    
    set_destroy(set);
}

void test1_set_print() {
    Set* set = NULL;

    PRINT_TEST_RESULT(set_print(set) == ERROR);
}

void test2_set_print() {
    Set* set = NULL;

    int i;
    
	set = set_create();

	for (i=0; i<4; i++){
    	set_add_id(set, i);
    }

    PRINT_TEST_RESULT(set_print(set) == OK);

    set_destroy(set);
}

void test3_set_print() {
    Set* set = NULL;

	set = set_create();

    PRINT_TEST_RESULT(set_print(set) == OK);

    set_destroy(set);
}

void test1_set_check_id() {
    Set* set = NULL;

    set = set_create();

    set_add_id(set, 1);

    PRINT_TEST_RESULT(set_check_id(set, 1) == TRUE);

    set_destroy(set);
}

void test2_set_check_id() {
    Set* set = NULL;

    PRINT_TEST_RESULT(set_check_id(set, 1) == FALSE);
}

void test3_set_check_id() {
    Set* set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_check_id(set, NO_ID) == FALSE);

    set_destroy(set);
}

void test4_set_check_id() {
    Set* set = NULL;

    set = set_create();

    set_add_id(set, 1);

    PRINT_TEST_RESULT(set_check_id(set, 2) == FALSE);

    set_destroy(set);
}

void test5_set_check_id() {
    Set* set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_check_id(set, 1) == FALSE);

    set_destroy(set);
}

void test1_set_get_numId() {
    Set* set = NULL;

    set = set_create();

    set_add_id(set, 1);

    PRINT_TEST_RESULT(set_get_numId(set) == 1);

    set_destroy(set);
}

void test2_set_get_numId() {
    Set* set = NULL;

    PRINT_TEST_RESULT(set_get_numId(set) == -1);
}

void test1_set_check_noId() {
    Set* set = NULL;

    set = set_create();

    set_add_id(set, 1);

    PRINT_TEST_RESULT(set_check_noId(set) == FALSE);

    set_destroy(set);
}

void test2_set_check_noId() {
    Set* set = NULL;

    PRINT_TEST_RESULT(set_check_noId(set) == FALSE);
}

void test3_set_check_noId() {
    Set* set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_check_noId(set) == TRUE);

    set_destroy(set);
}

void test1_set_get_id() {
    Set* set = NULL;

    set = set_create();

    set_add_id(set, 1);

    PRINT_TEST_RESULT(set_get_id(set, 1) == 1);

    set_destroy(set);
}

void test2_set_get_id() {
    Set* set = NULL;

    set = set_create();

    set_add_id(set, 1);

    PRINT_TEST_RESULT(set_get_id(set, 2) == NO_ID);

    set_destroy(set);
}

void test3_set_get_id() {
    Set* set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_get_id(set, 1) == NO_ID);

    set_destroy(set);
}

void test4_set_get_id() {
    Set* set = NULL;

    PRINT_TEST_RESULT(set_get_id(set, 1) == NO_ID);
}