class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum=0, ans=0;
        for(auto& x:nums){
            sum+=x;
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            // if(mp.find(sum)==mp.end()){
            //     mp[sum] = 1;
            // }
            // else{
                mp[sum]++;
            // }
        }
        return ans;
    }
};