#include <stdio.h>
#include <stdlib.h>
int main() {
    int N;
    double max, sum = 0;
    double *s;
    scanf("%d", &N);
    s = (double*)malloc(sizeof(double) * N);

    for(int i=0; i<N; i++)
        scanf("%lf", &s[i]);
    max = s[0];
    for(int i=1; i<N; i++)
        if(max < s[i])
            max = s[i];
    for(int i=0; i<N; i++) {
        s[i] = (s[i] / max) * 100; 
        sum += s[i];
    }
    printf("%lf\n", sum / N);
}