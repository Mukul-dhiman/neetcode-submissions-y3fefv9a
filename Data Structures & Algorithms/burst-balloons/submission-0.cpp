class Solution {
    int minc(vector<int>& nums, int s, int e, vector<vector<int>>& mem){
        if(s>e){
            return 0;
        }
        if(mem[s][e]!=-1){
            return mem[s][e];
        }
        int ans = 0;

        for(int i=s;i<=e;i++){
            int lastburst = nums[s-1]*nums[i]*nums[e+1];
            ans=max(ans, lastburst + minc(nums,s,i-1,mem) + minc(nums,i+1,e,mem));
        }
        return mem[s][e] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> mem(n+1, vector<int>(n+1, -1));
        return minc(nums, 1, nums.size()-2,mem);
    }
};
