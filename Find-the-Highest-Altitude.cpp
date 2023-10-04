class Solution {
    public:
   int largestAltitude(vector<int>& gain) {  
    int n = gain.size();
    vector<int> altitude(n+1);
    int maxal = 0;
    for(int i =0; i <n; i++){
        altitude[0] = 0;
        altitude[i+1] = altitude[i] + gain[i];
        maxal = max(maxal, altitude[i+1]);
    }
    return maxal;
   }
};
