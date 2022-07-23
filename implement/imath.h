#ifndef ALGO_IMATH_H
#define ALGO_IMATH_H

#include <stdint.h>
#include <string.h>
#include <limits.h>

namespace alg {
    static uint32_t dot_product(const uint32_t* K, const uint32_t* A, uint32_t len) {
        uint32_t i;
        uint32_t sum = 0;
        for (i = 0; i < len; i++){
            sum += K[i] * A[i];
        }
        return sum;
    }
    static int dot_product(std::vector<int> K, std::vector<int> A){
        int sum = 0;
        for (int i = 0; i < K.size(); i++){
            sum += K[i] * A[i];
        }
        return sum;
    }


#define KLEN 64
    static void base(uint64_t key, int m, uint32_t k[]){
        memset(k, 0, sizeof(uint32_t) * KLEN);

        int quotient;
        int i = 0;
        while ((quotient = key/m) != 0){
            k[i] = key % m;
            key = quotient;
            i++;
        }
        k[i] = key;
    }

    static unsigned exp(unsigned base, unsigned exponent, unsigned modulus){
        unsigned result = 1;
        while (exponent > 0){
            if (exponent % 2 == 1){
                result = (uint64_t(result)*base) % modulus;
            }
            exponent = exponent >> 1;
            base = (uint64_t(base)*base) % modulus;
        }
        return result;
    }

    static inline int ZeroR(unsigned int v){
        int c;
        if (v){
            v = (v ^ (v-1)) >> 1;
            for (c = 0; v != 0; c++){
                v >>= 1;
            }
        } else {
            c = CHAR_BIT * sizeof(v);
        }
        return c;
    }
}

#endif