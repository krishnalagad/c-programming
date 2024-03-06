#include <stdio.h>
#include "header.h"

int main(void) {
    Player p[SIZE];
    for (int i = 0; i < SIZE; i++){
        printf("Enter Id for player %d: ", (i + 1));
        scanf("%d", &p[i].id);
        for (int j = 0; j < CHANCE; j++){
            printf("For Plyer %d, Enter score %d: ", (i+1), (j+1));
            scanf("%d", &p[i].scores[j]);
        }
        printf("\n");
    }
    solution(&p);
    return 0;
}