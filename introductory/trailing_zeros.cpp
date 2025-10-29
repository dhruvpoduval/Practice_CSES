#include <bits/stdc++.h>

// Intuition : for every trailing 0, there will be a pair of (2, 5) creating this 0. So, counting the number of such pairs is feasible.
// Now, the number of 2's will always be larger due to the every even number providing a 2.
// Hence we only need to count the number of 5's in the fators of numbers from 1 to n.
int main(){
    int n;
    std::cin >> n;
    int count_of_five = 0;
    for(int i = 5; i <= n; i *=  5){
        count_of_five += n/i;
    }
    std::cout << count_of_five << std::endl;
    return 0;
}

// We divide n by successive powers of 5 (5, 25, 125, ...).
// Each division counts how many numbers contribute a factor of 5 to n!.
// For example:
//   - n/5 counts numbers contributing at least one 5.
//   - n/25 counts numbers (like 25, 50, 75, 100) that contribute an extra 5.
// The total number of 5s = n/5 + n/25 + n/125 + ... 
// And since each (2,5) pair forms a trailing zero, this gives the total number of trailing zeros.
