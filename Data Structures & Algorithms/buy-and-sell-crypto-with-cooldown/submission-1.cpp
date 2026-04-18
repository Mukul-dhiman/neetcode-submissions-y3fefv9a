class Solution {
    int prof(vector<int>& prices, int day, int sell, vector<vector<int>>& mem){
        int n = prices.size();
        if(day>=n){
            return 0;
        }

        if(mem[day][sell]!=-1){
            return mem[day][sell];
        }

        if(sell==0){
            return mem[day][sell] = max(prof(prices, day+1,sell, mem), -1*prices[day] + prof(prices, day+1,1, mem));
        }
        return mem[day][sell] = max(prof(prices, day+1,sell, mem), prices[day] + prof(prices, day+2,0, mem));
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> mem(prices.size(), vector<int>(2, -1));
        return prof(prices, 0, 0, mem);
    }
};
