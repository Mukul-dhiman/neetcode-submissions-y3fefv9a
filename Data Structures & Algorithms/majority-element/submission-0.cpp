class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=nums[0], cou=1;
        for(int i=1;i<nums.size();i++){
            if(x==nums[i]){
                cou++;
            }
            else{
                cou--;
                if(cou==0){
                    x=nums[i];
                    cou=1;
                }
            }
        }
        return x;
    }
};