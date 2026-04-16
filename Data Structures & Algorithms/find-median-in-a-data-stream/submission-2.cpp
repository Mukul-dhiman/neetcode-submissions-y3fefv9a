class MedianFinder {
    priority_queue<int> sm;
    priority_queue<int, vector<int>, greater<int>> lar;
    int median=INT_MIN;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(median==INT_MIN){
            median=num;
            return;
        }
        if(sm.size()==lar.size()){
            if(num<=median){
                sm.push(num);
            }
            else{
                sm.push(median);
                if(lar.empty()){
                    median=num;
                }
                else{
                    if(num< lar.top()){
                        median = num;
                    }
                    else{
                        median = lar.top();
                        lar.pop();
                        lar.push(num);
                    }
                }
            }
        }
        else{
            if(num<=median){
                lar.push(median);
                if(sm.top()<=num)   median=num;
                else{
                    median = sm.top();
                    sm.pop();
                    sm.push(num);
                }
            }
            else{
                lar.push(num);
            }
        }
    }
    
    double findMedian() {
        cout<<sm.size()<<" - ";
        if(sm.size()) cout<<sm.top()<<endl;
        cout<<lar.size()<<" - ";
        if(lar.size()) cout<<lar.top()<<endl;
        cout<<endl;
        cout<<"==="<<median<<endl;
        if(sm.size()==lar.size()){
            return median;
        }
        return (median + sm.top())/2.0;
    }
};
