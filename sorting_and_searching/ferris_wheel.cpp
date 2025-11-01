#include <bits/stdc++.h>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> weights(n);
    for(int i=0; i<n; i++){
        std::cin >> weights[i];
    }
    std::sort(weights.begin(), weights.end());

    int i=0, j=n-1;
    int gondolas = 0;
    while(i <=j){
        if(weights[i] + weights[j] <=x){
            i++;
            j--;
            gondolas++;
        }else{
            j--;
            gondolas++;
        }
    }
    std::cout << gondolas << std::endl;
    return 0;
}