class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        int sig = (n<0);
        n = abs(n);
        while(n--){
            ret*=x;
        }
        return sig?1/ret:ret;
    }
};
