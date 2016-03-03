#include <stdio.h>

int main() {
    int dividend, divisor;
    printf("Enter dividend & divisor:\n");
    scanf("%d %d", &dividend, &divisor);

    int quotient = dividend / divisor;
    printf("%d / %d = %d\n", dividend, divisor, quotient);
    return 0;
}

/*
Enter dividend & divisor:
100
9
100 / 9 = 11

Enter dividend & divisor:
-2147483648
-1
Floating point exception: 8
*/
