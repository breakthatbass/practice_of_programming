/**
 * exercise 2-9: write a generic list type for C. the easiest way is to have
 * each list item hold a void* that points to the data. do the same for C++ by
 * defining a template  and for Java by defining a class that holds losts of
 * type Object. What are the strengths and weakness of the various languages for
 * this job?
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
struct node {
	void *value;
	node *next;
};

static node *create_new_node(void *value)
{
	node *new_node = malloc(sizeof(node));
	new_node->value = value;
	new_node->next = NULL;

	return new_node;
}


// push: add to the front of list
static node push(node **head, node *node_to_add)
{
	node_to_add->next = *head;
	*head = node_to_add;
	return *node_to_add;
}


// append: add to the end of list
static node *append(node **head, node *new_node)
{
	if (*head == NULL) {
		new_node->next = *head;
		*head = new_node;
		return new_node;
	} else {
		node *tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	return *head;
}


static void print_ints(node *head)
{	   
   	node *tmp = head;
		   
   	while (tmp != NULL) {
		printf("%d\n",(int)tmp->value);
		tmp = tmp->next;						    
	}		
}

static void print_strs(node *head)
{
	node *tmp = head;

	while (tmp != NULL) {
		printf("%s\n", (char)tmp->value);
		tmp = tmp->next;
	}
}


int main()
{
	node *new_node;
	int i;

	node *int_list = NULL;
	node *str_list = NULL;

	// push ints to list
	for (i = 1; i <= 5; i++) {
		new_node = create_new_node(i);
		push(&int_list, new_node);
	}

	
	// append ints to list
	for (i = 6; i <= 10; i++) {
		new_node = create_new_node(i);
		append(&int_list, new_node);
	}


	// test it out with strings
	const char *names[666666] = {"bill", "bob", "frank", "joe"};

	char name;
	for (i = 0; i < 4; i++) {
		name = strdup(names[i]);
		append(&str_list, &name);
	}

	print_ints(int_list);
	print_strs(str_list);

	return 0;
}
