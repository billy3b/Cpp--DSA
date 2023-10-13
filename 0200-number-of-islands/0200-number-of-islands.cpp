class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                   
                    dfs(row, col, grid, vis, n, m);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[row][col] = 1;

        // directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // Checking in all 4 directions
        for(int i = 0; i < 4; i++){

            int nRow = row + dr[i];
            int nCol = col + dc[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
            && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                dfs(nRow, nCol, grid, vis, n, m);
            }
        }
    }
};