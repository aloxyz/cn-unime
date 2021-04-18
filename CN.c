#include<stdio.h>
#include<stdlib.h>
#include"CN.h"

//general purpose functions
int isVector(matrix *A){
    return ((A->rows == 1) || (A->cols == 1));
}

int isScalar(matrix *A){
    return ((A->rows == 1) && (A->cols == 1)); 
}

int check(matrix *A, matrix *B){
    return ((A->rows == B->cols) && (A->cols == B->cols));
}

int inner_check(matrix *A, matrix *B){
    return (A->cols == B->rows);
}

matrix *newMatrix(int cols, int rows){
    matrix *A = (matrix*)malloc(sizeof(matrix));
    A->rows = rows;
    A->cols = cols;
    scanf("%d", &A->type); //1 = shortint, 2 = int, 3 = float, 4 = double
    switch(A->type){
        case shortint:
                A->elements.shortint = (short int*)malloc(sizeof(short int)*A->rows*A->cols); 
                for(int i=0; i< A->rows; i++)
                    for(int j=0; i< A->cols; j++)
                        scanf("%hd", &A->elements.shortint[i*A->cols + A->cols]);
                break;

        case integer:
                A->elements.integer = (int*)malloc(sizeof(int)*A->rows*A->cols); 
                for(int i=0; i< A->rows; i++)
                    for(int j=0; i< A->cols; j++)
                        scanf("%d", &A->elements.integer[i*A->cols + A->cols]);
                break;

        case floating:
                A->elements.floating = (float*)malloc(sizeof(int)*A->rows*A->cols); 
                for(int i=0; i< A->rows; i++)
                    for(int j=0; i< A->cols; j++)
                        scanf("%f", &A->elements.floating[i*A->cols + A->cols]);
                break;

        case chonkster:
                A->elements.chonkster = (double*)malloc(sizeof(int)*A->rows*A->cols); 
                for(int i=0; i< A->rows; i++)
                    for(int j=0; i< A->cols; j++)
                        scanf("%lf", &A->elements.chonkster[i*A->cols + A->cols]);
                break;

        default:
            puts("Wrong code");
    }
    return A;
}

void printMatrix(matrix *A){
    switch(A->type){
        case shortint:
                for(int i = 0; i<A->rows; i++){
                    printf("| ");
                    for(int j = 0; j<A->cols; j++)
                        printf("%hd", A->elements.shortint[i*A->cols + A->cols]);
                    printf(" |");
                }
                break;

        case integer: 
                for(int i = 0; i<A->rows; i++){
                    printf("| ");
                    for(int j = 0; j<A->cols; j++)
                        printf("%d", A->elements.integer[i*A->cols + A->cols]);
                    printf(" |");
                }
                break;
        
        case floating:
                for(int i = 0; i<A->rows; i++){
                    printf("| ");
                    for(int j = 0; j<A->cols; j++)
                        printf("%f", A->elements.floating[i*A->cols + A->cols]);
                    printf(" |");
                }
                break;

        case chonkster:
                for(int i = 0; i<A->rows; i++){
                    printf("| ");
                    for(int j = 0; j<A->cols; j++)
                        printf("%lf", A->elements.chonkster[i*A->cols + A->cols]);
                    printf(" |");
                }
                break;
    }
    

}

//SHORT INT
short int *somma_matrici_shortint(short int *A, short int *B, int size){
    int i,j;
    short int *C;

    C = malloc(sizeof(short int)*size*size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++) 
            C[i*size+j] = A[i*size+j] + B[i*size+j];
    return C;
}


short int prodotto_scalare_shortint(short int arrayA[], short int arrayB[], int size){
    int z=0, i;
    for(i=0; i<size; i++){
        z+= arrayA[i] * arrayB[i];
    }
    return z;
}
short int *prodotto_tensoriale_shortint(short int arrayA[], short int arrayB[], int size){
    short int *c;
    c = malloc(sizeof(short int)*size*size);
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)        
            c[i*size+j]=arrayA[i]*arrayB[j];

    return c;
}

//INT
int *somma_matrici_int(int *A, int *B, int size){
    int i,j;
    int *C;

    C = malloc(sizeof(int)*size*size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++) 
            C[i*size+j] = A[i*size+j] + B[i*size+j];
    return C;
}

int prodotto_scalare_int(int arrayA[], int arrayB[], int size){
    int z=0, i;
    for(i=0; i<size; i++){
        z+= arrayA[i] * arrayB[i];
    }
    return z;
}
int *prodotto_tensoriale_int(int arrayA[], int arrayB[], int size){
    int *c;
    c = malloc(sizeof(int)*size*size);
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)        
            c[i*size+j]=arrayA[i]*arrayB[j];

    return c;
}

//FLOAT
float *somma_matrici_float(float *A, float *B, int size){
    int i,j;
    float *C;

    C = malloc(sizeof(float)*size*size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++) 
            C[i*size+j] = A[i*size+j] + B[i*size+j];
    return C;
}

float prodotto_scalare_float(float arrayA[], float arrayB[], int size){
    int z=0, i;
    for(i=0; i<size; i++){
        z+= arrayA[i] * arrayB[i];
    }
    return z;
}
float *prodotto_tensoriale_float(float arrayA[], float arrayB[], int size){
    float *c;
    c = malloc(sizeof(float)*size*size);
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)        
            c[i*size+j]=arrayA[i]*arrayB[j];

    return c;
}

//DOUBLE
double *somma_matrici_double(double *A, double *B, int size){
    int i,j;
    double *C;

    C = malloc(sizeof(double)*size*size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++) 
            C[i*size+j] = A[i*size+j] + B[i*size+j];
    return C;
}

double prodotto_scalare_double(double arrayA[], double arrayB[], int size){
    int z=0, i;
    for(i=0; i<size; i++){
        z+= arrayA[i] * arrayB[i];
    }
    return z;
}
double *prodotto_tensoriale_double(double arrayA[], double arrayB[], int size){
    double *c;
    c = malloc(sizeof(double)*size*size);
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)        
            c[i*size+j]=arrayA[i]*arrayB[j];

    return c;
}

void fact(int m) {
    int x = 1; float y = 1; double z = 1;
    for(int i = 2; i < m + 1; i++) {
        x *= i; y *= i; z *= i;
        printf("%d!: int: %d\t float: %.3f\tdouble: %.5lf\n", i, x, y, z);
    }
}

void fact_plus(int x, float y, double z, int max) {

    printf("max: %d\n-------", max);

    printf("\nint %d:\n\n", x);
    while(x < max) {
        int tmp = x;
        for(int i = x - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%d! = %d\n", x, tmp);
        x++;
    }
    printf("\nfloat %.2f:\n\n", y);
    while(y < max) {
        float tmp = y;
        for(int i = y - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%.2f! = %.2f\n", y, tmp);
        y++;
    }
    printf("\ndouble %.4lf:\n\n", z);
    while(z < max) {
        double tmp = z;
        for(int i = z - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%.4lf! = %.4lf\n", z, tmp);
        z++;
    }
}

int int_sum(int *v, int n) {
    int sum = v[0];
    for(int i = 0; i < n; i++) { sum += v[i]; }
    return sum;
}

double double_sum(double *v, int n) {
    double sum = v[0];
    for(int i = 0; i < n; i++) { sum += v[i]; }
    return sum;
}

int int_prod(int *v, int n) {
    int prod = v[0];
    for(int i = 0; i < n; i++) { prod *= v[i]; }
    return prod;
}

int int_avg(int *v, int n) {
    return (int_sum(v, n)/n);
}

double double_avg(double *v, int n) {
    return (double_sum(v, n)/n);
}

int int_min(int *v, int n) {
    int tmp = v[0];
    for(int i = 0; i < n; i++) {
        if(tmp > v[i]) tmp = v[i];
    }
    return tmp;
}

int int_max(int *v, int n) {
    int tmp = v[0];
    for(int i = 0; i < n; i++) {
        if(tmp < v[i]) tmp = v[i];
    }
    return tmp;
}

void int_sort(int *v, int n) {
    int result[n];
    int tmp = v[0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; i < n; j++) {
        }
    result[i] = tmp;
    }
}

