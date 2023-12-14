#include <stdio.h>

static int num = 101;

void fun1() {
    int x = 10;
    {
        int x = 4;
        printf("%d\n", x);
    }
    printf("%d\n", x);
}

void fun2() {
    extern int num;
    printf("%d\n", num);
    num++;
}

int main(void) {
    fun2();
    fun2();
    return 1;
}