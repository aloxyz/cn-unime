#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int m) {
    int x = 1; float y = 1; double z = 1;
    for(int i = 2; i < m + 1; i++) {
        x *= i; y *= i; z *= i;
        printf("%d!: int: %d\t float: %.3f\tdouble: %.5lf\n", i, x, y, z);
    }
}

int fact_plus(int x, float y, double z, int max) {

    printf("max: %d\n-------", max);

    printf("\nint %d:\n\n", x);
    while(x < max) {
        int tmp = x;
        for(int i = x - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%d! = %d\n", x, tmp);
        x++;
    }
    printf("\nfloat %.2f:\n\n", y);
    while(y < max) {
        float tmp = y;
        for(int i = y - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%.2f! = %.2f\n", y, tmp);
        y++;
    }
    printf("\ndouble %.4lf:\n\n", z);
    while(z < max) {
        double tmp = z;
        for(int i = z - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%.4lf! = %.4lf\n", z, tmp);
        z++;
    }
}

int int_sum(int *v, int n) {
    int sum = v[0];
    for(int i = 0; i < n; i++) { sum += v[i]; }
    return sum;
}

double double_sum(double *v, int n) {
    double sum = v[0];
    for(int i = 0; i < n; i++) { sum += v[i]; }
    return sum;
}

int int_prod(int *v, int n) {
    int prod = v[0];
    for(int i = 0; i < n; i++) { prod *= v[i]; }
    return prod;
}

int int_avg(int *v, int n) {
    return (int_sum(v, n)/n);
}

double double_avg(double *v, int n) {
    return (double_sum(v, n)/n);
}

int int_min(int *v, int n) {
    int tmp = v[0];
    for(int i = 0; i < n; i++) {
        if(tmp > v[i]) tmp = v[i];
    }
    return tmp;
}

int int_max(int *v, int n) {
    int tmp = v[0];
    for(int i = 0; i < n; i++) {
        if(tmp < v[i]) tmp = v[i];
    }
    return tmp;
}

int int_sort(int *v, int n) {
    int result[n];
    int tmp = v[0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; i < n; j++) {
        }
    result[i] = tmp;
    }
}

