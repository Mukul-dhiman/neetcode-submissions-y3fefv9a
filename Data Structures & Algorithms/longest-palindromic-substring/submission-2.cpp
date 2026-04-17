class Solution {
    string common(string& s1, string& s2){
        int n = s1.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        string ans="";
        int i=n,j=n;
        while(i>0 && j>0){

        }

        return ans;
    }
public:
    string longestPalindrome(string str) {
        int n=str.size();
        // string s2 = s;
        // reverse(s2.begin(), s2.end());
        // return common(s, s2);
        string ans ="";
        int max=0;
        for(int i=0;i<n;i++){
            int s=i,e=i;
            while(s>=0 && e<n){
                if(str[s]==str[e]){
                    int temp = e-s+1;
                    if(max<temp){
                        max=temp;
                        ans=str.substr(s, max);
                    }
                    s--;e++;
                }
                else{
                    break;
                }
            }


            s=i,e=i+1;
            if(e==n){
                continue;
            }
            while(s>=0 && e<n){
                if(str[s]==str[e]){
                    int temp = e-s+1;
                    if(max<temp){
                        max=temp;
                        ans=str.substr(s, max);
                    }
                    s--;e++;
                }
                else{
                    break;
                }
            }
        }

        return ans;
    }
};
