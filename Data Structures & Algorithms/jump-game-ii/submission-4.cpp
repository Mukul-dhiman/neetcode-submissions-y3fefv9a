class Solution {
    int canj(vector<int>& nums, int start, vector<int>& mem) {
        if(start==nums.size()-1){
            return 0;
        }
        if(mem[start]!=INT_MAX-1)  return mem[start];
        int ans=INT_MAX-1;
        for(int i=start+1;i<=min((int)nums.size()-1, start+nums[start]);i++){
            ans = min(ans, 1+canj(nums,i,mem));
        }
        return mem[start] = ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> mem(nums.size(), INT_MAX-1);
        return canj(nums, 0,mem);
    }
};