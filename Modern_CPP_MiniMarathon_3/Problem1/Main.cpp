#include "Functionalities.hpp"

/*
    Client code:
        g++ Main.cpp Functionalities.cpp -lpthread -o app && time ./app && rm app
*/
int main(){
    Container threads;
    int f1_param = 10;
    std::vector<int> f2_param {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 5> f3_param {2, 3, 4, 5, 6};
    std::array<int, 5> f4_param {2, 3, 4, 5, 6};

    std::promise<int> pr;

    createThreads(threads, f1_param, f2_param, f3_param, f4_param);

    std::future<void> ft = std::async(std::launch::async, generateAndDisplayIntegers, std::ref(pr));

    for (std::thread& th : threads)
        if (th.joinable()) 
            th.join();

    int num = 5;
    pr.set_value(num);
    
    return 0;
}