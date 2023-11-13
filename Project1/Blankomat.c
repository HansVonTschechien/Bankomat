#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable: 4996)

    void displayMenu() {
        printf("\n=== ATM Menu ===\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("===============\n");
    }

    int main() {
 int PIN = 1234;

    // Initial balance
    float balance = 1000.0;
    int enteredPIN;
    int choice;
    float amount;

    printf("=== ATM System ===\n");

    // PIN entry loop
    do {
        printf("Enter your PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN != PIN) {
            printf("Incorrect PIN. Please try again.\n");
        }

    } while (enteredPIN != PIN);

    printf("PIN accepted. Welcome!\n");

    do {
        displayMenu(); // Display the main menu

        // User choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Check balance
                printf("Your balance is: $%.2f\n", balance);
                break;

            case 2:
                // Deposit
                printf("Enter the amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful. Your new balance is: $%.2f\n", balance);
                } else {
                    printf("Invalid amount. Please enter a positive value.\n");
                }
                break;

            case 3:
                // Withdraw
                printf("Enter the amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Withdrawal successful. Your new balance is: $%.2f\n", balance);
                } else {
                    printf("Invalid amount or insufficient balance.\n");
                }
                break;

            case 4:
                // Exit
                printf("Goodbye! Have a nice day.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4); // Continue until the user chooses to exit

    return 0;
}