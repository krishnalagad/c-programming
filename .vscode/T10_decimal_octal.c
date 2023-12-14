#include <stdio.h>

void decimalToOctal(int decimalNumber) {
    int octalNumber = 0, i = 1;

    while (decimalNumber != 0) {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    printf("Octal equivalent: %d\n", octalNumber);
}

int main() {
    int decimalNumber;

    // Input from the user
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Function call to convert decimal to octal
    decimalToOctal(decimalNumber);

    return 0;
}
