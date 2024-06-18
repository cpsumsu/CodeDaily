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
#include <sstream>
#include <iomanip>
using namespace std;


class Solution_a {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string ans = "";
        string tmp = "";
        while(ss >> tmp)
        {
            if (!ans.empty())
                ans+= ' ';
            if (tmp.size() > 1 && tmp[0] == '$')
            {
                bool b = true;
                for (int i = 1; i < tmp.size(); ++i)
                {
                    char ch = tmp[i];
                    if (ch >= '0' && ch <= '9')
                        continue;
                    else 
                    {
                        b = false;
                        break;
                    }
                }
                if (b)
                {
                    stringstream sss;
                    sss << fixed << setprecision(2)
                        << '$' << stoll(tmp.substr(1)) * 
                        ((double)(1 - discount / 100.0));
                    ans += sss.str();
                }
                else
                    ans += tmp;
            }
            else
            {
                ans += tmp;
            }
        }
        return ans;
    }
};
int main()
{
   return 0;
}