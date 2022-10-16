#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll prefix_sum(vector<ll> arr, ll i, ll j) {
	if (arr[i] < 0) {
		return 0;
	}

	ll psum = 0;
	while (i < j) {
		psum += arr[i];
		if (psum < 0) {
			return 0;
		}
		i++;
	}

	return psum;
}

int main() {
	ll t;
	cin >> t;

	for (ll T = 1; T <= t; T++) {
		ll n;
		cin >> n;

		vector<ll> arr(n);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}

		ll happy = 0;
		for (ll i = 0; i < n; i++) {
			for (ll j = i + 1; j <= n; j++) {
				happy += prefix_sum(arr, i, j);
			}
		}

		cout << "Case #" << T << ": " << happy << endl;
	}
}
