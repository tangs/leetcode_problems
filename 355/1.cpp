#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

class Twitter {
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, unordered_set<int>> following;

    unordered_map<int, int> tweetMap;
    unordered_map<int, unordered_set<int>> tweets;
    unordered_map<int, set<int, std::greater<int>>> userTweets;

    int tweetIdx;
public:
    /** Initialize your data structure here. */
    Twitter() {
        tweetIdx = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetMap[tweetIdx] = tweetId;
        tweets[userId].insert(tweetIdx);
        userTweets[userId].insert(tweetIdx);

        for (int follower: followers[userId]) {
            userTweets[follower].insert(tweetIdx);
        }
        ++tweetIdx;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto& tweets = userTweets[userId];
        vector<int> ret;
        auto it = tweets.begin();
        while (it != tweets.end() && ret.size() < 10) {
            ret.push_back(tweetMap[*it++]);
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        following[followerId].insert(followeeId);
        followers[followeeId].insert(followerId);

        auto& tweets1 = userTweets[followerId];
        for (int idx: tweets[followeeId]) tweets1.insert(idx);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        auto& follow = following[followerId];
        auto it = follow.find(followeeId);
        if (it == follow.end()) return;
        follow.erase(it);

        auto& follower = followers[followeeId];
        follower.erase(follower.find(followerId));

        auto& tweets1 = userTweets[followerId];
        for (int idx: tweets[followeeId]) 
            tweets1.erase(tweets1.find(idx));
    }
};

int main() {
    Twitter* obj = new Twitter();
    // obj->postTweet(1, 5);
    // vector<int> param_1 = obj->getNewsFeed(1);
    // obj->follow(1, 2);
    // obj->postTweet(2, 6);
    // vector<int> param_2 = obj->getNewsFeed(1);
    // obj->unfollow(1, 2);
    // vector<int> param_3 = obj->getNewsFeed(1);
    obj->postTweet(1, 5);
    obj->follow(1, 2);
    obj->follow(2, 1);
    vector<int> param_1 = obj->getNewsFeed(2);
    obj->postTweet(2, 6);
    vector<int> param_2 = obj->getNewsFeed(1);
    vector<int> param_3 = obj->getNewsFeed(2);
    obj->unfollow(2, 1);
    vector<int> param_4 = obj->getNewsFeed(1);
    vector<int> param_5 = obj->getNewsFeed(2);
    obj->unfollow(1, 2);
    vector<int> param_6 = obj->getNewsFeed(1);
    vector<int> param_7 = obj->getNewsFeed(2);
    return 0;
}