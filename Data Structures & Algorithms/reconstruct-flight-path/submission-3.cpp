class Solution {
    void dfs(unordered_map<string, vector<string>>& adj, string curr, vector<vector<string>>& path, vector<string> trace, int n){
        if(path.size()!=0){
            return;
        }
        trace.push_back(curr);
        if(trace.size() == n+1){
            path.push_back(trace);
            return;
        }

        for(int i=0;i<adj[curr].size();i++) {
                string nb = adj[curr][i];
                adj[curr].erase(adj[curr].begin() + i);
                dfs(adj, nb, path, trace, n);
                adj[curr].insert(adj[curr].begin() + i, nb);
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        sort(tickets.begin(), tickets.end());
        for(auto tic:tickets){
            if(adj.find(tic[0])==adj.end()){
                adj[tic[0]] = {tic[1]};
            }
            else{    
                adj[tic[0]].push_back(tic[1]);
            }
        }

        vector<string> trace;
        vector<vector<string>> path;
        dfs(adj, "JFK", path, trace, tickets.size());
        // sort(path.begin(), path.end());
        return path[0];
    }
};
