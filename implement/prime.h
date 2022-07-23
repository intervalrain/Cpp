#ifndef ALGO_PRIME_H
#define ALGO_PRIME_H

#include <stdlib.h>
#include <math.h>

namespace alg {
    static bool true_prime(unsigned n){
        
        if (n == 0 || n == 1)
            return false;
        else if (n == 2)
            return true;
        else if (n % 2 == 0)
            return false;
        
        unsigned sqrtn = sqrt((double)n);
        for (unsigned int i = 3; i <= sqrtn; i += 2){
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }

    static inline bool miller_rabin_prime(unsigned n){
        switch (n){
            case 0:
            case 1:
                return false;
            case 2:
            case 3:
                return true;
        }

        if (n % 2 == 0) return false;

        unsigned s = ZeroR(n-1);
        unsigned d = (n-1) >> s;

        for (int k = 0; k < 3; k++){
            unsigned a = rand() % (n-4) + 2;
            unsigned x = Exp(a, d, n);
        }
    }
}