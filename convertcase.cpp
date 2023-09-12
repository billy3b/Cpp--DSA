
//if choice =1 camelCase
//if choice =2 kebab-case
//if choice =2 PascalCase

#include <iostream>
using namespace std;
string convertcase(string inputStr, int choice){
    int n=inputStr.size();
    string res="";
    if(choice==1){
        for(int i=0;i<n;i++){
            if(inputStr[i] == ' '){
                inputStr[i+1] =toupper(inputStr[i+1]);
                inputStr.erase(i,1);
            }
        }
        res=res+inputStr;
    }
    if(choice == 2){
        for(int i=0;i<n;i++){
            if(inputStr[i] == ' '){
                inputStr[i]='-';
            }
        }
        res=res+inputStr;
    }
    if(choice ==3){
        inputStr[0]=toupper(inputStr[0]);
        for(int i=1;i<n;i++){
            
            if(inputStr[i] ==' '){
                inputStr[i+1]=toupper(inputStr[i+1]);
                inputStr.erase(i,1);
            }
        }
        res=res+inputStr;
    }
    return res;
}
int main() {
    cout<<convertcase("hi there",3);
    return 0;
}
