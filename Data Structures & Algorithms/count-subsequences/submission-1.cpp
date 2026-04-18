class Solution {
    int num(string s, string t, int i, int j, vector<vector<int>>& mem){
        if(j==t.size()){
            return 1;
        }
        if(i>=s.size()){
            return 0;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }

        if(s[i]!=t[j]){
            return mem[i][j] = num(s,t,i+1,j,mem);
        }
        return mem[i][j] = num(s,t,i+1,j,mem) + num(s,t,i+1,j+1,mem);
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> mem(s.size()+1, vector<int>(t.size()+1, -1));
        return num(s,t,0,0,mem);
    }
};
