#include <stdio.h>
#include "header.h"

float getAvg(int *arr, int len) {
    int sum = 0;
    float avg;
    for (int i = 0; i < CHANCE; i++)
        sum += arr[i];
    avg = (float) sum / CHANCE;
    return avg;
}

void getMaxScoreAvg(float *arr, int len) {
    float max = arr[0];
    int maxIndex = 0;
    for (int i = 1; i < CHANCE; i++){
        // printf("%f ", arr[i]);
        if (arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }  
    printf("\nThe selected candidate with the highest average score is %d with an average score of %f\n\n", (maxIndex + 1), max);
}

void solution(Player *p) {
    float avgArr[CHANCE];
    float ans;
    for (int i = 0; i < CHANCE; i++){
        avgArr[i] = getAvg(p[i].scores, CHANCE);
    }
    getMaxScoreAvg(avgArr, CHANCE);

}