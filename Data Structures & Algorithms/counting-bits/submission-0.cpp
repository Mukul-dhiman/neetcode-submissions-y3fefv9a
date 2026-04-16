class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int x = i;
            int c=0;
            for(int j=0;j<32;j++){
                if(x& (1<<j)){
                    c++;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};
