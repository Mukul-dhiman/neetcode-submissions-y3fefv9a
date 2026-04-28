class Solution {
    int minc(vector<int>& cost, int i, vector<int>& mem){
        if(i>=cost.size()){
            return 0;
        }
        if(mem[i]!=-1)  return mem[i];
        return mem[i] = cost[i]+min(minc(cost, i+1, mem), minc(cost, i+2, mem));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> mem(n,-1);
        return min(minc(cost, 0, mem),minc(cost, 1, mem));
    }
};
