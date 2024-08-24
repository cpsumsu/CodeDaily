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

void run_case() {
	int N, T;
	cin >> N >> T;
	map<int, int> m;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		int want = T - x;
		
		if (m.find(want) != m.end()) {
			cout << i + 1 << ' ' << m[want] + 1 << '\n';
			return ;
		}

		m[x] = i;
	}

	cout << "IMPOSSIBLE" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}