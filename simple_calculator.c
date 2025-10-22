#include <stdio.h>
#include <ctype.h> 

int main() {
    char operator;
    double current_number;
    double result;

    printf("--- Advanced Continuous Calculator ---\n");

    printf("Enter the starting number: ");
    if (scanf("%lf", &result) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    while (1) {
        printf("\nResult: %.2lf\n", result);
        printf("Enter operator (+, -, *, /) or 'q' to quit: ");

        // Clear any previous newline/whitespace before reading the operator
        if (scanf(" %c", &operator) != 1) {
            break;
        }

        if (tolower(operator) == 'q') {
            break;
        }

        printf("Enter next number: ");
        if (scanf("%lf", &current_number) != 1) {
            printf("Invalid number input. Exiting.\n");
            break;
        }

        switch (operator) {
            case '+':
                result += current_number;
                break;

            case '-':
                result -= current_number;
                break;

            case '*':
                result *= current_number;
                break;

            case '/':
                if (current_number != 0) {
                    result /= current_number;
                } else {
                    printf("Error: Division by zero is not allowed. Result remains unchanged.\n");
                }
                break;

            default:
                printf("Error: Invalid operator entered. Please use +, -, *, or /. Result remains unchanged.\n");
                break;
        }
    }

    printf("\nFinal Result: %.2lf\n", result);
    printf("Calculator finished. Goodbye!\n");

    return 0;
}
