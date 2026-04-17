class Solution {
public:
    int countSubstrings(string str) {
        int n=str.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int s=i,e=i;
            while(s>=0 && e<n){
                if(str[s]==str[e]){
                    ans++;
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
                    ans++;
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
