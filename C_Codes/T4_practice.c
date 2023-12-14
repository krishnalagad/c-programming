#include <stdio.h>
#include <string.h>

int main(void)
{

    int a = 10, b;
    a >= 5 ? b = 100: (b = 200);
    printf("%d\n", b);

    char str[] = "Krishna lagad is my name";
    int c = 5;
    printf("%d %d\n", c++, c++);
    int len = printf(c > 10 ? "%50s\n" : "%s\n", str);
    printf("%d\n", len);

    // extern int func(float);
    // int a;
    // a = func(3.14);
    // printf("%d\n", a);
    // return 0;

    // int i = 1;
    // while (i < 10){       // condition in while loop in must.
    //     printf("%d\n", i++);
    //     // if (i > 10){
    //     //     break;
    //     // }
        
    // }

    // char str[20];
    // printf("Enter nmae: ");
    // scanf("%s", str);
    // printf("\nReversed: %s", strrev(str));  // function doen't exist
    
}



// int func(float num)
// // float num;
// {
//     return ((int)num);
// }
// // int a = 20;