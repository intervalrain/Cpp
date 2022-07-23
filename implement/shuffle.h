#ifndef ALGO_SHUFFLE_H
#define ALGO_SHUFFLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

namespace alg {
    template<typename T>
    static void shuffle(T* list, int n){
        srand(time(NULL));

        if (n == 0) return;
        int j;
        int i = n;
        T tmp;
        while (--i){
            j = rand() % (i + 1);
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
        }
    }
    template <typename T>
    static void shuffle(std::vector<T> list){
        
        srand(time(NULL));
        int n = list.size();
        int i = n, j;
        T tmp;
        if (i == 0) return;
        while (--i){
            j = rand() % (i + 1);
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
        }
    }
}

#endif