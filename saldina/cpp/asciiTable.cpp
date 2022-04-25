#include <iostream>

using namespace std;

int main(){
    cout << "  ";
    for (int i = 0; i < 10; i++){
        printf("%3d",i);
    }
    for (int i = 60; i < 130; i++){
        if (i % 10 == 0){
            cout << endl;
            printf("%3d", i / 10);
        }
        printf(" %c ",i);
    }
    return 0;

}
