class Solution {
public:

    int solve(vector<int>& cost){
        int n = cost.size();
        //step1
        vector<int> dp(n+1);
        dp[0]= cost[0];
        dp[1] = cost[1];

        //step2
        for(int i =2; i<n; i++){
            dp[i] = min(dp[i-1] , dp[i-2]) + cost[i];
        }
        return min(dp[n-1], dp[n-2]);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost);
    }
};