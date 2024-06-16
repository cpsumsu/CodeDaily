#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;


class Solution_a {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int cnt = 0;
        for (int i = citations.size() - 1; i >= 0 && cnt < citations[i]; i--, cnt++)
            ;

        return cnt;
    }
};

class Solution_b {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();

        vector<int> brucket(N + 1);
        for (auto &x : citations) {
            if (x >= N)
                brucket[N]++;
            else
                brucket[x]++;
        }

        int cnt = 0;
        for (int i = N; i >= 0; i--) {
            cnt += brucket[i];

            if (cnt >= i)
                return i;
        }   

        return 0;
    }
};
int main()
{
   return 0;
}