#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char a[4], b[4], at[4], bt[4];
    int len, j=0, ia, ib;
    scanf("%s %s", a, b);
    len = strlen(a);
    for(int i=len-1; i>=0; i--) {
        at[j] = a[i];
        bt[j] = b[i];
        j++;
    }
    at[j] = '\0'; bt[j] = '\0';
    ia = atoi(at); ib = atoi(bt);
    if(ia > ib)
        printf("%d\n", ia);
    else
        printf("%d\n", ib);
}