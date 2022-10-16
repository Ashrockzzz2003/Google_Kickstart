#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll t;
	cin >> t;

	for (ll T = 0; T < t; T++) {
		ll m, n, p;
		cin >> m >> n >> p;

		// m -> Participant ID
		// n -> Total number of days
		// p -> Last Year PID of John

		// find max_diff of steps between john and participants.

		vector<vector<ll>> data(m, vector<ll> (n));

		for (ll i = 0; i < m; i++) {
			for (ll j = 0; j < n; j++) {
				cin >> data[i][j];
			}
		}

		// Finding max steps on each day.
		vector<ll> max_steps(n);

		for (ll i = 0; i < n; i++) {

			ll max_col = data[0][i];
			for (ll j = 1; j < m; j++) {
				if (data[j][i] > max_col) {
					max_col = data[j][i];
				}
			}

			max_steps[i] = max_col;
		}

		ll improve = 0;
		for (ll i = 0; i < n; i++) {
			if (data[p - 1][i] < max_steps[i]) {
				improve += abs(max_steps[i] - data[p - 1][i]);
			}
		}

		cout << "Case #" << T+1 << ": " << improve << endl;
	}
}
