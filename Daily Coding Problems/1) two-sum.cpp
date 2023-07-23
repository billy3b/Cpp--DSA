// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17

---  
#include <iostream>
#include <vector>
using namespace std;

bool checksum(vector<int>& arr, int k){
    for(int i=0; i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==k){
                return true;
            }
        }
    } return false;
}

int main() {
    vector<int> arr ={10,2,3,5,7};
    int k=17;
    cout<<boolalpha<<checksum(arr,k)<<endl;
    return 0;
}
