#include <stdio.h>
int main() {
    char ch;
    int time = 0;
    while((ch = getchar()) != '\n') {
        if(ch == 'A' || ch == 'B' || ch == 'C')
            time += 3;
        else if(ch == 'D' || ch == 'E' || ch == 'F')
            time += 4;
        else if(ch == 'G' || ch == 'H' || ch == 'I')
            time += 5;
        else if(ch == 'J' || ch == 'K' || ch == 'L')
            time += 6;
        else if(ch == 'M' || ch == 'N' || ch == 'O')
            time += 7;
        else if(ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S')
            time += 8;
        else if(ch == 'T' || ch == 'U' || ch == 'V')
            time += 9;
        else if(ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z')
            time += 10;
    }
    printf("%d\n", time);
}