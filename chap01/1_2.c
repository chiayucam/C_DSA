#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 1) {
            return 1;
        }
    return n*factorial(n-1);
}

void main() {
    int factorialNum;
    printf("Enter an integer: ");
    scanf("%d", &factorialNum);
    printf("%d", factorial(factorialNum));
}