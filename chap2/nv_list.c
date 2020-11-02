/**
 * exercise 2-7: implement some of the other operators: copy, merge, split,
 * insert before or after a specific item. how do the two insertion operations
 * differ in difficulty? how much can you use the routines we've written, and
 * how much must you create yourself?
 *
 * */


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


// copy: make a copy of listp
Nameval *copy(Nameval *listp)
{
	Nameval *newlist;

	newlist = NULL;
	for ( ; listp != NULL; listp = listp->next )
		newlist = addend(newlist, newitem(listp->name, listp->value));

	return newlist;
}


// merge: merge two list into one
Nameval *merge(Nameval *list_a, Nameval *list_b)
{
	list_a = addend(list_a, list_b);
	return list_a;
}


// functions for apply function pointer

// call like this: apply(nvlist, printnv, "%s: %x\n");
void printnv(Nameval *p, void *arg)
{
	char *fmt;

	fmt = (char *) arg;
	printf(fmt, p->name, p->value);
}


void inccounter(Nameval *p, void *arg)
{
	int *ip;

	// p is unused
	ip = (int *) arg;
	(*ip)++;
}

static void printlist(Nameval *head)
{
	Nameval *tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;						    
	}	
}

int main()
{
	Nameval *list, *node, *end; 

	Nameval *newlist;		// list to copy to
	Nameval *mergelist;		// list to merge into

	
	// create and add to list
	list = newitem("tom brady", 12);
	end = addend(list, newitem("michael jordan", 23));
	end = addend(list, newitem("steve kerr", 25));
	end = addend(list, newitem("roger federer", 1));
	
	// print list	
	apply(list, printnv, "%s: %d\n");

	// count elements in list and print number
	int n = 0;
	apply(list, inccounter, &n);
	printf("%d elements in list\n", n);

	// make copy of list and print it
	newlist = copy(list);
	apply(newlist, printnv, "%s: %d\n");

	// merge original list and copied list
	mergelist = merge(list, newlist);

	// print merged list
	printf("\nmerged list:\n");
	apply(mergelist, printnv, "%s: %d\n");



	return 0;
}
