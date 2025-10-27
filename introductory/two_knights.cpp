#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    for(int i=1; i<=n; i++){
        //std::cout << n << std::endl;;
        long long total_ways = (long long)(i*i) * (i*i-1) / 2;
        long long attack_ways = 4*(i-1)*(i-2);
        std::cout << total_ways-attack_ways << std::endl;
    }
    return 0;
}

