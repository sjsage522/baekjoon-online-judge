#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int t, l, len;
    char *s;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &l);
        s = (char*)malloc((sizeof(char) * l) + 1);
        scanf("%s", s);
        len = strlen(s);
        for(int i=0; i<len; i++)
            for(int j=0; j<l; j++)
                printf("%c", s[i]);
        printf("\n");
    }
}