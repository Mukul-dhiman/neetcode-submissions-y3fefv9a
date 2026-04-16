class Solution {
    void mquicksort(vector<int>& nums, int s, int e, int pos, int& ans){
        if(ans!=-1){
            return;
        }
        if(s>e){
            return;
        }
        int pivot = nums[e];
        int sm=s, itr = s;
        for(itr=s;itr<e;itr++){
            if(nums[itr]<=pivot){
                swap(nums[itr],nums[sm]);
                sm++;
            }
        }
        swap(nums[e], nums[sm]);
        // cout<<s<<" "<<sm<<" "<<e<<" "<<pos<<" "<<endl;
        // for(auto x:nums)    cout<<x<<" ";
        // cout<<endl;
        if(sm == pos){
            ans = nums[pos];
            return;
        }
        if(pos<sm)
            mquicksort(nums, s, sm-1, pos, ans);
        if(pos>sm)
            mquicksort(nums, sm+1, e, pos, ans);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans = -1;
        mquicksort(nums, 0, nums.size()-1, nums.size() - k, ans);
        return ans;
    }
};