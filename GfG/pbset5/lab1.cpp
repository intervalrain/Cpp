#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int roll_no[] = {17, 20, 15,  1,  5};
    int mark[]    = {80, 75, 93, 78, 84};
    int n = sizeof(mark)/sizeof(int);
    vector<pair<int,int> > vec;
    for (int i = 0; i < n; i++){
        vec.push_back(make_pair(mark[i], roll_no[i]));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++){
        cout << "(" << vec[i].second << ", " << vec[i].first << ")\n";
    }

    return 0;
}
