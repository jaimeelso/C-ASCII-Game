/**
* @brief Modulo die test
*
* Es el modulo que prueba el modulo character para confirmar su correcto funcionamiento
* 
* @file character_test.c
* @author SungPil Choi
* @version 14-03-2016 versión inicial 1.0	
* @date 18-04-2016
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "../include/character_test.h"

/** 
 * @brief Funcion principal de pruebas para el modulo Character. 
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
        printf("Running all test for module Character:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_character_create();
	if (todas || test == 2) test2_character_create();
	if (todas || test == 3) test1_character_destroy();
    if (todas || test == 4) test2_character_destroy();
    if (todas || test == 5) test1_character_get_id();
    if (todas || test == 6) test2_character_get_id();
    if (todas || test == 7) test1_character_set_location();
	if (todas || test == 8) test2_character_set_location();
    if (todas || test == 9) test1_character_get_location();
    if (todas || test == 10) test2_character_get_location();
    if (todas || test == 11) test1_character_set_object();
    if (todas || test == 12) test2_character_set_object();
	if (todas || test == 13) test3_character_set_object();
	if (todas || test == 14) test1_character_get_object();
    if (todas || test == 15) test2_character_get_object();
    if (todas || test == 16) test1_character_set_name();
    if (todas || test == 17) test2_character_set_name();
    if (todas || test == 18) test3_character_set_name();
    if (todas || test == 19) test1_character_get_name();
    if (todas || test == 20) test2_character_get_name();
    if (todas || test == 21) test1_character_set_description();
    if (todas || test == 22) test2_character_set_description();
    if (todas || test == 23) test3_character_set_description();
    if (todas || test == 24) test1_character_get_description();
    if (todas || test == 25) test2_character_get_description();
    if (todas || test == 26) test1_character_set_talk();
    if (todas || test == 27) test2_character_set_talk();
    if (todas || test == 28) test1_character_get_talk();
    if (todas || test == 29) test2_character_get_talk();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_character_create() {
    Character* character = NULL;

    character = character_create(1);

    int result = character != NULL;

	PRINT_TEST_RESULT(result);

    character_destroy(character);
}

void test2_character_create() {
	Character* character = NULL;

	character = character_create(2);

	PRINT_TEST_RESULT(character_get_id(character) == 2);

    character_destroy(character);
}

void test1_character_destroy() {
    Character* character = NULL;
    STATUS result;

    character = character_create(1);

    result = character_destroy(character);

    PRINT_TEST_RESULT(result == OK);
}

void test2_character_destroy() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_destroy(character) == ERROR);
}

void test1_character_get_id() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_get_id(character) == 1);

    character_destroy(character);
}

void test2_character_get_id() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_get_id(character) == NO_ID);
}

void test1_character_set_location() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_set_location(character, 1) == OK);

    character_destroy(character);
}

void test2_character_set_location() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_set_location(character, 1) == ERROR);
}

void test1_character_get_location() {
    Character* character = NULL;

    character = character_create(1);

    character_set_location(character, 1);

    PRINT_TEST_RESULT(character_get_location(character) == 1);
    
    character_destroy(character);
}

void test2_character_get_location() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_get_location(character) == NO_ID);
    
    character_destroy(character);
}

void test1_character_set_object() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_set_object(character, 2) == OK);

    character_destroy(character);
}

void test2_character_set_object() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_set_object(character, NO_ID) == ERROR);

    character_destroy(character);
}

void test3_character_set_object() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_set_object(character, 1) == ERROR);
}

void test1_character_get_object() {
    Character* character = NULL;

    character = character_create(1);

    character_set_object(character, 2);

    PRINT_TEST_RESULT(character_get_object(character) == 2);

    character_destroy(character);
}

void test2_character_get_object() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_get_object(character) == NO_ID);
}

void test1_character_set_name() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_set_name(character, "Hola") == OK);

    character_destroy(character);
}

void test2_character_set_name() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_set_name(character, NULL) == ERROR);

    character_destroy(character);
}

void test3_character_set_name() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_set_name(character, "Hola") == ERROR);
}

void test1_character_get_name() {
    Character* character = NULL;

    character = character_create(1);

    character_set_name(character, "Hola");

    PRINT_TEST_RESULT(strcmp(character_get_name(character), "Hola") == 0);

    character_destroy(character);
}

void test2_character_get_name() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_get_name(character) == NULL);
}

void test1_character_set_description() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_set_description(character, "Esta es la descripcion") == OK);

    character_destroy(character);
}

void test2_character_set_description() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_set_description(character, NULL) == ERROR);

    character_destroy(character);
}

void test3_character_set_description() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_set_description(character, "Hola") == ERROR);
}

void test1_character_get_description() {
    Character* character = NULL;

    character = character_create(1);

    character_set_description(character, "Esta es la descripcion");

    PRINT_TEST_RESULT(strcmp(character_get_description(character), "Esta es la descripcion") == 0);

    character_destroy(character);
}

void test2_character_get_description() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_get_description(character) == NULL);
}

void test1_character_set_talk() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_set_talk(character, FALSE) == OK);

    character_destroy(character);
}

void test2_character_set_talk() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_set_talk(character, FALSE) == ERROR);
}

void test1_character_get_talk() {
    Character* character = NULL;

    character = character_create(1);

    PRINT_TEST_RESULT(character_get_talk(character) == TRUE);

    character_destroy(character);
}

void test2_character_get_talk() {
    Character* character = NULL;

    PRINT_TEST_RESULT(character_get_talk(character) == FALSE);
}
