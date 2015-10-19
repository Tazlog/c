#include <stdio.h>
#include <stdlib.h>
int pytha_triplet(int border);

int main()
{
    int i;
    for(i = 0; i < 500; i++) {
        pytha_triplet(i);
    }
    return 0;
}

int pytha_triplet(int border) {
    int a = 0;
    int b = 0;
    int c = 0;
    for(a = 0; a < (border-2); a++) {
        for(b = a + 1; b < (border-1); b++) {
            for(c = b + 1; c < border; c++) {
                if( a*a + b*b == c*c && a+b+c == border) {
                    printf("Found %d %d %d\n", a, b, c);
                    return 0;
                }

            }
        }
    }
}
