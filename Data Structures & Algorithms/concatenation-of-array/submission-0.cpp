class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret(nums.size()*2,0);
        for(int i=0;i<nums.size();i++){
            ret[i] = nums[i];
            ret[i+nums.size()] = nums[i];
        }
        return ret;
    }
};