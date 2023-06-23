//Maximum Sum of Distinct Subarrays With Length K

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long mx = 0;
        long long sum = 0;
        map<int,int> mp;
        int i, j = 0;

        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1<k) j++;
            else if(j-i+1 == k){
                if(mp.size()==k){
                    mx = max(mx,sum);
                }

                mp[nums[i]]--;

                if(mp[nums[i]]==0) mp.erase(nums[i]);
                sum-=nums[i];

                i++;
                j++;
            }
        }
        return mx;
    }
};
