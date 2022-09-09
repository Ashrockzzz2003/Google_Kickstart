#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s) {
	/*Returns true if string s is a palindrome of length greater than or equal to 5*/
	int n, flag = 1;
	n = s.size();

	if (n < 5) {
		return true;
	}
	else {
		for (int i = 0; i < n / 2; i++) {
			if (s[i] != s[n - i - 1]) {
				flag = 0;
				break;
			}
		}
	}

	if (flag == 1) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, l;
		cin >> n;

		string s, temp_1, temp_2;
		cin >> s;

		int flag = 0; // True when options is empty {true: "IMPOSSIBLE", false: "POSSIBLE"}

		queue<string> options, seen;

		cout << "Case #" << t + 1 << ": ";

		if (n < 5) {
			cout << "POSSIBLE" << endl;
			continue; //Move to next case
		}
		else {
			if (s[0] == '?') {
				options.push("1");
				options.push("0");
			}
			else if (s[0] == '1') {
				options.push("1");
			}
			else {
				options.push("0");
			}

			for (int i = 1; i < n; i++) {
				while (options.empty() == false) {
					temp_1 = options.front();
					options.pop();

					l = temp_1.size() + 1;

					if (s[i] == '?') {
						// CASE_1 Trying 0
						temp_2 = temp_1 + "0";

						if (l < 5) {
							seen.push(temp_2);
						}
						else if (l == 5) {
							if (palindrome(temp_2) == false) {
								seen.push(temp_2);
							}
						}
						else {
							if (palindrome(temp_2) == false && palindrome(temp_2.substr(1, l - 1)) == false) {
								seen.push(temp_2.substr(1, l - 1));
							}
						}

						// CASE_2 Trying 1 
						temp_2 = temp_1 + "1";

						if (l < 5) {
							seen.push(temp_2);
						}
						else if (l == 5) {
							if (palindrome(temp_2) == false) {
								seen.push(temp_2);
							}
						}
						else {
							if (palindrome(temp_2) == false && palindrome(temp_2.substr(1, l - 1)) == false) {
								seen.push(temp_2.substr(1, l - 1));
							}
						}
					}
					else {
						temp_2 = temp_1 + s[i];

						if (l < 5) {
							seen.push(temp_2);
						}
						else if (l == 5) {
							if (palindrome(temp_2) == false) {
								seen.push(temp_2);
							}
						}
						else {
							if (palindrome(temp_2) == false && palindrome(temp_2.substr(1, l - 1)) == false) {
								seen.push(temp_2.substr(1, l - 1));
							}
						}
					}

				}
				while (seen.empty() == false) {
					options.push(seen.front());
					seen.pop();
				}

				if (options.empty() == true) {
					flag = 1;
					break;
				}
			}

			if (flag == 1) {
				cout << "IMPOSSIBLE" << endl;;
			}
			else {
				cout << "POSSIBLE" << endl;
			}
		}
	}
}
