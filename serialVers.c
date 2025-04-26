#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime
    if (n == 2) return true;  // 2 is prime
    if (n % 2 == 0) return false; // exclude even numbers greater than 2

    // Check odd numbers from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N, count = 0;

    // Take input for N
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Measure start time
    clock_t start_time = clock();

    // Count prime numbers from 2 to N
    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            count++;
        }
    }

    // Measure end time and calculate elapsed time
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Print the result
    printf("The number of prime numbers between 1 and %d is: %d\n", N, count);
    printf("Serial execution time: %f seconds\n", time_taken);

    return 0;
}
