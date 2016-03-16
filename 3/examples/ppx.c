#include <stdio.h>


int main() {
    char x = 37;
    char* px = &x;
    char** ppx = &px;
    ** ppx = 42;
    printf("%d\n", x);
    return 0;
}
