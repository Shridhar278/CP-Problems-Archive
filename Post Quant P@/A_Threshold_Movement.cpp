#include <bits/stdc++.h>
using namespace std;

// its OK will check shortly

void work() {
	int n; cin >> n;
	long long L = 0, R = 1000000001LL;

	for (int i = 1; i <= n; ++i) {
		long long w; cin >> w;
		if (i & 1) R = min(R, w);
		else L = max(L, w);
	}

	cout << (n % 2 == 0 && L + 2 <= R ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) work();

	return 0;
}