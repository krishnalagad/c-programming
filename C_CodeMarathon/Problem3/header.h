#define SIZE 3
#define CHANCE 3
typedef struct Cricket_Selection {
    int id;
    int scores[3];
} Player;

void solution(Player *);
float getAvg(int *arr, int len);
void getMaxScoreAvg(float *arr, int len);