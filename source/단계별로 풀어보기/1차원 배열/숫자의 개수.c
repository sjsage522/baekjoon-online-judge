#include <stdio.h>
#include <string.h>
int main() {
    int a,b,c,n,len,cnt=0;
    char s[9];
    scanf("%d %d %d", &a, &b, &c);
    n = a*b*c;
    sprintf(s, "%d", n);
    len = strlen(s);
    for(int k=48; k<=57; k++){
        for(int i=0; i<len; i++) {
            if(s[i] == k)
                cnt++;
        }
        printf("%d\n", cnt);
        cnt = 0;
    }
}