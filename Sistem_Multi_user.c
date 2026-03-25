#include <stdio.h>
#include <string.h>

#define MAX_USER 20

struct User {
    char username[50];
    char password[50];
};

int main() {
    struct User users[MAX_USER];
    int n = 0, menu;
    char u[50], p[50];
    int i, found;

    do {
        printf("\n=== LOGIN SYSTEM ===\n");
        printf("1. Register\n2. Login\n3. Keluar\nPilih: ");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("Username: ");
            scanf("%s", users[n].username);
            printf("Password: ");
            scanf("%s", users[n].password);
            n++;
            printf("User berhasil dibuat.\n");
        }

        else if (menu == 2) {
            printf("Username: ");
            scanf("%s", u);
            printf("Password: ");
            scanf("%s", p);

            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(u, users[i].username) == 0 &&
                    strcmp(p, users[i].password) == 0) {
                    found = 1;
                }
            }

            if (found)
                printf("Login berhasil!\n");
            else
                printf("Login gagal!\n");
        }

    } while (menu != 3);

    return 0;
}