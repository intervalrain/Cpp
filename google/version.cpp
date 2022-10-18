#include <bits/stdc++.h>
using namespace std;

struct apk_info{
    int apk_version;
    int min_version = 1;
    int max_version = INT_MAX;

    apk_info(int ver, int mn, int mx){
        this->apk_version = ver;
        this->min_version = mn;
        this->max_version = mx;
    }
};

vector<int> find_version(vector<apk_info>& apk, vector<int>& ver){
    sort(apk.begin(), apk.end());
    vector<int> line;

}
// 1----8----12----16------MAX
//   v2   x     v3      v1

int main(){
    apk_info* a1 = new apk_info(1, 14, INT_MAX);
    apk_info* a2 = new apk_info(2, 1, 8);
    apk_info* a3 = new apk_info(3, 12, 16);

    vector<apk_info> apk = {*a1, *a2, *a3};
    vector<int> ver = {18, 4, 14, 10};    // 1, 2, 3, 0
    vector<int> res = find_version(apk, ver);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

