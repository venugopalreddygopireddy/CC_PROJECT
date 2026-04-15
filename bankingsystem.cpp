#include <stdio.h>

int main() {
    float balance = 0.0;
    int choice;
    float amount;

    while (1) {
        printf("\n--- BANK MANAGEMENT SYSTEM ---\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // Deposit
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful!\n");
                } else {
                    printf("Invalid amount! Enter positive value.\n");
                }
                break;

            // Withdraw
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("Invalid amount!\n");
                } else if (amount > balance) {
                    printf("Insufficient balance!\n");
                } else {
                    balance -= amount;
                    printf("Withdrawal successful!\n");
                }
                break;

            // Check balance
            case 3:
                printf("Current Balance = %.2f\n", balance);
                break;

            // Exit
            case 4:
                printf("Thank you! Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
