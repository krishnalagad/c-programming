#include <stdio.h>

int main(void) {
    // chechPosNegNumber(-10);
    testPrime(-10);
}

void chechPosNegNumber(int num) {
    if (num >  0){
        checkPrime(num);
    } else {
        printf("You entered negative number, please enter positive number: ");
        scanf("%d", &num);
        chechPosNegNumber(num);
    }
    
}

void checkPrime(int num) {
    int flag = 0;
    for (int i = 2; i < num; i++){
        if(num % i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        printf("\nNon Prime number\n");
    else
        printf("\nPrime number\n");
}

void testPrime(int num) {
    if(num > 0 ) {
        int flag = 0;
        for (int i = 2; i < num; i++){
            if(num % i == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            printf("\nNon Prime number\n");
        else
            printf("\nPrime number\n");
    } else {
        printf("You entered negative number, please enter positive number: ");
        scanf("%d", &num);
        testPrime(num);
    }
}