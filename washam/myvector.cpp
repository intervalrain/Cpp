#include <iostream>
#include <cstdlib>
#include "util.cpp"

#define INITIAL_CAPACITY (1 << 4)
#define MAXIMUM_CAPACITY (1 << 30)
using namespace std;

template <typename T>
class myvector{
private:
    T* arr;
    int _capacity;
    int _first;
    int _last;
public:
    myvector(){
        _capacity = INITIAL_CAPACITY;
        arr = new T[_capacity];
        _first = 0;
        _last = 0;
    }
    myvector(myvector<T>* begin, myvector<T>* end){
        int cap = tableSizeFor(end - begin);
        _capacity = cap;
        arr = new T[_capacity];
        int i = 0;
        for (auto it = begin; it != end; it++){
            arr[i++] = (*it);
        }
        _first = 0;
        _last = end - begin;
    }
    myvector(T* begin, T* end){
        int diff = end - begin;
        int cap = tableSizeFor(diff);
        _capacity = cap;
        arr = new T[_capacity];
        int i = 0;
        for (auto it = begin; it != end; it++){
            arr[i++] = (*it);
        }
        _first = 0;
        _last = end - begin;
    }

    myvector(int n, T item){
        int cap = tableSizeFor(n);
        _capacity = cap;
        arr = new T[_capacity];
        for (int i = 0; i < n; i++){
            arr[i] = item;
        }
        _first = 0;
        _last = n;
    }

    ~myvector(){
        delete [] arr;
    }

    int size(){
        return _last - _first;
    }
    int capacity(){
        return _capacity;
    }
    bool is_empty(){
        return size() == 0;
    }

    void checkBound(int index){
        if (index < _first || index >= _last){
            throw OutOfRange(size(), index);
        }
    }

    T at(int index){
        checkBound(index);
        return arr[index + _first];
    }

    T operator[](int index){
        return at(index);
    }

    void checkCap(){
        if (_last == _capacity){
            resize();
        }
    }

    void push_back(T item){
        checkCap();
        arr[_last++] = item;
    }

    void insert(int index, T item){
        checkCap();
        for (int i = _last ; i > _first; i--){
            arr[i] = arr[i-1];
        }
        arr[index + _first] = item;
        _last++;
    }

    void prepend(int index, T item){
        index < 0 ? (index + size()) : index;
        checkBound(index);
        insert(index, item);
    }

    T pop_back(){
        T tmp = arr[_last - 1];
        arr[_last - 1] = 0;
        _last--;
        return tmp;
    }

    T erase(int index){
        index += _first;
        T tmp = arr[index];
        for (int i = index; i < _last - 1; i++){
            arr[i] = arr[i + 1];
        }
        arr[_last - 1] = 0;
        _last--;
        return tmp;
    }
    bool remove(T item){
        int index = find(item);
        if (index == -1){
            return false;
        }
        erase(index);
        return true;
    }

    void removeAll(T item){
        while(remove(item));
    }
    int find(T item){
        for (int i = _first; i < _last; i++){
            if (arr[i] == item) {
                return i - _first;
            }
        }
        return -1;
    }

    void resize(int new_capacity){
        T* tmp = new T[new_capacity];
        int j = 0;
        for (int i = _first; i < _last; i++){
            tmp[j++] = arr[i];
        }
        _first = 0;
        _last = j;
        delete[] arr;
        _capacity = new_capacity;
        arr = tmp;
    }

    void resize(){
        resize(2 * _capacity);
    }

    T* begin(){
        return arr + _first;
    }
    T* end(){
        return arr + _last;
    }

    void print(){
        cout << "[";
        for (int i = _first; i != _last - 1; i++){
            cout << arr[i] << ", ";
        }
        cout << arr[_last-1] << "]" << endl;
    }

};

int main(){
    int nums[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(nums)/sizeof(int);
    myvector<int> v1(nums, nums + n);
    v1.print();

    myvector<int> v2(v1.begin(), v1.end());
    v2.print();

    myvector<int> v3(5, -1);
    v3.insert(0,100);
    v3.removeAll(-1);
    v3.print();

    cout << v3.pop_back() << endl;
    cout << v1.is_empty() << endl;
    cout << v3.is_empty() << endl;
    cout << v1.size() << endl;
    cout << v3.size() << endl;

    return 0;
}
