#include <stdio.h>
#include <math.h>

int main(void)
{
    int lowerLimit, upperlimit;
    printf("Enter lower limit and upper limit seperated by blank space: ");
    scanf("%d %d", &lowerLimit, &upperlimit);

    for (int i = lowerLimit; i <= upperlimit; i++)
    {

        printf("%f\t", pow(i, 2));
    }
    printf("\n");
    return 0;
}
