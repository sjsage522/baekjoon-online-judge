#include <stdio.h>
#include <stdlib.h>
int main() {
    int a, x, j=0;
    int *n, *res;
    scanf("%d %d", &a, &x);
    n = (int*)malloc(sizeof(int) * a);
    res = (int*)malloc((sizeof(int) * a) + 1);
    for(int i=0; i<a+1; i++)
        res[i] = 0;
    for(int i=0; i<a; i++)
        scanf("%d", &n[i]);
    for(int i=0; i<a; i++) 
        if(n[i] < x)
            res[j++] = n[i];
    for(j=0; j<a; j++) {
        if(res[j+1] == 0)
            break;
        printf("%d ", res[j]);
    }
    printf("%d\n", res[j]);
}