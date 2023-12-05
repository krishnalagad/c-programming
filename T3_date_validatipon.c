#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

// Function to validate the date
int isValidDate(int day, int month, int year) {
    // Validate month
    if (month < 1 || month > 12) {
        return 0; // Invalid month
    }

    // Validate day based on the month
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) 
                && (day < 1 || day > 31)) {
        return 0; // Invalid day
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
        return 0; // Invalid day
    } else if (month == 2) {
        // Check for February, considering leap year
        if (isLeapYear(year) && (day < 1 || day > 29)) {
            return 0; // Invalid day in leap year
        } else if (!isLeapYear(year) && (day < 1 || day > 28)) {
            return 0; // Invalid day in non-leap year
        }
    }

    // Validate year (you can add your own criteria if needed)
    if (year < 0) {
        return 0; // Invalid year (assuming years cannot be negative)
    }

    // If all validations pass, return 1 (valid date)
    return 1;
}

int main(void) {
    int day, month, year;

    // Input date in the format "day/month/year"
    printf("Enter date (day/month/year): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Perform date validation
    if (isValidDate(day, month, year)) {
        printf("The date is valid.\n");
    } else {
        printf("The date is invalid.\n");
    }

    return 0;
}
