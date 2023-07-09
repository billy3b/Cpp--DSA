#include <iostream>
using namespace std;
#include <stack>
#include <vector>

 vector<int> solve(vector<int>& arr){
    int n =arr.size();
    stack<int> st;
    vector<int> nge(n);
    //last element of array's nge is -1 and push into stack
    nge[n-1] = -1;
    st.push(arr[n-1]);
    
    //traverse from last
    for(int i = arr.size()-2; i>=0; i--){
        //if array element is > than stack element then pop
        while(st.size()>0 && arr[i]>=st.top()){
            st.pop();
        }
        if(st.size() == 0){
            nge[i] = -1;
        
        //else large element in stack then it is nge of nge[i]
        } else{
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}

int main() {

    vector<int> arr={3,2,5,45,6,88};
    vector<int> res = solve(arr);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
