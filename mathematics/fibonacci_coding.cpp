#include <cstdio>
#include <cstdlib>

#define N 30

int fib[N];

int largestFibLessOrEqualTo(int n) {
    fib[0] = 1;
    fib[1] = 2;

    int i;
    for (i = 2; fib[i - 1] <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return i - 2;
}

char* encode(int n) {
    int index = largestFibLessOrEqualTo(n);
    char* code = (char*) malloc(sizeof(char) * (index + 3));

    int i = index;
    while (n) {
        code[i] = '1';
        n = n - fib[i];
        i = i - 1;

        while (i >= 0 && fib[i] > n) {
            code[i] = '0';
            i -= 1;
        }
    }
    code[index + 1] = '1';
    code[index + 2] = '\0';
    return code;
}

int main() {
    int n = 143; 
    printf("Fibonacci code word for %d is %s\n", n, encode(n)); 
    return 0; 
}
