#include <bits/stdc++.h>
using namespace std;

void mergeSort(int[],int,bool(*)(int,int));
void merge(int[],int,int,int,bool(*)(int,int));
void sortSub(int[],int,int,bool(*)(int,int));

void mergeSort(int a[], int n, bool (*comp)(int,int)){
    sortSub(a, 0, n - 1, comp);
}

void sortSub(int a[], int left, int right, bool (*comp)(int,int)){
    if (right <= left)
        return;
    int mid = left + (right - left)/2;
    sortSub(a, left, mid, comp);
    sortSub(a, mid + 1, right, comp);
    merge(a, left, mid, right, comp);
}

void merge(int a[], int left, int mid, int right, bool (*comp)(int,int)){
    int i = left, j = mid + 1;
    vector<int> vec;
    while (i <= mid && j <= right){
        if (!comp(a[i], a[j])){
            vec.push_back(a[i++]);
        } else {
            vec.push_back(a[j++]);
        }
    }
    if (i == mid + 1){
        while (j <= right){
            vec.push_back(a[j++]);
        }
    } else if (j == right + 1) {
        while (i <= mid){
            vec.push_back(a[i++]);
        }
    }
    j = 0;
    for (i = left; i <= right; ++i){
        a[i] = vec[j++];
    }
}

bool asc(int x, int y) { return x < y; }
bool desc(int x, int y) { return x > y; }

int main(){
    int a[] = {0,2,5,6,9,1,3,4,8,7};
    mergeSort(a, 10, asc);
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
    cout << "\n";

    int b[] = {0,2,5,6,9,1,3,4,8,7};
    mergeSort(b, 10, desc);
    for (int i = 0; i < 10; ++i)
        cout << b[i] << " ";
    cout << "\n";

    return 0;
}
