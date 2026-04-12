class Solution {
    using T = pair<int, pair<int,int>>;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<T, vector<T>, greater<T>> pq;
        for(auto p:points){
            int x = p[0];
            int y = p[1];
            int d = (x*x) + (y*y);
            pq.push({d, {x, y}});
        }

        vector<vector<int>> ans; 
        while(k--){
            T tp = pq.top();pq.pop();
            ans.push_back({tp.second.first, tp.second.second});
        }
        return ans;
    }
};
