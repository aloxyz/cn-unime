#include<stdio.h>
#include<stdlib.h>
#include"CN.h"

//SHORT INT
short int *inizializza_matrice_shortint(int size){
    puts("Inserire gli elementi della matrice");
    int i,j;
    short int *A;
    A = malloc(sizeof(short int)*size*size);
    for(i=0; i<size; i++){
        for(j=0; j<size; j++)
            scanf("%hu", A+i*size+j);
        fflush(stdin);
        }
    fflush(stdin);
    return A;
}
short int *somma_matrici_shortint(short int *A, short int *B, int size){
    int i,j;
    short int *C;

    C = malloc(sizeof(short int)*size*size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++) 
            C[i*size+j] = A[i*size+j] + B[i*size+j];
    return C;
}
void stampa_matrice_shortint(short int A[], int size){
    int i,j;
    for(i=0; i<size; i++){
        printf("|");
        for(j=0; j<size; j++) 
            printf("%2hu", A[i*size+j]);
        printf("|\n");
    }
    printf("\n\n");
}
short int *inizializza_array_shortint(int size){
    puts("Inserire gli elementi del vettore");
    short int *a = malloc(sizeof(short int)*size);
    for(int i=0; i<size; i++)
        scanf("%hu", &a[i]);
    fflush(stdin);
    return a;
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
int *inizializza_matrice_int(int size){
    puts("Inserire gli elementi della matrice");
    int i,j;
    int *A;
    A = malloc(sizeof(int)*size*size);
    for(i=0; i<size; i++){
        for(j=0; j<size; j++)
            scanf("%d", A+i*size+j);
        fflush(stdin);
        }
    fflush(stdin);
    return A;
}
int *somma_matrici_int(int *A, int *B, int size){
    int i,j;
    int *C;

    C = malloc(sizeof(int)*size*size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++) 
            C[i*size+j] = A[i*size+j] + B[i*size+j];
    return C;
}
void stampa_matrice_int(int A[], int size){
    int i,j;
    for(i=0; i<size; i++){
        printf("|");
        for(j=0; j<size; j++) 
            printf("%2d ", A[i*size+j]);
        printf("|\n");
    }
    printf("\n\n");
}
int *inizializza_array_int(int size){
    puts("Inserire gli elementi dell'array");
    int *a = malloc(sizeof(int)*size);
    for(int i=0; i<size; i++)
        scanf("%d", &a[i]);
    fflush(stdin);
    return a;
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
float *inizializza_matrice_float(int size){
    puts("Inserire gli elementi della matrice");
    int i,j;
    float *A;
    A = malloc(sizeof(float)*size*size);
    for(i=0; i<size; i++){
        for(j=0; j<size; j++)
            scanf("%f", A+i*size+j);
        fflush(stdin);
        }
    fflush(stdin);
    return A;
}
float *somma_matrici_float(float *A, float *B, int size){
    int i,j;
    float *C;

    C = malloc(sizeof(float)*size*size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++) 
            C[i*size+j] = A[i*size+j] + B[i*size+j];
    return C;
}
void stampa_matrice_float(float A[], int size){
    int i,j;
    for(i=0; i<size; i++){
        printf("|");
        for(j=0; j<size; j++) 
            printf("%2f ", A[i*size+j]);
        printf("|\n");
    }
    printf("\n\n");
}
float *inizializza_array_float(int size){
    puts("Inserire gli elementi dell'array");
    float *a = malloc(sizeof(float)*size);
    for(int i=0; i<size; i++)
        scanf("%f", &a[i]);
    fflush(stdin);
    return a;
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
double *inizializza_matrice_double(int size){
    puts("Inserire gli elementi della matrice");
    int i,j;
    double *A;
    A = malloc(sizeof(double)*size*size);
    for(i=0; i<size; i++){
        for(j=0; j<size; j++)
            scanf("%lf", A+i*size+j);
        fflush(stdin);
        }
    fflush(stdin);
    return A;
}
double *somma_matrici_double(double *A, double *B, int size){
    int i,j;
    double *C;

    C = malloc(sizeof(double)*size*size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++) 
            C[i*size+j] = A[i*size+j] + B[i*size+j];
    return C;
}
void stampa_matrice_double(double A[], int size){
    int i,j;
    for(i=0; i<size; i++){
        printf("|");
        for(j=0; j<size; j++) 
            printf("%2lf ", A[i*size+j]);
        printf("|\n");
    }
    printf("\n\n");
}
double *inizializza_array_double(int size){
    puts("Inserire gli elementi dell'array");
    double *a = malloc(sizeof(double)*size);
    for(int i=0; i<size; i++)
        scanf("%lf", &a[i]);
    fflush(stdin);
    return a;
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

