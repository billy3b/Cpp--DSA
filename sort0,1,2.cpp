Question Link - https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low=0;
   int mid =0;
   int end =n-1;

   while(mid<=end){

      if(arr[mid]==0){
         swap(arr[low],arr[mid]);
         low++;
         mid++;
      }
      else if(arr[mid]==1){
         mid++;
      }
      else if (arr[mid]==2){
         swap(arr[end],arr[mid]);
         end--;
      }

   }
}
