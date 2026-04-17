class Solution {
    vector<vector<int>> mem;
public:
    Solution():mem(101,vector<int>(101,-1)){}

    int uniquePaths(int m, int n) {
        if(m==1||n==1)  return 1;
        if(mem[m][n]!=-1)   return mem[m][n];
        return mem[m][n] = uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};
