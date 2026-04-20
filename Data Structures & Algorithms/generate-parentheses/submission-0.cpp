class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0){
            return {""};
        }
        if(n==1){
            return {"()"};
        }
        vector<string> ans, temp1, temp2;
        for(int i=0;i<=n-1;i++){
            temp1 = generateParenthesis(i);
            temp2 = generateParenthesis(n-1-i);
            for(auto t1:temp1){
                for(auto t2:temp2){
                    ans.push_back("(" + t1 + ")" + t2);
                }
            }
        }
        return ans;
    }
};
