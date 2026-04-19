class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<int,int>> rooms(n, {-1,-1});
        vector<int> meets(n, 0);
        sort(meetings.begin(), meetings.end());

        for(int i=0;i<meetings.size();i++){
            // for(int j=0;j<n;j++){
            //     cout<<"["<<rooms[j].first<<" - "<<rooms[j].second<<"] ";
            // }
            // cout<<endl;

            int st = meetings[i][0];
            int end = meetings[i][1];
            int done =0;
            for(int j=0;j<n;j++){
                if(rooms[j].second<=st){
                    meets[j]++;
                    rooms[j] = {st, end};
                    done = 1;
                    break;
                }
            }
            if(done){
                continue;
            }
            int first_end = -1;
            int first_end_time = INT_MAX;
            for(int j=0;j<n;j++){
                if(first_end_time>rooms[j].second){
                    first_end_time = rooms[j].second;
                    first_end = j;
                }
            }
            rooms[first_end] = {rooms[first_end].second, rooms[first_end].second + end - st};
            meets[first_end]++;
            
        }
        
            // for(int j=0;j<n;j++){
            //     cout<<"["<<rooms[j].first<<" - "<<rooms[j].second<<"] ";
            // }
            // cout<<endl;

        int most_meet = 0;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(meets[i]>most_meet){
                most_meet=meets[i];
                idx=i;
            }
        }

        return idx;
    }
};