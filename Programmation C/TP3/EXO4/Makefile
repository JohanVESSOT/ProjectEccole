# Variables :
CC = gcc
EXEC = EXE
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
LIB = 	# Librairie de GPIO du rapsberry -lwiringPi


all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LIB)

%.o : %.c
	$(CC) -o $(OBJ) -c $(SRC) $(LIB)


# Option de compilation :

clean : 
	rm -rf *.o

proper : clean
	rm -rf $(EXEC)

run : all 
	./$(EXEC)


# Variables spéciales :
# $@ : fait référence a la cible
# $< : Nom de la premier dépendance
# $^ : Liste des dépendance