//tabulation or bottom up approach

#define MOD 1000000007
#include <bits/stdc++.h> 
#include<vector>


int countDistinctWays(int nStairs) {
    
    vector<int> dp(nStairs+1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<= nStairs; i++){
        dp[i] = (dp[i-1]+dp[i-2]) % MOD;
    }

    return dp[nStairs];
}
