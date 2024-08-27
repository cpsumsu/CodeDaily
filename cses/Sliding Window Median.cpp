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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++) {
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
    }
}

// https://usaco.guide/problems/cses-1076-sliding-median/solution
void run_case() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);

	for (auto &x : A)
		cin >> x;

	multiset<int> lower, upper;
	lower.insert(A.front());

	vector<int> sol;

	auto increment = [&](int val) {
		auto last = *lower.rbegin();

		if (last < val) {
			upper.insert(val);

			if (int(upper.size()) > K / 2) {
				lower.insert(*upper.begin());
				upper.erase(upper.begin());
			}
		} else {
			lower.insert(val);

			// if there are odd number of element, lower must have (K + 1) / 2
			if (int(lower.size()) > (K + 1) / 2) {
				upper.insert(*lower.rbegin());
				lower.erase(prev(lower.end()));
			}
		}
	};

	auto remove = [&](int val) {
		if (auto it = lower.find(val); it != lower.end()) {
			lower.erase(it);
		} else {
			upper.erase(upper.find(val));
		}

		if (lower.empty()) {				// since must have an element for median
			auto it = upper.begin();
			lower.insert(*it);
			upper.erase(it);
		}
	};

	for (int i = 1; i < K; i++) 
		increment(A[i]);

	sol.push_back(*lower.rbegin());

	// sliding window, remove oldest and insert latest element
	for (int i = K; i < N; i++) {
		if (K == 1) {
			increment(A[i]);
			remove(A[i - K]);
		} else {
			remove(A[i - K]);
			increment(A[i]);
		}

		sol.push_back(*lower.rbegin());
	}

	output_vector(sol);
}	

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}