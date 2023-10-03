#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool handleclosings(stack<char> st, char corresch){
    if(st.empty()){
        return false;
    }
    else if(st.top()!=corresch){
        return false;
    }
    else{
        st.pop();
        return true;
    }
}


stack<char>  st;
string isBalanced(string s) {
 for(int i =0;i<s.length();i++){
     char ch = s[i];
     if(ch == '(' || ch=='{' || ch=='['){
         st.push(ch);
     }
     else if(ch == ')'){
        bool val = handleclosings(st,'(');
        if(val==false){
            return "NO";
        }
         
     } else if(ch == '}'){
         bool val = handleclosings(st,'{');
         if(val==false){
            return "NO";
        }
         
     } else if(ch == ']'){
         bool val = handleclosings(st,'[');
         if(val==false){
            return "NO";
        }
     }
 }
 if(st.empty()){
     return "YES";
 }
 else {
     return "NO";
 }

}

int main() {
    // Write C++ code here
    string result = isBalanced("{[(a+b)}");
    cout << result; //NO
    return 0;

    return 0;
}