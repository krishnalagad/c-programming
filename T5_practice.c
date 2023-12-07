#include <stdio.h>

void solution(int *p) {
    printf("\nEnter number: ");
    scanf("%d", p);
}
int main(void) {

    int a;
    int *ptr = &a;
    solution(ptr);
    printf("\nValue: %d\n\n", a);
    return 1;
}