class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        for(int i=0;i<32;i++){
            int bita = a&(1<<i);
            int bitb = b&(1<<i);
            int c = 0;
            if(bita)    c++;
            if(bitb)    c++;
            if(carry)    c++;
            if(c>=2){
                carry=1;
            }
            else{
                carry=0;
            }
            if(c%2!=0){
                ans = ans|(1<<i);
            }
        }
        return ans;
    }
};
