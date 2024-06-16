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
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int N = img.size(), M = img[0].size();
        vector<vector<int>> ret = img;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int cnt = 1;

                // check up
                if (i - 1 >= 0) {
                    ret[i][j] += img[i - 1][j];
                    cnt++;
                }

                // down
                if (i + 1 < N) {
                    ret[i][j] += img[i + 1][j];
                    cnt++;
                }

                // left
                if (j - 1 >= 0) {
                    ret[i][j] += img[i][j - 1];
                    cnt++;
                }

                // right
                if (j + 1 < M) {
                    ret[i][j] += img[i][j + 1];
                    cnt++;
                }

                // up left
                if (i - 1 >= 0 && j - 1 >= 0) {
                    ret[i][j] += img[i - 1][j - 1];
                    cnt++;
                }

                // down left
                if (i + 1 < N && j - 1 >= 0) {
                    ret[i][j] += img[i + 1][j - 1];
                    cnt++;
                }

                // up right
                if (i - 1 >= 0 && j + 1 < M) {
                    ret[i][j] += img[i - 1][j + 1];
                    cnt++;
                }

                // dwon right
                if (i + 1 < N && j + 1 < M) {
                    ret[i][j] += img[i + 1][j + 1];
                    cnt++;
                }

                ret[i][j] /= cnt;
            }
        }

        return ret;
    }
};

class Solution_b {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int N = img.size(), M = img[0].size();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int cnt = 0, sum = 0;

                // enumerate all 9 directions
                for (auto &&x : {-1, 0, 1}) {
                    for (auto &&y : {-1, 0, 1}) {
                        int dx = i + x, dy = j + y;

                        // if dx or dy is out-of-bound, skip
                        if (dx < 0 || dx >= N || dy < 0 || dy >= M) 
                            continue;

                        // get the original value of img[dx][dy]
                        sum += (img[dx][dy] & 0xFF);
                        cnt++;
                    }
                }

                // store the new value start from 9th bit
                img[i][j] |= ((sum / cnt) << 8);
            }
        }

        // since the last 8 bits are old value, so remove them
        for (auto &x : img)
            for (auto &y : x)
                y >>= 8;

        return img;
    }
};
int main()
{
   return 0;
}