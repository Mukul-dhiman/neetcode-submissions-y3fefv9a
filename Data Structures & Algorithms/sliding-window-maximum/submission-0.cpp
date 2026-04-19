class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> ans;

        for(int i=0;i<k;i++){
            ms.insert(nums[i]);
        }
        int i=k;
        ans.push_back(*ms.rbegin());
        while(i<nums.size()){
            ms.insert(nums[i]);
            ms.erase(ms.find(nums[i-k]));
            ans.push_back(*ms.rbegin());
            i++;
        }
        return ans;
    }
};
