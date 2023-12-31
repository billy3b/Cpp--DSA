//You are given a positive integer num consisting of exactly four digits. 
//Split num into two new integers new1 and new2 by using the digits found in num. 
//Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.
//For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. 
//Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].

class Solution {
public:
	int minimumSum(int num) {
        vector<int> v;
        while(num!=0){
            int digits = num%10;
            v.push_back(digits);
            num/=10;
        }
        sort(v.begin(), v.end());
        int sum = v[0]*10+v[3] + v[1]*10+v[2];
        return sum;
	}
};
