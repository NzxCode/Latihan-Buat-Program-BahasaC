#include <stdio.h>
#include <string.h>

#define MAX 20

struct Produk {
    char nama[50];
    int terjual;
};

int main() {
    struct Produk data[MAX];
    int n, i, j;

    printf("Jumlah produk: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Nama produk: ");
        scanf(" %[^\n]", data[i].nama);
        printf("Jumlah terjual: ");
        scanf("%d", &data[i].terjual);
    }

    // sorting descending
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (data[j].terjual > data[i].terjual) {
                struct Produk temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    printf("\n=== RANKING PRODUK ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s (%d)\n", i+1, data[i].nama, data[i].terjual);
    }

    return 0;
}