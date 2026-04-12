class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto s:stones)  pq.push(s);
        while(pq.size()>1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if(f>s)    pq.push(abs(f-s));
        }
        pq.push(0);
        return pq.top();
    }
};
