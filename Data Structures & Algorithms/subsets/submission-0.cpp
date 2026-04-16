class Solution {
    vector<vector<int>> sub(vector<int>& nums, int start) {
        if(start==nums.size()){
            return {};
        }
        if(start==nums.size()-1){
            return {{}, {nums[start]}};
        }
        vector<vector<int>> next = sub(nums, start+1);
        vector<vector<int>> ans = next;
        for(auto v:next){
            v.push_back(nums[start]);
            ans.push_back(v);
        }
        return ans;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return sub(nums, 0);
    }
};
