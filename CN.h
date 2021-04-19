#define typename(x) _Generic((x), short int: 0, int:1, float:2, double:3) //macro which allows to detect the type of a variable

//type definitions
typedef enum type{short_int=1, integer, floating, double_prec}type;

typedef union pointer{      //generic type pointer
    short int   *short_int;
    int         *integer;
    float       *floating;
    double      *double_prec;
    }pointer;

typedef union scalar{     //generic type scalar
    short int   short_int;
    int         integer;
    float       floating;
    double      double_prec;
    }scalar;

typedef struct matrix{  
    pointer elements;
    int rows, cols;
    type type;
}matrix;

//functions definitions

//general purpose functions
int isVector(matrix *A);                                    //returns 1 if A is a vector (1xN or Nx1 dimension, where N is greater than 1)
int isScalar(matrix *B);                                    //returns 1 if A is a scalar(1x1 dimension)
int sizeCmp(matrix *A, matrix *B);                          //returns 1 if A and B are the same size
int rowsColsCmp(matrix *A, matrix *B);                       //returns 1 if cols of A == rows of B
void printMatrix(matrix *A);                                //prints a matrix regardless of the type of its elements
matrix *newMatrix(int rowN, int colN, type t);                                        //creates a new matrix
matrix *matrixSum(matrix *A, matrix *B);                    //sum two matrices A and B

//short int type functions
//matrixes
//vectors
scalar dotProductshort_int(matrix *v, matrix *w);                          //dot product of two vector
scalar tensorialProductshort_int(matrix *v, matrix *w);                    //tensorial product of two vectors


//Operazioni di tipo int
//Matrici
//Vettori
int fact(int m);
int fact_plus(int x, float y, double z, int max);
int int_sum(int *v, int n);
int int_prod(int *v, int n);
int int_avg(int *v, int n);
int int_min(int *v, int n);
int int_max(int *v, int n);
int int_sort(int *v, int n);

int prodotto_scalare_int(int arrayA[], int arrayB[], int size);
int *prodotto_tensoriale_int(int arrayA[], int arrayB[], int size); 
//Operazioni di tipo float
//Matrici
float *somma_matrici_float(float A[], float B[], int size); 
//Vettori
float prodotto_scalare_float(float arrayA[], float arrayB[], int size);
float *prodotto_tensoriale_float(float arrayA[], float arrayB[], int size); 


//Operazioni di tipo double
//Matrici
//Vettori
double double_sum(double *v, int n);
double double_avg(double *v, int n);

double prodotto_scalare_double(double arrayA[], double arrayB[], int size);
double *prodotto_tensoriale_double(double arrayA[], double arrayB[], int size); 
