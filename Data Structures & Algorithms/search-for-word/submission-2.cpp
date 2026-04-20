class Solution {
    pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool dfs(int x,int y, vector<vector<char>>& board,
             string word,  vector<vector<bool>> visit, int idx){
        // cout<<x<<" "<<y<<endl;
        if(word[idx]!=board[x][y]){
            return false;
        }
        if(idx==word.size()-1){
            return true;
        }
        visit[x][y]=true;

        for(int d=0;d<4;d++){
            int dx = x + dir[d].first;
            int dy = y + dir[d].second;
            if(0<=dx && dx<board.size() && 0<=dy && dy<board[0].size()){
                if(!visit[dx][dy]){
                    if(dfs(dx,dy,board,word,visit,idx+1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word==""){
            return true;
        }

        int n=board.size(), m=board[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,board,word,visit,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
