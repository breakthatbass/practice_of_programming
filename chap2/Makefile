CC=gcc
CFLAGS=-g -lm -std=c99 -pedantic
SRC=lib_qsort.c

ifndef NAME
    NAME=sort
endif

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm $(NAME) *.txt