#include <stdio.h>
#include <string.h>
int main() {
    int len, alpha = 97;
    char s[100], res[26];
    scanf("%s", s);
    len = strlen(s);
    for(int i=0; i<26; i++)
        res[i] = -1;
    for(; alpha<=122; alpha++) {
        for(int i=0; i<len; i++) {
            if(alpha == s[i]) {
                res[alpha-97] = i;
                break;
            }
        }
    }
    for(int i=0; i<25; i++)
        printf("%d ", res[i]);
    printf("%d\n", res[25]);
}