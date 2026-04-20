class Solution {
public:
    unordered_map<int, vector<string>> mp = {
        {2, {"a", "b", "c"}},
        {3, {"d", "e", "f"}},
        {4, {"g", "h", "i"}},
        {5, {"j", "k", "l"}},
        {6, {"m", "n", "o"}},
        {7, {"p", "q", "r", "s"}},
        {8, {"t", "u", "v"}},
        {9, {"w", "x", "y", "z"}},
    };
    vector<string> letterCombinations(string digits) {
        int sz = digits.size();
        if(sz==0){
            return {};
        }
        int fdig = digits[0]-'0';
        if(sz==1){
            return mp[fdig];
        }

        vector<string> ans, temp = letterCombinations(digits.substr(1));

        for(auto fc:mp[fdig]){
            for(auto rm:temp){
                ans.push_back(fc+rm);
            }
        }

        return ans;
    }
};
