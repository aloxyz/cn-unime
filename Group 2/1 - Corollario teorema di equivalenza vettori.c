/*Verifica il corollario del teorema di equivalenza delle norme vettoriali:
norm_inf(v) <= norm2(v) <= sqrt(n)*norm_int(v)
norm2(v) <= norm1(v) <= sqrt(n)*norm2(v)  
norm_inf(v) <= norm1(v) <= n*norm_int(v)  

per un generico vettore in input di n componenti
*/

#include "..\CN.h"

void verify(double normA, double normB, double scalar); //Verifica la disuguaglianza normA <= normB <= scalar*normA

int main(){
    int n;
    printf("Inserire quanti elemenit vuoi il vettore abbia: ");
    scanf("%d", &n);
    Matrix *A = new_matrix("A", 1, n, double_prec);
    prompt_init_elements(A);

    verify(vec_norm_inf(A, double_prec)->elements.double_prec[0], vec_norm2(A, double_prec)->elements.double_prec[0], sqrt(size(A)));
    verify(vec_norm2(A, double_prec)->elements.double_prec[0], vec_norm1(A, double_prec)->elements.double_prec[0], sqrt(size(A)));
    verify(vec_norm_inf(A, double_prec)->elements.double_prec[0], vec_norm1(A, double_prec)->elements.double_prec[0], size(A));
    
    return 0;
}

void verify(double normA, double normB, double scalar){         

    printf("%.lf <= %lf <= %lf * %lf\n", normA, normB, scalar, normA);
    if(normA <= normB && normB <= scalar * normA) printf("Vero\n");
    else printf("Falso\n");

}