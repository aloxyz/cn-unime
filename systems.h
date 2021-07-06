#include "CN.h"

Matrix *inverse(Matrix *A);     //finds the inverse of a matrix using Gauss-Jordan

int is_upper_triangular(Matrix *A);                     //returns 1 if the matrix is upper triangular
Matrix *backwards_substitution(Matrix *A, Matrix* b);   //solves a system where matrix A is upper triangular

Matrix *upper(Matrix *A);                               //gives U matrix of LU factorization

Matrix *determinant(Matrix *A);                         /*returns the determinant of a matrix finding its upper triangular and 
                                                        multiplying the elements on the main diagonal*/

Matrix *gaussian_elimination(Matrix *A, Matrix *b);     //solves the linear system overwriting matrix A

