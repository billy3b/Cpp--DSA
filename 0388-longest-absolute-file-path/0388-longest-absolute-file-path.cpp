class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0;
        stack<pair<int,int> > s;
        input = "\n" + input;
        int l = 0; bool isfile = false; int maxl = 0;
        while(i<input.length())
        {
            if(input[i] == '\n'){
                int depth = 0;
                i++;
                while(input[i] == '\t') depth++,i++;
                while(i<input.length() and input[i] != '\n'){
                    if(input[i] == '.') isfile = true;
                    l++;i++;
                }
                if(isfile ==false) l+=1;
                if(!s.empty() and s.top().second == depth - 1){
                    s.push({s.top().first + l, depth});
                }
                else if(s.empty()){
                    s.push({l,depth});
                }
                else if(!s.empty() and s.top().second >= depth){
                    while(!s.empty() and s.top().second >= depth){
                        s.pop();
                    }
                    if(!s.empty() and s.top().second == depth - 1){
                        s.push({s.top().first + l, depth});
                    }
                    else if(s.empty()){
                        s.push({l,depth});
                    }
                }
                if(isfile and s.top().first > maxl) maxl = s.top().first; 
                isfile = false; l = 0;
            }
        }
        return maxl;
    }
};