#include <stdio.h>
#include <stdlib.h>

void flat_arr(int n, int m) {
    int* arr = malloc(n * m * sizeof(int));
    if (arr == NULL) return;

    // arr[i*m + j] = 37;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i*m + j] = counter++;
        }
    }

    free(arr);
}

void inherited_arr(int n, int m) {
    int** arr = malloc(n * sizeof(int*));
    if (arr == NULL) return;
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(m * sizeof(int));
        if (arr[i] == NULL) return;
    }

    // arr[i][j] = 37;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = counter++;
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    flat_arr(10, 20);
    inherited_arr(10, 20);
    return 0;
}
