#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        return mainTank * 10 + min((mainTank - 1) / 4, additionalTank) * 10;
    }
};
int main()
{
   return 0;
}