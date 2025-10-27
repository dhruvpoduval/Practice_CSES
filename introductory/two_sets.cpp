#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    // To be able to divide the set into equal sums, the total sum of all elements must be even.
    long long sum = n*(n+1)/2;
    if(sum%2 != 0){
        std::cout << "NO" << std::endl;
        return 0;
    }

    // since n(n+1)/2 is dividible by 2, n, or n+1 should be divisible by 4, which means n%4==0 or n%4==3.
    std::vector<int> set1, set2;
    if(n % 4 == 0){
        // Divide the numbers ito blocks of 4, where first and last of each bock in set1, and middle two of each block in set2.
        for(int i = 1; i<= n/4; i++){
            int base = 4*i - 3;
            set1.push_back(base);
            set1.push_back(base+3);
            set2.push_back(base+1);
            set2.push_back(base+2);
        }
    }else if(n%4==3){
        // Manually add first three elements equally across to get concrete blocks of 4 for the rest. Then follow the same strategy, one by one add the rest across sets.
        set1.push_back(1);
        set1.push_back(2);
        set2.push_back(3);
        for(int base=4; base<=n; base+=4){
            set1.push_back(base);
            set1.push_back(base+3);
            set2.push_back(base+1);
            set2.push_back(base+2);
        }
    }
    std::cout << "YES" << std::endl;
    std::cout << set1.size() << std::endl;
    for(int num: set1){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << set2.size() << std::endl;
    for(int num: set2){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
