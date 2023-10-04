class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums3;
		nums3.insert(nums3.begin(),nums1.begin(),nums1.end());
		nums3.insert(nums3.end(),nums2.begin(),nums2.end());
		sort(nums3.begin(),nums3.end());
		int s =0;
		int e = nums3.size()-1;

			double median;
			int mid = s+(e-s)/2;

			if(nums3.size() %2 != 0){
				return nums3[mid];
			}
			else{
				median = (nums3[mid]+nums3[mid+1])/2.0;
				return median;
			}
	}
};
