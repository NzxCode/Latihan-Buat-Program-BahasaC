#include <stdio.h>
#include <string.h>

#define MAX_TASK 50
#define MAX_LEN 100

struct Task {
    char nama[MAX_LEN];
    int prioritas;   // 1 = tinggi, 2 = sedang, 3 = rendah
    int selesai;
};

void tambahTask(struct Task tasks[], int *n) {
    if (*n >= MAX_TASK) {
        printf("Daftar tugas penuh.\n");
        return;
    }

    printf("Nama tugas: ");
    scanf(" %[^\n]", tasks[*n].nama);
    printf("Prioritas (1=tinggi, 2=sedang, 3=rendah): ");
    scanf("%d", &tasks[*n].prioritas);
    tasks[*n].selesai = 0;
    (*n)++;

    printf("Tugas berhasil ditambahkan.\n");
}

void lihatTask(struct Task tasks[], int n) {
    int i;
    if (n == 0) {
        printf("Belum ada tugas.\n");
        return;
    }

    printf("\n=== TO-DO LIST ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s | Prioritas: %d | Status: %s\n",
               i + 1,
               tasks[i].nama,
               tasks[i].prioritas,
               tasks[i].selesai ? "Selesai" : "Belum");
    }
}

void tandaiSelesai(struct Task tasks[], int n) {
    int pilih;
    lihatTask(tasks, n);
    if (n == 0) return;

    printf("Pilih nomor tugas yang selesai: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > n) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    tasks[pilih - 1].selesai = 1;
    printf("Tugas ditandai selesai.\n");
}

int main() {
    struct Task tasks[MAX_TASK];
    int n = 0, pilih;

    do {
        printf("\n=== TO-DO LIST PRIORITAS ===\n");
        printf("1. Tambah tugas\n");
        printf("2. Lihat tugas\n");
        printf("3. Tandai selesai\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: tambahTask(tasks, &n); break;
            case 2: lihatTask(tasks, n); break;
            case 3: tandaiSelesai(tasks, n); break;
            case 4: printf("Keluar.\n"); break;
            default: printf("Menu tidak valid.\n");
        }
    } while (pilih != 4);

    return 0;
}