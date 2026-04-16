class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visit, int x, int y, bool& pac, bool& atl){
        visit[x][y] = 1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        if(x==0 || y==0){
            pac=true;
        }
        if(x==n-1||y==m-1){
            atl=true;
        }

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<n && dx>=0 && dy>=0 && dy<m){
                if(grid[dx][dy]<=grid[x][y] && visit[dx][dy]==0){
                    dfs(grid, visit, dx, dy, pac, atl);
                }
            }
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> ret;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>> visit(n, vector<int>(m,0));
                bool pac=false,atl=false;
                dfs(heights, visit, i, j, pac, atl);
                if(pac && atl){
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }
};







