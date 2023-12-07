#include <stdio.h>

void solution(int *p) {
    printf("\nEnter number: ");
    scanf("%d", p);
}

void calculate(int *e, int *o, int num) {
    int eCount = 0;
    int oCount = 0;
    int i = 1,eSum = 0, oSum = 0;
    while (eCount < num || oCount < num){
        if (i % 2){
            oSum += i;
            oCount++;
        } else {
            eSum += i;
            eCount++;
        }
        i++;
    }
    *e = eSum;
    *o = oSum;
}

int main(void) {

    // int a;
    // int *ptr = &a;
    // solution(ptr);
    // printf("\nValue: %d\n\n", a);
    int eSum, oSum;
    calculate(&eSum, &oSum, 10);
    printf("\nSum of even numbers: %d \nSum of odd numbers: %d\n", eSum, oSum);
    return 1;
}