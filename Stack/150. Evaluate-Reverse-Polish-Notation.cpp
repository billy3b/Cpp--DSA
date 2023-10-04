class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        int i=0;
        
        while(i<tokens.size()){
            if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="-" || tokens[i]=="/"){
                long long a= st.top();
                st.pop();
                long long b= st.top();
                st.pop();
                if(tokens[i]=="+")st.push(a+b);
                else if(tokens[i]=="-")st.push(b-a);//here b is first element of operation
                else if(tokens[i]=="*")st.push(a*b);
                else st.push(b/a);// similarly b is first element of our operation.
            }else{
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        
        return (int)st.top();
        
    }
};
