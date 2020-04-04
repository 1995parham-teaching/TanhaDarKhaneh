#include <stdio.h>

#define CONTACTS_SIZE 100

int ids[CONTACTS_SIZE];
long long phones[CONTACTS_SIZE];

// the first empty space in ids and phones array
static int index;

int menu(void) {
    printf("1) Add\n");
    printf("2) Get\n");
    printf("3) Remove\n");
    printf("4) List\n");
    printf("5) Exit\n");
    printf(">> ");

    int choice;
    scanf("%d", &choice);

    return choice;
}

void contacts_print(void) {
    int i;

    for (i = 0; i < index; i++) {
        printf("####\n");
        printf("Index: %d\n", i);
        printf("ID: %d\n", ids[i]);
        printf("Phone: %lld\n", phones[i]);
        printf("####\n");
    }
}

long long contacts_get(int id) {
    int i;

    for (i = 0; i < index; i++) {
        if (ids[i] == id) {
            return phones[i];
        }
    }

    return -1;
}

void contacts_remove(int id) {
    int i;

    for (i = 0; i < index; i++) {
        if (ids[i] == id) {
            ids[i] = ids[index - 1];
            index--;
            return;
        }
    }
}

void contacts_add(int id, long long phone) {
    if (index == CONTACTS_SIZE) {
        return;
    }

    ids[index] = id;
    phones[index] = phone;
    index++;
}

int main() {
    int is_run = 1;

    int id;
    long long phone;

    while (is_run) {
        int i;

        int choice = menu();

        switch (choice) {
            case 1:
                printf("ID: ");
                scanf("%d", &id);

                printf("Phone: ");
                scanf("%lld", &phone);

                contacts_add(id, phone);
                break;
            case 2:
                printf("ID: ");
                scanf("%d", &id);

                phone = contacts_get(id);

                if (phone == -1) {
                    printf("ID not found");
                } else {
                    printf("Phone: 0%lld\n", phone);
                }
                break;
            case 3:
                printf("ID: ");
                scanf("%d", &id);

                contacts_remove(id);
                break;
            case 4:
                contacts_print();
                break;
            case 5:
                return 0;
            default:
                printf("Please select a valid option");
        }
    }
}
