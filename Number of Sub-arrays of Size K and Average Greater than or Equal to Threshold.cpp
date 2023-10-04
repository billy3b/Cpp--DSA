class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
         int count = 0;
         int sum = 0;

         for(int i = 0;i < k; i++){
             sum+=arr[i];
         }

         for(int i  = 0; i<=arr.size()-k;i++){
             int avg  = sum/k;

             if(avg>=threshold){
                 count+=1;
             }
             sum-=arr[i];
             if(i + k < arr.size()){
                 sum+=arr[i+k];
             }
         }
         return count;
    }
};

---
Complexity
Time complexity:
<O(n)>

Space complexity:
<O(1)>
