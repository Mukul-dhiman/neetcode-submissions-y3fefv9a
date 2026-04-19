class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        int i=0;
        vector<vector<int>> ret;
        
        sort(intv.begin(), intv.end());
        while(i<intv.size()){
            int x = intv[i][0];
            int y = intv[i][1];
            i++;
            while(i<intv.size() && y>=intv[i][0]){
                y=max(y,intv[i][1]);
                i++;
            }
            ret.push_back({x,y});
        }
        return ret;
    }
};
