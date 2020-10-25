CC=gcc
CFLAGS=-g -Wall -Wextra -Wconversion -pedantic
SRC=lib_qsort.c

ifndef NAME
    NAME=sort
endif

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm $(NAME) *.txt