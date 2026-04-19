class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> total;
        vector<int> vc;

        for(auto ch:s){total[ch]++;}

        for(int i=0;i<s.size();i++){
            unordered_map<char,int> curr;
            while(i<s.size()){
                curr[s[i]]++;
                int match = true;
                int val = 0;
                for(auto [ch, fr]:curr){
                    if(total[ch] !=fr){
                        match = false;
                        break;
                    }
                    val+=fr;
                }
                if(match){
                    vc.push_back(val);
                    break;
                }
                i++;
            }
        }

        return vc;
    }
};
