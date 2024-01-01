/**
* @brief Modulo space test
*
* Es el modulo que prueba el modulo space para confirmar su correcto funcionamiento
* 
* @file space_test.c
* @author SungPil Choi
* @version 20-03-2016 versión inicial 1.0	
* @date 20-03-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "../include/space_test.h"


/** 
 * @brief Funcion principal de pruebas para el modulo Space. 
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
        printf("Running all test for module Space:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }
	
    if (todas || test == 1) test1_space_create();
    if (todas || test == 2) test2_space_create();
    if (todas || test == 3) test1_space_set_name();
    if (todas || test == 4) test2_space_set_name();
    if (todas || test == 5) test3_space_set_name();
    if (todas || test == 6) test1_space_set_link_north();
    if (todas || test == 7) test2_space_set_link_north();
	if (todas || test == 8) test3_space_set_link_north();
    if (todas || test == 9) test1_space_set_link_south();
    if (todas || test == 10) test2_space_set_link_south();
	if (todas || test == 11) test3_space_set_link_south();
    if (todas || test == 12) test1_space_set_link_east();
    if (todas || test == 13) test2_space_set_link_east();
	if (todas || test == 14) test3_space_set_link_east();
    if (todas || test == 15) test1_space_set_link_west();
    if (todas || test == 16) test2_space_set_link_west();
	if (todas || test == 17) test3_space_set_link_west();
	if (todas || test == 18) test1_space_set_object();
	if (todas || test == 19) test2_space_set_object();
	if (todas || test == 20) test3_space_set_object();
    if (todas || test == 21) test1_space_get_name();
    if (todas || test == 22) test2_space_get_name();
    if (todas || test == 23) test1_space_get_object();
    if (todas || test == 24) test2_space_get_object();
    if (todas || test == 25) test1_space_get_link_north();
    if (todas || test == 26) test2_space_get_link_north();
    if (todas || test == 27) test1_space_get_link_south();
    if (todas || test == 28) test2_space_get_link_south();
    if (todas || test == 29) test1_space_get_link_east();
    if (todas || test == 30) test2_space_get_link_east();
    if (todas || test == 31) test1_space_get_link_west();
    if (todas || test == 32) test2_space_get_link_west();
    if (todas || test == 33) test1_space_get_id();
    if (todas || test == 34) test2_space_get_id();
	if (todas || test == 35) test1_space_destroy();
	if (todas || test == 36) test2_space_destroy();
	if (todas || test == 37) test1_space_set_gdesc();
	if (todas || test == 38) test2_space_set_gdesc();
	if (todas || test == 39) test3_space_set_gdesc();
	if (todas || test == 40) test1_space_get_gdesc();
	if (todas || test == 41) test2_space_get_gdesc();
	if (todas || test == 42) test1_space_print();
    if (todas || test == 43) test2_space_print();
	if (todas || test == 44) test1_space_set_description();
    if (todas || test == 45) test2_space_set_description();
    if (todas || test == 46) test3_space_set_description();
    if (todas || test == 47) test1_space_set_large_description();
    if (todas || test == 48) test2_space_set_large_description();
    if (todas || test == 49) test3_space_set_large_description();
    if (todas || test == 50) test1_space_set_illuminated();
    if (todas || test == 51) test2_space_set_illuminated();
    if (todas || test == 52) test3_space_set_illuminated();
    if (todas || test == 53) test1_space_set_link_up();
    if (todas || test == 54) test2_space_set_link_up();
    if (todas || test == 55) test3_space_set_link_up();
    if (todas || test == 56) test1_space_set_link_down();
    if (todas || test == 57) test2_space_set_link_down();
    if (todas || test == 58) test3_space_set_link_down();
    if (todas || test == 59) test1_space_get_description();
    if (todas || test == 60) test2_space_get_description();
    if (todas || test == 61) test1_space_get_large_description();
    if (todas || test == 62) test2_space_get_large_description();
    if (todas || test == 63) test1_space_get_illuminated();
    if (todas || test == 64) test2_space_get_illuminated();
    if (todas || test == 65) test1_space_get_link_up();
    if (todas || test == 66) test2_space_get_link_up();
    if (todas || test == 67) test1_space_get_link_down();
    if (todas || test == 68) test2_space_get_link_down();

    PRINT_PASSED_PERCENTAGE;

    return 0;
}

void test1_space_create() {
	Space* space = NULL;
	int result;
	space = space_create(5);
	result = space != NULL ;
	PRINT_TEST_RESULT(result);
	space_destroy(space);
}

void test2_space_create() {
    Space *space = NULL;
    space = space_create(4);
    PRINT_TEST_RESULT(space_get_id(space) == 4);
	space_destroy(space);
}

void test1_space_set_name() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_name(space, "hola") == OK);
	space_destroy(space);
}

void test2_space_set_name() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_name(space, "hola") == ERROR);
}

void test3_space_set_name() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_name(space, NULL) == ERROR);
	space_destroy(space);
}

void test1_space_set_link_north() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_north(space, 4) == OK);
	space_destroy(space);
}

void test2_space_set_link_north() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_link_north(space, 4) == ERROR);
}

void test3_space_set_link_north() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_north(space, NO_ID) == ERROR);
	space_destroy(space);
}

void test1_space_set_link_south() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_south(space, 4) == OK);
	space_destroy(space);
}

void test2_space_set_link_south() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_link_south(space, 4) == ERROR);
}

void test3_space_set_link_south() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_south(space, NO_ID) == ERROR);
	space_destroy(space);
}

void test1_space_set_link_east() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_east(space, 4) == OK);
	space_destroy(space);
}

void test2_space_set_link_east() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_link_east(space, 4) == ERROR);
}

void test3_space_set_link_east() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_east(space, NO_ID) == ERROR);
	space_destroy(space);
}

void test1_space_set_link_west() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_west(space, 4) == OK);
	space_destroy(space);
}

void test2_space_set_link_west() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_link_west(space, 4) == ERROR);
}

void test3_space_set_link_west() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_west(space, NO_ID) == ERROR);
	space_destroy(space);
}

void test1_space_set_object() {
    Space *space = NULL;
    space = space_create(1);
    PRINT_TEST_RESULT(space_set_object(space, 2) == OK);
	space_destroy(space);
}

void test2_space_set_object() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_object(space, 1) == ERROR);
}

void test3_space_set_object() {
    Space *space = NULL;
    space = space_create(1);
    PRINT_TEST_RESULT(space_set_object(space, NO_ID) == ERROR);
	space_destroy(space);
}

void test1_space_get_name() {
    Space *space = NULL;
    space = space_create(1);
    space_set_name(space, "adios");
    PRINT_TEST_RESULT(strcmp(space_get_name(space), "adios") == 0);
	space_destroy(space);
}

void test2_space_get_name() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_name(space) == NULL);
}

void test1_space_get_object() {
    Space *space = NULL;
    space = space_create(1);
    space_set_object(space,1);
    PRINT_TEST_RESULT(space_get_object(space) != NULL);
	space_destroy(space);
}

void test2_space_get_object() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_object(space) == NULL);
}

void test1_space_get_link_north() {
    Space *space = NULL;
    space = space_create(5);
    space_set_link_north(space, 4);
    PRINT_TEST_RESULT(space_get_link_north(space) == 4);
	space_destroy(space);
}

void test2_space_get_link_north() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_link_north(space) == NO_ID);
}

void test1_space_get_link_south() {
    Space *space = NULL;
    space = space_create(5);
    space_set_link_south(space, 2);
    PRINT_TEST_RESULT(space_get_link_south(space) == 2);
	space_destroy(space);
}

void test2_space_get_link_south() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_link_south(space) == NO_ID);
}

void test1_space_get_link_east() {
    Space *space = NULL;
    space = space_create(5);
    space_set_link_east(space, 1);
    PRINT_TEST_RESULT(space_get_link_east(space) == 1);
	space_destroy(space);
}

void test2_space_get_link_east() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_link_east(space) == NO_ID);
}

void test1_space_get_link_west() {
    Space *space = NULL;
    space = space_create(5);
    space_set_link_west(space, 6);
    PRINT_TEST_RESULT(space_get_link_west(space) == 6);
	space_destroy(space);
}

void test2_space_get_link_west() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_link_west(space) == NO_ID);
}

void test1_space_get_id() {
    Space *space = NULL;
    space = space_create(25);
    PRINT_TEST_RESULT(space_get_id(space) == 25);
	space_destroy(space);
}

void test2_space_get_id() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_id(space) == NO_ID);
}

void test1_space_destroy() {
    Space *space = NULL;
    STATUS result;

    space = space_create(1);

    result = space_destroy(space);

    PRINT_TEST_RESULT(result == OK);
}

void test2_space_destroy() {
    Space *space = NULL;
    STATUS result;

    result = space_destroy(space);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_space_set_gdesc() {
    Space *space = NULL;
    space = space_create(1);
    PRINT_TEST_RESULT(space_set_gdesc(space, 1, "hola") == OK);
	space_destroy(space);
}

void test2_space_set_gdesc() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_gdesc(space, 1, "hola") == ERROR);
}

void test3_space_set_gdesc() {
    Space *space = NULL;
    space = space_create(1);
    PRINT_TEST_RESULT(space_set_gdesc(space, 1, NULL) == ERROR);
	space_destroy(space);
}

void test1_space_get_gdesc() {
    Space *space = NULL;
    space = space_create(1);
	space_set_gdesc(space, 1, "hola");
    PRINT_TEST_RESULT(space_get_gdesc(space, 1) != NULL);
	space_destroy(space);
}

void test2_space_get_gdesc() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_gdesc(space, 1) == NULL);
}

void test1_space_print() {
    Space *space = NULL;

    PRINT_TEST_RESULT(space_print(space) == ERROR);
}

void test2_space_print() {
    Space *space = NULL;

    space = space_create(1);

	space_set_link_north(space, 1);
	space_set_link_south(space, 2);
	space_set_link_east(space, 3);
	space_set_link_west(space, 4);
	space_set_object(space, 1);

    PRINT_TEST_RESULT(space_print(space) == OK);

    space_destroy(space);
}

void test1_space_set_description() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_description(space, "hola esta es la descripcion") == OK);
    space_destroy(space);
}

void test2_space_set_description() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_description(space, "hola esta es la descripcion") == ERROR);
}

void test3_space_set_description() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_description(space, NULL) == ERROR);
    space_destroy(space);
}

void test1_space_set_large_description() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_large_description(space, "hola esta es la descripcion larga") == OK);
    space_destroy(space);
}

void test2_space_set_large_description() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_large_description(space, "hola esta es la descripcion larga") == ERROR);
}

void test3_space_set_large_description() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_large_description(space, NULL) == ERROR);
    space_destroy(space);
}

void test1_space_set_illuminated() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_illuminated(space, TRUE) == OK);
    space_destroy(space);
}

void test2_space_set_illuminated() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_illuminated(space, FALSE) == OK);
    space_destroy(space);
}

void test3_space_set_illuminated() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_illuminated(space, TRUE) == ERROR);
}

void test1_space_set_link_up() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_up(space, 1) == OK);
    space_destroy(space);
}

void test2_space_set_link_up() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_up(space, NO_ID) == ERROR);
    space_destroy(space);
}

void test3_space_set_link_up() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_link_up(space, 2) == ERROR);
}

void test1_space_set_link_down() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_down(space, 3) == OK);
    space_destroy(space);
}

void test2_space_set_link_down() {
    Space *space = NULL;
    space = space_create(5);
    PRINT_TEST_RESULT(space_set_link_down(space, NO_ID) == ERROR);
    space_destroy(space);
}

void test3_space_set_link_down() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_link_down(space, 4) == ERROR);
}

void test1_space_get_description() {
    Space *space = NULL;
    space = space_create(1);
    space_set_description(space, "Esto es la descripcion");
    PRINT_TEST_RESULT(strcmp(space_get_description(space), "Esto es la descripcion") == 0);
    space_destroy(space);
}

void test2_space_get_description() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_description(space) == NULL);
}

void test1_space_get_large_description() {
    Space *space = NULL;
    space = space_create(1);
    space_set_large_description(space, "Esto es la descripcion larga");
    PRINT_TEST_RESULT(strcmp(space_get_large_description(space), "Esto es la descripcion larga") == 0);
    space_destroy(space);
}

void test2_space_get_large_description() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_large_description(space) == NULL);
}

void test1_space_get_illuminated() {
    Space *space = NULL;
    space = space_create(1);
    space_set_illuminated(space, TRUE);
    PRINT_TEST_RESULT(space_get_illuminated(space) == TRUE);
    space_destroy(space);
}

void test2_space_get_illuminated() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_illuminated(space) == FALSE);
}

void test1_space_get_link_up() {
    Space *space = NULL;
    space = space_create(1);
    space_set_link_up(space, 1);
    PRINT_TEST_RESULT(space_get_link_up(space) == 1);
    space_destroy(space);
}

void test2_space_get_link_up() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_link_up(space) == NO_ID);
}

void test1_space_get_link_down() {
    Space *space = NULL;
    space = space_create(1);
    space_set_link_down(space, 2);
    PRINT_TEST_RESULT(space_get_link_down(space) == 2);
    space_destroy(space);
}

void test2_space_get_link_down() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_link_down(space) == NO_ID);
}
