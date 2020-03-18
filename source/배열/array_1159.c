#include <stdio.h>
#include <stdlib.h>

char *alpha = "abcdefghijklmnopqrstuvwxyz"; //26
char res[26] = {0, };

int main(){
    int cnt = 0, n;
    char **names;

    scanf("%d", &n);
    names = (char**)malloc(sizeof(char*) * n);

    for(int i=0; i<n; i++){
        names[i] = (char*)malloc(sizeof(char) * 30);
    }

    for(int i=0; i<n; i++)
        scanf("%s", names[i]);

    for(int i=0; i<26; i++){
        cnt = 0;
        for(int j=0; j<n; j++){
            if(names[j][0] == alpha[i])
                cnt++;
        }
        if(cnt >= 5)
            res[i] = alpha[i];
    }

    cnt = 0;
    for(int i=0; i<26; i++){
        if(res[i] == 0)
            cnt++;
    }
    if(cnt == 26)
        printf("PREDAJA");

    for(int i=0; i<26; i++){
        if(res[i] != 0)
            printf("%c", res[i]);
    }
    printf("\n");
}