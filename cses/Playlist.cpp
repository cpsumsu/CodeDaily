#include <iostream>
#include <vector>
#include <map>
using namespace std;

void run_case() {
	int N;
	cin >> N;
	vector<int> A(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	int sol = 0;
	map<int, int> mp;

	for (int i = 0, j = 0; i < N; i++) {
		while (j < N && mp[A[j]] < 1) {
			mp[A[j]]++;
			j++;
		}

		sol = max(sol, j - i);
		mp[A[i]]--;
	}

	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}