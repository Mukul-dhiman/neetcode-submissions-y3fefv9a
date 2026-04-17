class Solution {
    bool dfs(int n, vector<vector<int>>& edges, vector<int>& visit, vector<int>& trace, int curr,int  parent){
        visit[curr] = 1;
        trace[curr] = 1;

        for(auto nb:edges[curr]){
            if(!visit[nb]){
                if(dfs(n,edges,visit,trace,nb,curr)){
                    return true;
                }
            }
            else if(nb!=parent){
                return true;
            }
        }
        trace[curr] = 0;
        return false;
    }

    bool detectcycle(int n, vector<vector<int>>& edges){
        vector<int> visit(n, 0), trace(n, 0);

        for(int i=0;i<n;i++){
            if(!visit[i]){
                if(dfs(n, edges, visit, trace, i, -1)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n<=1 && edges.size()==0){
            return true;
        }
        if(edges.size()<n-1){
            return false;
        }

        set<int> nodes;
        for(auto ed:edges){
            if(ed[1]==ed[0]){
                return false;
            }
            nodes.insert(ed[1]);
            nodes.insert(ed[0]);
        }
        if(nodes.size()!=n){
            return false;
        }
        vector<vector<int>> adj(n, vector<int>());
        for(auto ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        if(detectcycle(n, adj)){
            return false;
        }
        return true;
    }
};
