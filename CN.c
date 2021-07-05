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
    return ((sizecmp(A, B) || 
    (A->MType==scalar) || B->MType == scalar) || 
    ((is_vector(A) || is_vector(B)) && (A->rows == B->rows || A->cols == B->cols)) ||
    ((is_vector(A) && is_vector(B)) && (A->rows == B->cols || A->cols == B->rows)) 
    );
}

MatrixType matrix_typeof(Matrix *A){
    if(A->rows == 1 && A->cols == 1) return scalar;
    else if(A->rows > 1 && A->cols > 1) return matrix;
    else if(A->rows == 1)  return row_vector;
    else if(A->cols == 1) return col_vector;
    else {printf("Invalid MatrixType, defaulting to scalar\n"); return scalar;}
}

#define INIT_ELEMENTS(NAME, TYPE, POINTER) \
    NAME->elements.TYPE = malloc(sizeof(*NAME->elements.TYPE) * size(NAME));  \
    for(int i=0; i< NAME->rows; i++) \
        for(int j=0; j< NAME->cols; j++) \
            NAME->elements.TYPE[i*NAME->cols + j] = POINTER.TYPE[i*NAME->cols + j];

void init_elements(Matrix *A, Pointer v) {
    switch (A->datatype){
        case short_int:     INIT_ELEMENTS(A, short_int, v);    break;
        case integer:       INIT_ELEMENTS(A, integer, v);      break;
        case floating:      INIT_ELEMENTS(A, floating, v);     break;
        case double_prec:   INIT_ELEMENTS(A, double_prec, v);  break;
    }
}

#define PROMPT_INIT_ELEMENTS(NAME, TYPE, FORMAT)                                \
    NAME->elements.TYPE = malloc(sizeof(*NAME->elements.TYPE) * size(NAME));    \
    for(int i=0; i< NAME->rows; i++) {                                          \
        printf("row %d:\n", i+1);                                               \
        for(int j=0; j< NAME->cols; j++) {                                      \
            scanf(FORMAT, &NAME->elements.TYPE[i*NAME->cols + j]);              \
            }                                                                   \
        fflush(stdin);                                                          \
    }

void prompt_init_elements(Matrix *A) {
    printf("\n>>\n");
    switch (A->datatype){
    case short_int:     PROMPT_INIT_ELEMENTS(A, short_int, "%hd");      break;
    case integer:       PROMPT_INIT_ELEMENTS(A, integer, "%d");         break;
    case floating:      PROMPT_INIT_ELEMENTS(A, floating, "%f");        break;
    case double_prec:   PROMPT_INIT_ELEMENTS(A, double_prec, "%lf");    break;
    }
}

Matrix *new_matrix(char *name, int rows, int cols, DataType t){
    Matrix *A = (Matrix*)malloc(sizeof(Matrix));
    strncpy(A->name, name, 15);
    A->rows = rows;
    A->cols = cols;
    
    A->MType = matrix_typeof(A);

    if(t > 4 || t < 1) {
        A->datatype = 2;
        perror("Invalid datatype, defaulting to integer\n"); 
    } else { A->datatype = t; }
    
    A->next = NULL;
    return A;
}

#define PRINT_MATRIX(NAME, FORMAT, TYPE)                                                     \
for(int i = 0; i<NAME->rows; i++){                                                           \
    printf("| ");                                                                            \
    for(int j = 0; j<NAME->cols; j++)                                                        \
        printf(FORMAT, NAME->elements.TYPE[i*NAME->cols + j]);                               \
    printf("|\n");                                                                           \
}

void print_matrix(Matrix *A){
    if (A == NULL) printf("NULL Matrix\n");
    else {
        printf("%s:\n", A->name);
        switch(A->datatype){
            case short_int:     PRINT_MATRIX(A, "%hd ", short_int);      break;
            case integer:       PRINT_MATRIX(A, "%d ", integer);         break;
            case floating:      PRINT_MATRIX(A, "%f ", floating);        break;
            case double_prec:   PRINT_MATRIX(A, "%lf ", double_prec);    break;
        }
    printf("\n");
    }
}

Matrix *prompt_matrix() {
    int rows, cols;
    char name[16];
    char datatype[16];
    printf("\ndatatype: ");             scanf("%s", datatype);
    printf("name: ");                   scanf("%s", name);
    printf("\nrows and columns:  ");    scanf("%d%d", &rows, &cols);

    Matrix *tmp = new_matrix(name, rows, cols, datatype_matrix_typeof(datatype));
    
    printf("\nInsert elements:");       
    prompt_init_elements(tmp);
    print_matrix(tmp);
    return tmp;

}

#define CONVERT(FROM, TO)                                                      \
  tmp.FROM = malloc(sizeof(*tmp.FROM) * size(A));                              \
  for (int i = 0; i < size(A); i++)                                            \
    tmp.FROM[i] = A->elements.FROM[i];                                         \
                                                                               \
  A->elements.TO = malloc(sizeof(*A->elements.TO) * size(A));                  \
  for (int i = 0; i < size(A); i++)                                            \
    A->elements.TO[i] = tmp.FROM[i];                                           \
  free(tmp.FROM);                                                              \
  A->datatype = TO                                                             \
 
void matrix_typeconv(Matrix *A, DataType to) {
  Pointer tmp;
  switch (to) {
  case short_int:
    switch (A->datatype) {
    case short_int:     break;
    case integer:       CONVERT(integer, short_int);     break;
    case floating:      CONVERT(integer, short_int);     break;
    case double_prec:   CONVERT(double_prec, short_int); break;
    } 
    break;

  case integer:
    switch (A->datatype) {
    case short_int:     CONVERT(short_int, integer);     break;
    case integer:       break;
    case floating:      CONVERT(floating, integer);      break;
    case double_prec:   CONVERT(double_prec, integer);   break;
    }
    break;

  case floating:
    switch (A->datatype) {
    case short_int:     CONVERT(short_int, floating);    break;
    case integer:       CONVERT(integer, floating);      break;
    case floating:      break;
    case double_prec:   CONVERT(double_prec, floating);  break;
    }
    break;

  case double_prec:
    switch (A->datatype) {
    case short_int:     CONVERT(short_int, double_prec);  break;
    case integer:       CONVERT(integer, double_prec);    break;
    case floating:      CONVERT(floating, double_prec);   break;
    case double_prec:   break;
    break;
        }
    }
}
#define ARITHMETIC_SUM(TYPE)                                                                                                        \
C->elements.TYPE = malloc(sizeof(*C->elements.TYPE)*size(C));                                                                       \
if( (A->MType != col_vector && B->MType != col_vector) ||                                                                           \
    (A->MType == col_vector && B->MType == col_vector) ||                                                                           \
    (A->MType == scalar || B->MType == scalar))                                                                                     \
                                                                                                                                    \
    for(int i=0; i< size(C); i++)                                                                                                   \
        C->elements.TYPE[i] = A->elements.TYPE[(i)%size(A)] + B->elements.TYPE[(i)%size(B)];                                        \
    else {                                                                                                                          \
        Matrix *non_col, *v_col;                                                                                                    \
        if(B->MType == col_vector) {non_col = A; v_col = B;} else {non_col = B; v_col = A;}                                         \
        for(int i=0; i< C->rows; i++)                                                                                               \
            for(int j=0; j< C->cols; j++)                                                                                           \
                C->elements.TYPE[(i*C->cols + j)] = non_col->elements.TYPE[(i*C->cols + j)%size(non_col)] + v_col->elements.TYPE[i];\
        }                                                                                                                           \
        
Matrix *matrix_sum(Matrix *A, Matrix *B){
    if(A!= NULL && B!=NULL && summable(A, B)){
        Matrix *C=malloc(sizeof(Matrix));        
        DataType tmp_datatype;
        enum casted { Acasted, Bcasted } casted;

        if(A->rows > B ->rows) C->rows = A->rows; else C->rows = B->rows;
        if(A->cols > B ->cols) C->cols = A->cols; else C->cols = B->cols;
        C->MType = matrix_typeof(C);
        strcpy(C->name, "ans");
        
        if (A->datatype > B->datatype) {
            C->datatype = A->datatype;
            tmp_datatype = B->datatype;
            matrix_typeconv(B, C->datatype);
            casted = Bcasted;
        } 
        else {
            C->datatype = B->datatype;
            tmp_datatype = A->datatype;
            matrix_typeconv(A, C->datatype);
            casted = Acasted;
        }

        switch(C->datatype){
            case short_int:     ARITHMETIC_SUM(short_int);      break;
            case integer:       ARITHMETIC_SUM(integer);        break;         
            case floating:      ARITHMETIC_SUM(floating);       break;             
            case double_prec:   ARITHMETIC_SUM(double_prec);    break;          
        }

        if (casted == Acasted)  matrix_typeconv(A, tmp_datatype);
        else    matrix_typeconv(B, tmp_datatype);        
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

DataType datatype_matrix_typeof(char *datatype) {
    if(strcmp(datatype, "short") == 0)  return short_int;
    if(strcmp(datatype, "int") == 0)        return integer;
    if(strcmp(datatype, "float") == 0)      return floating;
    if(strcmp(datatype, "double") == 0)     return double_prec;
    printf("Invalid datatype, defaulting to integer\n");
    return integer;
}

void print_info(Matrix *A) {
    if(A == NULL) printf("There is no such matrix");
    else{
        char *next = (char*)malloc(sizeof(char)*16);
        if(A->next != NULL) strcpy(next, A->next->name);
        else strcpy(next, "NULL");

        printf("%s: %dx%d %s %s, %s->%s",
        A->name,
        A->rows,
        A->cols,
        str_matrix_typeof(A),
        str_matrix_MTypeof(A),
        A->name,
        next);
    }
}

#define TRANSPOSE(TYPE)                                                             \
C->elements.TYPE = malloc(sizeof(*C->elements.TYPE) * size(A));                     \
for(int i = 0; i <A->rows; i++)                                                     \
    for(int j=0; j < A->cols; j++){                                                 \
        C->elements.TYPE[j * C->cols + i] = A->elements.TYPE[i * A->cols + j];      \
    }

Matrix *transpose(Matrix *A){
    if(A == NULL) return NULL;
    Matrix *C = new_matrix("ans", A->cols, A->rows, A->datatype);
    switch(A->datatype){
        case short_int:     TRANSPOSE(short_int);   break;
        case integer:       TRANSPOSE(integer);     break;
        case floating:      TRANSPOSE(floating);    break;
        case double_prec:   TRANSPOSE(double_prec); break;
    }
    return C;
}

#define ARITHMETIC_PROD(TYPE)                                                                                   \
  if (rccmp(A, B)) {                                                                                            \
    Pointer sum;                                                                                                \
    C->rows = A->rows;                                                                                          \
    C->cols = B->cols;                                                                                          \
    C->elements.TYPE = malloc(sizeof(*C->elements.TYPE) * size(C));                                             \
    sum.TYPE = malloc(sizeof(*sum.TYPE));                                                                       \
    for (int i = 0; i < C->rows; i++) {                                                                         \
      for (int j = 0; j < C->cols; j++) {                                                                       \
        *sum.TYPE = 0;                                                                                          \
        for (int k = 0; k < A->cols; k++)                                                                       \
          *sum.TYPE += A->elements.TYPE[i * A->cols + k]*B->elements.TYPE[k * B->cols + j];                     \
                                                                                                                \
        C->elements.TYPE[i * C->cols + j] = *sum.TYPE;                                                          \
      }                                                                                                         \
    }                                                                                                           \
    free(sum.TYPE);                                                                                             \
  } else {                                                                                                      \
    if (A->rows > B->rows) C->rows = A->rows; else C->rows = B->rows;                                           \
    if (A->cols > B->cols) C->cols = A->cols; else C->cols = B->cols;                                           \
                                                                                                                \
    C->elements.TYPE = malloc(sizeof(*C->elements.TYPE) * size(C));                                             \
    for (int i = 0; i < size(C); i++)                                                                           \
        C->elements.TYPE[i] =   A->elements.TYPE[(i) % size(A)] * B->elements.TYPE[(i) % size(B)];              \
      }                                                                                                         \
                                                                                                               

Matrix *matrix_prod(Matrix *A, Matrix *B) {
  if (( (A != NULL && B!= NULL) && 
        (rccmp(A, B) || A->MType == scalar || B->MType == scalar))) {

    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    DataType tmp_datatype;
    enum casted { Acasted, Bcasted } casted;

    if (A->datatype > B->datatype) {
        C->datatype = A->datatype;
        tmp_datatype = B->datatype;
        matrix_typeconv(B, C->datatype);
        casted = Bcasted;
    } 
    else {
        C->datatype = B->datatype;
        tmp_datatype = A->datatype;
        matrix_typeconv(A, C->datatype);
        casted = Acasted;
    }

    switch (C->datatype) {
    case short_int:     ARITHMETIC_PROD(short_int)      break;
    case integer:       ARITHMETIC_PROD(integer)        break;
    case floating:      ARITHMETIC_PROD(floating)       break;
    case double_prec:   ARITHMETIC_PROD(double_prec)    break;
    }

    C->MType = matrix_typeof(C);
    strcpy(C->name, "ans");
    if (casted == Acasted)  matrix_typeconv(A, tmp_datatype);
    else    matrix_typeconv(B, tmp_datatype);
    return C;
  }
  return NULL;
}

#define DOT_PRODUCT(TYPE)                            \
C->elements.TYPE = malloc(sizeof(*C->elements.TYPE));\
C->elements.TYPE[0] = 0;                             \
for(int i=0; i < size(A); i++)                       \
    C->elements.TYPE[0] += A->elements.TYPE[i] * B->elements.TYPE[i];

Matrix *dot_product(Matrix *A, Matrix *B){
    if(A!=NULL && B!=NULL && is_vector(A) && is_vector(B) && size(A) == size(B)){
    
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    DataType tmp_datatype;
    enum casted { Acasted, Bcasted } casted;

        if (A->datatype > B->datatype) {
        tmp_datatype = B->datatype;
        matrix_typeconv(B, A->datatype);
        casted = Bcasted;
        } 
        else {
        tmp_datatype = A->datatype;
        matrix_typeconv(A, B->datatype);
        casted = Acasted;
        }

    C = new_matrix("ans", 1, 1, A->datatype);
    switch(C->datatype){
        case short_int:     DOT_PRODUCT(short_int);     break;
        case integer:       DOT_PRODUCT(integer);       break;
        case floating:      DOT_PRODUCT(floating);      break;
        case double_prec:   DOT_PRODUCT(double_prec);   break;
    }
    return C;
    }
    return NULL;
}

#define V_TENSOR_PROD(TYPE)\
C->elements.TYPE = malloc(sizeof(*C->elements.TYPE)*size(C));\
    for(int i = 0; i < size(A); i++)\
        for(int j = 0; j < size(B); j++)\
            C->elements.TYPE[i * C->cols + j] = A->elements.TYPE[i] * B->elements.TYPE[j];

Matrix *v_tensor_prod(Matrix *A, Matrix *B) {
    if(A!=NULL && B!=NULL && is_vector(A) && is_vector(B)){
        DataType tmp_datatype;
        enum casted { Acasted, Bcasted } casted;
            if (A->datatype > B->datatype) {
                tmp_datatype = B->datatype;
                matrix_typeconv(B, A->datatype);
                casted = Bcasted;
            } else {
                tmp_datatype = A->datatype;
                matrix_typeconv(A, B->datatype);
                casted = Acasted;
            }
        
        Matrix *C = malloc(sizeof(Matrix));
        C = new_matrix("ans", size(A), size(B), A->datatype);
        switch(C->datatype){
            case short_int:     V_TENSOR_PROD(short_int);     break;
            case integer:       V_TENSOR_PROD(integer);       break;
            case floating:      V_TENSOR_PROD(floating);      break;
            case double_prec:   V_TENSOR_PROD(double_prec);   break;
        }
        return C;
    }
    return NULL;
}

#define MATRIX_AVERAGE(TYPE)   \
    ans = new_matrix("ans", 1, 1, TYPE);   \
    ans->elements.TYPE = malloc(sizeof(*ans->elements.TYPE) * size(ans));   \
    sum.TYPE = malloc(sizeof(TYPE));   \
    *sum.TYPE = 0;   \
    for(int i = 0; i < size(A); i++){   \
        *sum.TYPE += A->elements.TYPE[i];}   \
    ans->elements.TYPE[0] = (*sum.TYPE)/size(A);

Matrix *matrix_average(Matrix *A) {
    Matrix *ans;
    Pointer sum;

    switch(A->datatype) {
        case short_int:     MATRIX_AVERAGE(short_int);      break;
        case integer:       MATRIX_AVERAGE(integer);        break;
        case floating:      MATRIX_AVERAGE(floating);       break;
        case double_prec:   MATRIX_AVERAGE(double_prec);    break;
    }
    return ans;
}

#define MATRIX_SEQ_PROD(TYPE)   \
    ans = new_matrix("ans", 1, 1, TYPE);   \
    ans->elements.TYPE = malloc(sizeof(*ans->elements.TYPE) * size(ans));   \
    prod.TYPE = malloc(sizeof(TYPE));   \
    *prod.TYPE = 1;   \
    for(int i = 0; i < size(A); i++){   \
        *prod.TYPE *= A->elements.TYPE[i];}   \
    ans->elements.TYPE[0] = *prod.TYPE;

Matrix *matrix_seq_prod(Matrix *A) {
    Matrix *ans;
    Pointer prod;

    switch(A->datatype) {
        case short_int:     MATRIX_SEQ_PROD(short_int);      break;
        case integer:       MATRIX_SEQ_PROD(integer);        break;
        case floating:      MATRIX_SEQ_PROD(floating);       break;
        case double_prec:   MATRIX_SEQ_PROD(double_prec);    break;
    }
    return ans;

}

#define MATRIX_SEQ_SUM(TYPE)   \
    ans = new_matrix("ans", 1, 1, TYPE);   \
    ans->elements.TYPE = malloc(sizeof(*ans->elements.TYPE) * size(ans));   \
    sum.TYPE = malloc(sizeof(TYPE));   \
    *sum.TYPE = 0;   \
    for(int i = 0; i < size(A); i++){   \
        *sum.TYPE += A->elements.TYPE[i];}   \
    ans->elements.TYPE[0] = *sum.TYPE;

Matrix *matrix_seq_sum(Matrix *A) {
    Matrix *ans;
    Pointer sum;

    switch(A->datatype) {
        case short_int:     MATRIX_SEQ_SUM(short_int);      break;
        case integer:       MATRIX_SEQ_SUM(integer);        break;
        case floating:      MATRIX_SEQ_SUM(floating);       break;
        case double_prec:   MATRIX_SEQ_SUM(double_prec);    break;
    }
    return ans;

}

#define VEC_NORM1(VECTOR, VECTYPE, ANS, ANSTYPE)                                \
ANS->elements.ANSTYPE = malloc(sizeof(*ANS->elements.ANSTYPE));             \
ANS->elements.ANSTYPE[0] = 0;                                               \
for(int i = 0; i < size(VECTOR); i++)                                       \
    if(VECTOR->elements.VECTYPE[i] < 0)                                     \
        ANS->elements.ANSTYPE[0] -= VECTOR->elements.VECTYPE[i];            \
    else                                                                    \
        ANS->elements.ANSTYPE[0] += VECTOR->elements.VECTYPE[i];

Matrix *vec_norm1(Matrix *A, DataType type){
    Matrix *tmp = new_matrix("ans", 1, 1, type);
    
    switch(A->datatype){
        case short_int:
            switch(type){
            case short_int:     VEC_NORM1(A, short_int, tmp, short_int);   break;
            case integer:       VEC_NORM1(A, short_int, tmp, integer);     break;
            case floating:      VEC_NORM1(A, short_int, tmp, floating);    break;
            case double_prec:   VEC_NORM1(A, short_int, tmp, double_prec); break;
        }
        break;
        
        case integer:
            switch(type){
            case short_int:     VEC_NORM1(A, integer, tmp, short_int);   break;
            case integer:       VEC_NORM1(A, integer, tmp, integer);     break;
            case floating:      VEC_NORM1(A, integer, tmp, floating);    break;
            case double_prec:   VEC_NORM1(A, integer, tmp, double_prec); break;
        }
        break;

        case floating:
            switch(type){
            case short_int:     VEC_NORM1(A, floating, tmp, short_int);   break;
            case integer:       VEC_NORM1(A, floating, tmp, integer);     break;
            case floating:      VEC_NORM1(A, floating, tmp, floating);    break;
            case double_prec:   VEC_NORM1(A, floating, tmp, double_prec); break;
        }
        break;

        case double_prec:
            switch(type){
            case short_int:     VEC_NORM1(A, double_prec, tmp, short_int);   break;
            case integer:       VEC_NORM1(A, double_prec, tmp, integer);     break;
            case floating:      VEC_NORM1(A, double_prec, tmp, floating);    break;
            case double_prec:   VEC_NORM1(A, double_prec, tmp, double_prec); break;
        }
        break;
    }
    return tmp;
}

#define VEC_NORM2(VECTOR, VECTYPE, ANS, ANSTYPE)                                                   \
ANS->elements.ANSTYPE = malloc(sizeof(*ANS->elements.ANSTYPE));                                \
ANS->elements.ANSTYPE[0] = 0;                                                                  \
for(int i = 0; i < size(VECTOR); i++)                                                          \
    ANS->elements.ANSTYPE[0] += VECTOR->elements.VECTYPE[i] * VECTOR->elements.VECTYPE[i];     \
ANS->elements.ANSTYPE[0] = sqrt(ANS->elements.ANSTYPE[0]);

Matrix *vec_norm2(Matrix *A, DataType type){
    Matrix *tmp = new_matrix("ans", 1, 1, type);
    
    switch(A->datatype){
        case short_int:
            switch(type){
            case short_int:     VEC_NORM2(A, short_int, tmp, short_int);   break;
            case integer:       VEC_NORM2(A, short_int, tmp, integer);     break;
            case floating:      VEC_NORM2(A, short_int, tmp, floating);    break;
            case double_prec:   VEC_NORM2(A, short_int, tmp, double_prec); break;
        }
        break;
        
        case integer:
            switch(type){
            case short_int:     VEC_NORM2(A, integer, tmp, short_int);   break;
            case integer:       VEC_NORM2(A, integer, tmp, integer);     break;
            case floating:      VEC_NORM2(A, integer, tmp, floating);    break;
            case double_prec:   VEC_NORM2(A, integer, tmp, double_prec); break;
        }
        break;

        case floating:
            switch(type){
            case short_int:     VEC_NORM2(A, floating, tmp, short_int);   break;
            case integer:       VEC_NORM2(A, floating, tmp, integer);     break;
            case floating:      VEC_NORM2(A, floating, tmp, floating);    break;
            case double_prec:   VEC_NORM2(A, floating, tmp, double_prec); break;
        }
        break;

        case double_prec:
            switch(type){
            case short_int:     VEC_NORM2(A, double_prec, tmp, short_int);   break;
            case integer:       VEC_NORM2(A, double_prec, tmp, integer);     break;
            case floating:      VEC_NORM2(A, double_prec, tmp, floating);    break;
            case double_prec:   VEC_NORM2(A, double_prec, tmp, double_prec); break;
        }
        break;
    }
    return tmp;
}

#define VEC_NORM_INF(VECTOR, VECTYPE, ANS, ANSTYPE)                                                   \
ANS->elements.ANSTYPE = malloc(sizeof(*ANS->elements.ANSTYPE));                                   \
ANS->elements.ANSTYPE[0] = 0;                                                                     \
for(int i = 0; i < size(VECTOR); i++){                                                            \
    if(VECTOR->elements.VECTYPE[i] > 0){                                                          \
        if(VECTOR->elements.VECTYPE[i] > ANS->elements.ANSTYPE[0])                                \
            ANS->elements.ANSTYPE[0] = VECTOR->elements.VECTYPE[i];                               \
        }                                                                                         \
    else                                                                                          \
        if(-VECTOR->elements.VECTYPE[i] > ANS->elements.ANSTYPE[0])                               \
            ANS->elements.ANSTYPE[0] = -VECTOR->elements.VECTYPE[i];                              \
}
Matrix *vec_norm_inf(Matrix *A, DataType type){
    Matrix *tmp = new_matrix("ans", 1, 1, type);
    
    switch(A->datatype){
        case short_int:
            switch(type){
            case short_int:     VEC_NORM_INF(A, short_int, tmp, short_int);   break;
            case integer:       VEC_NORM_INF(A, short_int, tmp, integer);     break;
            case floating:      VEC_NORM_INF(A, short_int, tmp, floating);    break;
            case double_prec:   VEC_NORM_INF(A, short_int, tmp, double_prec); break;
        }
        break;
        
        case integer:
            switch(type){
            case short_int:     VEC_NORM_INF(A, integer, tmp, short_int);   break;
            case integer:       VEC_NORM_INF(A, integer, tmp, integer);     break;
            case floating:      VEC_NORM_INF(A, integer, tmp, floating);    break;
            case double_prec:   VEC_NORM_INF(A, integer, tmp, double_prec); break;
        }
        break;

        case floating:
            switch(type){
            case short_int:     VEC_NORM_INF(A, floating, tmp, short_int);   break;
            case integer:       VEC_NORM_INF(A, floating, tmp, integer);     break;
            case floating:      VEC_NORM_INF(A, floating, tmp, floating);    break;
            case double_prec:   VEC_NORM_INF(A, floating, tmp, double_prec); break;
        }
        break;

        case double_prec:
            switch(type){
            case short_int:     VEC_NORM_INF(A, double_prec, tmp, short_int);   break;
            case integer:       VEC_NORM_INF(A, double_prec, tmp, integer);     break;
            case floating:      VEC_NORM_INF(A, double_prec, tmp, floating);    break;
            case double_prec:   VEC_NORM_INF(A, double_prec, tmp, double_prec); break;
        }
        break;
    }
    return tmp;
}


#define MATRIX_NORM1(MATRIX, MATRIXTYPE, ANS, ANSTYPE)                                              \
ANS->elements.ANSTYPE = malloc(sizeof(*ANS->elements.ANSTYPE));                                     \
max.ANSTYPE = malloc(sizeof(*max.ANSTYPE));                                                         \
ANS->elements.ANSTYPE[0] = 0;                                                                       \
    for(int j = 0; j < MATRIX->cols; j++){                                                          \
        max.ANSTYPE[0] = 0;                                                                         \
        for(int i = 0; i < MATRIX->rows; i++)                                                       \
            if (MATRIX->elements.MATRIXTYPE[i * MATRIX->cols + j] > 0)                              \
                max.ANSTYPE[0] += MATRIX->elements.MATRIXTYPE[i * MATRIX->cols + j];                \
            else                                                                                    \
                max.ANSTYPE[0] -= MATRIX->elements.MATRIXTYPE[i * MATRIX->cols + j];                \
        if(max.ANSTYPE[0] > ANS->elements.ANSTYPE[0]) ANS->elements.ANSTYPE[0] = max.ANSTYPE[0];    \
    } free(max.ANSTYPE);

Matrix *matrix_norm1(Matrix *A, DataType type){
    Matrix *result = new_matrix("ans", 1, 1, type);
    Pointer max;


    switch(A->datatype){
        case short_int:
            switch(type){
            case short_int:     MATRIX_NORM1(A, short_int, result, short_int);   break;
            case integer:       MATRIX_NORM1(A, short_int, result, integer);     break;
            case floating:      MATRIX_NORM1(A, short_int, result, floating);    break;
            case double_prec:   MATRIX_NORM1(A, short_int, result, double_prec); break;
        }
        break;
        
        case integer:
            switch(type){
            case short_int:     MATRIX_NORM1(A, integer, result, short_int);   break;
            case integer:       MATRIX_NORM1(A, integer, result, integer);     break;
            case floating:      MATRIX_NORM1(A, integer, result, floating);    break;
            case double_prec:   MATRIX_NORM1(A, integer, result, double_prec); break;
        }
        break;

        case floating:
            switch(type){
            case short_int:     MATRIX_NORM1(A, floating, result, short_int);   break;
            case integer:       MATRIX_NORM1(A, floating, result, integer);     break;
            case floating:      MATRIX_NORM1(A, floating, result, floating);    break;
            case double_prec:   MATRIX_NORM1(A, floating, result, double_prec); break;
        }
        break;

        case double_prec:
            switch(type){
            case short_int:     MATRIX_NORM1(A, double_prec, result, short_int);   break;
            case integer:       MATRIX_NORM1(A, double_prec, result, integer);     break;
            case floating:      MATRIX_NORM1(A, double_prec, result, floating);    break;
            case double_prec:   MATRIX_NORM1(A, double_prec, result, double_prec); break;
        }
        break;
    }
    return result;
}


#define RANDOM_MATRIX(MATRIX, ROWS, COLS, TYPE, MIN, MAX)                                             \
MATRIX->elements.TYPE = malloc(sizeof(*MATRIX->elements.TYPE)*size(MATRIX));                \
for(int i=0; i<ROWS; i++)                                                                   \
    for(int j=0; j<COLS; j++)                                                               \
        MATRIX->elements.TYPE[i * COLS + j] = (fabs(MAX)+ fabs(MIN)) * ((double)rand()/(double)(RAND_MAX)) - fabs(MIN);


Matrix *random_matrix(int rows, int cols, DataType type, double range[]){
    Matrix *A = new_matrix("ans", rows, cols, type);

            switch(type){
                case short_int:     RANDOM_MATRIX(A, rows, cols, short_int,     range[0] , range[1]);      break;
                case integer:       RANDOM_MATRIX(A, rows, cols, integer,       range[0] , range[1]);      break;
                case floating:      RANDOM_MATRIX(A, rows, cols, floating,      range[0] , range[1]);      break;
                case double_prec:   RANDOM_MATRIX(A, rows, cols, double_prec,   range[0] , range[1]);      break;
            }
    return A;
}

#define HILBERT(MATRIX, TYPE)                                                   \
MATRIX->elements.TYPE = malloc(sizeof(*MATRIX->elements.TYPE)*size(MATRIX));    \
for(int i = 0; i < MATRIX->rows; i++)                                           \
    for(int j = 0; j < MATRIX -> cols; j++)                                     \
        MATRIX->elements.TYPE[i * MATRIX->cols + j] = (float)1 / (i + j + 1);    

Matrix *hilbert(int n, DataType type){
    if (n <= 0) return NULL;
    
    Matrix *A = new_matrix("ans", n, n, type);
  
       switch(type){
        case short_int:   HILBERT(A, short_int);    break;
        case integer:     HILBERT(A, integer);      break;
        case floating:    HILBERT(A, floating);     break;
        case double_prec: HILBERT(A, double_prec);  break;

    }

    return A;
}
