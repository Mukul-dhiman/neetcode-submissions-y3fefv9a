class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=-1,f1=0,n2=-1,f2=0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(n1==nums[i]){
                f1++;
                continue;
            }
            if(n2==nums[i]){
                f2++;
                continue;
            }
            if(f1==0){
                n1=nums[i];f1=1;
                continue;
            }
            if(f2==0){
                n2=nums[i];f2=1;
                continue;
            }
            f1--;f2--;
        }
        f1=0;f2=0;
        for(auto x:nums){
            if(x==n1)   f1++;
            if(x==n2)   f2++;
        }
        vector<int> ans;
        if(f1>n/3){ans.push_back(n1);}
        if(f2>n/3){ans.push_back(n2);}
        return ans;
    }
};