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
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n;++i)
        {
            // 每次數組刪除都會增加cnt格
            if ((i - cnt) % 2 == 0 && i + 1 < n)
                if (nums[i] == nums[i+1]) cnt++;
        }
        // 如果剩下的數組長度為奇數，就再減1
        if ((n - cnt) % 2 == 0)
            return cnt;
        else
            return cnt + 1;
    }
};
int main()
{
   return 0;
}