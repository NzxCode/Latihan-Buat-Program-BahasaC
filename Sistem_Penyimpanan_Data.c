#include <stdio.h>

struct Data {
    char nama[50];
    int nilai;
};

int main() {
    struct Data d;
    FILE *f;

    printf("Masukkan nama: ");
    scanf(" %[^\n]", d.nama);
    printf("Masukkan nilai: ");
    scanf("%d", &d.nilai);

    f = fopen("data.txt", "a");
    fprintf(f, "%s %d\n", d.nama, d.nilai);
    fclose(f);

    printf("\nData berhasil disimpan.\n");

    printf("\nIsi file:\n");

    f = fopen("data.txt", "r");
    while (fscanf(f, "%s %d", d.nama, &d.nilai) != EOF) {
        printf("%s - %d\n", d.nama, d.nilai);
    }
    fclose(f);

    return 0;
}