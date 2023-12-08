#include <stdio.h>

int main(void) {
    int amount = 100, curAmt, items = 0;
    do
    {
        printf("You have Rs.%d.\nEnter cost of price, you want to purchase Rs.(20/5): ", amount);
        scanf("%d", &curAmt);
        if(curAmt < 5 || curAmt > 20) {
            printf("\nYou can't purchase items of prices other than Rs.20 & Rs.5\n");
            continue;;
        }
        if (amount < curAmt){
            printf("\nYou dont have enough amount to purchase Rs.20 items, try purchasing items of cost Rs.5\n");
            continue;
        }
        
        amount -= curAmt;
        items += 1;
    } while (amount > 0);

    printf("\nTotal items purchased are: %d\n\n", items);
    return 1;
}