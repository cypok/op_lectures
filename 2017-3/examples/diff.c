#include <stdio.h>
#include <math.h>

double diff(double x, double (*f)(double)) {
    double dx = 0.01;
    return (f(x + dx) - f(x)) / dx;
}

double square(double x) {
    return x * x;
}

int main() {
    printf("%g\n", diff(M_PI/3, sin));
    printf("%g\n", diff(M_PI/6, cos));
    printf("%g\n", diff(3, square));
    return 0;
}

