#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    int age;
};

void addContact() {
    struct Contact c;
    FILE *f = fopen("contacts.txt", "a");

    printf("Enter name: ");
    scanf("%s", c.name);

    printf("Enter age: ");
    scanf("%d", &c.age);

    fprintf(f, "%s %d\n", c.name, c.age);
    fclose(f);

    printf("Contact added.\n");
}

void viewContacts() {
    struct Contact c;
    FILE *f = fopen("contacts.txt", "r");

    if (!f) {
        printf("No contacts found.\n");
        return;
    }

    while (fscanf(f, "%s %d", c.name, &c.age) != EOF) {
        printf("Name: %s | Age: %d\n", c.name, c.age);
    }

    fclose(f);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Exit\n");
        printf("Choose: ");

        scanf("%d", &choice);

        if (choice == 1)
            addContact();
        else if (choice == 2)
            viewContacts();
        else if (choice == 3)
            break;
        else
            printf("Invalid.\n");
    }

    return 0;
}

