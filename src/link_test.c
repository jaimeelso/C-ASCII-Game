/**
* @brief Modulo link test
*
* Es el modulo que prueba el modulo link para confirmar su correcto funcionamiento
* 
* @file link_test.c
* @author SungPil Choi
* @version 15-03-2016 versión inicial 1.0	
* @date 15-03-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "../include/link_test.h"


/** 
 * @brief Funcion principal de pruebas para el modulo Link. 
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
        printf("Running all test for module Link:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_link_create();
    if (todas || test == 2) test1_link_destroy();
    if (todas || test == 3) test2_link_destroy();
    if (todas || test == 4) test1_link_set_name();
    if (todas || test == 5) test2_link_set_name();
    if (todas || test == 6) test3_link_set_name();
    if (todas || test == 7) test1_link_set_linkA();
    if (todas || test == 8) test2_link_set_linkA();
    if (todas || test == 9) test3_link_set_linkA();
    if (todas || test == 10) test1_link_set_linkB();
    if (todas || test == 11) test2_link_set_linkB();
    if (todas || test == 12) test3_link_set_linkB();
    if (todas || test == 13) test1_link_set_access();
    if (todas || test == 14) test2_link_set_access();
    if (todas || test == 15) test3_link_set_access();
	if (todas || test == 16) test1_link_get_id();
	if (todas || test == 17) test2_link_get_id();
	if (todas || test == 18) test1_link_get_name();
	if (todas || test == 19) test2_link_get_name();
	if (todas || test == 20) test1_link_get_linkA();
	if (todas || test == 21) test2_link_get_linkA();
	if (todas || test == 22) test1_link_get_linkB();
	if (todas || test == 23) test2_link_get_linkB();
	if (todas || test == 24) test1_link_get_access();
	if (todas || test == 25) test2_link_get_access();
	if (todas || test == 26) test1_link_print();
	if (todas || test == 27) test2_link_print();
	
    PRINT_PASSED_PERCENTAGE;

    return 0;
}

void test1_link_create() {
    Link* link = NULL;
    int result;

    link = link_create(1);
    
    result = (link != NULL);

    PRINT_TEST_RESULT(result);

    link_destroy(link);
}

void test1_link_destroy() {
    Link* link = NULL;
    int result;

    link = link_create(1);

    result = link_destroy(link);

    PRINT_TEST_RESULT(result == OK);
}

void test2_link_destroy() {
    Link* link = NULL;
    int result;

    result = link_destroy(link);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_link_set_name() {
    Link* link = NULL;

    link = link_create(1);

    PRINT_TEST_RESULT(link_set_name(link, "name") == OK);

    link_destroy(link);
}

void test2_link_set_name() {
    Link* link = NULL;

    PRINT_TEST_RESULT(link_set_name(link, "name") == ERROR);
}

void test3_link_set_name() {
    Link* link = NULL;

    link = link_create(1);
    PRINT_TEST_RESULT(link_set_name(link, NULL) == ERROR);
    link_destroy(link);
}

void test1_link_set_linkA() {
    Link* link = NULL;

    link = link_create(1);
    PRINT_TEST_RESULT(link_set_linkA(link, 2) == OK);
    link_destroy(link);
}

void test2_link_set_linkA() {
    Link* link = NULL;

    link = link_create(1);
    PRINT_TEST_RESULT(link_set_linkA(link, NO_ID) == ERROR);
    link_destroy(link);
}

void test3_link_set_linkA() {
    Link* link = NULL;

    PRINT_TEST_RESULT(link_set_linkA(link, 1) == ERROR);
}

void test1_link_set_linkB() {
    Link* link = NULL;

    link = link_create(1);
    PRINT_TEST_RESULT(link_set_linkB(link, 2) == OK);
    link_destroy(link);
}

void test2_link_set_linkB() {
    Link* link = NULL;

    link = link_create(1);
    PRINT_TEST_RESULT(link_set_linkB(link, NO_ID) == ERROR);
    link_destroy(link);
}

void test3_link_set_linkB() {
    Link* link = NULL;

    PRINT_TEST_RESULT(link_set_linkB(link, 1) == ERROR);
}

void test1_link_set_access() {
    Link* link = NULL;

    link = link_create(1);
    PRINT_TEST_RESULT(link_set_access(link, 0) == OK);
    link_destroy(link);
}

void test2_link_set_access() {
    Link* link = NULL;

    link = link_create(1);
    PRINT_TEST_RESULT(link_set_access(link, 1) == OK);
    link_destroy(link);
}

void test3_link_set_access() {
    Link* link = NULL;

    PRINT_TEST_RESULT(link_set_access(link, 0) == ERROR);
}

void test1_link_get_id() {
    Link* link = NULL;

    link = link_create(1);

    PRINT_TEST_RESULT(link_get_id(link) == 1);

    link_destroy(link);
}

void test2_link_get_id() {
    Link* link = NULL;

    PRINT_TEST_RESULT(link_get_id(link) == NO_ID);
}

void test1_link_get_name() {
    Link* link = NULL;
    link = link_create(1);
    link_set_name(link, "adios");
    PRINT_TEST_RESULT(strcmp(link_get_name(link), "adios") == 0);
    link_destroy(link);
}

void test2_link_get_name() {
    Link* link = NULL;
    PRINT_TEST_RESULT(link_get_name(link) == NULL);
}

void test1_link_get_linkA() {
    Link* link = NULL;

    link = link_create(1);
	link_set_linkA(link, 1);
    PRINT_TEST_RESULT(link_get_linkA(link) == 1);
    link_destroy(link);
}

void test2_link_get_linkA() {
    Link* link = NULL;
	
    PRINT_TEST_RESULT(link_get_linkA(link) == NO_ID);
}

void test1_link_get_linkB() {
    Link* link = NULL;

    link = link_create(2);
	link_set_linkB(link, 2);
    PRINT_TEST_RESULT(link_get_linkB(link) == 2);
    link_destroy(link);
}

void test2_link_get_linkB() {
    Link* link = NULL;
	
    PRINT_TEST_RESULT(link_get_linkB(link) == NO_ID);
}

void test1_link_get_access() {
    Link* link = NULL;

    link = link_create(1);
    PRINT_TEST_RESULT(link_get_access(link) == 0);
    link_destroy(link);
}

void test2_link_get_access() {
    Link* link = NULL;
	
    PRINT_TEST_RESULT(link_get_access(link) == -1);
}

void test1_link_print() {
    Link* link = NULL;

    PRINT_TEST_RESULT(link_print(link) == ERROR);
}

void test2_link_print() {
    Link* link = NULL;

    link = link_create(1);
	link_set_name(link, "hola");
	link_set_linkA(link, 1);
	link_set_linkB(link, 2);

    PRINT_TEST_RESULT(link_print(link) == OK);

    link_destroy(link);
}
