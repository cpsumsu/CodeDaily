#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> tmp;
        for (int i = 1 - m; i < n; ++i)
        {
            int x = i < 0 ? 0 - i : 0;
            int y = i < 0 ? 0 : i;
            while(x < m && y < n)
                tmp.push_back(mat[x++][y++]);
            sort(tmp.begin(), tmp.end());
            int idx = tmp.size() - 1;
            while(idx >= 0)
                mat[--x][--y] = tmp[idx--];
            tmp.clear();
        }
        return mat;
    }
};
int main()
{
   return 0;
}