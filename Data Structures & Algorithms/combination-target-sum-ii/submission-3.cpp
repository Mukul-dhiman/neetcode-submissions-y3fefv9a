class Solution {
    void comb(vector<int>& nums, int target, int idx, set<vector<int>>& res, vector<int>& curr, int& curr_sum){
        if(curr_sum == target){
            res.insert(curr);
            return;
        }

        if(curr_sum>target){
            return;
        }

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            if(curr_sum+nums[i]>target){
                break;
            }
            curr_sum+=nums[i];
            curr.push_back(nums[i]);
            comb(nums,target, i+1, res, curr, curr_sum);
            curr.pop_back();
            curr_sum-=nums[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> curr;
        set<vector<int>> res;
        vector<vector<int>> ret;
        int curr_sum = 0;
        sort(nums.begin(), nums.end());
        comb(nums, target, 0, res, curr, curr_sum);
        for(auto v:res){ret.push_back(v);}
        return ret;
    }
};
