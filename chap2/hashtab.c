/**
 * exercise 2-15: write a function to access the successive elements of the hash
 * table in unsorted order
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum { MULTIPLIER = 31 };
#define NHASH 7919		// should be a prime number according to the book


typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
	Nameval *next;		// next in chain
};

Nameval *symtab[NHASH];	// a symbol table

// hash: compute hash value of string
unsigned int hash(char *str)
{
	unsigned int h;
	unsigned char *p;

	h = 0;
	for (p = (unsigned char *) str; *p != '\0'; p++)
		h = MULTIPLIER * h + *p;
	return h % NHASH;
}

// lookup: find name in symtab, with optional create
Nameval *lookup(char *name, int create, int value)
{
	int h;
	Nameval *sym;

	h = hash(name);
	for (sym = symtab[h]; sym != NULL; sym = sym->next)
		if (strcmp(name, sym->name) == 0)
			return sym;
	if (create) {
		sym = (Nameval *)malloc(sizeof(Nameval));
		sym->name = name;	//assumed allocated elsewhere
		sym->value = value;
		sym->next = symtab[h];
		symtab[h] = sym;
	}
	return sym;
}


// display: access all elements and if element exists, print it
void display(void)
{
	int i = 0;
	for (i = 0; i < NHASH; i++) {
		if (symtab[i] != NULL) 
			printf("%s: %d\n", symtab[i]->name, symtab[i]->value);
	}
}

int main()
{
	Nameval *tab = malloc(sizeof(Nameval));
	tab = lookup("tom brady", 1, 12);
	tab = malloc(sizeof(Nameval));
	tab = lookup("michael jordan", 1, 23);
	tab = malloc(sizeof(Nameval));
	tab = lookup("roger federer", 1, 1);

	display();	

	return 0;
}
