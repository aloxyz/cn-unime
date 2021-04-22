#include "CN.h"

Matrix *get_matrix(Matrix *head, char *name);
Matrix *get_last(Matrix *head);
int llen(Matrix *head);
void push_matrix(Matrix **head, Matrix *new);
void print_list(Matrix *head);

void remove_matrix(Matrix *head, char *name);
void rename_matrix(char *name, Matrix *A);
void clone_matrix(Matrix *head, Matrix *A, char* name);