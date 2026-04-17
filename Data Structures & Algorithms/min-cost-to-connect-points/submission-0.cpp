class djs{
    vector<int> parent, rank;
public:
    djs(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int getparent(int x){
        while(x!=parent[x]){
            x = parent[x];
        }
        return x;
    }

    bool isunion(int x, int y){
        return getparent(x) == getparent(y);
    }

    void unin(int x, int y){
        x = getparent(x);
        y = getparent(y);
        if(x==y){
            return;
        }

        if(rank[x]>=rank[y]){
            rank[x]++;
            parent[y] = x;
        }
        else{
            rank[y]++;
            parent[x] = y;
        }
    }
};

class Solution {
    using T = pair<int, pair<int, int>>;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<T, vector<T>, greater<T>> minheap;
        int n = points.size();
        int cost=0;
        djs st = djs(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                minheap.push({abs(x1-x2) + abs(y1-y2)  , {i, j}});
            }
        }

        while(!minheap.empty()){
            auto [c, p] = minheap.top();
            minheap.pop();
            auto [p1, p2] = p;
            // cout<<c<<" "<<p1<<" "<<p2;
            if(!st.isunion(p1, p2)){
                // cout<<" this ";
                cost+=c;
                st.unin(p1,p2);
            }
            // cout<<endl;
        }

        return cost;
    }
};
