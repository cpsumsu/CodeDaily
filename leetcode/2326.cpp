#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <stack>
#include <list>
#include <deque>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ans(n, vector<int>(m, -1));

        vector<pair<int, int>> direction {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> times {m, n - 1};
        int steps = 0;
        auto it = head; 

        int x = 0, y = -1;

        while (times[steps % 2]) {
            for (int i = 0; i < times[steps % 2] && it != nullptr; i++) {
                x += direction[steps].first;
                y += direction[steps].second;

                ans[x][y] = it->val;
                it = it->next;
            }

            if (it == nullptr) break;

            steps = (steps + 1) % 4;
            times[steps % 2]--;
        }

        return ans;
    }
};

void run_case() {
    
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}