#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, max, min;
    int *ns;
    scanf("%d", &n);
    ns = (int*)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++) {
        scanf("%d", &ns[i]);
    }
    max = ns[0];
    for(int i=1; i<n; i++) {
        if(max < ns[i])
            max = ns[i];
    }
    min = max;
    for(int i=0; i<n; i++) {
        if(min > ns[i])
            min = ns[i];
    }
    printf("%d %d\n", min, max);
    free(ns);
}