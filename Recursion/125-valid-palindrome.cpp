//Approach1-recursion
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


//Approach2-two pointer
class Solution {
public:
    bool isPalindrome(string s) {
        string modifiedString;

        // Convert to lowercase and remove non-alphanumeric characters
        for (char c : s) {
            if (isalnum(c)) {
                modifiedString += tolower(c);
            }
        }

        // Check if the modified string is a palindrome
        int left = 0;
        int right = modifiedString.length() - 1;
        while (left < right) {
            if (modifiedString[left] != modifiedString[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};