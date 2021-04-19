#include "lists.h"

//get n-th 
matrix *get_matrix(matrix *head, char *name) {
    while (head != NULL) {
        if(!strcmp(name, head->name)) return head;
        head = head->next;
    }
    return NULL;
}

matrix *get_last(matrix *head){
    matrix *tmp = head;
    while (tmp->next != NULL) tmp = tmp->next;

    return tmp;
}

int llen(matrix *head) {
    int i = 1;
    matrix *tmp = head;
    while(tmp->next != NULL) {
	    tmp = tmp->next;
	    i++;
    }
    return i;
}

void push_matrix(matrix **head, matrix *new) {
    if (*head == NULL) *head = new;
    else get_last(*head)->next = new;
    
    new->next = NULL;
}

void print_list(matrix *head){
    printf("existing variables: ");
    if(head == NULL) printf("none\n");
    else {
        while(head != NULL) {
            printf("%s, ", head->name);
            head = head->next;
        }
    }
    printf("\n");
}
