class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<pair<int,int>> st;
        vector<int> ans(n,-1);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[i]>=st.top().first){
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = st.top().second-i;
            }
            st.push({temp[i], i});
        }

        return ans;
    }
};
