class Solution {
public:

	bool check(vector<int>& piles, int mid, int h) {
		int time =0;
		for(int i=0;i<piles.size();i++){ 
			time+=ceil( (double)piles[i] / (double) mid);
		}
		if(time <= h){
			return true;
		} else {
			return false;
		}
	}

	int minEatingSpeed(vector<int>& piles, int h) {
		// Your code goes here
		int start = 1;
		int end = *max_element(piles.begin(), piles.end());
		
		while(start<end){
			int mid = start+ (end-start)/2;

			if(check(piles,mid,h) == true){
				end = mid;
			} else{
				start = mid+1;
			}
		}
		return end;
	}
};
