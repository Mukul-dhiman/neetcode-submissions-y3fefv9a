class Solution {
    set<int> mp;
public:
    bool isHappy(int n) {
        if(mp.count(n)){
            return false;
        }

        int next = 0, temp = n;
        while(temp){
            int re = temp%10;
            next+=re*re;
            temp /=10;
        }
        if(next==1){
            return 1;
        }
        mp.insert(n);
        return isHappy(next);
    }
};
