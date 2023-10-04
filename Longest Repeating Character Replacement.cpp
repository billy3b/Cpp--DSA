class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0;
        int maxLen = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            count[s[end] - 'A']++;
            maxCount = max(maxCount, count[s[end] - 'A']);

            if (end - start + 1 - maxCount > k) {
                count[s[start] - 'A']--;
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
