
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7

void llist_print(LinkedList * list) {
	
	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");

	e = list->head;
	while (e != NULL) {
		printf("%d", e->value);
		e = e->next;
		if (e!=NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}

//
// Appends a new node with this value at the beginning of the list
//
void llist_add(LinkedList * list, int value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

//
// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, int value) {
	//return 0;
//	if (list->head==value) ? 1 : 0;
	if (list->head == NULL) return 0;
	ListNode *p = list->head;
	while (p!=NULL){
	//	p = p->next;
		if(p->value ==value){
			return 1;
		}
		p = p->next;
	}
	return 0; 
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, int value) {
	//ListNode * p = (ListNode *) malloc(sizeof(ListNode));
	
	ListNode * p = list->head;
	ListNode *prev = NULL;

	while(p != NULL){
		if(p->value == value){
			break;
		}
		prev = p;
		p = p->next;	
	}
	
	if(p==NULL) return 0;

	if (prev == NULL){
		list->head = p->next;
	}
	else{
		prev->next = p->next;
	}

	//free(p->name);
	//free(p->address);
	//free(p);
	return 1;
	/*
	ListNode * p = (ListNode *) malloc(sizeof(ListNode));
	p = list->head;
	while(p->next!=NULL){
		if((p->next->value == value)){
			p->next = p->next->next;
			return 1;
		}
		p=p->next;
	}
	free(p->next);
	return 0;
	*/
}

//
// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, int * value) {
	ListNode * p = list->head;
	if (list->head == NULL){
		return 0;
	}
	//while(p!=NULL){
	for (int i = 0; i<ith; i++){
	if(p!=NULL){
			p = p->next;
		}
		else return 0;
	}
	*value = p->value;
	return 1;
	//}
	//return 0;

/*	ListNode * p = list->head;
	for(int i = 0; i<ith-1; i++){
		if(p!=NULL){
			p = p->next;
		}
		else return 0;
	}
	*value = p->next->value;
	//	return 1;

	//p->next = p->next->next;
	return 1;
	//}
	//else{
	//	return 0;
	//}
*/
}

//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {
/*	ListNode * p = list->head;
        	for(int i = 0; i<ith-1; i++){
 	     		if(p!=NULL){
             			p = p->next;
              		}
          
		     	else return 0;
        }
       // *value = p->next->value;
        //      return 1;

        p->next = p->next->next;
        return 1;
        //}
        //else{
        	//      return 0;
        //}
	
	return 1;
*/
	ListNode * n = list->head;
	ListNode *prev = NULL;
	if (list->head == NULL){
		return 0;
	}
	for (int i = 0; i< ith; i++){
		if (n!= NULL){
			prev = n;
			n = n->next;
		}
		else return 0;
	}

	if (prev == NULL){
		list->head = n->next;
	}
	else{
		prev->next = n->next;
	}
	return 1;
}

//
// It returns t	return 1;e number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
	ListNode *p = list->head;
	int c = 0;
	while (p!= NULL){
		c++;
		p = p->next;
	}
	return c;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {
/*	FILE * file = fopen(file_name,"w");
	ListNode *p = list->head;
	if (file == NULL){
		return 0;
	}
	else {
		while (p!=NULL){
			fprintf(file, "%d\n", p->value);
			p = p->next;
		}
	}	
	fclose(file);
	return 0;
*/
	FILE * fd = fopen(file_name, "w");
	ListNode *n = list->head;
	if (fd == NULL){
		return 0;
	}

	while (n!=NULL){
		fprintf(fd, "%d\n", n->value);
		n = n->next;
	}

	fclose(fd);
	return 0;
}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//
int llist_read(LinkedList * list, char * file_name) {
	/*FILE * file = fopen(file_name, "r");
	ListNode *p = list->head;
	
	int a;	
		
	if (file == NULL){
		return 0;
	}
	else{
//		if(scanf(file, "%d", &a)) llist_clear(list);
		//fgetc(file);
		fscanf(file, "%d", &a);
		while(feof(file)==0){
			//fgetc(file);
			//fscanf(file, "%d", &a);
			llist_add(list, a);
			fscanf(file, "%d", &a);
		}
//		fgetc(file);
		//llist_remove_last(list, 4);
	}
	fclose(file);

	return 1;
	*/
	FILE * fd = fopen (file_name, "r");
	ListNode *n = list->head;

	if (fd == NULL){
		return 0;
	}

	if (n!=NULL){
		list->head=NULL;
	}

	int val = 0;
	fscanf(fd, "%d", &val);
	while (!feof(fd)){
		llist_add(list, val);
		fscanf(fd, "%d", &val);
	}
	fclose(fd);
	return 1;	
}

//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {
	ListNode * p = list->head;
	int length = llist_number_elements(list);

	int i = 0;
	
	for(int y = 0; y<length; y++){
		int j = 0;
		while(j<length - y){
			
			ListNode * a = p;
	
			for(int m = 0; m<j; m++){
				a = a->next;
			}
			if (!ascending){
				if (p->value < a->value){
					int x = p->value;
					p->value = a->value;
					a->value = x;
				}
			}
			else {
				if(p->value > a->value){
					int x = p->value;
					p->value = a ->value;
					a->value = x;
				}
			}
			j++;
		}
		p=p->next;
		
	}

/*
	ListNode * newhead = (ListNode *) malloc(sizeof(ListNode));
	newhead ->next = list->head;
	ListNode * p = list->head;
	ListNode * prev = list->head;

	while (p == 1){
		if(p->next && p->next->value < p->value){
			while(prev->next && prev->next->value < p->next->value){
				prev = prev->next;
			}
			ListNode * temp = prev->next;
			prev->next = p->next;
			p->next = p->next->next;
			prev->next->next = temp;
			prev = newhead;
		}
		else p = p->next;
	}
	ListNode * ans = newhead->next;
*/



}

//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, int * value) {
	if(list->head == NULL) return 0;

	ListNode * p = list->head;
	list->head = p->next;
	*value = p->value;
	free(p);	
	
	return 1;
}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, int *value) {
	if(list->head == NULL) return 0;
	
	ListNode * p = list->head;
	ListNode * prev = NULL;
	while(p->next!=NULL){
		prev = p;	
		p = p->next;
	}
	//prev->next = NULL;
	*value = p->value;
	prev->next = NULL;
	free(p);
	return 1;
}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//

void llist_insert_first(LinkedList * list, int value) {
	ListNode * p = (ListNode *) malloc(sizeof(ListNode));
	p->next = list->head;
	p->value = value;
	list->head = p;
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, int value) {
	ListNode * p = (ListNode *) malloc(sizeof(ListNode));
	ListNode * n = list->head;
	while (n->next!= NULL){
		n = n->next; 
	}
	n->next = p;
	p->value = value;
	p->next = NULL;
}

//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list){
	ListNode * p = list->head;
	ListNode * n = NULL;
	while (p!=NULL){
		free(p);
		n = p->next; 
		//free(p);
		p = n;
	}
	list->head=NULL;
}
