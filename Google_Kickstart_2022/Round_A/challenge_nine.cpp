#include <bits/stdc++.h>
using namespace std;

int digit_sum(string N) {
	int sum = 0;
	for (int i = 0; i < N.size(); i++) {
		sum += N[i] - 48;
	}

	return sum;
}

int main() {
	//Reduce RunTime
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string N;
		cin >> N;

		int remainder = 9 - (digit_sum(N) % 9);
		if (remainder == 9) {
			remainder = 0;
		}

		int flag = 0; // To keep track of Insertion of digit

		cout << "Case #" << t + 1 << ": ";
		if (remainder == 0) {
			cout << N[0];
			cout << "0"; // Insert "0" in the seccond place

			for (int i = 1; i < N.size(); i++) {
				cout << N[i];
			}
		}
		else {
			for (int i = 0; i < N.size(); i++) {
				if (flag == 1) {
					cout << N[i];
				}
				else {
					if (N[i] - 48 > remainder) {
						cout << remainder;
						cout << N[i];
						flag = 1; //Digit Inserted
					}
					else {
						cout << N[i];
					}
				}
			}
			if (flag == 0) {
				cout << remainder; // Insert Digit in the End
			}
		}

		cout << endl;
	}
}