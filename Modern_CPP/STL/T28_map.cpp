#include <iostream>
#include <map>
#include <algorithm>

int main() {
    std::map<int, std::string> map;
    map[10] = "Krishna";
    map[20] = "Samiksha";
    map[30] = "Bhushan";
    std::map<int, std::string>::iterator it;
    for(it = map.begin(); it != map.end(); ++it)
        std::cout<<(*it).first<<" "<<(*it).second<<std::endl;
    
    map.insert({40, "Smita"});
    for(it = map.begin(); it != map.end(); ++it)
        std::cout<<(*it).first<<" "<<(*it).second<<std::endl;

    map.insert({{50, "Poonam"}, {60, "Ankita"}});
    for(it = map.begin(); it != map.end(); ++it)
        std::cout<<(*it).first<<" "<<(*it).second<<std::endl;

    return 0;
}