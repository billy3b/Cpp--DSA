class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> hash(26,0);
        vector<int> phash(26,0);
        int left = 0, right = 0;
        int len  = s.size();
        int window = p.size();

        if(len < window){
            return ans;
        }

        while(right< window){
            hash[s[right] - 'a']+=1;
            phash[p[right++] - 'a']+=1;
        }
        right-=1;

        while(right<len){
            if(phash == hash){
                ans.push_back(left);
            }
            right+=1;
            if(right!=len){
                hash[s[right] - 'a']+=1;
            }
            hash[s[left] - 'a']-=1;
            left+=1;
        }
        return ans;
    }
};
