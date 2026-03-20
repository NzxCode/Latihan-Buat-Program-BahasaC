#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int i;
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("Masukkan password: ");
    scanf(" %[^\n]", password);

    for (i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    printf("\n=== HASIL CEK PASSWORD ===\n");
    printf("Panjang password: %lu\n", strlen(password));
    printf("Huruf besar     : %s\n", hasUpper ? "Ada" : "Tidak ada");
    printf("Huruf kecil     : %s\n", hasLower ? "Ada" : "Tidak ada");
    printf("Angka           : %s\n", hasDigit ? "Ada" : "Tidak ada");
    printf("Karakter khusus : %s\n", hasSpecial ? "Ada" : "Tidak ada");

    if (strlen(password) >= 8 && hasUpper && hasLower && hasDigit && hasSpecial) {
        printf("Status          : Password kuat\n");
    } else {
        printf("Status          : Password lemah\n");
    }

    return 0;
}