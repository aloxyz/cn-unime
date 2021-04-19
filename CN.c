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

int sizeCmp(matrix *A, matrix *B){
    return ((A->rows == B->cols) && (A->cols == B->cols));
}

int rowsColsCmp(matrix *A, matrix *B){
    return (A->cols == B->rows);
}

matrix *newMatrix(int cols, int rows, type t){
    matrix *A = (matrix*)malloc(sizeof(matrix));
    A->rows = rows;
    A->cols = cols;

    if(t > 4 || t < 1) {
        A->type = 4;
        perror("Invalid type, defaulting to double_prec\n"); 
    } else { A->type = t; }
    
    switch(A->type){
        case short_int:
                A->elements.short_int = (short int*)malloc(sizeof(short int)*A->rows*A->cols); 
                for(int i=0; i< A->rows; i++)
                    for(int j=0; i< A->cols; j++)
                        scanf("%hd", &A->elements.short_int[i*A->cols + A->cols]);
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

        case double_prec:
                A->elements.double_prec = (double*)malloc(sizeof(int)*A->rows*A->cols); 
                for(int i=0; i< A->rows; i++)
                    for(int j=0; i< A->cols; j++)
                        scanf("%lf", &A->elements.double_prec[i*A->cols + A->cols]);
                break;
    }
    return A;
}

void printMatrix(matrix *A){
    switch(A->type){
        case short_int:
                for(int i = 0; i<A->rows; i++){
                    printf("| ");
                    for(int j = 0; j<A->cols; j++)
                        printf("%hd", A->elements.short_int[i*A->cols + A->cols]);
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

        case double_prec:
                for(int i = 0; i<A->rows; i++){
                    printf("| ");
                    for(int j = 0; j<A->cols; j++)
                        printf("%lf", A->elements.double_prec[i*A->cols + A->cols]);
                    printf(" |");
                }
                break;
    }
    

}
