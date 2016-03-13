#include <stdio.h>

//int[] reverse(int arr[], size_t size) {
//    int result[???];
//    // ...
//}

void reverse(int dst[], int src[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        dst[i] = src[size - i - 1];
    }
}

int main() {
    int original[3] = {1, 2, 3};
    int reversed[3];
    reverse(reversed, original, 3);
    for (size_t i = 0; i < 3; i++) {
        printf("%d\n", reversed[i]);
    }
    return 0;
}
