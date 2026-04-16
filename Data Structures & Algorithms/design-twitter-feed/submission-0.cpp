class Twitter {
    using T = pair<int,int>;
    unordered_map<int, priority_queue<T>> tweets;
    unordered_map<int, set<int>> folw;
    int tw_num=0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(tweets.find(userId)==tweets.end()){
            tweets[userId] = {};
        }
        tweets[userId].push({tw_num, tweetId});
        tw_num++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<T> feed, temp;
        vector<int> ans;

        for(auto x:folw[userId]){
            temp = tweets[x];
            while(!temp.empty()){
                feed.push(temp.top());
                temp.pop();
            }
        }
        if(folw[userId].find(userId)==folw[userId].end()){
            temp = tweets[userId];
            while(!temp.empty()){
                feed.push(temp.top());
                temp.pop();
            }
        }

        for(int i=0;i<10 && !feed.empty();i++){
            ans.push_back(feed.top().second);
            feed.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(folw.find(followerId)==folw.end()){
            folw[followerId] = {followeeId};
        }
        else{
            folw[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(folw.find(followerId)!=folw.end()){
            folw[followerId].erase(followeeId);
        }
    }
};
