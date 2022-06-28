#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()

int tribonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n <= 2) {
        return 1;
    } else {
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
}

// long int tribonacci(int n) {
//     long int n0 = 0, n1 = 1, n2 = 1;
//     if (n == 0) {
//         return n0;
//     } else if (n <= 2) {
//         return 1;
//     }
//     long int res = 0;
//     for (long int i = 0; i<n-2; i++) {
//         res = n0 + n1 + n2;
//         n0 = n1;
//         n1 = n2;
//         n2 = res;
//     }
//     return res;
// }

int main() {
    double time_spent = 0.0;
    clock_t begin = clock();


    long int n;
    printf("Calculate Tribonacci of: ");
    scanf("%d", &n);
    printf("Tribonacci (%d) = %ld\n", n, tribonacci(n));




    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);

    return 0;
}