#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll t;
	cin >> t;

	for (ll T = 0; T < t; T++) {
		ll N;
		cin >> N;
		// N -> Number of Fabrics
		vector<pair<int, int>> charles;
		vector<pair<string, int>> ada;

		for (ll i = 0; i < N; i++) {
			string color;
			ll durability, identifier;
			cin >> color >> durability >> identifier;

			charles.push_back({ durability, identifier });
			ada.push_back({ color, identifier });
		}

		sort(charles.begin(), charles.end());
		sort(ada.begin(), ada.end());

		ll unchanged = 0;
		for (int i = 0; i < N; i++) {
			unchanged += (ada[i].second == charles[i].second);
		}

		cout << "Case #" << T+1 << ": " << unchanged << endl;
	}
}
