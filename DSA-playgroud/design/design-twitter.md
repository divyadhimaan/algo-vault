# Design Twitter

Practice [here](https://leetcode.com/problems/design-twitter/description/)


Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the `Twitter` class:

`Twitter()` Initializes your twitter object.
- `void postTweet(int userId, int tweetId)` Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
- `List<Integer> getNewsFeed(int userId)` Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
- `void follow(int followerId, int followeeId)` The user with ID followerId started following the user with ID followeeId.
- `void unfollow(int followerId, int followeeId)` The user with ID followerId started unfollowing the user with ID followeeId.

##  Hashmap + Priority Queue implementation

- `userToTweets[userId]` → Stores all tweets by a user as {timestamp, tweetId}
- `followList[followerId]` → Stores all followees of a user
- `globalTimestamp` → Ensures correct order of tweets globally

```cpp

class Twitter {
public:
    typedef pair<int,int> pii;
    // user_id -> [{timestamp, tweet_id}]
    unordered_map<int, vector<pair<int, int>>> userToTweets;

    // user_id -> [user_id1, user_id2, ...]
    unordered_map<int, set<int>> followList;
    int globalTimestamp;
    Twitter() {
        globalTimestamp = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        userToTweets[userId].push_back({globalTimestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pii> pq;

        //push all tweets from userId given
        auto& userTweets = userToTweets[userId];
        for(int i=userTweets.size()-1, count=0; i>=0 && count<10;i--, count++){
            pq.push(userTweets[i]);
        }

        if(followList.count(userId))
        {
            //push all tweets from followers of userId given            
            for(auto followeeId: followList[userId])
            {
                auto& userTweets = userToTweets[followeeId];
                for(int i=userTweets.size()-1, count=0; i>=0 && count<10;i--, count++){
                    pq.push(userTweets[i]);
                }
            }
            
        }

        vector<int> res;
        while(!pq.empty() && res.size()<10)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
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
```

| Method        | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| `postTweet`   | O(1)            | O(1)             |
| `follow`      | O(log k)        | O(1)             |
| `unfollow`    | O(log k)        | O(1)             |
| `getNewsFeed` | O(n log n)      | O(n)             |

## Time and Space Complexity - `getNewsFeed(int userId)` 

Let:
- `n` = number of users `userId` follows
- `t` = number of tweets per user (max)
- `K` = total number of tweets considered = `(n + 1) * min(t, 10)`  
  (own tweets + up to 10 from each followee)

---

### Time Complexity:

1. **Collect own tweets:**
   - Fetch last 10 tweets → `O(min(t, 10))`

2. **Collect followees' tweets:**
   - For each followee (up to `n`), fetch last 10 tweets
   - Total: `O(n * min(t, 10))`

3. **Push tweets into max-heap (priority queue):**
   - Each of the `K` tweets is pushed → `O(log K)` per insert
   - Total heap cost: `O(K * log K)`

4. **Pop top 10 tweets from heap:**
   - `O(10 * log K)`

**Overall Time Complexity:**


    O(n⋅10+K⋅logK) = O(n+logn) ≈ O(nlogn)


---

### Space Complexity:

- **Max-heap:** stores up to `K` tweets → `O(K)`
- **Result vector:** stores 10 tweet IDs → `O(10)`

**Overall Space Complexity:**

    O(K) = O(n)


## LinkedList + Hashmap Approach

Merge k lists

```cpp
class TweetNode {
public:

    int timestamp;
    int tweet_id;
    TweetNode* next;
    TweetNode(int ts, int tid){
        timestamp = ts;
        tweet_id = tid;
        next = NULL;
    }

};

class Twitter {
private:
    int globalTimestamp;

    // userId -> head of tweet linked list (most recent first)
    unordered_map<int, TweetNode*> userToTweetMap;

    // user_id -> set of followees
    unordered_map<int, unordered_set<int>> followList;
public:

    Twitter() {
        globalTimestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        TweetNode* newTweet = new TweetNode(globalTimestamp++, tweetId);
        newTweet->next = userToTweetMap[userId];

        userToTweetMap[userId] = newTweet;
    }
    
    vector<int> getNewsFeed(int userId) {

        auto cmp = [](TweetNode* a, TweetNode* b){
            return a->timestamp < b->timestamp;
        };

        priority_queue<TweetNode*, vector<TweetNode*>, decltype(cmp)> pq(cmp);


        unordered_set<int> sources = followList[userId];
        sources.insert(userId);

        for(int uid: sources){
            if(userToTweetMap.count(uid)){
                pq.push(userToTweetMap[uid]);
            }
        }

        vector<int> res;
        while(!pq.empty() && res.size()<10)
        {
            TweetNode* top = pq.top();
            pq.pop();

            res.push_back(top->tweet_id);
            if(top->next)
                pq.push(top->next);
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
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
```


| Method        | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| `postTweet`   | O(1)            | O(1)             |
| `follow`      | O(1)            | O(1)             |
| `unfollow`    | O(1)            | O(1)             |
| `getNewsFeed` | O(n log n)      | O(n)             |


### 📌 `getNewsFeed(int userId)`

Let:
- `n` = number of followees
- Each user has tweets stored in a singly linked list
- You are retrieving at most **10 recent tweets** total

#### Steps:
1. Add the user's own tweet list head and heads of all followees to a max-heap → `O(n log n)`
2. Pop the most recent tweet and push the next tweet in the same list → Up to 10 operations

#### ✅ Time Complexity:
\[
    O(n log n)
\]

#### ✅ Space Complexity:
- Heap holds at most one node per source → `O(n)`
- Result vector stores 10 tweet IDs → `O(1)`

---