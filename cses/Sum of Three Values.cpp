#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// // TLE 
// void run_case() {
// 	int64_t N, T;
// 	cin >> N >> T;

// 	vector<int64_t> A(N);
// 	for (auto &x : A)
// 		cin >> x;

// 	unordered_map<int64_t, int64_t> contains;
// 	for (int64_t i = 0; i < N - 2; i++) {
// 		int64_t target = T - A[i];

// 		if (target <= 0)
// 			continue;

// 		for (int64_t j = i + 1; j < N; j++) {
// 			int64_t oppo = target - A[j];

// 			if (oppo <= 0)
// 				continue;

// 			if (contains[oppo]) {
// 				cout << i + 1 << ' ' << contains[oppo] << ' ' << j + 1 << '\n';
// 				return ;
// 			} else {
// 				contains[A[j]] = j + 1;
// 			}
// 		}
// 	}

// 	cout << "IMPOSSIBLE" << '\n';
// }

void run_case() {
	int64_t N, T;
	cin >> N >> T;

	vector<array<int64_t, 2>> A(N);
	for (int i = 0; i < N; i++) {
		auto &[a, b] = A[i];
		cin >> a;
		b = i + 1;
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N - 2; i++) {
		int64_t target = T - A[i][0];
		int64_t lo = i + 1, hi = N - 1;

		while (lo < hi) {
			int compare = A[lo][0] + A[hi][0] - target;

			if (compare == 0) {
				cout << A[i][1] << ' ' << A[lo][1] << ' ' << A[hi][1] << '\n';
				return ;
			}

			if (compare < 0)
				lo++;
			else
				hi--;
		}
	}

	cout << "IMPOSSIBLE" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}