class Solution {
    bool canj(vector<int>& nums, int start) {
        if(start==nums.size()-1){
            return true;
        }
        for(int i=start+1;i<=min((int)nums.size()-1, start+nums[start]);i++){
            if(canj(nums,i)){
                return true;
            }
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return canj(nums, 0);
    }
};