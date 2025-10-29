#include <bits/stdc++.h>

int main(){
    std::string s;
    std::cin >> s;
    // Frequency array to store the count of each character
    int freq[26] = {0};
    for(char c: s){
        freq[c-'A']++;
    }
    // Check how many characters have odd frequency, and also keep a track of the character with oddCount.
    int odd_count = 0;
    char oddChar;
    for(int i=0; i<26; i++){
        if(freq[i]%2!=0){
            odd_count++;
            oddChar = 'A' + i; 
        }
    }

    if(odd_count > 1){
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }
    std::string first_half = "";
    // Construct the first half of the palindrome
    for(int i=0; i<26; i++){
        first_half += std::string(freq[i]/2, 'A' + i);
    }
    
    // Second half is jut the reverse of the first half
    std::string second_half = first_half;
    std::reverse(second_half.begin(), second_half.end());
    
    // If odd character exists, add it in the middle else print the first half, then reverse it.
    if(odd_count == 1){
        std::cout << first_half << oddChar << second_half << std::endl;
    }else{
        std::cout << first_half << second_half << std::endl;
    }
    return 0;
}