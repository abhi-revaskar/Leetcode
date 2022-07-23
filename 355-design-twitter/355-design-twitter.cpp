class Twitter {
public:
    int time;
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,vector<pair<int,int>>> tweets; // userId : [[time,tweet]]
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        time--;
        tweets[userId].push_back({time,tweetId});
        following[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int k=10;
        set<pair<int,int>> feed;
        for(auto followee:following[userId])
        {
            for(auto tweet:tweets[followee])
                feed.insert(tweet);
        }
        for(auto tweet:feed)
            if(k)
            {
                ans.push_back(tweet.second);
                k--;
            }
        return ans;
            
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */