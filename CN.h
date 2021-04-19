//type definitions
typedef enum type {
    short_int = 1,
    integer,
    floating,
    double_prec
    } type;

typedef union pointer {
    short int   *short_int;
    int         *integer;
    float       *floating;
    double      *double_prec;
    } pointer;

typedef struct matrix {  
    pointer elements;
    int rows, cols;
    type type;
    } matrix;


//generic purpose functions
int isVector(matrix *A);                                    //returns 1 if A is a vector (1xN or Nx1 dimension, where N is greater than 1)
int isScalar(matrix *B);                                    //returns 1 if A is a scalar(1x1 dimension)
int sizeCmp(matrix *A, matrix *B);                          //returns 1 if A and B are the same size
int rowsColsCmp(matrix *A, matrix *B);                      //returns 1 if cols of A == rows of B


void printMatrix(matrix *A);                                //prints a matrix regardless of the type of its elements
void initMatrix(matrix *A);
matrix *promptMatrix();                                     //prompt for a new matrix
matrix *newMatrix(int rowN, int colN, type t);              //creates a new matrix


//matrix operations
matrix *matrixSum(matrix *A, matrix *B);                    //sum two matrices A and B
