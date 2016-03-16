#include <stdio.h>

int x;

int foo() {
    int x = 37;
    void* p = &x;
    double* y = p; // bad idea
    return 0;
}

int main() {
    int y;
    static int z;
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);
    foo();
    return 0;
}
