class Solution {
    int poss(vector<int>& nums, int idx, int target, vector<vector<int>>& mem){
        if(target==0){
            return 1;
        }
        if(idx==nums.size()){
            return 0;
        }

        if(mem[idx][target]!=-1){
            return mem[idx][target];
        }
        
        int not_pick = poss(nums, idx+1, target, mem);
        int pick = 0;
        if(target>=nums[idx]){
            pick = poss(nums, idx + 1, target-nums[idx], mem);
        }
        return mem[idx][target] = not_pick || pick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%2==1){
            return false;
        }

        vector<vector<int>> mem(nums.size(), vector<int>(1+(sum/2), -1));

        return poss(nums, 0, sum/2, mem)>=1?true:false;
    }
};
