#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char s[1000000]; 
    int len, cnt, max, index, res[26];
    scanf("%s", s);
    len = strlen(s);
    for(int i=0; i<len; i++)
        s[i] = toupper(s[i]);
    for(int a=65; a<=90; a++) {
        cnt = 0;
        for(int i=0; i<len; i++) {
            if(a == s[i]) {
                cnt++;
            }
        }
        res[a-65] = cnt;
    }

    max = res[0];
    index = 0;
    for(int i=0; i<26; i++) {
        if(max < res[i]) {
            max = res[i];
            index = i;
        }
    }

    cnt = 0;
    for(int i=0; i<26; i++) {
        if(max == res[i]) {
            cnt++;
        }
    }
    if(cnt >= 2)
        printf("?\n");
    else
        printf("%c\n", index + 65);
}