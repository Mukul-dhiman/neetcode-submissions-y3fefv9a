class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), curr1 = 0, curr2=0, mx=*max_element(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            if(curr1<0){
                curr1=0;
            }
            curr1+=nums[i];

            if(curr2<0){
                curr2=0;
            }
            curr2+=nums[n-1-i];

            mx = max(mx, max(curr1,curr2));
        }
        return mx;
    }
};
