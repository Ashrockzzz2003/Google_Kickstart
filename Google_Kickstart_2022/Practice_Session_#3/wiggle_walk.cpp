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
		int n, r, c, s_r, s_c;
		cin >> n >> r >> c >> s_r >> s_c;
		//r -> Number of Rows
		//c -> Number of Columns
		//s_r -> initial r
		//s_c -> initial c

		string instructions;
		cin >> instructions;

		//Changing to our 0 based matrix system
		s_r -= 1;
		s_c -= 1;

		vector< vector<bool> > seen(r, vector<bool>(c)); //Maze with Boolean values to represent seen squares
		seen[s_r][s_c] = 1;

		for (int j = 0; j < n; j++) {
			//East
			if (instructions[j] == 'E') {
				while (seen[s_r][s_c + 1] == 1) {
					s_c++;
				}
				s_c++;
				seen[s_r][s_c] = 1;
			}

			//West
			else if (instructions[j] == 'W') {
				while (seen[s_r][s_c - 1] == 1) {
					s_c--;
				}
				s_c--;
				seen[s_r][s_c] = 1;
			}

			//South
			else if (instructions[j] == 'S') {
				while (seen[s_r + 1][s_c] == 1) {
					s_r++;
				}
				s_r++;
				seen[s_r][s_c] = 1;
			}

			//North
			else if (instructions[j] == 'N') {
				while (seen[s_r - 1][s_c] == 1) {
					s_r--;
				}
				s_r--;
				seen[s_r][s_c] = 1;
			}
		}

		cout << "Case #" << i + 1 << ": " << s_r + 1 << " " << s_c + 1 << endl;
	}
}
