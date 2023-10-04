class Solution {
public:
	int result =0;
	int singleNumber(vector<int>& nums) {
		for(int num : nums){
			result^=num;
		}
		return result;
	}
};
