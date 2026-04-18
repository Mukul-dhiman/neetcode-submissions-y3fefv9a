class Solution {
    int find(vector<int>& nums, int target, int idx){
        if(idx == nums.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }

        return find(nums,target+nums[idx], idx + 1) + find(nums,target-nums[idx], idx + 1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return find(nums, target, 0);
    }
};
