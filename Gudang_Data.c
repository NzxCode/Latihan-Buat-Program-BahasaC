#include <stdio.h>
#include <stdlib.h>

int* gandakanArray(int arr[], int n, int isiBaru) {
    int i;

    // alokasi array baru 2x lebih besar
    int *baru = (int*) malloc(2 * n * sizeof(int));

    // copy isi lama
    for (i = 0; i < n; i++) {
        baru[i] = arr[i];
    }

    // isi bagian tambahan
    for (i = n; i < 2 * n; i++) {
        baru[i] = isiBaru;
    }

    return baru;
}

int main() {
    int n, i;
    int *arr;
    int isiBaru;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    // alokasi array awal
    arr = (int*) malloc(n * sizeof(int));

    // input elemen array
    printf("Masukkan %d angka:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // input nilai untuk isi tambahan
    printf("Masukkan nilai untuk mengisi slot baru: ");
    scanf("%d", &isiBaru);

    // panggil fungsi
    int *hasil = gandakanArray(arr, n, isiBaru);

    // tampilkan hasil
    printf("\nArray setelah digandakan:\n");
    for (i = 0; i < 2 * n; i++) {
        printf("%d ", hasil[i]);
    }
    printf("\n");

    // free memory
    free(arr);
    free(hasil);

    return 0;
}