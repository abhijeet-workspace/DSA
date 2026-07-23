# Design Twitter

## Problem Statement
[LeetCode 355](https://leetcode.com/problems/design-twitter/) — design a simplified Twitter: post tweets, follow/unfollow, and fetch a user’s 10 most recent news-feed tweets.

- **Inputs (API):** `postTweet(userId, tweetId)`, `getNewsFeed(userId)`, `follow(follower, followee)`, `unfollow(...)`.
- **Output:** `getNewsFeed` returns up to 10 tweet IDs, newest first, from self + followees.
- **Valid answer:** chronological by post time; user always sees own tweets.
- **Edges:** unfollow; follow self (no-op); empty feed; >10 candidates; user with no tweets.

## Intuition
Store each user’s tweets in time order. News feed is a k-way merge of “self + followees” newest tips — same pattern as merging sorted lists with a max-heap.

## Brute Force → Optimal
- **Brute:** collect all candidate tweets, sort by time, take 10 — O(T log T) per feed.
- **Optimal:** max-heap merge from each user’s latest tweet, expand older ones lazily — O(F + 10 log F) for F = 1 + followees with tweets.

## Data Structure / Approach Justification
**Chosen:** map of tweet vectors `{time, id}` + followee sets + max-heap of `(time, id, user, idx)`.

- **vs global sorted list of all tweets:** filter by follow graph each query — worse with large T.
- **vs min-heap of size 10 while scanning all:** still scans everything; lazy merge only touches needed tweets.

## Logic Walkthrough
`postTweet` appends `(time++, id)`. `getNewsFeed` seeds heap with each relevant user’s newest tweet; repeatedly pop newest, push that user’s next older tweet, stop at 10. `follow` / `unfollow` update the set (ignore self-follow).

## Dry Run
`post(1,5)`, `follow(1,2)`, `post(2,6)`:
- user1 tweets: `[(0,5)]`; user2: `[(1,6)]`
- feed for 1: seed `(1,6)` and `(0,5)` → pop 6 then 5 → **[6, 5]**

## Time & Space Complexity
`post` / `follow` / `unfollow`: **O(1)** amortized. `getNewsFeed`: **O(F + 10 log F)**. Space **O(U + T)** for graph + tweets. Why: heap merge over F sources, stop after 10 (section 4).

## Trade-offs & Alternatives
Global chronological index + fan-out on write (real Twitter) trades write cost for faster reads. This design optimizes for interview clarity and sparse follow graphs.

## Common Mistakes / Edge Cases
Forgetting user’s own tweets; allowing self-follow loops; returning oldest-first; not advancing `idx` to older tweets; hard-coding sort of entire history.

## Interview Follow-ups / Variations
Pagination beyond 10; unfollow mid-stream; media / retweets; scale to millions of users (fan-out vs fan-in).

## Tags
`design`, `heap`, `hash-map`, `merge-k`, `leetcode-355`, `difficulty:medium`
