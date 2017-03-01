#include <stdio.h>


void foo() {
    int x = 518;
    int y = 320;

    int *p;
    p = &x; // & - взятие адреса
    printf("%p %d\n", p, *p); // 0x20 518
    p = &y;
    printf("%p %d\n", p, *p); // 0x40 320
    *p = 999 ; // * - разыменование указателя
    printf("%d %d\n", x, y); // 518 999
}

int main() {

    foo();

    //int *x, y;
    //int* x, y;

    //double a = 37.5;

    //long long b = 1;
    //long long *p;// = &b;

    ////p = &a;
    //*((double*)p) = a;

    //printf("%p: <%lld>\n", p, *p);
    return 0;
}

