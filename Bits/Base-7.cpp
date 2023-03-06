class Solution {
public:
    string convertToBase7(int num) {
         string base7="";
        int sign=1;
        if(num == 0)
         return "0";
         
        if(num<0)
          sign=-1;
        num = abs(num);
          while(num){

              base7 += to_string(num%7);
              num = num/7;
          }
         if(sign == -1)
           base7 += "-";   
        reverse(base7.begin(),base7.end());
         return base7; 
    }
};