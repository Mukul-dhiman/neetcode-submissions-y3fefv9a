class Solution {
    set<vector<int>> sub(vector<int>& nums, int start) {
        if(start==nums.size()){
            return {};
        }
        if(start==nums.size()-1){
            return {{}, {nums[start]}};
        }
        set<vector<int>> next = sub(nums, start+1);
        set<vector<int>> ans = next;
        for(auto v:next){
            v.push_back(nums[start]);
            sort(v.begin(), v.end());
            ans.insert(v);
        }
        return ans;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res = sub(nums, 0);
        vector<vector<int>> ret;
        for(auto v:res){ret.push_back(v);}
        return ret;
    }
};
