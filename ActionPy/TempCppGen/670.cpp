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
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int n = charArray.size();
        int maxNum = num;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(charArray[i], charArray[j]);
                maxNum = max(maxNum, stoi(charArray));
                swap(charArray[i], charArray[j]);
            }
        }
        return maxNum;
    }
};
int main()
{
   return 0;
}