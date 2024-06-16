#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    const int MOD = 1e9 + 7;
    // x : 1000
    // y : 0111
    // x * y = x * (y' + 2^k) = x * y' + x * 2^k
    // ===
    // x' : 1110
    // y' : 0001
    // (x + 2^k) * y' = x * y' = y' + 2^k
    // 一共有 2^(p - 1) - 1 對
    // ans = (2^p - 1)(2^p - 2)^(p-1)
    long long pow(long long x, int p)
    {
        x %= MOD;
        long long a = 1;
        while(p--)
        {
            a = a * x % MOD;
            // 用於乘積 x % MOD
            x = x * x % MOD;
        }
        return a;
    }
    int minNonZeroProduct(int p) {
        
        long long k = (1LL << p) - 1;
        return k % MOD * pow(k - 1, p - 1) % MOD;
    }
};