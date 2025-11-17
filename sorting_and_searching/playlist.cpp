#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> songs(n);
    for(int i=0; i<n; i++){
        cin >> songs[i];
    }

    map<int, int> last_occurence;
    int left =0;
    int max_length = 0;

    for(int right=0; right<n; right++){
        if(last_occurence.count(songs[right])){
            left = max(left, last_occurence[songs[right]] + 1); // Move left pointer to the right of the last occurrence. We use max to ensure left only moves forward.
        }
        last_occurence[songs[right]] = right; // Update the last occurrence of the current song
        max_length = max(max_length, right - left + 1); // Update the maximum length
    }

    cout << max_length << "\n";
    return 0;
}


// {1, 1, 1, 3, 3, 3, 3, 4, 5, 5}