/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intv) {
        vector<pair<int, int>> time;
        for(auto it:intv){
            time.push_back({it.start, 1});
            time.push_back({it.end, -1});
        }
        int ans = 0,temp=0;
        sort(time.begin(), time.end());
        for(auto [st, room]: time){
            temp+=room;
            ans=max(ans, temp);
        }
        return ans;
    }
};
