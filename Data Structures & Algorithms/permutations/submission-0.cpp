class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>  res,temp;
        if(nums.size()==1){
            res.push_back({nums[0]});
            return res;
        }
        for(int i=0;i<nums.size();i++){
            int tar = nums[i];
            swap(nums[i], nums[nums.size()-1]);
            nums.pop_back();
            temp = permute(nums);
            for(auto x:temp){
                x.push_back(tar);
                res.push_back(x);
            }
            nums.push_back(tar);
            swap(nums[i], nums[nums.size()-1]);
        }
        return res;
    }
};
