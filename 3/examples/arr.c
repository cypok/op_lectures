#include <stdio.h>

int main() {
    short arr[3] = {10, 20, 30};

    short* p = &(arr[0]); // 0x20
    short* p2 = p + 1;    // 0x22
    short* p3 = p + 2;    // 0x24
    *p3 = 300;

    {
        // swap arr[0] & arr[1]
        short tmp = arr[0];
        arr[0] = arr[1];
        arr[1] = tmp;
    }

    {
        // swap arr[0] & arr[1]
        short tmp = 0[p];
        0[p] = 1[p];
        1[p] = tmp;
    }

    printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    return 0;
}
