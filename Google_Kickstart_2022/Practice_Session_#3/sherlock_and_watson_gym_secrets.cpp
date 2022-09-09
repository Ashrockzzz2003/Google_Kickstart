#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll X = 1e9 + 7;

ll power_using_repeated_exponentiation(ll base, ll pow, ll mod) {
	//Base Case
	if (pow == 0) {
		return 1 % mod;
	}
	if (pow == 1) {
		return base % mod;
	}

	ll res = power_using_repeated_exponentiation(base * base % mod, pow / 2, mod);

	if (pow % 2 == 1) {
		return (base * res) % mod;
	}

	return res;
}


int main() {
	//Fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;

	for (ll T = 0; T < t; T++) {
		ll a, b, n, k;
		cin >> a >> b >> n >> k;

		vector<ll> L(k);

		//Precomputing a list where L[x] stores how many j exist such that x = (j^b)%k
		for (int j = 1; j <= min(n, k); j++) {
			ll num = ((n - j) / k + 1) % X;
			ll mod_p = power_using_repeated_exponentiation(j, b, k);
			L[mod_p] = (L[mod_p] + num) % X;
		}
		ll count = 0;
		for (int i = 1; i <= min(n, k); i++) {
			ll num = ((n - i) / k + 1) % X;
			ll key = (k - power_using_repeated_exponentiation(i, a, k)) % k;
			count += (L[key] * num) % X;

			if (power_using_repeated_exponentiation(i, b, k) == key) {
				count += X - num;
			}
		}
		cout << "Case #" << T + 1 << ": " << count % X << endl;
	}
}
