#include <stdio.h>

int main() {
    int N, res, tmp, cnt = 0;
    scanf("%d", &N);

    res = N;
    do {
        tmp = (res % 10) * 10 + (res/10 + res%10) % 10;
        res = tmp;
        cnt++;
    } while(N != res);
    printf("%d\n", cnt);
}