class Solution {
private:
    long coin(vector<int>& coins, int amount, vector<int>& mem){
        if(amount==0){
            return 0;
        }
        long mn=INT_MAX;
        if(mem[amount]!=-1){
            return mem[amount];
        }

        for(int i=0;i<coins.size();i++){
            if(amount>=coins[i]){
                mn = min(mn, 1 + coin(coins, amount-coins[i], mem));
            }
        }

        return mem[amount] = mn;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount+1, -1);
        return coin(coins, amount, mem)==INT_MAX?-1:coin(coins, amount, mem);
    }
};
