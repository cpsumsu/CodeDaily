#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int N = piles.size(), sum = 0;
        // piles[j] is the second highest number of coins in each round
        for (int i = 0, j = N - 2; i < j; i++, j -= 2) {
            sum += piles[j];
        }

        return sum;
    }
};

class Solution_b {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int N = piles.size(), sum = 0;
        for (int i = N - 2; i > N / 3 - 1; i -= 2) {
            sum += piles[i];
        }

        return sum;
    }
};