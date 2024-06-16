#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int divide(int dividend, int divisor) {
        int64_t a = labs(dividend), b = labs(divisor);

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        int64_t cnt = 0;
        for (int ind = 1000000000; ind > 0; ind /= 10) {
            while (a >= ind * b) {
                a -= ind * b;
                cnt += ind;
            }
        }

        cnt = sign * cnt;

        if (cnt > INT_MAX) return INT_MAX;
        if (cnt < INT_MIN) return INT_MIN;

        return (int) cnt;
    }
};

class Solution_b {
public:
    int divide(int dividend, int divisor) {
        int64_t a = labs(dividend), b = labs(divisor);

        int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;

        int64_t ret = 0;
        while (a >= b) {
            int64_t tmp = b, cnt = 1;

            while (a >= (tmp << 1)) {
                tmp <<= 1;
                cnt <<= 1;
            }

            a -= tmp;
            ret += cnt;
        }

        ret *= sign;

        if (ret > INT_MAX) return INT_MAX;
        if (ret < INT_MIN) return INT_MIN;
        return ret;
    }  
};
int main()
{
   return 0;
}