#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll T;
    cin >> T;

    for (ll t = 1; t <= T; t++) {
        ll l, n;
        cin >> l >> n;

        vector<ll> d(n);
        vector<char> c(n);

        for (ll i = 0; i < n; i++) {
            cin >> d[i] >> c[i];
        }


        ll current_position = 0;
        ll lap_count = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] == 'C') {
                lap_count += abs((current_position + d[i]) / l);
                current_position = (current_position + d[i]) % l;
            }
            else if (c[i] == 'A') {
                lap_count += abs((current_position - d[i]) / l);
                current_position = (current_position - d[i]) % l;
            }
        }

        cout << "Case #" << t << ": " << lap_count << endl;
    }
}
