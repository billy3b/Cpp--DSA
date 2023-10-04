class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Fix the first element of the triplet and iterate over the rest of the array
        for (int i = 0; i < nums.size(); i++) {
            // Check for duplicates
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int j = i+1;
            int k = nums.size()-1;
            
            // Two pointer approach
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    // Check for duplicates
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        
        return result;
    }
};
