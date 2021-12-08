#include <stdio.h>
#define REMOVED 0
#define PRESENT 1

int main(){
    int n;
    scanf("%d" , &n);

    int people[n];

    // Assume all people are present
    for(int i = 0; i < n; i++)
        people[i] = PRESENT;

    int presentPeopleCount = n;

    int person = 0;
    while(presentPeopleCount > 1) {

        // Skip removed people
        while(people[person] == REMOVED)
            person = (person + 1) % n;

        // Skip present person
        person = (person + 1) % n;

        // Find next present person
        while(people[person] == REMOVED)
            person = (person + 1) % n;

        // Remove that person
        people[person] = REMOVED;
        presentPeopleCount--;
    }

    // Find the only alive man
    int singlePresentPerson = 0;
    for(int i = 0; i < n; i++) {
        if(people[i] == PRESENT)
            singlePresentPerson = i;
    }

    printf("%d", singlePresentPerson + 1);

    return 0;
}