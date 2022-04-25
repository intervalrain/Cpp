#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &nums){
    vector<int>::iterator iter;
    for (iter = nums.begin(); iter != nums.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

// how to initialize vector
int main(){
    // 1. using push_back
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    print(A);

    // 2. using the overloaded constructor
    vector<int> B(3, 2);
    print(B);

    // 3. passing an array to the vector constructor(need -std=c++11)
    vector<int> C{1, 2, 3, 4, 5};
    print(C);

    // 4. using an existing array
    int array[] = {1,2,3,4,5};
    vector<int> D(array, array+4);
    print(D);

    // 5. using an existing vector
    vector<int> E(C.begin()+1, C.end()-3);
    print(E);

    // 6. using the fill method
    vector<int> F(6);
    fill(F.begin(), F.end(), 6);
    print(F);
}


