class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pqk;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                pqk.push(nums[i]);
            }
            else{
                add(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pqk.size()<K){
            pqk.push(val);
            return pqk.top();
        }
        int tp = pqk.top();
        if(tp<val){
            pqk.pop();
            pqk.push(val);
        }
        return pqk.top();
    }
};
