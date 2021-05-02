#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_minmax(int *v, int size, char *m) {
    int tmp = v[0];

    if(strcmp(m, "min") == 0) {
        for(int i = 0; i < size; i++) if(v[i] < tmp) tmp = v[i];
        return tmp;
    }
    if(strcmp(m, "max") == 0) {
        for(int i = 0; i < size; i++) if(v[i] > tmp) tmp = v[i];
        return tmp;
    }
    return -1;
}
double double_minmax(double *v, int size, char *m) {
    double tmp = v[0];

    if(strcmp(m, "min") == 0) {
        for(int i = 0; i < size; i++) if(v[i] < tmp) tmp = v[i];
        return tmp;
    }
    if(strcmp(m, "max") == 0) {
        for(int i = 0; i < size; i++) if(v[i] > tmp) tmp = v[i];
        return tmp;
    }
    return -1;
}

int main() {
    int t, size;
    char m[BUFSIZ];
    printf("scegliere tra\n1. interi\n2. reali\n>> ");
    scanf("%d", &t);
    printf("inserire la lunghezza del vettore\n>>  ");
    scanf("%d", &size);
    printf("\"min\" o \"max\"\n>> ");
    scanf(" %s", m);

    printf("inizializzare il vettore\n>> ");
    if(t <= 1) {
        int *v = malloc(sizeof(int) * size);
        int sum = 0;
        for(int i = 0; i < size; i++) scanf("%d", &v[i]);
        printf("%d", int_minmax(v, size, m));
    }
    if(t >= 2) {
        double *v = malloc(sizeof(int) * size);
        double sum = 0;
        for(int i = 0; i < size; i++) scanf("%lf", &v[i]);
        printf("%lf", double_minmax(v, size, m));
    }
}