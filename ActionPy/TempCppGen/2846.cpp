#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // LCA 模版，CV的，日後再看
        // https://www.bilibili.com/video/BV1Nj411178Z/?vd_source=c8f797eb0ed2b9ae031c806a2b48a232
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1], w = e[2] - 1;
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }

        int m = 32 - __builtin_clz(n); // n 的二进制长度
        vector<vector<int>> pa(n, vector<int>(m, -1));
        vector<vector<array<int, 26>>> cnt(n, vector<array<int, 26>>(m));
        vector<int> depth(n);
        function<void(int, int)> dfs = [&](int x, int fa) {
            pa[x][0] = fa;
            for (auto [y, w]: g[x]) {
                if (y != fa) {
                    cnt[y][0][w] = 1;
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        for (int i = 0; i < m - 1; i++) {
            for (int x = 0; x < n; x++) {
                int p = pa[x][i];
                if (p != -1) {
                    int pp = pa[p][i];
                    pa[x][i + 1] = pp;
                    for (int j = 0; j < 26; ++j) {
                        cnt[x][i + 1][j] = cnt[x][i][j] + cnt[p][i][j];
                    }
                }
            }
        }

        vector<int> ans;
        for (auto &q: queries) {
            int x = q[0], y = q[1];
            int path_len = depth[x] + depth[y]; // 最后减去 depth[lca] * 2
            int cw[26]{};
            if (depth[x] > depth[y]) {
                swap(x, y);
            }

            // 让 y 和 x 在同一深度
            for (int k = depth[y] - depth[x]; k; k &= k - 1) {
                int i = __builtin_ctz(k);
                int p = pa[y][i];
                for (int j = 0; j < 26; ++j) {
                    cw[j] += cnt[y][i][j];
                }
                y = p;
            }

            if (y != x) {
                for (int i = m - 1; i >= 0; i--) {
                    int px = pa[x][i], py = pa[y][i];
                    if (px != py) {
                        for (int j = 0; j < 26; j++) {
                            cw[j] += cnt[x][i][j] + cnt[y][i][j];
                        }
                        x = px;
                        y = py; // x 和 y 同时上跳 2^i 步
                    }
                }
                for (int j = 0; j < 26; j++) {
                    cw[j] += cnt[x][0][j] + cnt[y][0][j];
                }
                x = pa[x][0];
            }

            int lca = x;
            path_len -= depth[lca] * 2;
            ans.push_back(path_len - *max_element(cw, cw + 26));
        }
        return ans;
    }
};