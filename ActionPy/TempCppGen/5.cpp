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
using namespace std;


class Solution_a {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<2) return s;

        int pos=0,len=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int i=0; i<n;i++){
            dp[i][i] = true;
            for(int j=0;j<=i;j++){
                int L = i-j+1;
                if(s[i] == s[j] && (L<3 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    if (L >= len){
                        len=L;
                        pos=j;
                    }
                }
            }
        }
        return s.substr(pos,len);
    }
};

class Solution_b {
public:
    string longestPalindrome(string s) {
        //initialisation
        int start=0;
        int length=1;
        int n=s.length();

        //loop through the even and odd centres
        for(int i=0;i<n;i++){
            //even 
            int lower = i;
            int upper = i+1;
            while((upper < n && lower >=0) && s[lower]==s[upper]){
                if((upper-lower+1) >= length) length = upper-lower+1,start=lower ;
                lower--;
                upper++;
            }

            //odd
            lower = i-1;
            upper = i+1;
            while((upper < n && lower >=0) && s[lower]==s[upper]){
                if((upper-lower+1) >= length) length = upper-lower+1,start=lower ;
                lower--;
                upper++;
            }
        }
        return s.substr(start,length);
    }
    
};
int main()
{
   return 0;
}