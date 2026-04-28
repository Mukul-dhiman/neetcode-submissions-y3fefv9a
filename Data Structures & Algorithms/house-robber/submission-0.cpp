class Solution {
    int rb(vector<int>& nums, int i, vector<int>& mem){
        if(i>=nums.size()){
            return 0;
        }
        if(mem[i]!=-1)  return mem[i];
        return mem[i] = max(nums[i]+rb(nums, i+2, mem), rb(nums, i+1, mem));
    }
public:
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return rb(nums, 0, mem);
    }
};
