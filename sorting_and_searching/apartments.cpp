#include <bits/stdc++.h>

int main(){
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> sizes(n);
    std::vector<int> apartments(m);
    for(int i=0; i<n; i++){
        std::cin >> sizes[i];
    }
    for(int i=0; i<m; i++){
        std::cin >> apartments[i];
    }
    std::sort(sizes.begin(), sizes.end());
    std::sort(apartments.begin(), apartments.end());
    
    int count = 0, i=0, j=0;
    while(i<m && j<n){
        if(apartments[i] < sizes[j]-k){
            i++;
        }else if(apartments[i] > sizes[j]+k){
            j++;
        }else{
            count++;
            i++;
            j++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}