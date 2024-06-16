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
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), ans = 0;
        vector<vector<int>> moves = {{0,1}, {1, 0}};
        function<void(int,int)> dfs = [&](int x, int y) {
            board[x][y] = 'D';
            for (auto& v : moves)
            {
                int xx = v[0] + x, yy = v[1] + y;
                if (xx >= m || xx < 0 || yy >= n || yy < 0) continue;
                if (board[xx][yy] == 'D' || board[xx][yy] == '.') continue;
                dfs(xx, yy);
            }
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.' || board[i][j] == 'D') continue;
                ans++;
                dfs(i,j);
            }
        return ans;
    }
};
int main()
{
   return 0;
}