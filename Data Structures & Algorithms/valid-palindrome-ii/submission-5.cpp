class Solution {
    bool pal(string s, int beg, int end, bool del){
        if(beg>end){
            return true;
        }
        if(s[beg]==s[end]){
            return pal(s,beg+1, end-1,del);
        }
        if(!del){
            return false;
        }
        return pal(s,beg+1,end,false) or pal(s,beg,end-1,false);
    }
public:
    bool validPalindrome(string s) {
        return pal(s,0,s.size()-1,true);
    }
};