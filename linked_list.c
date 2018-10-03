#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node * next;
} node_t;

void print_list(node_t *);
void append(node_t *, int);
int remove_last(node_t *);
void push(node_t **, int);
void push2(node_t *, int);
int pop(node_t **);
int pop2(node_t *);
int main(int argc, char **argv){
	/*create *head node pointer for first node in list*/
	node_t *head = NULL;
	head = malloc(sizeof(node_t));
	if(head == NULL){
		return 1;
	}
	head->val = 1;

	print_list(head); /*1*/

	push(&head, 12);
	print_list(head); /*12 1*/
	append(head, 21); /*12 1 21*/
	push(&head, 99);  /*99 12 1 21*/
	append(head, 55); /*99 12 1 21 55*/
	print_list(head); 
	pop(&head);       /*12 1 21 55*/
	print_list(head);
	remove_last(head); /*12 1 21*/
	print_list(head);

	
	free(head);
	return 0;
}
/**
 * print linked list
 */
void print_list(node_t *head){
	node_t * current = head;
	while(current != NULL){
		printf("%d\t",current->val);
		current = current->next;
	}
	printf("\n");
}
/**
 * Append to end of linked list
 */
void append(node_t * head, int val){
	node_t * current = head;
	while (current->next != NULL){
		current = current->next;
	}

	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

/*
 * Remove the last node from end of linked list
 */
int remove_last(node_t * head){
	int retval = 0;
	/* If only one node, next will be null, so free it and return */
	if (head->next == NULL){
		retval= head->val;
		free(head);
		return retval;
	}

	/*Go to second last node*/
	node_t *current = head;
	while (current->next->next != NULL){
		current = current->next;
	}

	retval = current->next->val;
	free(current->next);
	current->next=NULL;
	return retval;
}
/**
 * Push node onto start of list stack
 * - 1. Get the pointer to the head pointer, that's out next address
 * - 2. Create new node
 * - 3. New node's next is address of head pointer
 * - 4. Set the new node to be at the address of the new node
 */
void push(node_t ** head, int val){
	/*create your new node and malloc*/
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}
/**
 * pop node off start of list stack
 * return the popped value
 */
int pop(node_t ** head){
	int retval = -1;
	node_t *next_node = NULL;

	if(*head == NULL) {
		return -1;
	}
	
	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

