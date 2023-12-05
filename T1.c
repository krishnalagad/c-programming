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

    int choice = 1;
    switch (choice)
    {
        default:
        printf("Default\n");
        // break;
        case 1:
            printf("\nOne\n");
            // break;
        case 2:
        printf("Two\n");
            break;
        case 3:
            printf("Three\n");
            break;

    // -------------------------------------------------------------------------
        
        int x = -1, y = 5;
        int z = ++x || ++y;
        printf("\nx = %d, y = %d, z = %d\n\n", x, y, z);
    }

    return 0;
}