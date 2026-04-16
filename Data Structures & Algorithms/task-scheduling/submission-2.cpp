class Solution {
    using T = pair<int, pair<int, char>>;

    struct comp{
        bool operator() (const T a, const T b){
            if(a.first == b.first){
                return a.second.first > b.second.first;
            }
            return a.first < b.first;
        }
    };

public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<T, vector<T>, comp> pq;
        unordered_map<char, int> mp;
        for(auto t:tasks){mp[t]++;}
        for(auto t:mp){
            pq.push({t.second, {1, t.first}});
        }
        unordered_map<int, vector<T>> sch;
        int lasttime = 1;

        int time = 1;
        while(!pq.empty() || time<=lasttime){

            for(auto x:sch[time]){
                pq.push(x);
            }
            if(pq.empty()){
                time++;
                continue;
            }

            T tp = pq.top();
            pq.pop();
            int fr = tp.first;
            auto [when, name] = tp.second;
            if(when<=time){
                if(fr>1){
                    int sch_time = time+n+1;
                    T temp = {fr-1,{sch_time,name}};
                    if(sch.find(sch_time)==sch.end()){
                        sch[sch_time] = {temp};
                    }
                    else{
                        sch[sch_time].push_back(temp);
                    }
                    lasttime = max(lasttime, sch_time);
                }
            }
            else{
                pq.push(tp);
            }
            // cout<<time<<" - "<<endl;
            // cout<<fr<<" "<<when<<" "<<name<<" "<<lasttime<<endl;
            time++;
        }
        return time-1;
    }
};
