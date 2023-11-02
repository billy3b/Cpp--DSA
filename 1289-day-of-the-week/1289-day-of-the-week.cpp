class Solution {
public:
    string str[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int sum = 4;                                          
    string dayOfTheWeek(int d , int m , int y){
        for(int i=1971; i<y; i++){
            if((i%4==0 && i%100!=0) || (i%400==0)){       
                sum+=366;
            }
            else{
                sum+=365;                  
            }
        }
        for(int i=1; i<m; i++){
            if(i==2 && ((y%4==0 && y%100!=0) || (y%400==0))){
                sum+=1;
            }
            sum+=mon[i];
        }
        sum+=d;                 
        return str[sum%7];
    }
};