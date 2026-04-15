#include <stdio.h>

#define MAX 100

int main() {
    int choice;
    int marks[MAX];
    int n = 0;   // number of students
    int i;

    while (1) {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student Marks\n");
        printf("2. Display All Marks\n");
        printf("3. Calculate Average\n");
        printf("4. Find Highest Marks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of students (max 100): ");
                scanf("%d", &n);

                if (n <= 0 || n > MAX) {
                    printf("Invalid number of students!\n");
                    n = 0;
                    break;
                }

                for (i = 0; i < n; i++) {
                    printf("Enter marks for student %d: ", i + 1);
                    scanf("%d", &marks[i]);

                    if (marks[i] < 0 || marks[i] > 100) {
                        printf("Invalid marks! Enter between 0-100\n");
                        i--; // retry same student
                    }
                }
                printf("Marks added successfully!\n");
                break;

            case 2:
                if (n == 0) {
                    printf("No data available!\n");
                } else {
                    printf("\nStudent Marks:\n");
                    for (i = 0; i < n; i++) {
                        printf("Student %d: %d\n", i + 1, marks[i]);
                    }
                }
                break;

            case 3:
                if (n == 0) {
                    printf("No data available!\n");
                } else {
                    int sum = 0;
                    for (i = 0; i < n; i++) {
                        sum += marks[i];
                    }
                    float avg = (float)sum / n;
                    printf("Average Marks: %.2f\n", avg);
                }
                break;

            case 4:
                if (n == 0) {
                    printf("No data available!\n");
                } else {
                    int max = marks[0];
                    for (i = 1; i < n; i++) {
                        if (marks[i] > max) {
                            max = marks[i];
                        }
                    }
                    printf("Highest Marks: %d\n", max);
                }
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
