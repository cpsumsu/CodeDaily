#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < j;)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return {i+1,j+1};
            else if (sum > target) j--;
            else i++;
        }
        return {};
    }
};
int main()
{
   return 0;
}