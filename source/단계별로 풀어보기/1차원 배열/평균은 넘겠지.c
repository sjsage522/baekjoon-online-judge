#include <stdio.h>
#include <stdlib.h>
void CheckAvg(int *s, int stds) {
    double sum = 0, cnt = 0, avg;
    for(int i=0; i<stds; i++) {
        sum += s[i];
    }
    avg = sum / stds;
    for(int i=0; i<stds; i++) {
        if(avg < s[i])
            cnt++;
    }
    printf("%.3lf%%\n", ((double)cnt / stds) * 100);
}
int main() {
    int t, stds;
    int *s;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &stds);
        s = (int*)malloc(sizeof(int) * stds);
        for(int i=0; i<stds; i++)
            scanf("%d", &s[i]);
        CheckAvg(s, stds);
    }
}