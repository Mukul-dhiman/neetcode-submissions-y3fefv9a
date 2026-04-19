class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        int rc = n/2 + (n%2!=0);
        int cc = n/2;

        for(int i=0;i<rc;i++){
            for(int j=0;j<cc;j++){
                int temp = mat[i][j];
                mat[i][j] = mat[n-j-1][i];
                mat[n-j-1][i] = mat[n-i-1][n-j-1];
                mat[n-i-1][n-j-1] = mat[j][n-i-1];
                mat[j][n-i-1] = temp;
            }
        }
    }
};
