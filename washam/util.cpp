#include <iostream>

#define INITIAL_CAPACITY (1 << 4)
#define MAXIMUM_CAPACITY (1 << 30)

using namespace std;

class OutOfRange{
private:
    int _flag;
    int _size;
    int _index;
public:
    OutOfRange(){
        _flag = 1;
    }
    OutOfRange(int size, int index){
        _flag = 2;
        _size = size;
        _index = index;
    }
    void what(){
        if (_flag == 1){
            cout << "Error: empty array, no elements to pop." << endl;
        } else if (_flag == 2){
            cout << "Error: out of range (array length " << _size << ", access index " << _index << ")" << endl;
        } else {
            cout << "Unknown exception." << endl;
        }
    }
};

int tableSizeFor(int cap) {
    if (cap >= MAXIMUM_CAPACITY) return MAXIMUM_CAPACITY;
    int i = 1;
    while (i < cap){
        i <<= 1;
    }
    return (cap < 0) ? 1 : (i >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : i;
}