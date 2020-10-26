/*
 * exercise 2-6: implement the necessary changes to addname and delname to
 * delete items by marking items as unused. how isolated is the program from
 * this change?
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
};

struct NVtab {
	int nval;			// current number of values
	int max;			// allocated number of values
	Nameval *nameval;	// array of name value pairs
} nvtab;

enum {NVINIT = 1, NVGROW = 2};

// addname: add a new name and value to nvtab
int addname(Nameval newname)
{
	Nameval *nvp;

	if (nvtab.nameval == NULL) {	// first time
		nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
		if (nvtab.nameval == NULL)
			return -1;
		nvtab.max = NVINIT;
		nvtab.nval = 0;
	} else if (nvtab.nval >= nvtab.max) {	// grow
		nvp = (Nameval *) realloc(nvtab.nameval, 
				(NVGROW * nvtab.max) * sizeof(Nameval));
		if (nvp == NULL)
			return -1;
		nvtab.max *= NVGROW;
		nvtab.nameval = nvp;
	}
	nvtab.nameval[nvtab.nval] = newname;
	return nvtab.nval++;
}


// delname: remove first matching nameval from nvtab
int delname(char *name)
{
	int i;

	for (i = 0; i < nvtab.nval; i++)
		if (strcmp(nvtab.nameval[i].name, name) == 0) {
			memmove(nvtab.nameval + i, nvtab.nameval + i + 1, (nvtab.nval - (i + 1)) * sizeof(Nameval));
			// set as unused
			(nvtab.nameval+i+1)->name = NULL;
			(nvtab.nameval+i+1)->value = 0;

			nvtab.nval--;
			return 1;
		}
	return 0;
}

void printarr(Nameval arr)
{
	int i = 0;
	while (nvtab.nameval[i].name != NULL) {
		printf("name: %s, value: %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);	
		i++;
	}
}


int main()
{

	Nameval el;

	el.name = "taylor";
	el.value = 33;
	addname(el);

	el.name = "suki";
	el.value = 5;
	addname(el);

	el.name = "catharine";
	el.value = 36;
	addname(el);
	
	printf("original array:\n");
	printarr(el);

	delname("suki");
	
	printf("array with element deleted: \n");
	printarr(el);

	el.name = "bill";
	el.value = 75;
	addname(el);

	printf("array with element added: \n");
	printarr(el);

	return 0;
}
