class Solution {
    bool dfs(vector<vector<int>>& adj, vector<int>& visit, 
                vector<int>& parents, int curr,int  parent,
                int& cycle_start, int& cycle_end){
        visit[curr] = 1;
        parents[curr] = parent;

        for(auto nb:adj[curr]){
            if(!visit[nb]){
                if(dfs(adj,visit,parents,nb,curr, cycle_start, cycle_end)){
                    return true;
                }
            }
            else if(nb!=parent){
                cycle_start = curr;
                cycle_end = nb;
                return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n, vector<int>());
        vector<int> visit(n, 0);
        vector<int> parents(n, -1);
        int cycle_start = -1, cycle_end = -1;

        for(int i=0;i<n;i++){
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
        }

        if(!dfs(adj, visit, parents, 0, -1, cycle_start, cycle_end)){
            return {};
        }

        set<vector<int>> cycle;
        for(int node = cycle_start; node !=cycle_end;node = parents[node]){
            cycle.insert({min(node+1, parents[node]+1), max(node+1, parents[node]+1)});
        }
        cycle.insert({min(cycle_start+1, cycle_end+1),
                      max(cycle_start+1, cycle_end+1)});

        for(int i=n-1;i>=0;i--){
            vector<int> ed = edges[i];
            if(cycle.count(ed)){
                return ed;
            }
        }

        return {};
    }
};
