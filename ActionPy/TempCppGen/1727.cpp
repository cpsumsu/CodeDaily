#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        vector<int> height(M);

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                height[j] = matrix[i][j] ? height[j] + 1 : 0;
            }

            vector<int> ordered_height = height;
            sort(ordered_height.begin(), ordered_height.end());

            for (int j = 0; j < M; j++) 
                ans = max(ans, ordered_height[j] * (M - j));
        }

        return ans;
    }
};