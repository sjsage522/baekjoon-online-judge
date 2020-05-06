#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintScore(char *s) {
    int cur_score = 0, len = strlen(s), sum = 0;
    for(int i=0; i<len; i++) {
        if(s[i] == 'O') {
            cur_score++;
            sum += cur_score;
        }
        else {
            cur_score = 0;
        }
    }
    printf("%d\n", sum);
}
int main() {
    int n;
    char *s = (char*)malloc(sizeof(char) * 80);
    scanf("%d", &n);
    while(n--) {
        scanf("%s", s);
        PrintScore(s);
    }
}