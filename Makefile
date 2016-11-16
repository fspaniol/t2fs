#
# Makefile ESQUELETO
#
# OBRIGATÓRIO ter uma regra "all" para geração da biblioteca e de uma
# regra "clean" para remover todos os objetos gerados.
#
# NECESSARIO adaptar este esqueleto de makefile para suas necessidades.
# 

CC=gcc
AR=ar
LIB_DIR=./lib/
INC_DIR=./include/
BIN_DIR=./bin/
SRC_DIR=./src/
TST_DIR=./teste/

all: t2fs t2aux t2lib exec

t2fs:	./src/t2fs.c
	$(CC) -c $(SRC_DIR)t2fs.c -o $(BIN_DIR)t2fs.o -Wall

t2aux:	./src/t2fsaux.c
	$(CC) -c $(SRC_DIR)t2fsaux.c -o $(BIN_DIR)t2fsaux.o -Wall

t2lib:	./bin/t2fs.o ./bin/t2fsaux.o ./lib/apidisk.o
	$(AR) crs $(LIB_DIR)libt2fs.a $(BIN_DIR)t2fs.o $(BIN_DIR)t2fsaux.o $(LIB_DIR)apidisk.o

exec:	./lib/libt2fs.a ./teste/teste1.c
	$(CC) -o teste1 $(TST_DIR)teste1.c -L$(LIB_DIR) -lt2fs -Wall

clean:
	rm -rf $(LIB_DIR)/*.a $(BIN_DIR)/*.o