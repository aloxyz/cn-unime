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
}