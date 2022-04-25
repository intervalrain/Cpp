#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

int randint(int n){
    if ((n - 1) == RAND_MAX)
        return rand();
    long end = RAND_MAX / n;
    assert (end > 0L);
    end *= n;
    int r;
    while ((r = rand()) >= end);

    return r % n;
}

int main(){
    srand(time(NULL));
    int i = rand();
    int x = randint(i);
    cout << x << endl;

    return 0;
}
