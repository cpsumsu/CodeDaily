#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int moves[] = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        vector<int> vis(jug1Capacity + jug2Capacity + 1, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            // reach target
            if (cur == targetCapacity) return true;

            // move like a bfs
            for (auto v : moves)
            {
                int x = v + cur;
                if (x >= 0 && x <= jug1Capacity + jug2Capacity && vis[x] == 0)
                {
                    q.push(x);
                    vis[x] = 1;
                }
            }
            cout << cur << endl;
        }
        return false;
    }
};