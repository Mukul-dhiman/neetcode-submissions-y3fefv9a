class Solution {
    int mind(string word1, string word2, int i, int j, vector<vector<int>>& mem) {
        if(j==word2.size()){
            return word1.size()-i;
        }
        if(i==word1.size()){
            return word2.size()-j;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }

        if(word1[i] == word2[j]){
            return mem[i][j] = mind(word1,word2,i+1,j+1,mem);
        }
        return mem[i][j] = 1+min(mind(word1,word2,i+1,j+1,mem), 
            min(mind(word1,word2,i+1,j,mem), mind(word1,word2,i,j+1,mem)));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(), m = word2.size();
        vector<vector<int>> mem(n, vector<int>(m, -1));
        return mind(word1,word2,0,0,mem);
    }
};
