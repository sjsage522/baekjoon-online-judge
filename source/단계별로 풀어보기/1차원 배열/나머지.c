#include <stdio.h>

int main(){
    int number[10], res[42] = {0,};
    int n, tmp, cnt = 0;
    for(int i=0; i<10; i++){
        scanf("%d", &n);
        number[i] = n % 42;
    }

    for(int i=0; i<10; i++){
        tmp = number[i];
        res[tmp] = 1;
    }

    for(int i=0; i<42; i++){
        if(res[i] == 1)
            cnt++; 
    }

    printf("%d\n", cnt);
}