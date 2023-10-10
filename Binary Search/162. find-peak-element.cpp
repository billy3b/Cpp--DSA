class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        return util(nums, 0, n-1, n);
    }

    int util(vector<int>& nums, int start, int end, const int n){
        int mid = start + (end - start)/2;

        if((mid > 0 && mid < n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                || (mid == 0 && nums[mid] > nums[mid+1]) 
                || (mid == n-1 && nums[mid] > nums[mid-1]))
            return mid;
        else if(mid > 0 && nums[mid-1] > nums[mid])
            return util(nums, start, mid-1, n);
        else
            return util(nums, mid+1, end, n);

    }
};