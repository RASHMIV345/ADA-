#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    int i;
    if (n <= 1) 
     return false; // 0 and 1 are not prime
    if (n == 2) 
     return true;  // 2 is prime
    if (n % 2 == 0) 
     return false; // exclude even numbers greater than 2

    // Check odd numbers from 3 to sqrt(n)
    for ( i = 3; i * i <= n; i += 2) {
        if (n % i == 0) 
         return false;
    }
    return true;
}

int main() {
    int N, count = 0;
    int i;
    // Take input for N
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Count prime numbers from 2 to N
    for (i = 2; i <= N; i++) {
        if (is_prime(i)) {
            count++;
        }
    }

    // Print the result
    printf("The number of prime numbers between 1 and %d is: %d\n", N, count);

    return 0;
}
