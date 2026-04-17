class Solution {
    void bfs(vector<vector<pair<int,int>>>& adj, int k, vector<int>& dist){

        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [dst, curr] = pq.top();
            pq.pop();
            if(dist[curr]<dst){
                continue;
            }

            for(auto [nb, nb_dst]:adj[curr]){
                if(dist[nb]>nb_dst + dist[curr]){
                    dist[nb]=nb_dst + dist[curr];
                    pq.push({dist[nb], nb});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());

        for(auto nod:times){
            adj[nod[0]].push_back({nod[1], nod[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        bfs(adj, k, dist);
        int dst = *max_element(dist.begin()+1, dist.end());
        return dst==INT_MAX?-1:dst;
    }
};
