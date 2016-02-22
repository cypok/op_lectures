#include <stdio.h>

int main() {
    int x;
    printf("Enter number: ");
    scanf("%d", &x);

    if (x < 0) {
        x = -x;
    }

    printf("Absolute value = %d\n", x);
    return 0;
}

/*
Enter number: -37
Absolute value = 37

Enter number: -2147483648
Absolute value = -2147483648
*/
