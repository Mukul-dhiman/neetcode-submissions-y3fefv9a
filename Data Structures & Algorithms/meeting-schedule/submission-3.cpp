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
bool comp(const Interval& a, const Interval& b){
    return a.start <= b.start;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intv) {
        sort(intv.begin(), intv.end(), comp);
        for(int i=0;i<=(int)intv.size()-2;i++){
            if(intv[i].end>intv[i+1].start){
                return false;
            }
        }
        return true;
    }
};
