#include <iostream>
#include <assert.h>


using namespace std;
#define DEFAULT_CAPACITY 8
#define true 1
#define false 0

template <class T>
class myVector{
private:
    size_t _size;
    size_t _capacity;
public:
    T* arr;
    myVector(){
        this->_size = 0;
        this->_capacity = DEFAULT_CAPACITY;
        this->arr = new int[this->_capacity];
    }
    myVector(int capacity){
        this->_size = 0;
        this->_capacity = capacity;
        this->arr = new int[this->capacity];
    }
    myVector(const myVector<T>& v):
        _size(v.size),
        _capacity(v._capacity)
    {
        this->reserve(v.capacity);
        for (size_t i = 0; i < v._size; ++i){
            this->push_back(v[i]);
        }
    }
    myVector(size_t n, T val):
        _size(n),
        _capacity(n)
    {
        this->arr = new int[this->_capacity];
        for (size_t i = 0; i < n; ++i){
            this->arr[i] = val;
        }
    }
    ~myVector(){
        delete[] this->arr;
    }

    size_t size(){
        return this->_size;
    }

    size_t capacity(){
        return this->_capacity;
    }

    T* begin(){
        return this->arr;
    }

    T* end(){
        return this->arr + this->_size;
    }

    const T* begin() const{
        return this->arr;
    }

    const T* end() const{
        return this->arr + this->_size;
    }

    bool isEmpty(){
        return this->_size == 0;
    }

    // force to resize with a n capacity
    void reserve(size_t n){
        if (n > this->_capacity){
            T* tmp = new T[n];
            if (arr != nullptr){
                for (size_t i = 0; i < this->_size; ++i){
                    tmp[i] = this->arr[i];
                }
                delete[] this->arr;
            }
            this->arr = tmp;
            _capacity = n;
        }
    }

    // operator overload
    T& operator[](size_t i){
        assert (i < this->_size);
        return this->arr[i];
    }

    // expand the capacity while adding elements
    void resize(){
        this->_capacity *= 2;
        int* tmp = new int[this->_capacity];
        for (size_t i = 0; i < this->_size; ++i){
            tmp[i] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = tmp;
    }

    // adding elements in the last of vector
    void push_back(T val){
        if (this->_capacity < this->_size + 1)
            resize();
        this->arr[this->_size] = val;
        this->_size++;
    }

    // remove elements in the last of vector
    T pop_back(){
        assert(!this->isEmpty());
        T tmp = *(this->end()-1);
        this->_size--;
        return tmp;
    }

    // insert element by the index.
    void insert(size_t i, T val){
        assert (i <= this->_size);
        if (this->_size + 1 > this->capacity()) resize();
        int* ptr = this->begin() + i;
        for (int* it = this->end(); it != ptr; --it)
            *it = *(it - 1);
        *ptr = val;
        this->_size++;
    }

    //erase element by the index
    T erase(size_t i){
        assert(i < this->_size);
        int* it = this->begin() + i;
        T tmp = *it;
        for (; it != this->end(); ++it){
            *it = *(it + 1);
        }
        this->_size--;
        return tmp;
    }
};

int main(){
    myVector<int> vec;

    cout << vec.isEmpty() << endl;                                      // []: true
    for (size_t i = 0; i <= 9; ++i){                                    // [0,1,2,3,4,5,6,7,8,9]
        vec.push_back(i);
    }
    cout << "the size of vector is: " << vec.size() << endl;            // the size of vector is: 10
    cout << "the capacity of vector is: " << vec.capacity() << endl;    // the capacity of vector is: 16
    cout << vec.isEmpty() << endl;                                      // false
    cout << vec.pop_back() << endl;                                     // [0,1,2,3,4,5,6,7,8]: 9
    cout << vec.pop_back() << endl;                                     // [0,1,2,3,4,5,6,7]: 8
    vec.insert(5, 111);                                                 // [0,1,2,3,4,111,5,6,7]
    vec.erase(4);                                                       // [0,1,2,3,111,5,6,7]

    for (int* it = vec.begin(); it != vec.end(); ++it){                 // [0,1,2,3,111,5,6,7]
        cout << *it << " ";
    }
    cout << endl;

    int* it = vec.begin() + 5;
    cout << *it << endl;                                                // [0,1,2,3,111,5,6,7]: 5
    vec.reserve(32);
    cout << "the size of vector is: " << vec.size() << endl;            // the size of vector is: 8
    cout << "the capacity of vector is: " << vec.capacity() << endl;    // the capacity of vector is: 32
    cout << *it << endl;

    return 0;
}