class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=INT_MIN,minsum=INT_MAX,currmax=0,currmin=0,n=nums.size(),total=0;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
            // maximum subarray sum
            currmax+=nums[i];
            maxsum=max(maxsum,currmax);
            if(currmax<0) currmax=0;
            // minimum subarray sum
            currmin+=nums[i];
            minsum=min(minsum,currmin);
            if(currmin>0) currmin=0;
        }
        maxsum=(maxsum<0?maxsum:max(maxsum,total-minsum));
        return maxsum;
    }
};