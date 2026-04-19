class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intv, vector<int>& queries) {
        vector<int> time(10001,-1);
        priority_queue<pair<int, int>> maxheap;
        for(int i=0;i<intv.size();i++){
            maxheap.push({intv[i][1]- intv[i][0]+1, i});
        }

        while(!maxheap.empty()){
            auto [size,id] = maxheap.top();
            maxheap.pop();
            int st = intv[id][0];
            int end = intv[id][1];

            for(int i=st;i<=end;i++){
                time[i] = size;
            }
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(time[queries[i]]);
        }
        return ans;
    }
};
