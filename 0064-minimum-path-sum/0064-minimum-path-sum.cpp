class Solution {
public:
   
    int minPathSum(vector<vector<int>>& grid) {

       int n=grid.size();
       int m=grid[0].size();

      vector<int> prev(m,0),cur(n,0);

      prev[0]=grid[0][0];

      for(int i=0;i<n;i++){
          cur=prev;
          for(int j=0;j<m;j++){
              if(i==0 && j==0) continue;

              int d=1e7,r=1e7;
              if(i>0){
                  d=grid[i][j]+prev[j];
              }
              if(j>0){
                  r=grid[i][j]+cur[j-1];
              }
              cur[j]=min(d,r);
          }
          prev=cur;
      }

      return prev[m-1]; 
    }
};