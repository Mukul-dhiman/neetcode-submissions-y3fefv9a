class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visit, int x, int y){
        visit[x][y] = 1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<n && dx>=0 && dy>=0 && dy<m){
                if(grid[dx][dy]=='1' && visit[dx][dy]==0){
                    dfs(grid, visit, dx, dy);
                }
            }
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        int island = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visit[i][j]==0){
                    island++;
                    dfs(grid, visit, i, j);
                }
            }
        }

        return island;
    }
};
