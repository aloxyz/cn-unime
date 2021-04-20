#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//type definitions
typedef enum DataType {
    short_int = 1,
    integer,
    floating,
    double_prec
    } DataType;

typedef enum MatrixType {
    matrix, 
    row_vector, 
    col_vector, 
    scalar
    } MatrixType;

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
    DataType type;
    MatrixType MType;
    
    struct Matrix *next;
    } Matrix;


//generic purpose functions
int size(Matrix *A);                                            //returns the number of elements (rows * columns)
int sizecmp(Matrix *A, Matrix *B);                              //returns 1 if A and B have the same number of rows and columns
int rccmp(Matrix *A, Matrix *B);                                //returns 1 if cols of A == rows of B
int summable(Matrix *A, Matrix *B);                             //returns 1 if the two matrixes can be summed
void init_elements(Matrix *A);                                  //initializes the elements of a matrix
Matrix *new_matrix(char *name, int rows, int cols, DataType t);     //creates a new matrix
void print_matrix(Matrix *A);                                   //prints a Matrix regardless of the type of its elements
Matrix *prompt_matrix();                                        //prompt for a new matrix (wraps new_matrix and init_elements)


//matrix operations
Matrix *matrix_sum(Matrix *A, Matrix *B);                    //sum two matrices A and B
