#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {-1, -3, 4, 2, 3};
    int threshold = 3;
    int onTimeComers = std::count_if(std::begin(arr), std::end(arr), [](int num){return num <= 0;});
    int lateComers = std::count_if(std::begin(arr), std::end(arr), [](int num){return num > 0;});
    if (onTimeComers >= threshold)
        std::cout<<"YES"<<std::endl;
    else    
        std::cout<<"NO"<<std::endl;

    int key = 2;    //specify inside of [], if want to make accisible all vars then specify [=]
    int cnt = std::count_if(std::begin(arr), std::end(arr), [key](int ele){ return ele >= key;});
    std::cout<<"Number of elements >= "<<cnt<<std::endl;

    return 0;
}