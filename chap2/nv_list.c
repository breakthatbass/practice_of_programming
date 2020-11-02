
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

// newitem: create new item from name and value
Nameval *newitem(char *name, int value)
{
	Nameval *newp;

	newp = (Nameval *)malloc(sizeof(Nameval));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

//addfront: add newp to front of listp
Nameval *addfront(Nameval *listp, Nameval *newp)
{
	newp->next = listp;
	return newp;
}


//addend: add newp to end of listp
Nameval *addend(Nameval *listp, Nameval *newp)
{
	Nameval *p;

	if (listp == NULL)
		return newp;
	for (p = listp; p->next != NULL; p = p->next)
		;
	p->next = newp;
	return listp;
}


// lookup: sequential search for name in listp
Nameval *lookup(Nameval *listp, char *name)
{
	for ( ; listp != NULL; listp = listp->next )
		if (strcmp(name, listp->name) == 0)
			return listp;
	return NULL;	// no match
}

// apply: execute fn for each element in listp
void apply(Nameval *listp, void (*fn)(Nameval*, void*), void *arg)
{
	for ( ; listp != NULL; listp = listp->next)
		(*fn)(listp, arg);	// call the function
}


// freeall: free all elements of listp
void freeall(Nameval *listp)
{
	Nameval *next;

	for ( ; listp != NULL; listp = next ) {
		next = listp->next;
		// assumes name is freed elsewhere
		free(listp);
	}
}


// delitem: delete first "name" from listp
Nameval *delitem(Nameval *listp, char *name)
{
	Nameval *p, *prev;

	prev = NULL;
	for (p = listp; p != NULL; p = p->next) {
		if (strcmp(name, p->name) == 0) {
			if (prev == NULL)
				listp = p->next;
			else
				prev->next = p->next;
			free(p);
			return listp;
		}
		prev = p;
	}
	printf("delitem: %s not in list", name);
	return NULL;	// can't get here
}

int main()
{

	return 0;
}
