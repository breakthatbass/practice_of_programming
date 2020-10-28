
#include <stdio.h>
#include <stdlib.h>

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

int main()
{

	return 0;
}
