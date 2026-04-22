class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        mp[s[0]]++;
        int l=0,r=0;
        while(r<s.size()){
            int mostf = 0;
            for(auto el:mp){
                mostf = max(mostf, el.second);
            }
            if((r-l+1)-mostf <=k){
                ans=max(ans, (r-l+1));
                r++;
                mp[s[r]]++;
            }
            else{
                mp[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};
