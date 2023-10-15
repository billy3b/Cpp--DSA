class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q1;
        queue<int> q2;
        sort(deck.begin(),deck.end());
        for(auto i=0 ; i<deck.size() ; i++){
            q1.push(deck[i]);
            q2.push(i);
        }
        vector<int> ans(deck.size());
        while(!q2.empty()){
            ans[q2.front()] = q1.front();
            q1.pop();
            q2.pop();
            if(q2.size()>0){
                int x = q2.front();
                q2.pop();
                q2.push(x);
            }
        }
        return ans;
    }
};