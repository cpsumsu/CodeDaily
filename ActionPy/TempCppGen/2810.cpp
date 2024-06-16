#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    string finalString(string s) {
        string ans = "";
        for (auto ch : s) 
            if (ch == 'i') 
                for (int i = 0; i < ans.size() / 2; ++i)
                    swap(ans[i], ans[ans.size() - 1 - i]);
            else
                ans+=ch;
        return ans;
    }
};
int main()
{
   return 0;
}