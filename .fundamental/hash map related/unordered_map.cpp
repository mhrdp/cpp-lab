#include <iostream>
#include <unordered_map>

// This is equivalent to dictionary in python
std::unordered_map<char, int> myMap = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
};

int main(){
    // auto will tell the compiler to determine the type of data by its own
    for(auto i: myMap){
        // .first is the key, and .second is the value
        std::cout << i.first << ' ' << i.second << std::endl; 
    }

    return 0;
}
