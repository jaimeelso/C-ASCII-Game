# Jaime Elso de Blas
# Sergio García Bordonado
# Alfredo de Frutos Estebaranz
# SungPil Choi

# .c files
SRC_DIR = src
# .h files
INC_DIR = include
# .dat files
DATA_DIR = data

# compiler
CC = gcc
# compiler flags
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

game.o: $(SRC_DIR)/game.c $(INC_DIR)/game.h $(INC_DIR)/game_managment.h 
	$(CC) $(CFLAGS) $< -o game.o

game_loop.o: $(SRC_DIR)/game_loop.c $(INC_DIR)/game.h 
	$(CC) $(CFLAGS) $< -o game_loop.o

command.o: $(SRC_DIR)/command.c $(INC_DIR)/command.h
	$(CC) $(CFLAGS) $< -o command.o

space.o: $(SRC_DIR)/space.c $(INC_DIR)/space.h $(INC_DIR)/types.h $(INC_DIR)/link.h
	$(CC) $(CFLAGS) $< -o space.o

game_managment.o: $(SRC_DIR)/game_managment.c $(INC_DIR)/game_managment.h $(INC_DIR)/game.h
	$(CC) $(CFLAGS) $< -o game_managment.o

object.o: $(SRC_DIR)/object.c $(INC_DIR)/object.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) $< -o object.o

player.o: $(SRC_DIR)/player.c $(INC_DIR)/player.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) $< -o player.o

set.o: $(SRC_DIR)/set.c $(INC_DIR)/set.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) $< -o set.o

die.o: $(SRC_DIR)/die.c $(INC_DIR)/die.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) $< -o die.o

link.o: $(SRC_DIR)/link.c $(INC_DIR)/link.h 
	$(CC) $(CFLAGS) $< -o link.o

inventory.o: $(SRC_DIR)/inventory.c $(INC_DIR)/inventory.h $(INC_DIR)/set.h
	$(CC) $(CFLAGS) $< -o inventory.o

character.o: $(SRC_DIR)/character.c $(INC_DIR)/character.h
	$(CC) $(CFLAGS) $< -o character.o

graphic_engine.o: $(SRC_DIR)/graphic_engine.c $(INC_DIR)/graphic_engine.h
	$(CC) $(CFLAGS) $< -o graphic_engine.o

dialogue.o: $(SRC_DIR)/dialogue.c $(INC_DIR)/dialogue.h
	$(CC) $(CFLAGS) $< -o dialogue.o

set_test.o: $(SRC_DIR)/set_test.c $(INC_DIR)/set.h $(INC_DIR)/set_test.h
	$(CC) $(CFLAGS) $< -o set_test.o

die_test.o: $(SRC_DIR)/die_test.c $(INC_DIR)/die_test.h $(INC_DIR)/die.h 
	$(CC) $(CFLAGS) $< -o die_test.o

character_test.o: $(SRC_DIR)/character_test.c $(INC_DIR)/character_test.h $(INC_DIR)/character.h
	$(CC) $(CFLAGS) $< -o character_test.o

link_test.o: $(SRC_DIR)/link_test.c $(INC_DIR)/link_test.h $(INC_DIR)/link.h
	$(CC) $(CFLAGS) $< -o link_test.o

dialogue_test.o: $(SRC_DIR)/dialogue_test.c $(INC_DIR)/dialogue_test.h $(INC_DIR)/dialogue.h
	$(CC) $(CFLAGS) $< -o dialogue_test.o

inventory_test.o: $(SRC_DIR)/inventory_test.c $(INC_DIR)/inventory_test.h $(INC_DIR)/inventory.h $(INC_DIR)/set.h 
	$(CC) $(CFLAGS) $< -o inventory_test.o

player_test.o: $(SRC_DIR)/player_test.c $(INC_DIR)/player_test.h $(INC_DIR)/player.h
	$(CC) $(CFLAGS) $< -o player_test.o

space_test.o: $(SRC_DIR)/space_test.c $(INC_DIR)/space_test.h $(INC_DIR)/space.h
	$(CC) $(CFLAGS) $< -o space_test.o

clean: 
	rm -R *.o Minas_de_Rococo *_test html latex Doxyfile doxygen_sqlite3.db

dist: 
	tar -cf JaimeElso-SergioGarcia-AlfredoDeFrutos-Pil.tar *.h *.c Makefile spaces.dat objects.dat links.dat

run:
	./Minas_de_Rococo $(DATA_DIR)/spaces.dat $(DATA_DIR)/objects.dat $(DATA_DIR)/links.dat $(DATA_DIR)/characters.dat $(DATA_DIR)/players.dat

log:
	./Minas_de_Rococo $(DATA_DIR)/spaces.dat $(DATA_DIR)/objects.dat $(DATA_DIR)/links.dat $(DATA_DIR)/characters.dat $(DATA_DIR)/players.dat -l registro.log

nv: 
	./Minas_de_Rococo $(DATA_DIR)/spaces.dat $(DATA_DIR)/objects.dat $(DATA_DIR)/links.dat $(DATA_DIR)/characters.dat $(DATA_DIR)/players.dat -l registro.log -nv < comandos.ent

doxyfile:
	doxygen -g

doxygen: 
	doxygen Doxyfile
	
