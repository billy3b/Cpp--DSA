class Solution {
public:

    bool solve(vector<char>&arr,int j,int k){
        if(j>=k){
            return true;
        }
        if(arr[j]!=arr[k-j]){
            return false;
        }
        return solve(arr,j+1,k);
    }

    bool isPalindrome(string s) {
        vector<char>arr;
        for(char c:s){
            if(isalnum(c)){
                arr.push_back(tolower(c));
            }
        }
        int j=0;
        int k=arr.size()-1;
        return solve(arr,j,k);
    }
};