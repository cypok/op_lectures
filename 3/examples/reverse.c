#include <stdio.h>
#include <stdlib.h>

//int[] reverse(int arr[], size_t size) {
//    int result[???];
//    // ...
//}

void reverse(int dst[], int src[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        dst[i] = src[size - i - 1];
    }
}

int* reverse2(int src[], size_t size) {
    int* dst = malloc(size * sizeof(int));
    if (dst == NULL) return NULL;

    for (size_t i = 0; i < size; i++) {
        dst[i] = src[size - i - 1];
    }
    return dst;
}



int main() {
    int original[3] = {1, 2, 3};

    //int reversed[3];
    //reverse(reversed, original, 3);

    int* reversed = reverse2(original, 3);

    for (size_t i = 0; i < 3; i++) {
        printf("%d\n", reversed[i]);
    }

    free(reversed);
    return 0;
}
