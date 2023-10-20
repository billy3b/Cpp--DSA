class Solution {
public:
double ans{},temp;
    int reverse(int x) {
        if(x>0){
            temp=x%10;
            if((double)INT_MAX/ans<=10.0)
                return 0;
            ans = ans*10 + temp;
            return reverse(x/10);
        } else{
            if(abs(x)>0){
                return reverse(abs(x)) * (-1);
            }
            return ans;
        }
    }
};