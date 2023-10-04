
//Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

//For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6]

#include <iostream>
#include <vector>
------- 
    //Time complexity O(N^2)
using namespace std;

vector<int> productexcepti(vector<int>& arr){
    int n=arr.size();
    vector<int> output;
    for(int i=0;i<n;i++){
        int product = 1;
        for(int j=0;j<n;j++){
            if(i==j){ 
                continue;
            }
            product*=arr[j];
        }
        output.push_back(product);
    }
        
    return output;
}
-----------
//optimised code with time complexity O(N)
    vector<int> productExceptSelf(vector<int>& arr) {
    int n=arr.size();
    int suffixprod=1;
    vector<int> output(size(arr),1);
    for(int i=1;i<n;i++)
        output[i] = output[i-1]*arr[i-1];
    for(int j=n-1;j>=0;j--){
        output[j] = output[j] * suffixprod;
        suffixprod = suffixprod*arr[j];
        }
    return output;
    }

int main() {
    vector<int> arr ={10,2,3,5,7};
    vector<int> output = productexcepti(arr);
    for(int i=0;i<output.size(); i++){
        cout<<output[i]<<" ";
    }
    return 0;
}
