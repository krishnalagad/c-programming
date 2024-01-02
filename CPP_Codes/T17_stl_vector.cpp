#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(120);
    v1.push_back(40);
    v1.push_back(80);
    v1.push_back(60);

    for (int i = 0; i < v1.size(); i++)
        std::cout<<v1[i]<<" ";
    
    std::cout<<"\n";
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++)
        std::cout<<v1[i]<<" ";
    
    v1.pop_back();

    std::cout<<"\n";
    std::vector<int>::iterator it = v1.begin();
    while (it != v1.end()){
        std::cout<<*it<<" ";
        it++;
    }
    
    return 0;
}