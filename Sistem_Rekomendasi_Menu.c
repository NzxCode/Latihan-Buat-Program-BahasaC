#include <stdio.h>

int main() {
    int pilihan;

    printf("=== REKOMENDASI MENU ===\n");
    printf("1. Hemat\n");
    printf("2. Normal\n");
    printf("3. Premium\n");
    printf("Pilih kategori: ");
    scanf("%d", &pilihan);

    printf("\nRekomendasi:\n");

    switch (pilihan) {
        case 1:
            printf("- Nasi telur\n");
            printf("- Mie goreng\n");
            break;
        case 2:
            printf("- Ayam goreng\n");
            printf("- Nasi ayam\n");
            break;
        case 3:
            printf("- Steak\n");
            printf("- Seafood\n");
            break;
        default:
            printf("Pilihan tidak valid\n");
    }

    return 0;
}