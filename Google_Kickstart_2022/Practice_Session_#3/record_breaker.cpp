#include <bits/stdc++.h>
using namespace std;

int main() {
	//Reduce RunTime
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<int> visitors;

		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			visitors.push_back(temp);
		}
		int record_count = 0;
		int current_maximum = -1;
		if (n == 1) {
			record_count = 1;
		}
		else {
			for (int j = 0; j < n - 1; j++) {
				if (visitors[j] > current_maximum) {
					current_maximum = visitors[j];
					if (visitors[j] > visitors[j + 1]) {
						record_count++;
					}
				}
			}
			if (visitors[n - 1] > current_maximum) {
				record_count++;
			}
		}
		cout << "Case #" << i + 1 << ": " << record_count << endl;
	}
}
