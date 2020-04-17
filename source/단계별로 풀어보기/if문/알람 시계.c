#include <stdio.h>
int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    if((m -= 45) < 0) {
        m += 60;
        if((h -= 1) < 0) h = 23;
    }
    printf("%d %d", h, m);
}