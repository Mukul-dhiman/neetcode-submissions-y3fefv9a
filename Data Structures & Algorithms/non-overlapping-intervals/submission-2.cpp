bool comp(const vector<int>& a, const vector<int>& b){
    if(a[0]==b[0]){
        return a[1] > b[1];
    }
    return a[0]<b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intv) {
        sort(intv.begin(), intv.end(), comp);
        if(intv.size()<=1){
            return 0;
        }
        int ans = 0;
        for(int i=0;i<=intv.size()-2;i++){
            if(intv[i][1]>intv[i+1][0]){
                if(intv[i][1]<intv[i+1][1]){
                    intv[i+1][0]=intv[i][0];
                    intv[i+1][1]=intv[i][1];
                }
                ans++;
            }
        }

        return ans;
    }
};
