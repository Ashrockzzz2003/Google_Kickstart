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

		vector<int> start_point;
		vector<int> end_point;

		for (int j = 0; j < n; j++) {
			int start, end;
			cin >> start >> end;

			start_point.push_back(start);
			end_point.push_back(end);
		}

		int number_of_cities;
		cin >> number_of_cities;

		vector<int> gbus_count;

		for (int j = 0; j < number_of_cities; j++) {
			int query;
			cin >> query;

			int count = 0;

			for (int k = 0; k < n; k++) {
				if (query >= start_point[k] && query <= end_point[k]) {
					count++;
				}
			}

			gbus_count.push_back(count);
		}

		cout << "Case #" << i + 1 << ": ";

		for (int j = 0; j < number_of_cities; j++) {
			if (j == number_of_cities - 1) {
				cout << gbus_count[j] << endl;
			}
			else {
				cout << gbus_count[j] << " ";
			}
		}

	}
}
