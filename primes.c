#include <stdio.h>
#include <math.h>

int main() {
    int n = 20;

    for (int i = 2; i < n; i++) {
        int j = 2;
        int jmax = (int)(sqrt(i) + 1);

        while (j <= jmax) {
            if (i % j == 0) {
                break; 
            }
            j++;
        }

        if (j > jmax) {
            printf("%d è un numero primo\n", i);
        }
    }

    return 0;
}
