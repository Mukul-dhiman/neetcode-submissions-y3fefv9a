class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> seq(n, 1), prev(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(seq[j]+1>=seq[i]){
                        seq[i] = seq[j]+1;
                        prev[i] = j;
                    }
                }
            }
        }
        return *max_element(seq.begin(), seq.end());
    }
};
