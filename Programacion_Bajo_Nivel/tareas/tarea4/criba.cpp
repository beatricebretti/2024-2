#include "criba.h"
#include <vector>

using namespace std;

unsigned long criba(unsigned long num) {
    if (num < 2) return 0;

    vector<bool> is_prime(num + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (unsigned long p = 2; p * p <= num; ++p) {
        if (is_prime[p]) {
            for (unsigned long multiple = p * p; multiple <= num; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    unsigned long prime_count = 0;
    for (size_t i = 0; i <= num; ++i) {
        if (is_prime[i]) ++prime_count;
    }
    return prime_count;
}