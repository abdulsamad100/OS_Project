#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "locker.h"
#include "logger.h"

int main() {
    int choice;
    char filename[100];
    char inputPass[50];
    const char *correctPass = "1234";

    printf("Enter password: ");
    scanf("%49s", inputPass);  // read input without spaces

    if (strcmp(inputPass, correctPass) != 0) {
        printf("❌ Incorrect password. Access denied.\n");
        return 1;
    }

    printf("✅ Access granted.\n\n");

    while (1) {
        printf("\n===== File Locker Menu =====\n");
        printf("1. Lock a File\n");
        printf("2. Unlock a File\n");
        printf("3. View Access Logs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file to lock (in files/ folder): ");
                scanf("%99s", filename);
                lock_file(filename);
                break;
            case 2:
                printf("Enter file to unlock (in files/ folder): ");
                scanf("%99s", filename);
                unlock_file(filename);
                break;
            case 3:
                view_logs();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
