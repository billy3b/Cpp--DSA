class Solution {
public:
	int getOddOccurrence(vector<int>& arr) {
		// Your code goes here
		int res=0;
		for(int num:arr){
			res=res^num;
		}
		return res;
	}
};