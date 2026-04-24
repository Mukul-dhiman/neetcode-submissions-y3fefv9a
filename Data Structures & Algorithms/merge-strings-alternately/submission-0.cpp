class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        bool alt=true;
        string ans="";
        while(i<word1.size() and j<word2.size()){
            if(alt){
                ans+=word1[i];i++;
            }
            else{
                ans+=word2[j];j++;
            }
            alt=!alt;
        }
        while(i<word1.size()){
            ans+=word1[i];i++;
            
        }
        while(j<word2.size()){
            ans+=word2[j];j++;
        }
        return ans;
    }
};