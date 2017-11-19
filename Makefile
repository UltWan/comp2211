# code details

EXE_DIR = .
EXE = $(EXE_DIR)/shell

SRC= shell.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

shell.o:  shell.c

