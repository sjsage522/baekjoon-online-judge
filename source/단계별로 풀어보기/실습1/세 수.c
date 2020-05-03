#include <stdio.h>
void check(int x, int y) {
    if(x > y)
        printf("%d\n", x);
    else
        printf("%d\n", y);
}
int main() {
    int a,b,c,max;
    scanf("%d %d %d", &a, &b, &c);
    max = a;
    if(max < b) max = b; 
    if(max < c) max = c;
    if(a == max) check(b,c);
    else if(b == max) check(a,c);
    else if(c == max) check(a,b);
}