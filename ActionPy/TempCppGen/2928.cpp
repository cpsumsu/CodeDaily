#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int i = 0; i <= limit; ++i)
            for (int j = 0; j <= limit; ++j)
                if (i + j > n) break;
                else if (n - i - j <= limit) ans++;
        return ans; 
    }
};
int main()
{
   return 0;
}