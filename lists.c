#include "lists.h"

Matrix *get_matrix(Matrix *head, char *name) {
    while (head != NULL) {
        if(!strcmp(name, head->name)) return head;
        head = head->next;
    }
    return NULL;
}

Matrix *get_last(Matrix *head){
    Matrix *tmp = head;
    while (tmp->next != NULL) tmp = tmp->next;

    return tmp;
}

int llen(Matrix *head) {
    int i = 1;
    Matrix *tmp = head;
    while(tmp->next != NULL) {
	    tmp = tmp->next;
	    i++;
    }
    return i;
}

void push_matrix(Matrix **head, Matrix *new) {
    if (*head == NULL) *head = new;
    else get_last(*head)->next = new;
    
    new->next = NULL;
}

void print_list(Matrix *head){
    printf("existing variables: ");
    if(head == NULL) printf("none\n");
    else {
        while(head != NULL) {
            printf("%s ", head->name);
            head = head->next;
        }
    }
    printf("\n");
}

void remove_matrix(Matrix *head, char *name) {
    Matrix *tmp = head->next;
    Matrix *match = get_matrix(head, name);
    while(tmp->next != NULL && strcmp(name, tmp->name) != 0) {
        tmp = tmp->next;
    }
    if(match->next != NULL) tmp->next = match->next;
    match->next = NULL;
    free(match);
}

void rename_matrix(char *name, Matrix *A) {
    strncpy(A->name, name, 16);
}

void clone_matrix(Matrix *head, Matrix *A, char* name) {
    push_matrix(&head, A);
    rename_matrix(name, get_last(head));
}

