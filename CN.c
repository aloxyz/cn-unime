#include"CN.h"

//general purpose functions

int size(Matrix *A){
    return(A->rows * A->cols);
}

int is_vector(Matrix *A){
    return(A->MType == row_vector || A->MType == col_vector);
}

int sizecmp(Matrix *A, Matrix *B){
    return ((A->rows == B->rows) && (A->cols == B->cols));
}

int rccmp(Matrix *A, Matrix *B){
    return (A->cols == B->rows);
}


int summable(Matrix *A, Matrix *B){
    return ((sizecmp(A, B) || (A->MType==scalar) || B->MType == scalar) || ((is_vector(A) || is_vector(B)) && (A->rows == B->rows || A->cols == B->cols)));
}

MatrixType matrix_typeof(Matrix *A){
    if(A->rows == 1 && A->cols == 1) return scalar;
    else if(A->rows > 1 && A->cols > 1) return matrix;
    else if(A->rows == 1)  return row_vector;
    else if(A->cols == 1) return col_vector;
    else {printf("Invalid MatrixType, defaulting to scalar\n"); return scalar;}
}

void init_elements(Matrix *A, Pointer v) {
    switch (A->datatype){
        case short_int:
            A->elements.short_int = (short int*)malloc(sizeof(short int)*A->rows*A->cols); 
            for(int i=0; i< A->rows; i++) {
                for(int j=0; j< A->cols; j++)
                    A->elements.short_int[i*A->cols + j] = v.short_int[i*A->cols + j];
        }
        break;

        case integer:
            A->elements.integer = (int*)malloc(sizeof(int)*A->rows*A->cols); 
            for(int i=0; i< A->rows; i++) {
                for(int j=0; j< A->cols; j++){
                    A->elements.integer[i*A->cols + j] = v.integer[i*A->cols + j];
                }
            }
        break;

        case floating:
            A->elements.floating = (float*)malloc(sizeof(float)*A->rows*A->cols); 
            for(int i=0; i< A->rows; i++) {
                for(int j=0; j< A->cols; j++)
                    A->elements.floating[i*A->cols + j] = v.floating[i*A->cols + j];
            }
        break;

        case double_prec:
            A->elements.double_prec = (double*)malloc(sizeof(double)*A->rows*A->cols); 
            for(int i=0; i< A->rows; i++) {
                for(int j=0; j< A->cols; j++)
                    A->elements.integer[i*A->cols + j] = v.double_prec[i*A->cols + j];
        }

        break;
    }
}

void prompt_init_elements(Matrix *A) {
    printf("\n>>\n");
    switch(A->datatype){
        case short_int:
            A->elements.short_int = (short int*)malloc(sizeof(short int)*A->rows*A->cols); 
            for(int i=0; i< A->rows; i++) {
                printf("row %d:\n", i);
                for(int j=0; j< A->cols; j++) { 
                    scanf("%hd", &A->elements.short_int[i*A->cols + j]);
                    }
                fflush(stdin);
            }
            break;

        case integer:
            A->elements.integer = (int*)malloc(sizeof(int)*A->rows*A->cols); 
            for(int i=0; i< A->rows; i++) {
                printf("row %d:\n", i);
                for(int j=0; j< A->cols; j++) { 
                    scanf("%d", &A->elements.integer[i*A->cols + j]);
                }
                fflush(stdin);
            }
            break;

        case floating:
            A->elements.floating = (float*)malloc(sizeof(int)*A->rows*A->cols); 
            for(int i=0; i< A->rows; i++) {
                printf("row %d:\n", i);
                for(int j=0; j< A->cols; j++) { 
                    scanf("%f", &A->elements.floating[i*A->cols + j]);
                }
                fflush(stdin);
            }
            break;

        case double_prec:
            A->elements.double_prec = (double*)malloc(sizeof(int)*A->rows*A->cols); 
            for(int i=0; i< A->rows; i++) {
                printf("row %d:\n", i);
                for(int j=0; j< A->cols; j++) { 
                    scanf("%lf", &A->elements.double_prec[i*A->cols + j]);
                }
                fflush(stdin);
            }
            break;
    }
}

Matrix *new_matrix(char *name, int rows, int cols, DataType t){
    Matrix *A = (Matrix*)malloc(sizeof(Matrix));
    strncpy(A->name, name, 15);
    A->rows = rows;
    A->cols = cols;
    
    A->MType = matrix_typeof(A);

    if(t > 4 || t < 1) {
        A->datatype = 4;
        perror("Invalid datatype, defaulting to double_prec\n"); 
    } else { A->datatype = t; }
    
    return A;
}

void print_matrix(Matrix *A){
    if (A == NULL);
    else {
        printf("%s:\n", A->name);
        switch(A->datatype){
            case short_int:
                    for(int i = 0; i<A->rows; i++){
                        printf("| ");
                        for(int j = 0; j<A->cols; j++)
                            printf("%hd ", A->elements.short_int[i*A->cols + j]);
                        printf("|\n");
                    }
                    break;

            case integer: 
                    for(int i = 0; i<A->rows; i++){
                        printf("| ");
                        for(int j = 0; j<A->cols; j++)
                            printf("%d ", A->elements.integer[i*A->cols + j]);
                        printf("|\n");
                    }
                    break;
            
            case floating:
                    for(int i = 0; i<A->rows; i++){
                        printf("| ");
                        for(int j = 0; j<A->cols; j++)
                            printf("%f ", A->elements.floating[i*A->cols + j]);
                        printf("|\n");
                    }
                    break;

            case double_prec:
                    for(int i = 0; i<A->rows; i++){
                        printf("| ");
                        for(int j = 0; j<A->cols; j++)
                            printf("%lf ", A->elements.double_prec[i*A->cols + j]);
                        printf("|\n");
                    }
                    break;
        }
    }

}

Matrix *prompt_matrix() {
    int rows, cols, t;
    char name[16];
    printf("New matrix\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Rows and columns separated by space:\n>> ");
    scanf("%d%d", &rows, &cols);
    printf("\nDatatype:\n1.short_int\n2.integer\n3.floating\n4.double_prec\n>> ");
    scanf("%d", &t);
    Matrix *tmp = new_matrix(name, rows, cols, t);
    printf("\nInsert elements:");
    prompt_init_elements(tmp);
    print_matrix(tmp);
    return tmp;

}

void cast_matrix(Matrix *A, DataType datatype){
    Pointer tmp = A->elements;
    switch(A->datatype){
        case short_int:
            switch(datatype){
                case short_int: break;
                case integer: 
                            A->elements.integer = (int*)malloc(sizeof(int)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.integer[i] = (int)tmp.short_int[i];
                            break;
                case floating:
                            A->elements.floating = (float*)malloc(sizeof(float)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.floating[i] = (float)tmp.short_int[i];
                            break;
                case double_prec:
                            A->elements.double_prec = (double*)malloc(sizeof(double)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.double_prec[i] = (double)tmp.short_int[i];
            break;
            }
        case integer:
            switch(datatype){
                case short_int: 
                            A->elements.short_int = (short int*)malloc(sizeof(int)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.integer[i] = (int)tmp.integer[i];
                            break;
                case integer: break;
                case floating:
                            A->elements.floating = (float*)malloc(sizeof(float)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.floating[i] = (float)tmp.integer[i];
                            break;
                case double_prec:
                            A->elements.double_prec = (double*)malloc(sizeof(double)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.double_prec[i] = (double)tmp.integer[i];
            break;
            }
        case floating:
            switch(datatype){
                case short_int: 
                            A->elements.short_int = (short int*)malloc(sizeof(short int)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.integer[i] = (short int)tmp.floating[i];
                            break;
                case integer:
                            A->elements.floating = (float*)malloc(sizeof(float)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.integer[i] = (int)tmp.floating[i];
                            break;
                case floating: break;
                case double_prec:
                            A->elements.double_prec = (double*)malloc(sizeof(double)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.double_prec[i] = (double)tmp.floating[i];
            break;
            }
        case double_prec:
            switch(datatype){
                case short_int: 
                            A->elements.short_int = (short int*)malloc(sizeof(short int)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.short_int[i] = (short int)tmp.double_prec[i];
                            break;
                case integer:
                            A->elements.integer = (int*)malloc(sizeof(int)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.integer[i] = (int)tmp.double_prec[i];
                            break;
                case floating:
                            A->elements.floating = (float*)malloc(sizeof(float)*A->cols*A->rows);
                            for(int i=0; i<size(A); i++) A->elements.floating[i] = (float)tmp.double_prec[i];
                case double_prec: break;
            break;
            }
    }

}

Matrix *matrix_sum(Matrix *A, Matrix *B){
    Matrix *C=(Matrix*)malloc(sizeof(Matrix));
    if(summable(A, B)){
        if(A->rows > B ->rows) C->rows = A->rows; else C->rows = B->rows;
        if(A->cols > B ->cols) C->cols = A->cols; else C->cols = B->cols;
        if(A->datatype > B->datatype) C->datatype = A->datatype; else C->datatype = B->datatype;
        C->MType = matrix_typeof(C);
        strcpy(C->name, "ans");
        cast_matrix(A, C->datatype);
        cast_matrix(B, C->datatype);
        
        switch(C->datatype){
            case short_int:
                C->elements.short_int=(short int*)malloc(sizeof(short int)*C->rows*C->cols);
                break;
            case integer:
                C->elements.integer=(int*)malloc(sizeof(int)*C->rows*C->cols);
                break;

            case floating:
                C->elements.floating=(float*)malloc(sizeof(float)*C->rows*C->cols);
                break;

            case double_prec:
                C->elements.double_prec=(double*)malloc(sizeof(double)*C->rows*C->cols);
                break;
        }
        
        if((A->MType != col_vector && B->MType != col_vector) || (A->MType == col_vector && B->MType == col_vector) || (A->MType == scalar || B->MType == scalar)){
            for(int i=0; i< size(C); i++)
                C->elements.short_int[i] = A->elements.short_int[(i)%size(A)] + B->elements.short_int[(i)%size(B)];
        }
        else {
        Matrix *non_col, *v_col;
        if(B->MType == col_vector) {non_col = A; v_col = B;} else {non_col = B; v_col = A;} 
            for(int i=0; i< C->rows; i++)
                for(int j=0; j< C->cols; j++) 
                     C->elements.short_int[(i*C->cols + j)] = non_col->elements.short_int[(i*C->cols + j)%size(C)] + v_col->elements.short_int[i]; 
        }
        print_matrix(C);
        return C;
    }
    else{
        
        return NULL;
    }
}

char *str_matrix_MTypeof(Matrix *A) {
    switch (A->MType) {
        case row_vector:
        return "row_vector";
        break;
        
        case col_vector:
        return "col_vector";
        break;
        
        case scalar:
        return "scalar";
        break;
        
        case matrix:
        return "matrix";
        break;
    }
}

char *str_matrix_typeof(Matrix *A) {
    switch (A->datatype) {
        case short_int:
        return "short_int";
        break;
        
        case integer:
        return "integer";
        break;
        
        case floating:
        return "floating";
        break;
        
        case double_prec:
        return "double_prec";
        break;
    }
}

void print_info(Matrix *A) {
    char *next = "NULL";
    if(A->next != NULL) strcpy(next, A->next->name);

    printf("%s: %dx%d %s %s, %s->%s",
    A->name,
    A->rows,
    A->cols,
    str_matrix_typeof(A),
    str_matrix_MTypeof(A),
    A->name,
    next);
}