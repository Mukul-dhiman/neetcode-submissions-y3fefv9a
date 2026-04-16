class Solution {
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& visit, vector<int> trace, vector<int>& order){
        visit[node] = 1;
        trace[node] = 1;

        for(auto nb:adj[node]){
            // cout<<nb<<" - ";
            if(!visit[nb]){
                if(dfs(adj, nb, visit, trace, order)){
                    return true;
                }
            }
            else if(trace[nb]==1){
                return true;
            }
            
        }

        order.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> order;
        vector<int> visit(n,0);

        for(auto req:prerequisites){
            adj[req[0]].push_back(req[1]);
        }

        for(int i=0;i<n;i++){
            vector<int> trace(n,0);
            if(!visit[i]){
                if(dfs(adj, i, visit, trace, order)){
                    return {};
                }
            }
        }
        // reverse(order.begin(), order.end());
        return order;
    }
};