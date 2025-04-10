#include <stdio.h>

#define MAX_SIZE 100

void intersezione_vettori(int v1[], int v2[], int n1, int n2) {
    int intersezione[MAX_SIZE];
    int count[MAX_SIZE];
    int count_intersezione = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (v1[i] == v2[j]) {
                int trovato = 0;
                for (int k = 0; k < count_intersezione; k++) {
                    if (intersezione[k] == v1[i]) {
                        trovato = 1;
                        count[k]++;
                        break;
                    }
                }
                if (!trovato) {
                    intersezione[count_intersezione] = v1[i];
                    count[count_intersezione] = 1;
                    count_intersezione++;
                }
            }
        }
    }

    printf("Intersezione dei vettori:\n");
    for (int i = 0; i < count_intersezione; i++) {
        printf("Elemento: %d, Occorrenze: %d\n", intersezione[i], count[i]);
    }
}

int main() {
    int v1[] = {1, 2, 3, 4, 5, 6};
    int v2[] = {4, 5, 6, 7, 8};

    int n1 = sizeof(v1) / sizeof(v1[0]);
    int n2 = sizeof(v2) / sizeof(v2[0]);

    intersezione_vettori(v1, v2, n1, n2);

    return 0;
}
