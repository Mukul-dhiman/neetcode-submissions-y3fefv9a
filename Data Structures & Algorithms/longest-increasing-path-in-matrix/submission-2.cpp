class Solution {
    using T = pair<int, pair<int,int>>;
    pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n=0,m=0;
    void dfs(vector<vector<int>>& mat, vector<vector<int>>& len, int x, int y, int d){
        len[x][y] = d;
        // cout<<x<<" - "<<y<<endl;

        for(auto [dx, dy]:dir){
            int nx = x + dx;
            int ny = y + dy;
            // cout<<nx<<" n "<<ny<<endl;
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(mat[nx][ny]>mat[x][y]  && len[nx][ny]<1+len[x][y]){
                    dfs(mat, len, nx, ny, d+1);
                }
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<T, vector<T>, greater<T>> pq;
        n=matrix.size(), m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push({matrix[i][j], {i,j}});
            }
        }

        vector<vector<int>> len(n+1, vector<int>(m+1, 1));

        while(!pq.empty()){
            auto [d, cor] = pq.top();
            auto [x, y] = cor;
            pq.pop();
            // cout<<"ff";
            dfs(matrix, len, x, y, len[x][y]);
        }

        int ans = 1;
        for(int i=0;i<n;i++){
            ans = max(ans, *max_element(len[i].begin(), len[i].end()));
        }

        return ans;
    }
};
