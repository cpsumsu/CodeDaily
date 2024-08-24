#include <iostream>
#include <type_traits>
#include <vector>
#include <sstream>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;

template<typename T_container, typename = enable_if_t<!is_same_v<string, T_container>, typename T_container::value_type>> ostream &operator<<(ostream &os, const T_container &arg) { for (const auto &x : arg) os << x << ' '; return os; } 
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void println() { cerr << endl; }
template<typename Head, typename... Tail> void println(Head H, Tail... T) { cerr << H << ' '; println(T...); }

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

	int64_t N;
	cin >> N;


	while (N != 1) {
		cout << N << ' ';

		if (N & 1)
			N = N * 3 + 1;
		else
			N /= 2;
	} 

	cout << 1 << '\n';

    return 0;
}