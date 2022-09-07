#include <bits/stdc++.h>
using namespace std;


int main() {
	//Reduce runtime
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string I;
		string P;
		cin >> I;
		cin >> P;

		int i = 0, j = 0; //Two-pointer approach. If same, move both one step, otherwise move only the second one.

		while (i < I.length() && j < P.length()) {
			if (I[i] == P[j]) {
				i++;
				j++;
			}
			else {
				j++;
			}
		}

		if (i != I.length()) {
			cout << "Case #" << t + 1 << ": " << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "Case #" << t + 1 << ": " << P.length() - I.length() << endl;
		}
	}
}
