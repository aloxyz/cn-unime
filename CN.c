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
        printf("row %d:\n", i);                                                 \
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
    if (A == NULL);
    else {
        printf("%s:\n", A->name);
        switch(A->datatype){
            case short_int:     PRINT_MATRIX(A, "%hd ", short_int);      break;
            case integer:       PRINT_MATRIX(A, "%d ", integer);         break;
            case floating:      PRINT_MATRIX(A, "%f ", floating);        break;
            case double_prec:   PRINT_MATRIX(A, "%lf ", double_prec);    break;
        }
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
    
    printf("\nInsert elements:");       prompt_init_elements(tmp);
    
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

        print_matrix(C);
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
    if(strcmp(datatype, "short_int") == 0)  return short_int;
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