#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n), d(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		// set best_defense to -1
		int best_defense = -1;
		for (int i = 0; i < n - 1; i++) {
			// if i == 0, then add the values from the last soldier and the next soldier
			// and check if the current soldier's defense is STRICTLY greater than the sum
			if (i == 0) {
				if (a[n - 1] + a[i + 1] < d[i]) {
					best_defense = max(best_defense, d[i]);
				}
			} else {
				// otherwise, add the values from the previous soldier and the next soldier
				// and check if the current soldier's defense is STRICTLY greater than the sum
				if (a[i - 1] + a[i + 1] < d[i]) {
					best_defense = max(best_defense, d[i]);
				}
			}
		}
		// create one more condition since the last soldier will not be iterated upon in the FOR loop
		// add the values of the previous soldier and the first soldier
		// and check if the current soldier's defense is STRICTLY greater than the sum
		if (a[n - 2] + a[0] < d[n - 1]) {
			best_defense = max(best_defense, d[n - 1]);
		}
		cout << best_defense << '\n';
	}
	return 0; 
}
