class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(), people.rend());
        int n = people.size();
        vector<int> comp(n, 0);

        int boats = 0;
        int crossed = 0;

        if(people[0]>limit){
            return -1;
        }

        for(int i=0;i<n;i++){
            if(comp[i]==1){
                continue;
            }
            int x = people[i];
            comp[i] = 1;
            int j=i+1;
            while(j<n and !(x+people[j]<=limit and comp[j]==0)){
                j++;
            }
            if(j<n){
                comp[j] = 1;
                crossed+=2;
            }
            else{
                crossed+=1;
            }
            boats++;
        }

        return boats;
    }
};