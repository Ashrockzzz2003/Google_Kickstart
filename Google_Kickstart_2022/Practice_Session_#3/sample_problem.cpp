#include <bits/stdc++.h>
using namespace std;

int main() {
    //Reduce RunTime
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        long long int n, m;
        cin >> n >> m;
        long long int sum = 0;
        for(int j = 0; j < n; j++){
            long long int temp;
            cin >> temp;
            sum += temp;
        }
        cout << "Case #" << i+1 << ": " << sum%m << endl;
    }
}
