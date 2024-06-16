#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n);

        a[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;

        for (int i = 1; i < n; i++) {
            int A = a[t2] * 2;
            int B = a[t3] * 3;
            int C = a[t5] * 5;

            a[i] = min({A, B, C});

            if (a[i] == A) t2++;
            if (a[i] == B) t3++;
            if (a[i] == C) t5++;
        }

        return a[n - 1];
    }
};