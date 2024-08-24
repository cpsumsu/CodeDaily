#include <iostream>
#include <map>
using namespace std;


void run_case() {
	int64_t N, T;
	cin >> N >> T;

	map<int64_t, int64_t> m;
	m[0] = 1;  						// if prefix_sum - T == 0, that means no need to remove any element from subarray, 
	int64_t prefix_sum = 0, sol = 0;

	for (int64_t i = 0; i < N; i++) {
		int64_t a;
		cin >> a;
		prefix_sum += a;

		sol += m[prefix_sum - T];
		m[prefix_sum]++;
	}	

	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}