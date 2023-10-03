#include <bits/stdc++.h> 
bool duplicateParanthesis(string &expr)
{
     stack<char> st;
      
      for(int i =0; i<expr.length(); i++){
          char ch = expr[i];
          if(ch == ')'){
              if(st.empty() || st.top() == '('){
                  return true;
              }
              else{
                  while(st.top()!='('){
                      st.pop();
                  }
                  st.pop();
              }
          }else{
              st.push(ch);
          }
      }
      return false;
}