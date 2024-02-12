#include <iostream>
#include <vector>
#include <future>

float averageOfNValues(std::future<int>& ft) {
    std::vector<int> data {10, 20, 30, 40, 50};

    int N = ft.get();
    if (data.size() < N || N < 0)
        throw std::runtime_error("Invalid operation!!\n");
    
    float ans = 0.0f;
    int count = 0;

    for (auto itr = data.begin(); count < N; count++) {
        ans += *itr;
        itr++;
    }

    return ans / N;
}

/*
    g++ async_demo1.cpp -lpthread -g -o app && ./app && rm app
*/
int main() {
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    /*
        any param we pass to std::async(), std::bind() or std::thread() with a function pointer
        such that param must be received by the function as reference, you must 
        pass such a param by using std::ref()
    */
    std::future<float> result = std::async(std::launch::async, averageOfNValues, std::ref(ft));

    int n {0};
    std::cin >> n;

    pr.set_value(n);

    std::cout << "Average: " << result.get() << std::endl;

    return 0;
}

/*
    PARALLEL Execution of threads using async programming: Pictorial representation


     MAIN                                                                                                                       set value                               WAITING for other 
    Thread                                                                                                                      in promise                              thread to complete                    
-------------->Future and Promise objects created---------->Async thread launched---------->Value created-------->USER INPUT-------------------> Go to avg thread------------------------------->Print result in main thread


                                                            averageOfNValues                                               WAITING                                                   cal avg
                                                            -------------------> Vector creation--------->count variable------------> START_NOW -----------> check/throw Exception--------------->send result signal 
                                                                                                                                                                                                  to Main thread

*/