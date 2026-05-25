class Solution {
public:
    int lengthOfLastWord(string s) {
        int n =s.size();
        int w = 0, b = 1;
        for(auto c:s){
            if(c==' '){
                b=1;
            }
            else{
                if(b==1){
                    b=0;
                    w=0;
                }
                w++;
            }
        }

        return w;
    }
};