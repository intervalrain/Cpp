#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<int>& vec){
    cout << "[";
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end() - 1; ++it){
        cout << *it << ", ";
    }
    cout << *it << "]" << endl; 
}

void print(vector<char>& vec){
    cout << "[";
    vector<char>::iterator it;
    for (it = vec.begin(); it != vec.end() - 1; ++it){
        cout << *it << ", ";
    }
    cout << *it << "]" << endl; 
}

void print(vector<double>& vec){
    cout << "[";
    vector<double>::iterator it;
    for (it = vec.begin(); it != vec.end() - 1; ++it){
        cout << *it << ", ";
    }
    cout << *it << "]" << endl; 
}

void print(vector<string>& vec){
    cout << "[";
    vector<string>::iterator it;
    for (it = vec.begin(); it != vec.end() - 1; ++it){
        cout << *it << ", ";
    }
    cout << *it << "]" << endl; 
}