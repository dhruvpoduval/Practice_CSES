#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    // Store the numbers along with their original indices.
    vector<pair<int, int>> numbers(n);
    for(int i=0; i<n; i++){
        cin >> numbers[i].first;
        numbers[i].second = i; // original index
    }

    // Dry run
    // {{1,2}, {2,1}, {3,4}, {4,0}, {5,3}}
    int rounds = 1; // Number of rounds, first round always starting from 1
    sort(numbers.begin(), numbers.end()); // Sort based on the number values

    for(int i=0; i<n-1; i++){
        if(numbers[i].second > numbers[i+1].second){
            rounds++;
        }
    }
    cout << rounds << "\n";
    return 0;
}