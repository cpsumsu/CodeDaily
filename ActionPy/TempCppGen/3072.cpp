#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;
class smt {
    vector<int> tree;
public:
    smt(int n) : tree(n) {}

    void add(int i)
    {
        while(i < tree.size())
        {
            tree[i]++;
            i += i & -i;
        }
    }
    int pre(int i)
    {
        int res = 0;
        while(i > 0)
        {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};



class Solution_a {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        auto a = nums;
        ranges::sort(a);
        int m = a.size();
        a.erase(unique(a.begin(), a.end()), a.end());
        smt t1(m + 1), t2(m + 1);
        t1.add(ranges::lower_bound(a, nums[0]) - a.begin() + 1);
        t2.add(ranges::lower_bound(a, nums[1]) - a.begin() + 1);
        vector<int> a1{nums[0]}, a2{nums[1]};

        for (int i = 2; i < n; ++i)
        {
            int x = nums[i];
            int v = ranges::lower_bound(a, x) - a.begin() + 1;
            int g1 = a1.size() - t1.pre(v);
            int g2 = a2.size() - t2.pre(v);
            if (g1 > g2 || g1 == g2 && a1.size() <= a2.size())
            {
                a1.push_back(x);
                t1.add(v);
            }
            else
            {
                a2.push_back(x);
                t2.add(v);
            }
        }
        a1.insert(a1.end(), a2.begin(), a2.end());
        return a1;
    }
};
int main()
{
   return 0;
}