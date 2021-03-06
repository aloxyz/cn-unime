#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

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
    DataType datatype;
    MatrixType MType;
    
    struct Matrix *next;
    } Matrix;


//generic purpose functions
int size(Matrix *A);                                            //returns the number of elements (rows * columns)
int is_vector(Matrix *A);                                       //returns 1 if A is a vector
int sizecmp(Matrix *A, Matrix *B);                              //returns 1 if A and B have the same number of rows and columns
int rccmp(Matrix *A, Matrix *B);                                //returns 1 if cols of A == rows of B
int summable(Matrix *A, Matrix *B);                             //returns 1 if the two matrixes can be summed
MatrixType matrix_typeof(Matrix *A);                            //returns MatrixType 
char *str_matrix_MTypeof(Matrix *A);
char *str_matrix_typeof(Matrix *A);
DataType datatype_matrix_typeof(char *datatype);
void print_info(Matrix *A);

//matrix control functions
void matrix_typeconv(Matrix* A, DataType);                              //casts a matrix type to the argument
void init_elements(Matrix *A, Pointer v);                                  
Matrix *new_matrix(char *name, int rows, int cols, DataType t);     //creates a new matrix
Matrix *random_matrix(int rows, int cols, DataType type, double range[]);           //creates a random matrix with given dimensions and type in a given range
Matrix *random_tridiagonal(int n, DataType type, double range[]);      //creates a random tridiagonal matrix with given dimensions and type in a given range
Matrix *hilbert(int n, DataType type);
Matrix *banded(int p, int q, int n);


//prompt functions
void prompt_init_elements(Matrix *A);                           //initializes the elements of a matrix
void print_matrix(Matrix *A);                                   //prints a Matrix regardless of the type of its elements
Matrix *prompt_matrix();                                        //prompt for a new matrix (wraps new_matrix and init_elements)
void matrix_typeconv(Matrix* A, DataType);                      //casts a matrix type to the argument

//matrix operations
Matrix *matrix_sum(Matrix *A, Matrix *B);                       //sum two matrices A and B
Matrix *matrix_prod(Matrix *A, Matrix *B);
Matrix *matrix_average(Matrix *A);       
Matrix *matrix_seq_prod(Matrix *A);
Matrix *matrix_seq_sum(Matrix *A);         
Matrix *dot_product(Matrix *A, Matrix *B);                      //returns dot product of A and B
Matrix *transpose(Matrix *A);
Matrix *v_tensor_prod(Matrix *A, Matrix *B);
//vectorial norms
Matrix *vec_norm1(Matrix *A, DataType type);
Matrix *vec_norm2(Matrix *A, DataType type);
Matrix *vec_norm_inf(Matrix *A, DataType type);

//matrix norms
Matrix *matrix_norm1(Matrix *A, DataType type);
Matrix *matrix_norm2(Matrix *A, DataType type);
Matrix *matrix_norm_inf(Matrix *A, DataType type);
