//Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
//For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
//Follow-up: Can you do this in O(N) time and constant space?

#include <bits/stdc++.h> 
#include<vector>

// int solveMem(std::vector<int>& arr, int n, std::vector<int>& dp) {

// 	if (n < 0)
// 		return 0;
// 	if (n == 0)
// 		return arr[0];
	
// 	if(dp[n] != -1)
// 		return dp[n];

// 	int incl = solve(arr, n - 2,dp) + arr[n];
// 	int excl = solve(arr, n-1,dp) + 0;

// 	dp[n] = max(incl, excl);
// 	return dp[n];
// }

int solveTab(std::vector<int>& nums){
	int n = nums.size();
	std::vector<int> dp(n,0);

	dp[0] = nums[0];

	for(int i =1;i<n;i++){
		int incl = dp[i-2]+nums[i];
		int excl = dp[i-1] + 0;
		dp[i] = max(incl,excl);
	}
	return dp[n-1];
}


int maximumNonAdjacentSum(std::vector<int> &nums) {
	// int n = nums.size();
	// vector<int> dp(n, -1);
	// return solve(nums, n - 1, dp); 

	return solveTab(nums);

}
