#include <stdio.h>
#include <stdlib.h>

#define MAX_STATIONS 5

int main() {
    int choice;
    int source = -1, destination = -1;
    int booked = 0;
    int fare = 0;

    char stations[MAX_STATIONS][20] = {
        "Central",
        "Park Street",
        "City Mall",
        "Airport",
        "Bus Stand"
    };

    while (1) {
        printf("\n===== METRO TRAIN BOOKING SYSTEM =====\n");
        printf("1. View Stations\n");
        printf("2. Book Ticket\n");
        printf("3. Show Ticket Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nAvailable Stations:\n");
                for (int i = 0; i < MAX_STATIONS; i++) {
                    printf("%d. %s\n", i + 1, stations[i]);
                }
                break;

            case 2:
                printf("\nEnter Source Station Number: ");
                scanf("%d", &source);
                printf("Enter Destination Station Number: ");
                scanf("%d", &destination);

                // Validation
                if (source < 1 || source > MAX_STATIONS ||
                    destination < 1 || destination > MAX_STATIONS) {
                    printf("Invalid station numbers!\n");
                    booked = 0;
                }
                else if (source == destination) {
                    printf("Source and Destination cannot be the same!\n");
                    booked = 0;
                }
                else {
                    int distance = abs(destination - source);
                    fare = distance * 10;

                    printf("Ticket booked successfully!\n");
                    booked = 1;
                }
                break;

            case 3:
                if (!booked) {
                    printf("No ticket booked yet!\n");
                } else {
                    printf("\n===== TICKET DETAILS =====\n");
                    printf("Source      : %s\n", stations[source - 1]);
                    printf("Destination : %s\n", stations[destination - 1]);
                    printf("Fare        : ?%d\n", fare);
                }
                break;

            case 4:
                printf("Thank you! Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
