class Solution {
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& visit, vector<int> trace){
        visit[node] = 1;
        trace[node] = 1;

        for(auto nb:adj[node]){
            // cout<<nb<<" - ";
            if(!visit[nb]){
                if(dfs(adj, nb, visit, trace)){
                    return true;
                }
            }
            else if(trace[nb]==1){
                return true;
            }
            
        }
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for(auto req:prerequisites){
            adj[req[0]].push_back(req[1]);
        }

        for(int i=0;i<n;i++){
            vector<int> visit(n,0);
            vector<int> trace(n,0);
            // cout<<i<<"->";
            if(dfs(adj, i, visit, trace)){
                return false;
            }
            // cout<<endl;
        }
        return true;
    }
};
