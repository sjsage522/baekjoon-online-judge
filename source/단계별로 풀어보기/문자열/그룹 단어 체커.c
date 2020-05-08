#include <stdio.h>
#include <string.h>
int main() {
    int check[26] = {0, }, n, len, cnt=0, res;
    char s[101] = {0, };
    scanf("%d", &n);
    while(n--) {
        for(int i=0; i<26; i++)
            check[i] = 0;
        res = 1;
        scanf("%s", s);
        len = strlen(s);
        for(int i=0; i<len; i++) {
            if(s[i] != s[i+1])
                check[s[i]-97] += 1;
        }
        for(int i=0; i<26; i++) {
            if(check[i] >= 2)
                res = 0;
        }
        if(res == 1)
            cnt++;
    }
    printf("%d\n", cnt);
}