#include <stdio.h>
#include <math.h>

int binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;

    // Convert binary to decimal
    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
        binaryNumber /= 10;
    }

    return decimalNumber;
}

int main() {
    long long binaryNumber;

    // Input from the user
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);

    // Function call to convert binary to decimal
    int decimalNumber = binaryToDecimal(binaryNumber);

    // Display the result
    printf("Decimal equivalent: %d\n", decimalNumber);

    return 0;
}
