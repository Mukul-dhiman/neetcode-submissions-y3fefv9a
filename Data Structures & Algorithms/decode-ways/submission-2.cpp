class Solution {
    int decode(string s, int idx, vector<int>& mem){
        if(idx>=s.size()){
            return 0;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(idx==s.size()-1){
            return 1;
        }
        int twodigit = stoi(s.substr(idx,2));
        if(idx==s.size()-2){
            if(twodigit>=1 && twodigit<=26){
                if(s[idx+1]=='0'){
                    return 1;
                }
                return 2;
            }
            if(s[idx+1]==0){
                return 0;
            }
            return 1;
        }

        if(mem[idx]!=-1){
            return mem[idx];
        }

        
        if(twodigit>=1 && twodigit<=26){
            return mem[idx] = decode(s, idx+1, mem) + decode(s,idx+2, mem);
        }
        return mem[idx] = decode(s, idx + 1, mem);
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> mem(n,-1);
        return decode(s,0,mem);
    }
};
