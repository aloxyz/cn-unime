#define typename(x) _Generic((x), short int: 0, int:1, float:2, double:3) //macro which allows to detect the type of a variable

//type definitions
typedef enum type{shortint=1, integer, floating, chonkster}type;
typedef union pointer{      //unknown type pointer
    short int   *shortint;
    int         *integer;
    float       *floating;
    double      *chonkster;
    }pointer;

typedef union scalar{     //unknown type scalar
    short int   shortint;
    int         integer;
    float       floating;
    double      chonkster;
    }scalar;

typedef struct matrix{  
    pointer elements;
    int rows, cols;
    type type;
}matrix;

//functions definitions
//general purpose functions
int isVector(matrix *A);                                    //checks if the matrix passed is an array (1xN or Nx1 dimension, where N is greater than 1)
int isScalar(matrix *B);                                    //checks if the matrix passed is a scalar(1x1 dimension)
int check(matrix *A, matrix *B);                            //checks whether the two matrixes have the same size
int inner_check(matrix *A, matrix *B);                       //checks whether the two matrixes are compatible for being multiplicated 
void printMatrix(matrix *A);                                //prints a matrix regardless of the type of its elements
matrix *newMatrix();                                        //creates a new matrix
matrix *matrixSum(matrix *A, matrix *B);

//short int type functions
//matrixes
//vectors
scalar dotProductShortint(matrix *v, matrix *w);                          //dot product between two vector
scalar tensorialProductShortint(matrix *v, matrix *w);                    //tensorial product between two vectors


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
