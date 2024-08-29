#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <stack>
#include <list>
#include <deque>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;


template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename = enable_if_t<!is_same_v<string, T_container>, typename T_container::value_type>> ostream &operator<<(ostream &os, const T_container &arg) { for (const auto &x : arg) os << x << ' '; return os; } 

#ifdef PO_DEBUG
template <typename> struct is_tuple: std::false_type {};
template <typename ...T> struct is_tuple<std::tuple<T...>>: std::true_type {};
template<typename T> void tuple_out(T &&t) { apply([](auto &&...arg) { ((cout << arg << ' '), ...) << '\n'; }, t); }

template <typename T> void _deduce(T arg) { if constexpr (is_tuple<T>::value) { tuple_out(arg); } else { cerr << arg << ' '; } }
template<typename... Arg> void println(Arg&&... args) { (_deduce(args), ...); cerr << '\n'; }

#define dbug_out(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "): ", println(__VA_ARGS__)
#else
#define dbug_out(...)
#endif


template<typename T>
void output_matrix(const vector<vector<T>> &v, bool add_one = false, int except = -1) {
    cout << "==================debug: ================================" << '\n';
    if (except == -1) except = INT_MAX;
    int N = v.size(), M = v[0].size();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) 
            cout << v[i][j] + (add_one ? 1 : 0) << " \n"[j == M - 1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,mod=1e9+7;
    cin>>n;

    int S = n*(n+1)/2; //calculate total sum 1 to n
    int s = S/2; // total sum / 2 = requires sum of each subset

    vector<vector<int>> dp(n,vector<int>(s+1,0)); //2D vector declared
    //dp[i][sum] = no. of ways to make sum using numbers 0 to i

    
    dp[0][0] = 1;// number of ways to make 0 using 0 = 1

    for(int w=0;w<=s;w++)
    {
        
        for(int i=1;i<n;i++)//till n-1 as we permanently put n into a particular subset to avoid repeats
        {
            dp[i][w] = dp[i-1][w];
            if(w - i >= 0)
            {
                dp[i][w] = dp[i-1][w] + dp[i-1][w-i];
                // ways = (either not include that number keeping the w same) or (include the number decreasing w by i.)
                dp[i][w] %= mod;
            }

            output_matrix(dp);
        }
    }

    output_matrix(dp);
    cout << (S % 2 ? 0 : dp[n - 1][s]) << '\n';
    
    return 0;
}