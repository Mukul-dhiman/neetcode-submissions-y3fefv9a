class Solution {
    pair<int,int> dir[4] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    pair<int,int> rangemn[4] = {{1,0}, {0,0}, {0, 0}, {0, 1}};
    pair<int,int> rangemx[4] = {{0,0}, {0,-1}, {-1, 0}, {0, 0}};

    void spiral(vector<vector<int>>& matrix, vector<int>& order, int x, int y, int d, int mnx, int mxx, int mny, int mxy){
        if(mnx>mxx || mny>mxy){return;}
        
        auto [dx, dy] = dir[d%4];
        int i=x,j=y;

        for(; mnx<=i && i<=mxx && mny<=j && j<=mxy; i+=dx, j+=dy){
            order.push_back(matrix[i][j]);
        }
        
        spiral(matrix, order,
                i-dx+dir[(d+1)%4].first, j-dy+dir[(d+1)%4].second, d+1,
                mnx + rangemn[d%4].first, mxx + rangemx[d%4].first,
                mny + rangemn[d%4].second, mxy + rangemx[d%4].second);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size(), m=matrix[0].size();
        spiral(matrix, ans,
               0, 0, 0,
               0, n-1, 0, m-1);
        return ans;
    }
};
