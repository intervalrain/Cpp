#include <iostream>
using namespace std;

int main(){
    // int* ptr1 = 0;          -->  ptr1 is uninitialized so it becomes an invalid pointer
    int arr[10];
    // int* ptr2 = arr + 20;   -->  ptr2 is out of bounds of arr so it becomes an invalid pointer

    int *ptr3 = 0;    //       -->  ptr3 is a Null pointer which point nowhere and not just an invalid address.
    int *ptr4 = NULL; //       -->  ptr4 is a Null pointer too.

    return 0;
}
