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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        triangle[0].push_back(1);       // since often use push_back, the time used is longer 

        for (int i = 1; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    triangle[i].push_back(triangle[i - 1][j]);
                else if (j == i)
                    triangle[i].push_back(triangle[i - 1][j - 1]);
                else
                    triangle[i].push_back(triangle[i - 1][j] + triangle[i - 1][j - 1]); 
            }
        }

        return triangle;
    }   
};

class Solution_b {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        vector<int> vec {1};

        for (int j = 1; j < numRows; j++) {

            // i > 0, since the first element of each row is always 1
            for (int i = vec.size() - 1; i > 0; i--)
                vec[i] += vec[i - 1];

            // push 1 to the back of each row
            vec.push_back(1);
            ans.push_back(vec);
        }

        return ans;
    }
};

class Solution_c {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> tmp(i + 1, 1);

            for (int j = 1; j < i; j++) 
                tmp[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];

            // std::move() used suppose to be faster than previous two methods, but it might be restricted by leetcode compiler
            triangle.push_back(std::move(tmp));
        }    

        return triangle;
    }
};
int main()
{
   return 0;
}