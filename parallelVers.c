#include <stdio.h>
#include <stdbool.h>
#include <omp.h>
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
    double start_time = omp_get_wtime();

    // Start parallel region using OpenMP
    #pragma omp parallel for reduction(+:count) schedule(dynamic)
    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            count++;
        }
    }

    // Measure end time and calculate elapsed time
    double end_time = omp_get_wtime();
    double time_taken = end_time - start_time;

    // Print the result
    printf("The number of prime numbers between 1 and %d is: %d\n", N, count);
    printf("Parallel execution time: %f seconds\n", time_taken);

    return 0;
}
