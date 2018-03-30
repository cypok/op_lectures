#include <stdio.h>

int main() {
    float x = 37;
    float* px = &x;
    void* p = px;
    int* py = p;
    printf("%d\n", *py);
    return 0;
}
