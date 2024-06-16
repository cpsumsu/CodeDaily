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
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); ++i)
            for (auto a : words[i])
            {
                if (a == x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        return ans;
    }
};
int main()
{
   return 0;
}