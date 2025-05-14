#include <stdio.h>

int main() {
    int number, result = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else if (number == 0 || number == 1) {
        printf("Factorial of %d is 1\n", number);
    } else {
        // Outer loop to iterate over the range from 2 to n
        for (int i = 2; i <= number; i++) {
            int temp = 0; // Temporary variable to store result of repeated addition
            // Inner loop to simulate multiplication using addition
            for (int j = 0; j < result; j++) {
                temp += i; // Add 'i' to 'temp' exactly 'result' times
            }
            result = temp; // Update the result with the simulated product
        }

        printf("Factorial of %d is %d\n", number, result);
    }

    return 0;
}