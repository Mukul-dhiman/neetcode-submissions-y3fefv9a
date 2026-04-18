class Solution {
    int chan(int amount, vector<int>& coins, int idx, vector<vector<int>>& mem){
        if(amount==0){
            return 1;
        }

        if(mem[amount][idx]!=-1){
            return mem[amount][idx];
        }

        int ans = 0;

        for(int i = idx;i<coins.size();i++){
            if(amount>=coins[i]){
                ans+=chan(amount-coins[i], coins, i, mem);
            }
        }

        return mem[amount][idx] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> mem(amount+1, vector<int>(coins.size(), -1));
        return chan(amount, coins, 0, mem);
    }
};
