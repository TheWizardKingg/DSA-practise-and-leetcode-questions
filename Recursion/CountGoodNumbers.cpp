#include <iostream>
using namespace std;

class Solution {
public:
    long long power(long long x, long long n, long long mod) {
        long long result = 1;

        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * x) % mod;
            }

            x = (x * x) % mod;
            n /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1000000007;

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long a = power(5, even, mod);
        long long b = power(4, odd, mod);

        return (a * b) % mod;
    }
};