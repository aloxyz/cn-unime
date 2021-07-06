#include "systems.h"
#include <stdlib.h>

#define IS_UPPER(MATRIX, TYPE)                              \
    for(int j = 0; j<A->rows; j++){                         \
        for(int i = i+1; i<A->cols; i++)                    \
            if(A->elements.TYPE[i*A->cols+j]!=0) return 0;  \
    }                                                       \
    return 1;

int is_upper_triangular(Matrix *A){
    if(A->rows != A->cols) return 0;

    switch(A->datatype){
        case short_int:     IS_UPPER(A, short_int);     break;
        case integer:       IS_UPPER(A, integer);       break;
        case floating:      IS_UPPER(A, floating);      break;
        case double_prec:   IS_UPPER(A, double_prec);   break;
    }
}

#define DETERMINANT(MATRIX, DET, TYPE)                                   \
    DET->elements.TYPE = malloc(sizeof(*DET->elements.TYPE));            \
    DET->elements.TYPE[0] = 1;                                           \
    for(int i=0; i<MATRIX->rows; i++)                                    \
        DET->elements.TYPE[0] *= MATRIX->elements.TYPE[i*MATRIX->cols+i];   

Matrix *determinant(Matrix *A){
    Matrix *det = new_matrix("ans", 1, 1, A->datatype);
    if(!is_upper_triangular(A)) return NULL; //to modify in trying to factorize the matrix


    switch(A->datatype){
        case short_int:     DETERMINANT(A, det, short_int);     break;
        case integer:       DETERMINANT(A, det, integer);       break;
        case floating:      DETERMINANT(A, det, floating);      break;
        case double_prec:   DETERMINANT(A, det, double_prec);   break;
    
    }
    
    return det;
}

#define BACKWARDS(MATRIX, X, B, TYPE)                                                                   \
X->elements.TYPE = malloc(sizeof(*X->elements.TYPE) * size(X));                                         \
                                                                                                        \
    for(int i=size(X)-1; i>=0; i--){                                                                    \
        X->elements.TYPE[i] = B->elements.TYPE[i];                                                      \
        for(int j=i+1; j<size(X); j++){                                                                 \
            X->elements.TYPE[i] -= X->elements.TYPE[j] * MATRIX->elements.TYPE[i * MATRIX->cols + j];   \
        }                                                                                               \
         X->elements.TYPE[i] /= MATRIX->elements.TYPE[i * MATRIX->cols + i];                            \
    }
        
Matrix *backwards_substitution(Matrix *A, Matrix* b){

    Matrix *x = NULL;
    DataType tmp_datatype;
    enum casted { Acasted, bcasted } casted;
        if (A->datatype > b->datatype) {
        tmp_datatype = b->datatype;
        matrix_typeconv(b, A->datatype);
        casted = bcasted;
        } 
        else {
        tmp_datatype = A->datatype;
        matrix_typeconv(A, b->datatype);
        casted = Acasted;
        }

    x = new_matrix("ans", A->rows, 1, A->datatype);

    switch(A->datatype){
        case short_int:     BACKWARDS(A, x, b, short_int)       break;
        case integer:       BACKWARDS(A, x, b, integer)         break;
        case floating:      BACKWARDS(A, x, b, floating)        break;
        case double_prec:   BACKWARDS(A, x, b, double_prec)     break;
    
    }

    if (casted == Acasted)  matrix_typeconv(A, tmp_datatype);
    else    matrix_typeconv(b, tmp_datatype);
    return x;
}


#define GAUSS_ELIMINATION(TMP, MATRIX, TYPE, B)                                                                                                  \
  TMP->elements.TYPE = malloc(sizeof(*TMP->elements.TYPE));                                                                                      \
    for(int k = 0, l; k<MATRIX->cols-1; k++){                                                                                                    \
        TMP->elements.TYPE[0] = 0;                                                                                                               \
        for(int i = 0; i<MATRIX->rows; i++){                                                                                                     \
            if(TYPE >= floating){                                                                                                                \
                if(TMP->elements.TYPE[0] < fabs(MATRIX->elements.TYPE[i * MATRIX->cols + k])) {                                                  \
                    TMP->elements.TYPE[0] = fabs(MATRIX->elements.TYPE[i * MATRIX->cols + k]);                                                   \
                    l = i;                                                                                                                       \
                }                                                                                                                                \
            }                                                                                                                                    \
            else                                                                                                                                 \
                if(TMP->elements.TYPE[0] < abs(MATRIX->elements.TYPE[i * MATRIX->cols + k])){                                                    \
                    TMP->elements.TYPE[0] = abs(MATRIX->elements.TYPE[i * MATRIX->cols + k]);                                                    \
                    l = i;                                                                                                                       \
                }                                                                                                                                \
        }                                                                                                                                        \
        if  (TMP->elements.TYPE[0] == 0) return NULL;                                                                                            \
        if (l != k){                                                                                                                             \
            for(int j = k; j<MATRIX->cols; j++){                                                                                                 \
                TMP->elements.TYPE[0] = MATRIX->elements.TYPE[k * MATRIX->cols + j];                                                             \
                MATRIX->elements.TYPE[k * MATRIX->cols + j] = MATRIX->elements.TYPE[l * MATRIX->cols + j];                                       \
                MATRIX->elements.TYPE[l * MATRIX->cols + j] = TMP->elements.TYPE[0];                                                             \
            }                                                                                                                                    \
            TMP->elements.TYPE[0] = B->elements.TYPE[k];                                                                                         \
            B->elements.TYPE[k] = B->elements.TYPE[l];;                                                                                          \
            B->elements.TYPE[l] = TMP->elements.TYPE[0];                                                                                         \
        }                                                                                                                                        \
                                                                                                                                                 \
        for(int i = k+1; i<MATRIX->cols; i++){                                                                                                   \
            TMP->elements.TYPE[0] = MATRIX->elements.TYPE[i * MATRIX->cols + k]/MATRIX->elements.TYPE[k * MATRIX->cols + k];                     \
            for(int j = k+1; j<MATRIX->rows; j++){                                                                                               \
                MATRIX->elements.TYPE[i * MATRIX->cols + j]-=TMP->elements.TYPE[0] * MATRIX->elements.TYPE[k * MATRIX->cols + j];                \
                                                                                                                                                 \
                                                                                                                                                 \
            }                                                                                                                                    \
            B->elements.TYPE[i]-=TMP->elements.TYPE[0] * B->elements.TYPE[k];                                                                    \
        }                                                                                                                                        \
    }                                                                                                                                            \
    if(MATRIX->elements.TYPE[size(MATRIX)-1] == 0) return NULL;

Matrix *gaussian_elimination(Matrix *A, Matrix *b){

    DataType tmp_datatype;
    enum casted { Acasted, bcasted } casted;
        if (A->datatype > b->datatype) {
        tmp_datatype = b->datatype;
        matrix_typeconv(b, A->datatype);
        casted = bcasted;
        } 
        else {
        tmp_datatype = A->datatype;
        matrix_typeconv(A, b->datatype);
        casted = Acasted;
        }

    Matrix *tmp = new_matrix("tmp", 1, 1, A->datatype);

    switch(A->datatype){
        case short_int:     GAUSS_ELIMINATION(tmp, A, short_int, b)       break;
        case integer:       GAUSS_ELIMINATION(tmp, A, integer, b)         break;
        case floating:      GAUSS_ELIMINATION(tmp, A, floating, b)        break;
        case double_prec:   GAUSS_ELIMINATION(tmp, A, double_prec, b)     break;
    }

    Matrix *result = backwards_substitution(A, b);

    if (casted == Acasted)  matrix_typeconv(A, tmp_datatype);
    else    matrix_typeconv(b, tmp_datatype);
    
    return result;
}