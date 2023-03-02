class Solution {
public:
int popCount(int x){
	int count;
	for(count =0; x!=0; ++count){
		x&=x-1;
	}
	return count;
}
	vector<int> countBits(int n) {
		vector<int> ans(n+1);
		for(int x =0; x<=n; ++x){
			ans[x] = popCount(x);
		}
        return ans;
	}
};