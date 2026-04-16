class Solution {
    void dfs(vector<vector<int>>& grid, int x, int y, int dist){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        grid[x][y] = dist;

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<n && dx>=0 && dy>=0 && dy<m){
                if(grid[dx][dy]!=-1 && grid[dx][dy]>=dist+1){
                    dfs(grid, dx, dy, dist+1);
                }
            }
        }

    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    dfs(grid, i, j, 0);
                }
            }
        }
    }
};
