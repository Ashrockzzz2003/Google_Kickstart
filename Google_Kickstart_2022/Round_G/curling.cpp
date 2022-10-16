#include <bits/stdc++.h>
#define ll long long
using namespace std;

double distance(ll x1, ll y1) {
	return sqrt(x1 * x1 + y1 * y1);
}

ll circle(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2){
	double d = sqrt((x1 - x2) * (x1 - x2)
		+ (y1 - y2) * (y1 - y2));

	if (d <= r1 - r2) {
		return 1;
	}
	else if (d < r1 + r2) {
		return 1;
	}
	else if (d == r1 + r2) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	ll t;
	cin >> t;

	for (ll T = 1; T <= t; T++) {
		ll rs, rh;
		cin >> rs >> rh;

		ll n;
		cin >> n;

		vector<pair<ll, ll>> red(n);

		for (ll i = 0; i < n; i++) {
			ll x, y;
			cin >> x >> y;

			red[i] = { x, y };
		}

		ll m;
		cin >> m;

		vector<pair<ll, ll>> yellow(m);

		for (ll i = 0; i < m; i++) {
			ll x, y;
			cin >> x >> y;

			yellow[i] = { x, y };
		}

		if (m == 0) {
			ll score = 0;
			for (ll i = 0; i < n; i++) {
				if (circle(0, 0, rh, red[i].first, red[i].second, rs) == 1) {
					score++;
				}
			}

			cout << "Case #" << T << ": " << score << " 0" << endl;
		}
		else if (n == 0) {
			ll score = 0;
			for (ll i = 0; i < n; i++) {
				if (circle(0, 0, rh, yellow[i].first, yellow[i].second, rs) == 1) {
					score++;
				}
			}

			cout << "Case #" << T << ": " << score << " 0" << endl;
		}
		else {
			// house region -> circle of radius rh

			vector<double> red_sort;
			vector<double> yellow_sort;

			for (ll i = 0; i < n; i++) {
				if (circle(0, 0, rh, red[i].first, red[i].second, rs) == 1) {
					red_sort.push_back(distance(red[i].first, red[i].second));
				}
			}

			for (ll i = 0; i < m; i++) {
				if (circle(0, 0, rh, yellow[i].first, yellow[i].second, rs) == 1) {
					yellow_sort.push_back(distance(yellow[i].first, yellow[i].second));
				}
			}

			sort(red_sort.begin(), red_sort.end());
			sort(yellow_sort.begin(), yellow_sort.end());

			ll red_score = 0;
			ll yellow_score = 0;

			/*
			cout << "RED STATE" << " ";
			for (ll i = 0; i < red_sort.size(); i++) {
				cout << red_sort[i] << " ";
			}
			cout << endl;

			cout << "YELLOW STATE" << " ";
			for (ll i = 0; i < yellow_sort.size(); i++) {
				cout << yellow_sort[i] << " ";
			}
			cout << endl;
			*/

			for (ll i = 0; i < red_sort.size(); i++) {
				if (lower_bound(yellow_sort.begin(), yellow_sort.end(), red_sort[i]) - yellow_sort.begin() == 0) {
					red_score++;
				}
			}

			for (ll i = 0; i < yellow_sort.size(); i++) {
				if (lower_bound(red_sort.begin(), red_sort.end(), yellow_sort[i]) - red_sort.begin() == 0) {
					yellow_score++;
				}
			}
			
			if(yellow_sort.size() == 0){
			    cout << "Case #" << T << ": " << red_sort.size() << " " << yellow_sort.size() << endl;
			}
			else if(red_sort.size() == 0){
			    cout << "Case #" << T << ": " << red_sort.size() << " " << yellow_sort.size() << endl;
			}
			else{
			    cout << "Case #" << T << ": " << red_score << " " << yellow_score << endl;   
			}
		}
	}
}
