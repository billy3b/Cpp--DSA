class Solution {
public:
    int maxRepeating(string seq, string word) {
        if(word.size()>seq.size()) return 0;
        int i=0,j=word.size()-1,k=0,Max=0;
        while(j<seq.size()){
            if(seq.substr(i,j-i+1)!=word){ // is the substring does'nt match
                if(k!=0){ // is the previous substring was a match, go to previous substring and start from next index.
                    i-=word.size();
                    j-=word.size();
                }
                i++; // just pass to next sliding window
                j++;
                k=0; // reset the value
            }
            else{ // if the substring is a match
                Max=max(Max,++k);
                i+=word.size();
                j+=word.size();
            }
        }
        return Max;
    }
};