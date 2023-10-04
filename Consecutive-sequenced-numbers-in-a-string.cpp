#include <bits/stdc++.h>
using namespace std;

int isConsecutive(string str){
    int start;
    
    for(int i=0;i<str.size()/2;i++){
        string new_str=str.substr(0,i+1);
        
        int num = atoi(new_str.c_str());
        start=num;
        while(new_str.size()<str.size()){
            num++;
            new_str+=to_string(num);
        }
    
        if(new_str == str){
            return start;
    }
        
    }

    return -1;
}

int main() {
    // Write C++ code here
    string str ="99100";
    cout<<"String:"<<str<<endl;
    int start = isConsecutive(str);
    if(start!=-1){
        //cout<<"start:"<<start<<endl;
        cout<<"yes the given string is consecutive";
    } else{
        cout<<"No the given string is not consecutive";
    }

    return 0;
}
