#include <iostream>

int main()
{
    int n = 2;
    int m = 3;

    int **arr = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(m * sizeof(int));
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = count++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << sizeof(arr) << std::endl;
    return 0;
}