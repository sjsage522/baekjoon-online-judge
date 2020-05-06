#include <stdio.h>

int main() {
    int n[9], max, index = 0;
    for(int i=0; i<9; i++)
        scanf("%d", &n[i]);
    max = n[0];
    for(int i=1; i<9; i++)
        if(max < n[i]) {
            max = n[i];
            index = i;
        }
    printf("%d\n%d\n", max, index+1);
}