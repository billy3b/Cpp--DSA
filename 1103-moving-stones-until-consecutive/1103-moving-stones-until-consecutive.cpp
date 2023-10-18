class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int mn = min(a,min(b,c));
        int mx = max(a,max(b,c));
        int md = a + b + c - mx - mn;
        if(mx==md+1  && md==mn+1){
            return {0,0};
        }
        int ans = md - mn - 1 + mx - md - 1;
        if(mx==md+1 || md==mn+1){
            return {1,ans};
        }
        if(mx==md+2 || md==mn+2){
            return {1,ans};
        }
        return {2,ans};
    }
};