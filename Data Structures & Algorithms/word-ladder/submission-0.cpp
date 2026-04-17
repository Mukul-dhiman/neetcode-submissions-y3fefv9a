class Solution {
    bool canTrans(string a, string b){
        int n=a.size(), comm=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                comm++;
            }
        }
        return comm==n-1;
    }

    void dfs(vector<vector<int>>& adj, int curr, vector<int>& dist){
        for(auto nb:adj[curr]){
            if(dist[nb]>=1+dist[curr]){
                dist[nb]=1+dist[curr];
                dfs(adj, nb, dist);
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int start =-1, end =-1;

        for(int i=0;i<wordList.size();i++){
            if(beginWord==wordList[i]){
                start = i;
            }
            if(endWord==wordList[i]){
                end = i;
            }
        }
        if(start==-1){
            wordList.push_back(beginWord);
        }
        if(end==-1){
            return 0;
        }
        int n = wordList.size();
        vector<vector<int>> adj(wordList.size(), vector<int>());
        for(int i=0;i<n;i++){
            if(beginWord==wordList[i]){
                start = i;
            }
            if(endWord==wordList[i]){
                end = i;
            }
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(canTrans(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                }
            }
        }
        cout<<"s->"<<start<<endl;
        cout<<"e->"<<end<<endl;
        for(int i=0;i<n;i++){
            cout<<i<<" -> ";
            for(auto x:adj[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }

        vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        dfs(adj, start, dist);
        return dist[end]==INT_MAX?0:dist[end]+1;
    }
};
