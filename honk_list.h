#include <stdlib.h>

//IMPLEMENTATION OF SINGLY LINKED LIST

//A node to store data in the linked list
struct llist_node {
	void*  data;
	struct llist_node* next;
};

//A linked list
struct llist {
	int length;
	struct llist_node* head;
	struct llist_node* tail;
};

//Create an empty linked list
struct llist* llist_create() {
	struct llist* newlist = malloc(sizeof(*newlist));
	if(newlist == NULL) { 
		return NULL; 
	} else {
		newlist->head = NULL;
		newlist->tail = NULL;
		newlist->length = 0;
		return newlist;
	}
}

void llist_free(struct llist* list) {
	struct llist_node* node;
	while(list->head) {
		node = list->head;
		list->head = node->next;
		if(node->data) free(node->data);
		free(node);
	}
	free(list);
}

//Insert a node in the linked list
struct llist* llist_insert(struct llist* list, void* d) {
	struct llist_node* newnode = malloc(sizeof(*newnode));
	if(newnode == NULL) { return NULL; }

	newnode->data = d;
	newnode->next = NULL;

	if((list->head == NULL) && (list->tail == NULL)) {
		list->head = newnode;
		list->tail = newnode;
		return list;
	} else {
		list->tail->next = newnode;
		list->tail = newnode;
	}
	list->length++;
	return list;
}

//Perform operation on the linked list
int llist_foreach(struct llist* list, int(*func)(void*))
{
	struct llist_node* node = NULL;
	for(node = list->head; node; node = node->next) {
		func(node->data);
	}
	return 0;
}
