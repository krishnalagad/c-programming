#include <stdio.h>
#include <math.h>

int main(void)
{
    // int lowerLimit, upperlimit;
    // printf("Enter lower limit and upper limit seperated by blank space: ");
    // scanf("%d %d", &lowerLimit, &upperlimit);

    // for (int i = lowerLimit; i <= upperlimit; i++)
    // {

    //     printf("%f\t", pow(i, 2));
    // }
    // printf("\n");

    int count = 0;
    int num = 2;
    while(count <= 500) {
        if (isPrime(num)){
            printf("%d is prime number.\n", num);
            count++;
        }
        num++;
    }
    return 0;
}

int isPrime(int num) {
    if (num < 2)
        return 0;

    for (int i = 2; i < num; i++){
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
