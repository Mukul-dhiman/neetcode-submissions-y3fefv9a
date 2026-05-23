class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0){
            return true;
        }
        int n = s.size(), m = t.size();
        for(int i=0;i<t.size();i++){
            if(s[0]==t[i]){
                return isSubsequence(s.substr(1), t.substr(i+1));
            }
        }
        return  false;
    }
};