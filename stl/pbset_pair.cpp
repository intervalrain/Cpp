#include <iostream>
#include <utility>
using namespace std;

void print(pair<int,char>* p, int n){
    for (int i = 0; i < n; i++){
        cout << "(" << p[i].first << ", " << p[i].second << ") ";
    }
    cout << endl;
}

bool comp2(pair<int,char> a, pair<int,char> b){
    return a.second < b.second;
}

int main(){
    int a[] = {2, 1, 5, 4, 8, 3, 6, 7};
    char b[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    pair<int,char> p[8];

    for (int i = 0; i < 8; i++){
        p[i] = make_pair(a[i], b[i]);
    }
    sort(p, p + 8);

    print(p, 8);

    sort(p, p+8, comp2);

    print(p, 8);

    return 0;
}
