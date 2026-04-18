class Solution {
    int isinter(string s1, string s2, string s3, int i, int j, vector<vector<int>>& mem){
        int k=i+j;
        if(k==s3.size()){
            return 1;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
            
        if(i<s1.size() && s1[i]==s3[k]){
            if(isinter(s1,s2,s3,i+1,j,mem)){
                return mem[i][j] =  1;
            }
        }
        if(j<s2.size() && s2[j]==s3[k]){
            if(isinter(s1,s2,s3,i,j+1,mem)){
                return mem[i][j] = 1;
            }
        }
        return mem[i][j] = 0;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n3!=n1+n2){
            return false;
        }
        vector<vector<int>> mem(n1+1, vector<int>(n2+1, -1));

        return isinter(s1,s2,s3,0,0, mem)==0?false:true;
    }
};
