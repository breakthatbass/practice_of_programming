#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
	Nameval *left;		// lesser
	Nameval *right;		// greater
};


// insert: insert newp in treep, return treep
Nameval *insert(Nameval *treep, Nameval *newp)
{
	int cmp;

	if (treep == NULL)
		return newp;
	cmp = strcmp(newp->name, treep->name);
	if (cmp == 0)
		printf("insert: duplicate entry %s ignored\n", newp->name);
	else if (cmp < 0)
		treep->left = insert(treep->left, newp);
	else
		treep->right = insert(treep->right, newp);
	return treep;
}


// lookup: look up name in tree treep
Nameval *lookup(Nameval *treep, char *name)
{
	int cmp;

	if (treep == NULL) 
		return NULL;
	cmp = strcmp(name, treep->name);
	if (cmp == 0)
		return treep;
	else if (cmp < 0)
		return lookup(treep->left, name);
	else
		return lookup(treep->right, name);
}


//nrlookup: non-recursively look up name in tree treep
Nameval *nrlookup(Nameval *treep, char *name)
{
	int cmp;

	while (treep != NULL) {
		cmp = strcmp(name, treep->name);
		if (cmp == 0)
			return treep;
		else if (cmp < 0)
			treep = treep->left;
		else
			treep = treep->right;
	}
	return NULL;
}


// applyinorder: in order application of fn to treep
void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg)
{
	if (treep == NULL)
		return;
	applyinorder(treep->left, fn, arg);
	(*fn)(treep, arg);
	applyinorder(treep->right, fn, arg);
}


// applypostorder: post order application of fn to treep
void applypostorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg)
{
	if (treep == NULL)
		return;
	applypostorder(treep->left, fn, arg);
	applypostorder(treep->right, fn, arg);
	(*fn)(treep, arg);
}

void print(Nameval *treep, void *arg)
{
	char *fmt = (char *)arg;
	printf(fmt, treep->name, treep->value);
}

int main()
{

	Nameval *leaf_mj = malloc(sizeof(Nameval));
	leaf_mj->name = "michael jordan";
	leaf_mj->value = 23;
	leaf_mj->left = NULL;
	leaf_mj->right = NULL;

	Nameval *leaf_tb = malloc(sizeof(Nameval));
	leaf_tb->name = "tom brady";
	leaf_tb->value = 12;
	leaf_tb->left = NULL;
	leaf_tb->right = NULL;

	Nameval *leaf_rf = malloc(sizeof(Nameval));
	leaf_rf->name = "roger federer";
	leaf_rf->value = 1;
	leaf_rf->left = NULL;
	leaf_rf->right = NULL;

	leaf_mj = insert(leaf_mj, leaf_tb);
	leaf_mj = insert(leaf_mj, leaf_rf);

	applyinorder(leaf_mj, print, "%s: %d\n");

	return 0;
}
