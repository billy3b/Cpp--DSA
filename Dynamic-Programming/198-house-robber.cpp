class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        int maxval = 0; //current
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            maxval = max(nums[i]+prev1, prev2);
            prev1=prev2;
            prev2=maxval; //prev2 = current
        }
        return maxval;
    }
};