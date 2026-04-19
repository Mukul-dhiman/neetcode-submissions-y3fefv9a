class CountSquares {
    unordered_map<long, int> mp;
    vector<vector<int>> points;
    long getkey(int x, int y){
        long xshift = x;
        xshift = xshift << 32;
        return xshift+y;
    }
public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        mp[getkey(point[0], point[1])]++;
        
        points.push_back({point});
        
    }
    
    int count(vector<int> point) {
        int ans=0;
        int x = point[0], y=point[1];
        for(auto p:points){
            int px=p[0], py=p[1];
            if(abs(x-px)==abs(y-py) && x!=px && y!=py){
                ans+=mp[getkey(x,py)]*mp[getkey(px,y)];
            }
        }
        return ans;
    }
};
