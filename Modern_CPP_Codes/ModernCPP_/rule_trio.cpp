#include <iostream>

class Vehicle {
    private:
        int* _readingArrays;
        int _vahicleId;
        int _readingSize;
    public:
        Vehicle() = default;
        Vehicle(int* reading, int id, int size): _vahicleId(id) {
            this->_readingArrays = new int[size];
            _readingSize = size;
            for (int i = 0; i < size; i++) 
                _readingArrays[i] = reading[i];
        }
        Vehicle(const Vehicle& vehicle) {
            this->_readingSize = vehicle._readingSize;
            this->_vahicleId = vehicle._vahicleId;
            this->_readingArrays = new int[vehicle._readingSize];
            for (int i = 0; i < vehicle._readingSize; i++) 
                _readingArrays[i] = vehicle._readingArrays[i];
        }
        Vehicle& operator=(const Vehicle& vehicle) {
            this->_readingSize = vehicle._readingSize;
            this->_vahicleId = vehicle._vahicleId;
            this->_readingArrays = new int[vehicle._readingSize];
            for (int i = 0; i < vehicle._readingSize; i++) 
                _readingArrays[i] = vehicle._readingArrays[i];
            return *this;
        }
        ~Vehicle() { delete []_readingArrays; }
};

/*
    g++ rule_trio.cpp -g -fsanitize=address -o app && time ./app && rm app
*/
int main() {
    int arr[] = {1,2,3,4,5};
    Vehicle v1(arr, 101, 5);
    return 0;
}