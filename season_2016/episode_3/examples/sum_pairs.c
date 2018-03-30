#include <stdio.h>

int sum_values(int values[], size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum;
}

int sum_pairs(int pairs[][2], size_t pairs_num) {
    int sum = 0;
    for (size_t i = 0; i < pairs_num; i++) {
        sum += pairs[i][0] + pairs[i][1];
    }
    return sum;
}

int sum_matrix(int matrix[3][3]) {
    int sum = 0;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int values[] = {1, 2, 3};
    printf("%d\n", sum_values(values, 3));

    int pairs[][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
    };
    printf("%d\n", sum_pairs(pairs, 3));

    int matrix[3][3] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1},
    };
    printf("%d\n", sum_matrix(matrix));
    return 0;
}
