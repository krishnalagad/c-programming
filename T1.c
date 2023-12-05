#include <stdio.h>

int main()
{
    // int *arr[10]; // array of integer pointers
    // int(*p)[6];   // p is pointer to an array
    // int x = -10, y = -1;
    int a = 4;
    int b = ++a * a++ * a++;
    int c = a;
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    // ------------------------------------------------------------------

    int arr[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    int *ptr = arr;
    for (int i = 0; i < sizeof(arr) / 4; i++){
        printf("%d\t", *ptr);
        sum += *ptr++;
    }
    printf("\n%d\n", sum);
    printf("%d %d %d\n", sum++, sum++, sum++);

    // -----------------------------------------------------------------------

    

    return 0;
}