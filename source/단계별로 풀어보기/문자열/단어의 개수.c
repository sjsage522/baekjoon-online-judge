#include <stdio.h>
#include <string.h>
int main() {
    char s[1000000];
    char *ptr;
    int cnt = 0;
    scanf("%[^\n]s", s);

    ptr = strtok(s, " ");      
    while (ptr != NULL)               
    {      
        cnt++;
        ptr = strtok(NULL, " ");      
    }
    printf("%d\n", cnt);
}