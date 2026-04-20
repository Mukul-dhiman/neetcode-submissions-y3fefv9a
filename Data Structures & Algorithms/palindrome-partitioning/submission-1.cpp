class Solution {
    vector<vector<string>> part(string s, int st) {
        if(st==s.size()-1){
            return {{string(1,s[st])}};
        }

        vector<vector<string>> ans, temp;


        for(int i=st;i<s.size();i++){
            string curr = s.substr(st, i-st+1);
            string rev = curr;
            reverse(rev.begin(), rev.end());
            if(curr==rev){
                if(i==s.size()-1){
                    ans.push_back({curr});
                }
                else{
                    temp = part(s, i+1);
                    for(int j=0;j<temp.size();j++){
                        temp[j].insert(temp[j].begin(), curr);
                        ans.push_back(temp[j]);
                    }
                }
                
            }
        }

        return ans;
    }
public:
    vector<vector<string>> partition(string s) {
        return part(s,0);
    }
};
