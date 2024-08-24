#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void run_case() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (auto &x : A)	
		cin >> x;

	auto min_operation = [&]() -> int {
		unordered_set<int, int> s;
		int sol = 0;

		for (int i = 0; i < N; i++) {
			if (A[i] == 1 || !s[A[i] - 1])
				sol++;
			s[A[i]] = true;
		}

		return sol;
	};

	auto first = min_operation();

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		swap(A[a - 1], A[b - 1]);


	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}