class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int x=INT_MAX, com=-1;
        for(auto s:strs){
            x=min(x, (int)s.size());
        }

        for(int i=0;i<x;i++){
            bool iscomm=true;
            for(auto s:strs){
                if(s[i]!=strs[0][i]){
                    iscomm=false;
                }
            }
            if(!iscomm){
                break;
            }
            com =i;
        }

        return strs[0].substr(0,com+1);
    }
};