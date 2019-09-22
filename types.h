/**
* @brief Modulo Types
*
* archivo de cabecera de todo el programa en general
* 
* @file space.h
* @author Jaime Elso de Blas y Sergio García Bordonado
* @version 1.0 (version inicial)
* @date 02-02-2016
*/


#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000	/*Tamaño de una palabra*/
#define DESCRIPTION_SIZE 100 /*Tamaño de la descripcion*/
#define LARGE_DESCRIPTION_SIZE 2000 /*Tamaño de la descripcion*/
#define NO_ID -1	/*Valor de NO_ID*/

typedef long Id;	/*renombramos el tipo de variable "long" por Id*/

#define DESC_SIZE 100

/**
 * @brief enum BOOL
 *
 * Enumeracion de tipo BOOL con dos opciones, FALSE o TRUE.
 */
typedef enum {
  FALSE, /*!< falso*/
   TRUE /*!< verdadero*/
} BOOL;

/**
 * @brief enum STATUS
 *
 * Enumeracion de tipo STATUS con dos opciones, ERROR o OK.
 */
typedef enum {
    ERROR,/*!< error*/
    OK /*!< ok*/
} STATUS;

/**
 * @brief enum DIRECTION
 *
 * Enumeracion que la llamamos DIRECTION con cuatro opciones.
 */
typedef enum {
    N,/*!< norte*/
    S,/*!< sur*/
    E,/*!< este*/
    W/*!< oeste*/
} DIRECTION;

typedef enum{
	PUERTA = 1,
	RELACIONES,
	CAMELLO,
	CAMARERA,
	ROPERO,
	BORRACHO,
	DJ,
	CHICA,
	BILLGATES,
	PUERTA2,
	HOMBRE,
	FIESTERO,
	SATANISTA,
	OSCAR
} PERSONAJES;

typedef enum{
	TELEFONO = 1,
	APUNTES,
	PAPELERA,
	JERINGUILLA,
	FLYER,
	COPA,
	DNI,
	FORMULA_COCACOLA,
	LISTA_IMPLICADOS,
	PASTIS,
	VOMITO,
	BOCADILLO,
	LINTERNA,
	URINARIO,
	CARTERA,
	CRUCIFIJO,
	BURUNDANGA,
	ANTIDOTO,
	DINERO,
	ABRIGO
} OBJETOS;

typedef enum{
	PRIMERO = 0,
	SEGUNDO,
	TERCERO
} ORDEN;

#define COST_FLYER -12
#define COST_PASTIS -20
#define COST_ABRIGO -2
#define COST_COPA -10
#define GIVE_COPA 1
#define LOSE_COPA -1
#define MONEY_BILL 300

#endif 