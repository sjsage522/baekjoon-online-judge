#include <stdio.h>
#define MAX_SIZE 12
int combi[MAX_SIZE];
void print_case(int j, int cnt, int k, int *s) {
    if(cnt == 6) {
        for(int i=0; i<6; i++)
            printf("%d ", combi[i]);
        printf("\n");
        return;
    }
    for(int i=j; i<k; i++) {
        combi[cnt] = s[i];
        print_case(i+1, cnt+1, k, s);
    }
}

int main() {
    int k;
    int s[MAX_SIZE] = {0};

    do {
        scanf("%d", &k);
        if(k == 0)
            break;
        for(int i=0; i<k; i++)
            scanf("%d", &s[i]);
        print_case(0, 0, k, s); // dfs
        printf("\n");
    } while(k);
}