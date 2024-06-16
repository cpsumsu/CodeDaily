#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;
class unionfind {
public:
    unionfind(int n)
    {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    bool unite(int a, int b)
    {
        int pa = find(a), pb = find(b);
        if (pa == pb)
            return false;
        if (size[pa] > size[pb])
        {
            p[pb] = pa;
            size[pa] += size[pb];
        }
        else
        {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    int getSize(int root)
    {
        return size[root];
    }
private:
    vector<int> p, size;
};



class Solution_a {
public:

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        unionfind uf(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (graph[i][j])
                    uf.unite(i, j);
        int ans = n, mx = 0;
        vector<int> cnt(n);
        for (int x : initial) ++cnt[uf.find(x)];
        for (int x : initial)
        {
            int root = uf.find(x);
            // 有一個節點被感染，那麼移除這個節點後，該連通分量中的其他節點都不會被感染；
            // 如果有多個節點被感染，那麼移除任意一個感染節點後，該連通分量中 的其他節點還是會被感染
            // 如果該連通分量中只有一個被感染節點，即cnt[root]=1，我們就更新答案
            if (cnt[root] == 1)
            {
                // 我們利用並查集uf 維護節點的連通關係，用一個變數 ans 記錄答案，
                // 用一個變數mx 記錄當前能減少感染的最大節點數，
                // 初始時ans=n, mx=0。
                // 然後遍歷數組 initial，用一個哈希表或一個長度為 n 的數組 cnt 來統計每個連通分量中被感染節點的個數。
                // 接下來，我們再遍歷數組initial，對於每個節點x，我們找到其所在的連通分量的根節點root，
                
                // 更新的條件是該連通分量中的節點數sz 大於mx 或sz 等於mx 且 x 的值小於ans。
                int sz = uf.getSize(root);
                if (sz > mx || (sz == mx && ans > x))
                {
                    ans = x;
                    mx = sz;
                }
            }
        }
        // 最後，如果 ans 沒有被更新，說明所有的連通分量中都有多個被感染節點，
        // 那麼我們返回 initial 中的最小值，否則返回 ans。
        return ans == n ? *min_element(initial.begin(), initial.end()) : ans;
    }
};
int main()
{
   return 0;
}