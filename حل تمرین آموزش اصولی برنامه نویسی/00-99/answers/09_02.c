#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define NOT_FOUND -1

struct Contact {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char phoneNumber[MAX_LENGTH];
};

struct Contact contacts[MAX_LENGTH];
int contactCount = 0;

int findContact(char *firstName, char *lastName) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].firstName, firstName) == 0 && strcmp(contacts[i].lastName, lastName) == 0) {
            return i;
        }
    }
    return -1;
}

void insertContact(char *firstName, char *lastName, char *phoneNumber) {
    int index = findContact(firstName, lastName);
    if (index == NOT_FOUND) {
        struct Contact newContact;
        strcpy(newContact.firstName, firstName);
        strcpy(newContact.lastName, lastName);
        strcpy(newContact.phoneNumber, phoneNumber);

        contacts[contactCount++] = newContact;
    } else {
        strcpy(contacts[index].phoneNumber, phoneNumber);
    }
}

void delete(char *firstName, char *lastName) {
    int index = findContact(firstName, lastName);

    if (index == NOT_FOUND)
        return;

    for (int i = index; i < contactCount - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    contactCount--;
}

void update(char *firstName, char *lastName, char *newFirstName, char *newLastName, char *newPhoneNumber) {
    int index = findContact(firstName, lastName);
    int newIndex = findContact(newFirstName, newLastName);

    if (newIndex != NOT_FOUND) {
        delete(firstName, lastName);
        strcpy(contacts[newIndex].phoneNumber, newPhoneNumber);
    } else if (index != NOT_FOUND) {
        strcpy(contacts[index].firstName, newFirstName);
        strcpy(contacts[index].lastName, newLastName);
        strcpy(contacts[index].phoneNumber, newPhoneNumber);
    }
}

void search(char query[]) {
    for (int i = 0; i < contactCount; i++) {
        if (strstr(contacts[i].firstName, query) || strstr(contacts[i].lastName, query)) {
            printf("%s %s %s\n", contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
        }
    }
}

void list() {
    for (int i = 0; i < contactCount; i++) {
        printf("%s %s %s\n", contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
    }
}

void execute(char* statementType) {
    if (strcmp(statementType, "add") == 0) {
        char firstName[MAX_LENGTH];
        char lastName[MAX_LENGTH];
        char phoneNumber[MAX_LENGTH];
        scanf("%s %s %s", firstName, lastName, phoneNumber);

        insertContact(firstName, lastName, phoneNumber);
    } else if (strcmp(statementType, "delete") == 0) {
        char firstName[MAX_LENGTH];
        char lastName[MAX_LENGTH];
        scanf("%s %s %s", firstName, lastName);

        delete(firstName, lastName);
    } else if (strcmp(statementType, "edit") == 0) {
        char firstName[MAX_LENGTH];
        char lastName[MAX_LENGTH];

        char newFirstName[MAX_LENGTH];
        char newLastName[MAX_LENGTH];
        char newPhoneNumber[MAX_LENGTH];

        scanf("%s %s %s %s %s", firstName, lastName, newFirstName, newLastName, newPhoneNumber);

        update(firstName, lastName, newFirstName, newLastName, newPhoneNumber);
    } else if (strcmp(statementType, "search") == 0) {
        char query[MAX_LENGTH];
        scanf("%s", query);

        search(query);
    } else {
        list();
    }
}

int main() {
    int statementCount;
    scanf("%d", &statementCount);

    for (int i = 0; i < statementCount; i++) {
        char statementType[MAX_LENGTH];
        scanf("%s", statementType);
        execute(statementType);
    }

    return 0;
}
