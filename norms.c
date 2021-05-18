#include "CN.h"
#include <stdlib.h>
#include <math.h>

Matrix *norm1(Matrix *A, DataType type);
Matrix *norm2(Matrix *A, DataType type);
Matrix *norm_inf(Matrix *A, DataType type);
Matrix *p_norm(Matrix *A, unsigned long long n, DataType type);
Matrix *vectorial_norm(Matrix *A, char *n, DataType type);

int main(){
//the following lines until the next comment initializes 8 vectors, 4 rows and 4 cols of every type. Each of 5 elements ranging from 1 to 5

    Matrix* shortV = new_matrix("shortRow", 1, 5, short_int);
    Matrix* intV = new_matrix("intRow", 1, 5, integer);
    Matrix* floatingV = new_matrix("floatingRow", 1, 5, floating);
    Matrix* doubleV = new_matrix("doubleRow", 1, 5, double_prec);
    short shortp[] = {1,2,3,4,5};
    int   intp[] = {1,2,3,4,5};
    float floatp[] = {1,2,3,4,5};
    double doublep[] = {1,2,3,4,5};

    Pointer shortP, intP, floatP, doubleP;
    shortP.short_int = shortp;
    intP.integer = intp;
    floatP.floating = floatp;
    doubleP.double_prec = doublep;

    init_elements(shortV, shortP);
    init_elements(intV, intP);
    init_elements(floatingV, floatP);
    init_elements(doubleV, doubleP);

    Matrix* shortW = new_matrix("shortCol", 1, 5, short_int);
    Matrix* intW = new_matrix("intCol", 1, 5, integer);
    Matrix* floatingW = new_matrix("floatingCol", 1, 5, floating);
    Matrix* doubleW = new_matrix("doubleCol", 1, 5, double_prec);

    init_elements(shortW, shortP);
    init_elements(intW, intP);
    init_elements(floatingW, floatP);
    init_elements(doubleW, doubleP);

//The following lines test norm1 for every vector declared above, for each type
    puts("Short row");
    print_matrix(norm_inf(shortV, short_int));
    print_matrix(norm_inf(shortV, integer));
    print_matrix(norm_inf(shortV, floating));
    print_matrix(norm_inf(shortV, double_prec));

    puts("integer row");
    print_matrix(norm_inf(intV, short_int));
    print_matrix(norm_inf(intV, integer));
    print_matrix(norm_inf(intV, floating));
    print_matrix(norm_inf(intV, double_prec));

    puts("float row");
    print_matrix(norm_inf(floatingV, short_int));
    print_matrix(norm_inf(floatingV, integer));
    print_matrix(norm_inf(floatingV, floating));
    print_matrix(norm_inf(floatingV, double_prec));

    puts("double row");
    print_matrix(norm_inf(doubleV, short_int));
    print_matrix(norm_inf(doubleV, integer));
    print_matrix(norm_inf(doubleV, floating));
    print_matrix(norm_inf(doubleV, double_prec));

    puts("Short column");
    print_matrix(norm_inf(shortW, short_int));
    print_matrix(norm_inf(shortW, integer));
    print_matrix(norm_inf(shortW, floating));
    print_matrix(norm_inf(shortW, double_prec));

    puts("integer column");
    print_matrix(norm_inf(intW, short_int));
    print_matrix(norm_inf(intW, integer));
    print_matrix(norm_inf(intW, floating));
    print_matrix(norm_inf(intW, double_prec));

    puts("float column");
    print_matrix(norm_inf(floatingW, short_int));
    print_matrix(norm_inf(floatingW, integer));
    print_matrix(norm_inf(floatingW, floating));
    print_matrix(norm_inf(floatingW, double_prec));

    puts("double column");
    print_matrix(norm_inf(doubleW, short_int));
    print_matrix(norm_inf(doubleW, integer));
    print_matrix(norm_inf(doubleW, floating));
    print_matrix(norm_inf(doubleW, double_prec));

    return 0;
}

#define NORM1(VECTOR, VECTYPE, ANS, ANSTYPE)                                \
ANS->elements.ANSTYPE = malloc(sizeof(*ANS->elements.ANSTYPE));             \
ANS->elements.ANSTYPE[0] = 0;                                               \
for(int i = 0; i < size(VECTOR); i++)                                       \
    if(VECTOR->elements.VECTYPE[i] < 0)                                     \
        ANS->elements.ANSTYPE[0] -= VECTOR->elements.VECTYPE[i];            \
    else                                                                    \
        ANS->elements.ANSTYPE[0] += VECTOR->elements.VECTYPE[i];

Matrix *norm1(Matrix *A, DataType type){
    Matrix *tmp = new_matrix("ans", 1, 1, type);
    
    switch(A->datatype){
        case short_int:
            switch(type){
            case short_int:     NORM1(A, short_int, tmp, short_int);   break;
            case integer:       NORM1(A, short_int, tmp, integer);     break;
            case floating:      NORM1(A, short_int, tmp, floating);    break;
            case double_prec:   NORM1(A, short_int, tmp, double_prec); break;
        }
        break;
        
        case integer:
            switch(type){
            case short_int:     NORM1(A, integer, tmp, short_int);   break;
            case integer:       NORM1(A, integer, tmp, integer);     break;
            case floating:      NORM1(A, integer, tmp, floating);    break;
            case double_prec:   NORM1(A, integer, tmp, double_prec); break;
        }
        break;

        case floating:
            switch(type){
            case short_int:     NORM1(A, floating, tmp, short_int);   break;
            case integer:       NORM1(A, floating, tmp, integer);     break;
            case floating:      NORM1(A, floating, tmp, floating);    break;
            case double_prec:   NORM1(A, floating, tmp, double_prec); break;
        }
        break;

        case double_prec:
            switch(type){
            case short_int:     NORM1(A, double_prec, tmp, short_int);   break;
            case integer:       NORM1(A, double_prec, tmp, integer);     break;
            case floating:      NORM1(A, double_prec, tmp, floating);    break;
            case double_prec:   NORM1(A, double_prec, tmp, double_prec); break;
        }
        break;
    }
    return tmp;
}

#define NORM2(VECTOR, VECTYPE, ANS, ANSTYPE)                                                   \
ANS->elements.ANSTYPE = malloc(sizeof(*ANS->elements.ANSTYPE));                                \
ANS->elements.ANSTYPE[0] = 0;                                                                  \
for(int i = 0; i < size(VECTOR); i++)                                                          \
    ANS->elements.ANSTYPE[0] += VECTOR->elements.VECTYPE[i] * VECTOR->elements.VECTYPE[i];     \
ANS->elements.ANSTYPE[0] = sqrt(ANS->elements.ANSTYPE[0]);

Matrix *norm2(Matrix *A, DataType type){
    Matrix *tmp = new_matrix("ans", 1, 1, type);
    
    switch(A->datatype){
        case short_int:
            switch(type){
            case short_int:     NORM2(A, short_int, tmp, short_int);   break;
            case integer:       NORM2(A, short_int, tmp, integer);     break;
            case floating:      NORM2(A, short_int, tmp, floating);    break;
            case double_prec:   NORM2(A, short_int, tmp, double_prec); break;
        }
        break;
        
        case integer:
            switch(type){
            case short_int:     NORM2(A, integer, tmp, short_int);   break;
            case integer:       NORM2(A, integer, tmp, integer);     break;
            case floating:      NORM2(A, integer, tmp, floating);    break;
            case double_prec:   NORM2(A, integer, tmp, double_prec); break;
        }
        break;

        case floating:
            switch(type){
            case short_int:     NORM2(A, floating, tmp, short_int);   break;
            case integer:       NORM2(A, floating, tmp, integer);     break;
            case floating:      NORM2(A, floating, tmp, floating);    break;
            case double_prec:   NORM2(A, floating, tmp, double_prec); break;
        }
        break;

        case double_prec:
            switch(type){
            case short_int:     NORM2(A, double_prec, tmp, short_int);   break;
            case integer:       NORM2(A, double_prec, tmp, integer);     break;
            case floating:      NORM2(A, double_prec, tmp, floating);    break;
            case double_prec:   NORM2(A, double_prec, tmp, double_prec); break;
        }
        break;
    }
    return tmp;
}

#define NORM_INF(VECTOR, VECTYPE, ANS, ANSTYPE)                                                   \
ANS->elements.ANSTYPE = malloc(sizeof(*ANS->elements.ANSTYPE));                                   \
ANS->elements.ANSTYPE[0] = 0;                                                                     \
for(int i = 0; i < size(VECTOR); i++){                                                            \
    if(VECTOR->elements.VECTYPE[i] > 0)                                                           \
        if(VECTOR->elements.VECTYPE[i] > ANS->elements.ANSTYPE[0])                                \
            ANS->elements.ANSTYPE[0] = VECTOR->elements.VECTYPE[i];                               \
    else                                                                                          \
        if(-VECTOR->elements.VECTYPE[i] > ANS->elements.ANSTYPE[0])                               \
            ANS->elements.ANSTYPE[0] = -VECTOR->elements.VECTYPE[i];                              \
}
Matrix *norm_inf(Matrix *A, DataType type){
    Matrix *tmp = new_matrix("ans", 1, 1, type);
    
    switch(A->datatype){
        case short_int:
            switch(type){
            case short_int:     NORM_INF(A, short_int, tmp, short_int);   break;
            case integer:       NORM_INF(A, short_int, tmp, integer);     break;
            case floating:      NORM_INF(A, short_int, tmp, floating);    break;
            case double_prec:   NORM_INF(A, short_int, tmp, double_prec); break;
        }
        break;
        
        case integer:
            switch(type){
            case short_int:     NORM_INF(A, integer, tmp, short_int);   break;
            case integer:       NORM_INF(A, integer, tmp, integer);     break;
            case floating:      NORM_INF(A, integer, tmp, floating);    break;
            case double_prec:   NORM_INF(A, integer, tmp, double_prec); break;
        }
        break;

        case floating:
            switch(type){
            case short_int:     NORM_INF(A, floating, tmp, short_int);   break;
            case integer:       NORM_INF(A, floating, tmp, integer);     break;
            case floating:      NORM_INF(A, floating, tmp, floating);    break;
            case double_prec:   NORM_INF(A, floating, tmp, double_prec); break;
        }
        break;

        case double_prec:
            switch(type){
            case short_int:     NORM_INF(A, double_prec, tmp, short_int);   break;
            case integer:       NORM_INF(A, double_prec, tmp, integer);     break;
            case floating:      NORM_INF(A, double_prec, tmp, floating);    break;
            case double_prec:   NORM_INF(A, double_prec, tmp, double_prec); break;
        }
        break;
    }
    return tmp;
}

Matrix *vectorial_norm(Matrix *A, char *n, DataType type){
    char *lastn;
    unsigned long long p = strtoull(n, &lastn, 10);
    if(*lastn == 0){    //string was a number
        if(p == 1)      return norm1(A, type); 
        else if(p == 2) return norm2(A, type);
        else;
            //return p_norm(A, p);
    }
    else{
        if(!strcmp(n, "inf"))
            return norm_inf(A, type);
        else
            return NULL;
    }
}