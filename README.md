# ADA-

Parallel Version
Explanation:
is_prime() function:
  This function checks whether a number n is prime. It eliminates even numbers and checks divisibility for odd numbers up to the square root of n.
Parallel Region:
 >>The #pragma omp parallel for directive instructs the OpenMP compiler to parallelize the for loop. Each iteration of the loop will be executed in parallel across multiple threads.
 >>The reduction(+:count) clause ensures that the count variable is handled correctly by each thread. It accumulates the results from each thread into the global count variable 
   without data races.
 >>The schedule(dynamic) clause dynamically assigns iterations of the loop to threads. This can improve load balancing when iterations are uneven in complexity (such as prime- 
   checking).
Input and Output:
 >>The program prompts the user to input the value N, which is the upper bound for the prime number range.
 >>After the parallel loop completes, the program prints the total count of prime numbers between 1 and N.
How It Works in Parallel:
 *OpenMP will split the iterations of the for loop (checking each number from 2 to N) across multiple threads.
 *Each thread will independently check whether a number is prime and contribute to the total prime count.
 *The use of reduction ensures that the count variable is safely updated across all threads without conflicts.
 *This parallel approach should significantly improve performance, especially when N is large and the number of cores available is sufficient.



Serial Version
Explanation:
is_prime() function:
 This function checks if a number n is prime. It returns false for 0 and 1, and checks for divisibility by numbers up to the square root of n.
Main loop:
 >>The program iterates from 2 to N, checking each number using the is_prime() function.
 >>The count of prime numbers is stored in the variable count.
Input and Output:
 >>The program asks the user to input the value of N, which defines the upper limit for checking prime numbers.
 >>After the loop completes, it prints the total number of primes found.

This serial version works by checking each number sequentially to determine if it is prime. While it's easy to understand and implement, it may not be as efficient as the parallel version, especially for large values of N.
