class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i!=0 and nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){
                if(j!=i+1 and nums[j]==nums[j-1]){
                    continue;
                }
                // int tar = target - nums[i] - nums[j];
                int k=j+1,l=nums.size()-1;
                while(k<l){
                    long long curr = (long long)nums[i] + nums[j] + nums[k]+nums[l];
                    if(curr==target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while(k<l and nums[k]==nums[k-1]){
                            k++;
                        }
                    }
                    else if(curr<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};