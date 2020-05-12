#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int N, M, sub = 0, tmp, res, sum = 0;
    int *cards;

    scanf("%d %d", &N, &M);
    cards = (int*)malloc(sizeof(int) * N);

    for(int i=0; i<N; i++){
        scanf("%d", &cards[i]);
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                tmp = cards[i] + cards[j] + cards[k];
                if(M - tmp >= 0 && sum <= tmp){
                    sum = cards[i] + cards[j] + cards[k];
                    sub = M-sum;
                    res = cards[i] + cards[j] + cards[k];
                }
            }
        }
    }

    printf("%d\n", res);
}