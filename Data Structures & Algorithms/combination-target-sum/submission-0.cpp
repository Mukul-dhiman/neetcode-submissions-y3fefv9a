class Solution {
    void comb(vector<int>& nums, int target, set<vector<int>>& res, vector<int>& curr, int& curr_sum){
        if(curr_sum == target){
            vector<int> temp = curr;
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }

        if(curr_sum>target){
            return;
        }

        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            curr.push_back(nums[i]);
            comb(nums,target, res, curr, curr_sum);
            curr.pop_back();
            curr_sum-=nums[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        set<vector<int>> res;
        vector<vector<int>> ret;
        int curr_sum = 0;
        sort(nums.begin(), nums.end());
        comb(nums, target, res, curr, curr_sum);
        for(auto v:res){ret.push_back(v);}
        return ret;
    }
};
