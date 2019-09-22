# Jaime Elso de Blas
# Sergio García Bordonado
# Alfredo de Frutos Estebaranz
# SungPil Choi

CC = gcc
CFLAGS = -c -Wall -ansi -pedantic -g

all: Minas_de_Rococo set_test die_test inventory_test player_test space_test link_test character_test object_test dialogue_test

Minas_de_Rococo: game.o game_loop.o command.o space.o game_managment.o object.o player.o set.o die.o link.o inventory.o character.o graphic_engine.o dialogue.o
	$(CC) $^ -o $@

dialogue_test: dialogue.o dialogue_test.o
	$(CC) $^ -o $@

set_test: set.o set_test.o
	$(CC) $^ -o $@

die_test: die.o die_test.o
	$(CC) $^ -o $@

inventory_test: inventory.o set.o inventory_test.o
	$(CC) $^ -o $@

link_test: link.o link_test.o
	$(CC) $^ -o $@

player_test: player_test.o player.o inventory.o set.o
	$(CC) $^ -o $@

space_test: space_test.o space.o set.o 
	$(CC) $^ -o $@

object_test: object_test.o object.o
	$(CC) $^ -o $@

character_test: character_test.o character.o
	$(CC) $^ -o $@

game.o: game.c game.h game_managment.h 
	$(CC) $(CFLAGS) $< -o game.o

game_loop.o: game_loop.c game.h 
	$(CC) $(CFLAGS) $< -o game_loop.o

command.o: command.c command.h
	$(CC) $(CFLAGS) $< -o command.o

space.o: space.c space.h types.h link.h
	$(CC) $(CFLAGS) $< -o space.o

game_managment.o: game_managment.c game_managment.h game.h
	$(CC) $(CFLAGS) $< -o game_managment.o

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) $< -o object.o

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) $< -o player.o

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) $< -o set.o

die.o: die.c die.h types.h
	$(CC) $(CFLAGS) $< -o die.o

link.o: link.c link.h 
	$(CC) $(CFLAGS) $< -o link.o

inventory.o: inventory.c inventory.h set.h
	$(CC) $(CFLAGS) $< -o inventory.o

character.o: character.c character.h
	$(CC) $(CFLAGS) $< -o character.o

graphic_engine.o: graphic_engine.c graphic_engine.h
	$(CC) $(CFLAGS) $< -o graphic_engine.o

dialogue.o: dialogue.c dialogue.h
	$(CC) $(CFLAGS) $< -o dialogue.o

set_test.o: set_test.c set.h set_test.h
	$(CC) $(CFLAGS) $< -o set_test.o

die_test.o: die_test.c die_test.h die.h 
	$(CC) $(CFLAGS) $< -o die_test.o

character_test.o: character_test.c character_test.h character.h
	$(CC) $(CFLAGS) $< -o character_test.o

link_test.o: link_test.c link_test.h link.h
	$(CC) $(CFLAGS) $< -o link_test.o

dialogue_test.o: dialogue_test.c dialogue_test.h dialogue.h
	$(CC) $(CFLAGS) $< -o dialogue_test.o

inventory_test.o: inventory_test.c inventory_test.h inventory.h set.h 
	$(CC) $(CFLAGS) $< -o inventory_test.o

player_test.o: player_test.c player_test.h player.h
	$(CC) $(CFLAGS) $< -o player_test.o

space_test.o: space_test.c space_test.h space.h
	$(CC) $(CFLAGS) $< -o space_test.o

clean: 
	rm -R *.o Minas_de_Rococo *_test html latex Doxyfile doxygen_sqlite3.db

dist: 
	tar -cf JaimeElso-SergioGarcia-AlfredoDeFrutos-Pil.tar *.h *.c Makefile spaces.dat objects.dat links.dat

run:
	./Minas_de_Rococo spaces.dat objects.dat links.dat characters.dat players.dat

log:
	./Minas_de_Rococo spaces.dat objects.dat links.dat characters.dat players.dat -l registro.log

nv: 
	./Minas_de_Rococo spaces.dat objects.dat links.dat characters.dat players.dat -l registro.log -nv < comandos.ent

doxyfile:
	doxygen -g

doxygen: 
	doxygen Doxyfile
	
