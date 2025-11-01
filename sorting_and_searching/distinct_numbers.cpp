#include <bits/stdc++.h>

int main(){
    // Taking input for the problem
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0; i<n; i++){
        std::cin >> arr[i];
    }
    int count = 1;
    std::sort(arr.begin(), arr.end());
    for(int i=1; i<n; i++){
        if(arr[i]!=arr[i-1]) count++;
    }
    std::cout << count << std::endl;
    // for(int i:arr){
    //     std::cout << i << " ";
    // }
    return 0;
}