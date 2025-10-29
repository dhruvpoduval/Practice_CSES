#include <bits/stdc++.h>

#define MOD 1000000007

int main(){
    long long n;
    std::cin >> n;
    int result = 1;
    for(int i=0; i<n; i++){
        result = (result%MOD * 2)%MOD;    // (result = result*2)%MOD = (result%MOD * 2%MOD)%MOD = (result%MOD * 2)%MOD 
    }
    std::cout << result << std::endl;
    return 0;
}