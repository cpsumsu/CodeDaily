#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int b(int n)
    {
        int cnt = 0;
        while(n)
        {
            if (n % 2 == 1) cnt++;
            n /= 2;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (b(i) == k) ans += nums[i];
        }
        return ans;
    }
};
int main()
{
   return 0;
}