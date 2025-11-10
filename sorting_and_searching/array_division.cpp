#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
	long long n, k;
	cin >> n >> k;

	vector<long long> arr(n);
	for(long long i=0; i<n; i++){
		cin >> arr[i];
	}

	long long totalSum = 0;
	for(long long i: arr){
		totalSum += i;
	}

	// To find the minimum possible maximum sum of a subarray, define our search space between the maximum element of the array, and the total sum of all elements in the array(if our entire array was one subarray)
	// Perform binary search on the range, for every mid, see if we are able to form partitions, within k,  where subarray sum does not exceed mid. If we can form 
	// within k partitions, then reduce high, if we need more than k partitions, increase low.
	long long low = *max_element(arr.begin(), arr.end());
	long long high = totalSum;

	while(low<=high){
		long long mid = low + (high-low)/2;

		//Check if we can split int o <=k parts, with each sum<=mid.
		long long parts = 1;
		long long currentSum = 0; 
		for(auto x: arr){
			if(currentSum+x > mid){
				parts++;
				currentSum = x;
			}else{
				currentSum+=x;
			}
		}

		if(parts<=k){
			// feasible solution, but try smaller maximum
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	cout << low << endl;

	return 0;
}
