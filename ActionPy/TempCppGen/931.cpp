#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
#include <unordered_set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <string.h>
#include <numeric>
#include <cassert>
#include <cmath>
#include <cstdint>
using namespace std;


class Solution_a {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j == 0)
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                else if (j == M - 1)
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                else 
                    matrix[i][j] += min({matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i - 1][j + 1]});
            }
        }

        return *min_element(matrix[N - 1].begin(), matrix[N - 1].end());
    }
};
int main()
{
   return 0;
}