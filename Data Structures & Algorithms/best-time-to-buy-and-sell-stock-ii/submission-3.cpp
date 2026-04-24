class Solution {
    int prf(vector<int>& prices, int curr, int n, int stocks,
            vector<vector<int>>& mem){
        if(curr>n){
            return 0;
        }
        if(mem[curr][stocks]!=-1){
            return mem[curr][stocks];
        }
        if(stocks==0){
            return mem[curr][stocks] = max(prf(prices, curr+1, n, 0, mem),
                        -1*prices[curr-1]+ prf(prices, curr+1, n, 1, mem));
        }
        if(stocks==1){
            return mem[curr][stocks] = max(prf(prices, curr+1, n, 1, mem),
                        prices[curr-1]+ prf(prices, curr+1, n, 0, mem));
        }
        return -1;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> mem(n+1, vector<int>(2, -1));

        return prf(prices, 1, n, 0, mem);
    }
};