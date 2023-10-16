class Solution {
private:
    int totdays,d,f,mod = 1e9+7;
    vector<int> dp;
    int rec(int day){

        int forget_day = day+f,secret_reveal_day = day+d;

        //part 2
        if(secret_reveal_day >= totdays)return 1;

        if(dp[day] != -1)return dp[day];
        int ans = 0;

        //part 1
        for(int i=secret_reveal_day;i<=min(forget_day-1,totdays-1);i++){
            ans = (ans + rec(i))%mod;
        }

        //part 3
        return (day+f < totdays)?dp[day] = ans%mod:dp[day] = (1+ans)%mod;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        totdays = n;
        d = delay;
        f = forget;
        dp.resize(n,-1);
        int res = rec(0);
        return res;
    }
};