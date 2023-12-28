/**
* @brief Modulo Command
*
* Archivo de cabecera de command.c
* 
* @file command.h
* @authors 
*
* Jaime Elso de Blas
*
* Sergio García Bordonado
*
* Alfredo de Frutos Estebaranz
*
* Sung Pil Choi
* @version 1.0 (version inicial)
* 	versión 1.1: Dos nuevos comandos (TAKE y DROP)
* 	versión 2.0: Dos nuevos comandos (ROLL y JUMP)
* @date 02-02-2016
*/

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define CMD_LENGHT 30  /*!< Longitud maxima de un comando */

/**
 * @brief struct _MyCmd
 *
 * Estructura con nuestro comando y el argumento que recibe.
 */
typedef struct _MyCmd MyCmd;

/**
 * @brief struct enum enum_Command
 *
 * Es una enumeaciń de los diferentes comandos que puede introducir
 * el usuario, les asigna un valor desde "-2" hasta "2"
 */

typedef enum enum_Command {
	NO_CMD = -2,	/*!< Ningún comando */
	UNKNOWN,		/*!< Comando desconocido */
	QUIT,			/*!< Salir */
	GO,				/*!< Ir */
	NORTH,			/*!< al norte */
	SOUTH,			/*!< al sur */
	WEST,			/*!< al oeste */
	EAST,			/*!< al este */
	UP,				/*!< arriba */
	DOWN,			/*!< abajo */
	TAKE,			/*!< Coger objeto */
	DROP,			/*!< Dejar objeto */
	ROLL,			/*!< Lanzar el dado*/
	INSPECT,		/*!< Inspeccionar*/
	SPACE,			/*!< Inspeccionar espacio*/
	OBJECT, 		/*!< Inspeccionar objeto*/
	TURNON,  		/*!< Encender objeto*/
	TURNOFF,  		/*!< Apagar objeto*/
	OPENING,		/*!< Abrir*/
	SAVE,			/*!< Guardar*/
	TALK,			/*!< Hablar*/
	DRINK			/*!< Beber */
}T_Command; 

/*Cabeceras de funciones de command.c*/

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Modifica el comando introducido en la estructura MyCmd
 *
 * Lee el comando itroducido por el usuario, dependiendo
 * de lo que este haya introducido lo interpreta y da una u otra orden
 * @param mycmd: estructura de tipo MyCmd
 * @return MyCmd*: devuelve una estructura MyCmd con los valores que ha introducido
 * el usuario.
 */
MyCmd* get_user_input(MyCmd* mycmd);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Inicializa. Crea comando
 *
 * Crea una estructura MyCmd reservando memoria y asignando
 * unos valores por defecto
 * @return MyCmd*: devuelve una estructura MyCmd con los valores que se dan
 * por defecto.
 */
MyCmd* command_create();

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Destruir estructura MyCmd.
 *
 * Libera la memoria de la estructura de tipo MyCmd que se le asigne
 * @param mycmd: estructura que queremos destruir
 * @return void: la función no devuelve nada.
 */
void command_destroy(MyCmd* mycmd);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Obtener comando
 *
 * Devuelve el comando almacenado en la estructura MyCmd
 * @param mycmd: estructura MyCmd de la que vamos a obtener el dato
 * @return T_Command: comando que nos devuelve.
 */
T_Command command_get_cmd(MyCmd* mycmd);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Obtener argumento
 *
 * Devuelve el argumento almacenado en la estructura MyCmd
 * @param mycmd: estructura MyCmd de la que vamos a obtener el dato
 * @return T_Command: comando que nos devuelve.
 */
T_Command command_get_arg(MyCmd* mycmd);

/**
 * @date 05-03-2016
 * @author Jaime Elso de Blas
 * @brief Obtener id del objeto.
 *
 * Devuelve el id del objeto almacenado en la estructura MyCmd
 * @param mycmd: estructura MyCmd de la que vamos a obtener el dato
 * @return Id: id del objeto
 */
Id command_get_obj(MyCmd* mycmd);

/**
 * @date 05-03-2016
 * @author SungPil Choi
 * @brief Obtener nombre del objeto.
 *
 * Devuelve el nombre del objeto almacenado en la estructura MyCmd
 * @param mycmd: estructura MyCmd de la que vamos a obtener el dato
 * @return char*: nombre del objeto
 */
char* command_get_objname(MyCmd* mycmd);

/**
 * @date 09-04-2016
 * @author Alfredo de Frutos Estebaranz
 * @brief Obtener nombre del link introducido.
 *
 * @param mycmd: estructura MyCmd de la que vamos a obtener el dato
 * @return char*: nombre del link
 */
char* command_get_link(MyCmd* mycmd);

/**
 * @date 09-04-2016
 * @author SungPil Choi
 * @brief Obtener nombre del nombre del personaje introducido
 *
 * @param mycmd: estructura MyCmd de la que vamos a obtener el dato
 * @return char*: nombre del personaje
 */
char* command_get_charname(MyCmd* mycmd);

#endif