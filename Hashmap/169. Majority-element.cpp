class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp; // Create a map to store the count of each unique number.
        int n = nums.size() / 2; // Define the threshold for a majority element.

        // Count the occurrences of each number in the input vector.
        for (auto a : nums) {
            mp[a]++;
        }

        int ans = 0; // Initialize the result variable.

        // Iterate through the map to find the majority element.
        for (auto a : mp) {
            if (a.second > n) {
                ans = a.first; // If the count of a number exceeds the threshold, it's the majority element.
            }
        }

        return ans; // Return the majority element.
    }
};