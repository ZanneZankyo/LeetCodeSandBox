/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 *
 * https://leetcode.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (26.98%)
 * Total Accepted:    32.6K
 * Total Submissions: 120.8K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user and is able to see the 10 most recent tweets in
 * the user's news feed. Your design should support the following methods:
 * 
 * 
 * 
 * postTweet(userId, tweetId): Compose a new tweet.
 * getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's
 * news feed. Each item in the news feed must be posted by users who the user
 * followed or by the user herself. Tweets must be ordered from most recent to
 * least recent.
 * follow(followerId, followeeId): Follower follows a followee.
 * unfollow(followerId, followeeId): Follower unfollows a followee.
 * 
 * 
 * 
 * Example:
 * 
 * Twitter twitter = new Twitter();
 * 
 * // User 1 posts a new tweet (id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // User 1's news feed should return a list with 1 tweet id -> [5].
 * twitter.getNewsFeed(1);
 * 
 * // User 1 follows user 2.
 * twitter.follow(1, 2);
 * 
 * // User 2 posts a new tweet (id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 * // Tweet id 6 should precede tweet id 5 because it is posted after tweet id
 * 5.
 * twitter.getNewsFeed(1);
 * 
 * // User 1 unfollows user 2.
 * twitter.unfollow(1, 2);
 * 
 * // User 1's news feed should return a list with 1 tweet id -> [5],
 * // since user 1 is no longer following user 2.
 * twitter.getNewsFeed(1);
 * 
 * 
 */
class Twitter {
public:
    #define USER_ID int
    #define TWEET_ID int
    struct TweetUser{
        TWEET_ID tweetId;
        USER_ID userId;
        TweetUser(TWEET_ID t, USER_ID u) :tweetId(t), userId(u) {}
    };
    map<USER_ID,set<USER_ID>> follower_followee;
    vector<TweetUser> tweets;
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(USER_ID userId, TWEET_ID tweetId) {
        tweets.push_back(TweetUser(tweetId, userId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<TWEET_ID> getNewsFeed(USER_ID userId) {
        auto userItor = follower_followee.find(userId);
        set<USER_ID>* followees = nullptr;
        if(userItor != follower_followee.end()){
            followees = &userItor->second;
        }
        vector<TWEET_ID> feeds;
        int count = 0;
        for(auto it = tweets.rbegin(); it != tweets.rend() && count < 10; ++it){
            USER_ID followeeId = it->userId;
            if(it->userId == userId || 
            (followees && followees->find(followeeId) != followees->end())){
                feeds.push_back(it->tweetId);
                ++count;
            }
        }
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(USER_ID followerId, USER_ID followeeId) {
        if(followerId == followeeId){
            return;
        }
        follower_followee[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(USER_ID followerId, USER_ID followeeId) {
        if(followerId == followeeId){
            return;
        }
        auto it = follower_followee.find(followerId);
        if(it == follower_followee.end()){
            return;
        }
        set<USER_ID>& followees = it->second;
        auto found = find(followees.begin(), followees.end(), followeeId);
        if(found != followees.end()){
            followees.erase(found);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

