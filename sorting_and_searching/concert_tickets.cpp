#include <bits/stdc++.h>

int main(){
    int n, m;
    std::cin >> n >> m;

    // Using multiset for ore efficient searching and deletion operations.
    std::multiset<int> tickets;
    for(int i=0; i<n; i++){
        int price;
        std::cin >> price;
        tickets.insert(price);
    }

    for(int i=0; i<m; i++){
        int price;
        std::cin >> price;

        // Upper bound returns an iterator to the first element greater than the given price. 0-based index.
        auto it = tickets.upper_bound(price);
        // If the first element (tickets.begin()) is the upper bound, it means there is no ticket less than or equal to the price.
        if(it == tickets.begin()){
            std::cout << -1 << std::endl;
        }else{
            // Reduce the iterator by 1 to point to the largest ticket price for the customer(because the next index it is the first element greater than the price).
            --it;
            std::cout << *it << std::endl; // Print the ticket price. *it because it is an iterator, used to access the value.
            tickets.erase(it); // Remove the ticket from the multiset.
        }
    }

    // std::vector<int> tickets(n);
    // for(int i = 0; i < n; ++i){
    //     std::cin >> tickets[i];
    // }
    // std::vector<int> customers(m);
    // for(int i = 0; i < m; ++i){
    //     std::cin >> customers[i];
    // }

    // Sort the tickets array
    // std::sort(tickets.begin(), tickets.end());

    // For each customer, perform binary search to find the ticket price, or the next lower closest price.  
    // for(int i=0; i<m; i++){
    //     int price = customers[i];
    //     int low = 0, high = tickets.size()-1;
    //     int res = -1;
    //     while(low <= high){
    //         int mid = low + (high - low)/2;
    //         if(tickets[mid] <= price){
    //             res = mid;
    //             low = mid+1;
    //         }else{
    //             high = mid-1;
    //         }
    //     }
    //     if(res!=-1){
    //         std::cout << tickets[res] << std::endl;
    //         tickets.erase(tickets.begin() + res);
    //     }else{
    //         std::cout << -1 << std::endl;
    //     }
    // }


    return 0;
}