#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

class Solution_b {
public:
    vector<int> g;

    int climbStairs(int n) {
        g.resize(n + 1);
        return climb(n);
    }

    int climb(int n) {
        if (n <= 2)
            return n;

        if (g[n]) return g[n];

        return g[n] = climb(n - 1) + climb(n - 2);
    }   
};

class Solution_c {
public:
    int climbStairs(int n) {
        vector<int> A(n + 1);

        A[0] = 1;
        A[1] = 2;
        for (int i = 2; i < n; i++)
            A[i] = A[i - 1] + A[i - 2];

        return A[n - 1];
    }
};

class Solution_d {
public:
    int climbStairs(int n) {
        int pre = 1, cur = 1, tmp;

        for (int i = 1; i < n; i++) {
            tmp = cur;
            cur = cur + pre;
            pre = tmp;
        }

        return cur;
    }
};

class Solution_e {
public:
    int climbStairs(int n) {
        n++;
        return (pow(0.5 * (1 + sqrt(5)), n) - pow(0.5 * (1 - sqrt(5)), n)) / sqrt(5);
    }
};
int main()
{
   return 0;
}