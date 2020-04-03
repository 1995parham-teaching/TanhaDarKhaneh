#include <stdio.h>

int ids[100];
long long phones[100];

int main() {
    int is_run = 1;

    // the first empty space in ids and phones array
    int index = 0;

    int id;
    long long phone;

    while (is_run) {
        printf("1) Add\n");
        printf("2) Get\n");
        printf("3) Remove\n");
        printf("4) List\n");
        printf("5) Exit\n");
        printf(">> ");

        int i;
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ID: ");
                scanf("%d", &id);

                printf("Phone: ");
                scanf("%lld", &phone);

                ids[index] = id;
                phones[index] = phone;
                index++;

                break;
            case 2:
                printf("ID: ");
                scanf("%d", &id);

                for (i = 0; i < index; i++) {
                    if (ids[i] == id) {
                        printf("Phone: 0%lld\n", phones[i]);
                    }
                }
                break;
            case 3:
                printf("ID: ");
                scanf("%d", &id);

                for (i = 0; i < index; i++) {
                    if (ids[i] == id) {
                        ids[i] = ids[index - 1];
                        index--;
                        continue;
                    }
                }
                break;
            case 4:
                for (i = 0; i < index; i++) {
                    printf("####\n");
                    printf("Index: %d\n", i);
                    printf("ID: %d\n", ids[i]);
                    printf("Phone: %lld\n", phones[i]);
                    printf("####\n");
                }
                break;
            case 5:
                return 0;
            default:
                printf("Please select a valid option");
        }
    }
}
