#include <stdio.h>
#include <string.h>

#define MAX 50

struct Antrian {
    char nama[50];
};

int front = -1, rear = -1;
struct Antrian queue[MAX];

void tambahAntrian() {
    if (rear == MAX - 1) {
        printf("Antrian penuh.\n");
        return;
    }

    if (front == -1) front = 0;

    rear++;
    printf("Masukkan nama pelanggan: ");
    scanf(" %[^\n]", queue[rear].nama);

    printf("Pelanggan masuk antrian.\n");
}

void panggilAntrian() {
    if (front == -1 || front > rear) {
        printf("Antrian kosong.\n");
        return;
    }

    printf("Memanggil: %s\n", queue[front].nama);
    front++;
}

void lihatAntrian() {
    int i;
    if (front == -1 || front > rear) {
        printf("Antrian kosong.\n");
        return;
    }

    printf("\n=== DAFTAR ANTRIAN ===\n");
    for (i = front; i <= rear; i++) {
        printf("%d. %s\n", i - front + 1, queue[i].nama);
    }
}

int main() {
    int menu;

    do {
        printf("\n=== SISTEM ANTRIAN ===\n");
        printf("1. Tambah antrian\n");
        printf("2. Panggil antrian\n");
        printf("3. Lihat antrian\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: tambahAntrian(); break;
            case 2: panggilAntrian(); break;
            case 3: lihatAntrian(); break;
        }
    } while (menu != 4);

    return 0;
}