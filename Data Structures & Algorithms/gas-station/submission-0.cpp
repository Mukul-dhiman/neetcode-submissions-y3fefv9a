class Solution {
    int next(int st, int n){
        return (st+1)%n;
    }
    bool pos(vector<int>& gas, vector<int>& cost, int st){
        int n=gas.size();

        if(cost[st]>gas[st]){
            return false;
        }
        int fuel = gas[st] - cost[st];

        int nx = next(st, n);
        while(1){
            if(nx==st){
                return true;
            }
            if(cost[nx]>fuel+gas[nx]){
                return false;
            }
            fuel+=gas[nx]-cost[nx];

            nx = next(nx,n);
        }

    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
        if(pos(gas, cost, i)){
            return i;
        }
        }

        return -1;
    }
};
