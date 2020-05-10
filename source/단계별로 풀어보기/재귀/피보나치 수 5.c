#include <stdio.h>

int Fibonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1 || n == 2)
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", Fibonacci(n));
}