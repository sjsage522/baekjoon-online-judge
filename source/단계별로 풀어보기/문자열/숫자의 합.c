#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n, len, sum = 0;
    char *s;
    scanf("%d", &n);
    s = (char*)malloc((sizeof(char) * n) + 1);
    scanf("%s", s);
    len = strlen(s);
    for(int i=0; i<len; i++) {
        sum += ((int)s[i] - 48);
    }
    printf("%d\n", sum);
    free(s);
}