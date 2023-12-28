/**
* @brief Modulo object test
*
* Es el modulo que prueba el modulo object para confirmar su correcto funcionamiento
* 
* @file object_test.c
* @author SungPil Choi
* @version 22-03-2016 versión inicial 1.0	
* @date 22-03-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#include "../include/object.h"
#include "../include/object_test.h"
#include "../include/test.h"

/** 
 * @brief Funcion principal de pruebas para el modulo object. 
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
        printf("Running all test for module Object:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_object_create();
    if (todas || test == 2) test2_object_create();
    if (todas || test == 3) test1_object_destroy();
    if (todas || test == 4) test2_object_destroy();
    if (todas || test == 5) test1_object_set_name();
    if (todas || test == 6) test2_object_set_name();
    if (todas || test == 7) test3_object_set_name();
	if (todas || test == 8) test1_object_set_description();
    if (todas || test == 9) test2_object_set_description();
    if (todas || test == 10) test3_object_set_description();
    if (todas || test == 11) test1_object_set_alt_descrip();
    if (todas || test == 12) test2_object_set_alt_descrip();
    if (todas || test == 13) test3_object_set_alt_descrip();
    if (todas || test == 14) test1_object_set_movable();
    if (todas || test == 15) test2_object_set_movable();
    if (todas || test == 16) test1_object_set_move();
    if (todas || test == 17) test2_object_set_move();
    if (todas || test == 18) test1_object_set_visible();
    if (todas || test == 19) test2_object_set_visible();
    if (todas || test == 20) test1_object_set_illuminate();
    if (todas || test == 21) test2_object_set_illuminate();
    if (todas || test == 22) test1_object_set_on();
    if (todas || test == 23) test2_object_set_on();
    if (todas || test == 24) test3_object_set_on();
    if (todas || test == 25) test1_object_set_link();
    if (todas || test == 26) test2_object_set_link();
    if (todas || test == 27) test1_object_get_name();
    if (todas || test == 28) test2_object_get_name();
    if (todas || test == 29) test1_object_get_description();
    if (todas || test == 30) test2_object_get_description();
    if (todas || test == 31) test1_object_get_id();
    if (todas || test == 32) test2_object_get_id();
    if (todas || test == 33) test1_object_get_movable();
    if (todas || test == 34) test2_object_get_movable();
    if (todas || test == 35) test1_object_get_move();
    if (todas || test == 36) test2_object_get_move();
    if (todas || test == 37) test1_object_get_visible();
    if (todas || test == 38) test2_object_get_visible();
    if (todas || test == 39) test1_object_get_illuminate();
    if (todas || test == 40) test2_object_get_illuminate();
    if (todas || test == 41) test1_object_get_on();
    if (todas || test == 42) test2_object_get_on();
    if (todas || test == 43) test1_object_get_link();
    if (todas || test == 44) test2_object_get_link();
    if (todas || test == 45) test1_object_print();
    if (todas || test == 46) test2_object_print();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_object_create() {
	Object* object = NULL;
	int result;

	object = object_create(5);
	result = (object != NULL);

	PRINT_TEST_RESULT(result);

	object_destroy(object);
}

void test2_object_create() {
    Object* object = NULL;

    object = object_create(4);

    PRINT_TEST_RESULT(object_get_id(object) == 4);

	object_destroy(object);
}

void test1_object_destroy() {
    Object* object = NULL;
    STATUS result;

    object = object_create(1);

    result = object_destroy(object);

    PRINT_TEST_RESULT(result == OK);
}

void test2_object_destroy() {
    Object*  object = NULL;
    STATUS result;

    result = object_destroy(object);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_object_set_name() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_name(object, "hola");

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_name() {
    Object* object = NULL;
    STATUS result;

    result = object_set_name(object, "hola");

    PRINT_TEST_RESULT(result == ERROR);
}

void test3_object_set_name() {
    Object* object = NULL;
    STATUS result;

    object = object_create(5);
    result = object_set_name(object, NULL);

    PRINT_TEST_RESULT(result == ERROR);

    object_destroy(object);
}

void test1_object_set_description() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_description(object, "Esta es la descripcion");

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_description() {
    Object* object = NULL;
    STATUS result;

    result = object_set_description(object, "Esta es la descripcion");

    PRINT_TEST_RESULT(result == ERROR);
}

void test3_object_set_description() {
    Object* object = NULL;
    STATUS result;

    object = object_create(5);
    result = object_set_description(object, NULL);

    PRINT_TEST_RESULT(result == ERROR);

    object_destroy(object);
}

void test1_object_set_alt_descrip() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_alt_descrip(object, "Esta es la descripcion");

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_alt_descrip() {
    Object* object = NULL;
    STATUS result;

    result = object_set_alt_descrip(object, "Esta es la descripcion");

    PRINT_TEST_RESULT(result == ERROR);
}

void test3_object_set_alt_descrip() {
    Object* object = NULL;
    STATUS result;

    object = object_create(5);
    result = object_set_alt_descrip(object, NULL);

    PRINT_TEST_RESULT(result == ERROR);

    object_destroy(object);
}

void test1_object_set_movable() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_movable(object, FALSE);

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_movable() {
    Object* object = NULL;
    STATUS result;

    result = object_set_movable(object, FALSE);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_object_set_move() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_move(object, TRUE);

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_move() {
    Object* object = NULL;
    STATUS result;

    result = object_set_move(object, TRUE);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_object_set_visible() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_visible(object, FALSE);

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_visible() {
    Object* object = NULL;
    STATUS result;

    result = object_set_visible(object, FALSE);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_object_set_illuminate() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_illuminate(object, TRUE);

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_illuminate() {
    Object* object = NULL;
    STATUS result;

    result = object_set_illuminate(object, TRUE);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_object_set_on() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    object_set_illuminate(object, TRUE);
    result = object_set_on(object, TRUE);

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_on() {
    Object* object = NULL;
    STATUS result;

    result = object_set_on(object, FALSE);

    PRINT_TEST_RESULT(result == ERROR);
}

void test3_object_set_on() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_on(object, TRUE);

    PRINT_TEST_RESULT(result == ERROR);

    object_destroy(object);
}

void test1_object_set_link() {
    Object* object = NULL;  
    STATUS result;

    object = object_create(5);
    result = object_set_link(object, 1);

    PRINT_TEST_RESULT(result == OK);

    object_destroy(object);
}

void test2_object_set_link() {
    Object* object = NULL;
    STATUS result;

    result = object_set_link(object, 2);

    PRINT_TEST_RESULT(result == ERROR);
}

void test1_object_get_name() {
    Object* object = NULL;

    object = object_create(1);

    object_set_name(object, "adios");

    PRINT_TEST_RESULT(strcmp(object_get_name(object), "adios") == 0);

	object_destroy(object);
}

void test2_object_get_name() {
    Object* object = NULL;

    PRINT_TEST_RESULT(object_get_name(object) == NULL);
}

void test1_object_get_description() {
    Object* object = NULL;

    object = object_create(1);

    object_set_description(object, "Esta es la descripcion");

    PRINT_TEST_RESULT(strcmp(object_get_description(object), "Esta es la descripcion") == 0);

    object_destroy(object);
}

void test2_object_get_description() {
    Object* object = NULL;

    PRINT_TEST_RESULT(object_get_description(object) == NULL);
}

void test1_object_get_id() {
    Object* object = NULL;

    object = object_create(25);

    PRINT_TEST_RESULT(object_get_id(object) == 25);
	object_destroy(object);
}

void test2_object_get_id() {
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_id(object) == NO_ID);
}

void test1_object_get_movable() {
    Object *object = NULL;
    object = object_create(1);
    PRINT_TEST_RESULT(object_get_movable(object) == TRUE);
	object_destroy(object);
}

void test2_object_get_movable() {
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_movable(object) == FALSE);
}

void test1_object_get_move() {
    Object *object = NULL;
    object = object_create(1);
    object_set_move(object, TRUE);
    PRINT_TEST_RESULT(object_get_move(object) == TRUE);
	object_destroy(object);
}

void test2_object_get_move() {
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_move(object) == FALSE);
}

void test1_object_get_visible() {
    Object *object = NULL;
    object = object_create(1);
    PRINT_TEST_RESULT(object_get_visible(object) == TRUE);
	object_destroy(object);
}

void test2_object_get_visible() {
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_visible(object) == FALSE);
}

void test1_object_get_illuminate() {
    Object *object = NULL;
    object = object_create(1);
    object_set_illuminate(object, TRUE);
    PRINT_TEST_RESULT(object_get_illuminate(object) == TRUE);
	object_destroy(object);
}

void test2_object_get_illuminate() {
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_illuminate(object) == FALSE);
}

void test1_object_get_on() {
    Object *object = NULL;
    object = object_create(1);
    object_set_illuminate(object, TRUE);
    object_set_on(object, TRUE);
    PRINT_TEST_RESULT(object_get_on(object) == TRUE);
	object_destroy(object);
}

void test2_object_get_on() {
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_on(object) == FALSE);
}

void test1_object_get_link() {
    Object *object = NULL;
    object = object_create(1);
    object_set_link(object, 2);
    PRINT_TEST_RESULT(object_get_link(object) == 2);
	object_destroy(object);
}

void test2_object_get_link() {
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_link(object) == NO_ID);
}

void test1_object_print() {
    Object *object = NULL;

    PRINT_TEST_RESULT(object_print(object) == ERROR);
}

void test2_object_print() {
    Object *object = NULL;

    object = object_create(1);
	object_set_name(object, "hola");

    PRINT_TEST_RESULT(object_print(object) == OK);

    object_destroy(object);
}