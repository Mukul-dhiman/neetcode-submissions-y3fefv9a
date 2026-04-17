class Solution {
    bool canbreak(string s, set<string>& st, unordered_map<string, bool>& mem){
        if(st.count(s)){
            return true;
        }
        if(mem.find(s)!=mem.end()){
            return mem[s];
        }
        for(int i=0;i<s.size();i++){
            if(st.count(s.substr(0,i+1))){
                if(canbreak(s.substr(i+1), st, mem)){
                    return mem[s] = true;
                }
            }
        }
        return mem[s] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto str:wordDict){st.insert(str);}
        unordered_map<string, bool> mem;
        return canbreak(s, st, mem);
    }
};
