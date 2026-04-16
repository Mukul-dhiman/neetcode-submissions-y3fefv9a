class Solution {
    long recr(int n, long res){
        if(n==0){return res;}
        res = res*10 + n%10;
        return recr(n/10, res);
    }
public:
    int reverse(int x) {
        long long rec = recr(abs(x), 0)*(x>0?1:-1);
        if(rec>INT_MAX||rec<INT_MIN)    return 0;
        return rec;
    }
};
