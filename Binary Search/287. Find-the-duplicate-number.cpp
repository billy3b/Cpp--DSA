class Solution {
public:
	int findDuplicate(vector<int>& nums){
		int n = nums.size();
		unordered_set<int> unique;
		for(int num:nums){
			if(unique.count(num)>0){
				return num;
			} else{
				unique.insert(num);
			}
		}
        return -1;
	}
};
