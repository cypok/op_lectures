#include <stdio.h>

void div_rem(int a, int b, int *div, int *rem) {
    *div = a / b;
    *rem = a % b;
}

void div_rem_sample() {
    int a = 123;
    int b = 10;
    int div, rem;
    div_rem(a, b, &div, &rem);
    printf("%d = %d * %d + %d\n", a, b, div, rem);
}

int main() {
    div_rem_sample();
    return 0;
}
