#include <stdio.h>
#include <stdlib.h>


int main() {
    int t, size;
    
    printf("scegliere tra\n1. interi\n2. reali\n>> ");
    scanf("%d", &t);
    printf("inserire la lunghezza del vettore\n>>  ");
    scanf("%d", &size);
    
    printf("inizializzare il vettore\n>> ");
    if(t <= 1) {
        int *v = malloc(sizeof(int) * size);
        int sum = 0;
        for(int i = 0; i < size; i++) {
            scanf("%d", &v[i]);
            sum += v[i];
        }
        printf("\nmedia: %d\n", sum/size);
    }
    if(t >= 2) {
        double *v = malloc(sizeof(int) * size);
        double sum = 0;
        for(int i = 0; i < size; i++) {
            scanf("%lf", &v[i]);
            sum += v[i];
        }
        printf("\nmedia: %lf\n", sum/size);
    }

}