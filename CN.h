#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//type definitions
typedef enum Type {
    short_int = 1,
    integer,
    floating,
    double_prec
    } Type;

typedef union Pointer {
    short int   *short_int;
    int         *integer;
    float       *floating;
    double      *double_prec;
    } Pointer;

typedef struct Matrix {  
    char name[16];
    Pointer elements;
    int rows, cols;
    Type type;

    struct Matrix *next;
    } Matrix;


//generic purpose functions
int is_vector(Matrix *A);                                   //returns 1 if A is a vector (1xN or Nx1 dimension, where N is greater than 1)
int is_scalar(Matrix *B);                                   //returns 1 if A is a scalar(1x1 dimension)
int sizecmp(Matrix *A, Matrix *B);                          //returns 1 if A and B are the same size
int rccmp(Matrix *A, Matrix *B);                           //returns 1 if cols of A == rows of B


void print_matrix(Matrix *A);                                //prints a Matrix regardless of the type of its elements
void init_elements(Matrix *A);
Matrix *prompt_matrix();                                     //prompt for a new matrix
Matrix *new_matrix(char *name, int rows, int cols, Type t);  //creates a new matrix


//matrix operations
Matrix *matrix_sum(Matrix *A, Matrix *B);                    //sum two matrices A and B
