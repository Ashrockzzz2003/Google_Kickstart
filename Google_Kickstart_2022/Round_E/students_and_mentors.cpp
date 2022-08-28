#include <bits/stdc++.h>
using namespace std;

int can_be_mentor(long long int i, long long int j, long long int r[]){
    if(r[j-1] <= 2*r[i-1]){
        return 1;
    }
    return 0;
}

int find_max_rating_mentor(long long int i, long long int r[], long long int n){
    long long int max = -1;
    for(long long int j = 1; j < n+1; j++){
        if(i != j){
            if(can_be_mentor(i, j, r) == 1){
                if(r[j-1] > max){
                    max = r[j-1];
                }
            }
        }
    }
    return max;
}

int main() {
	//Reduce RunTime
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long int t;
    cin>>t;

    for(int x = 0; x < t; x++){
        long long int n;
        cin >> n;
        long long int r[n];
        for(long long int k = 0; k < n; k++){
            cin >> r[k];
        }
        cout << "Case #" << x+1 << ": ";
        for(long long int k = 1; k < n+1; k++){
            if(k == n){
                cout << find_max_rating_mentor(k, r, n);
            }
            else{
                cout << find_max_rating_mentor(k, r, n) << " ";
            }
        }
        cout << endl;
    }
}
