class Solution {
public:
	int getMaxDifference(string s) {
		int n = s.size();
		int ans = 0;
		int csum = 0;
		for(int i =0; i<n;i++){

			csum += (s[i]=='0'?1:-1); 
			if(csum < 0){
				csum = 0;
			}
			ans = max(csum,ans);
		}
		return ans == 0 ? -1 : ans;
	}
};
