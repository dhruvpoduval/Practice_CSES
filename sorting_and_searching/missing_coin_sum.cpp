#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    // Sort the coins in ascesnding order
    sort(coins.begin(), coins.end());

    long long current_sum = 0;
    for(int i=0; i<n; i++){
        // We can accept the coin c if c <= current_sum + 1
        // Else if the coin is larger than current_sum+1, then it exposes the smallest missing sum
        if(coins[i] > current_sum+1){
            cout << current_sum + 1 << "\n";
            return 0;
        }
        current_sum += coins[i];

    }

    //If we reach till the end without finding a mising sum, just return the next sum
    cout << current_sum + 1 << "\n";

    return 0;
}