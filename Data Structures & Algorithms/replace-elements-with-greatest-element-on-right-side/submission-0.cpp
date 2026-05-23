class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int curr = -1;
        for(int i=arr.size()-1;i>=0;i--){
            int temp=arr[i];
            arr[i] = curr;
            curr=max(curr, temp);
        }

        return arr;
    }
};