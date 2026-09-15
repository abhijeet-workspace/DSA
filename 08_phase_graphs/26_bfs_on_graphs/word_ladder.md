# Word Ladder

## 1. Problem Statement
[LeetCode 127](https://leetcode.com/problems/word-ladder/) — length of the shortest word ladder from `beginWord` to `endWord` where each step changes one letter and lands in `wordList` (include `beginWord` in the length). Return `0` if impossible.

- **Inputs:** `beginWord`, `endWord`, `wordList`.
- **Output:** ladder length (number of words) or `0`.
- **Valid answer:** minimum hops + 1 for start word.
- **Edges:** `endWord` missing; no path; begin equals end (rare per constraints).

## 2. Intuition
Implicit graph: words are nodes; edge if Hamming distance 1. Unweighted shortest path → BFS. Generate neighbors by trying all letter positions.

## 3. Brute Force → Optimal
- **Brute:** DFS all ladders — exponential.
- **Optimal:** BFS; erase from dict as visited — **O(N · L · 26)** typical.

## 4. Data Structure / Approach Justification
**Chosen:** `unordered_set` dictionary + queue of `{word, level}`.

- **vs prebuilding adjacency:** more memory; generation on the fly is standard.
- **vs bidirectional BFS:** faster in practice on large dicts.

## 5. Logic Walkthrough
If end not in dict → 0. BFS from begin at level 1. For each word, mutate each position `a–z`; if in dict, erase and enqueue at `level+1`.

## 6. Dry Run
`hit → hot → dot → dog → cog` length **5**.

## 7. Time & Space Complexity
Time **O(N · L · 26)** with dict ops. Space **O(N·L)**. Why: BFS over word graph (section 4).

## 8. Trade-offs & Alternatives
Word Ladder II asks for all shortest paths. Bidirectional BFS for tighter constants.

## 9. Common Mistakes / Edge Cases
Returning number of steps instead of word count; not removing visited words; assuming begin is in wordList.

## 10. Interview Follow-ups / Variations
Word Ladder II (126); genetic mutation (433); bidirectional BFS optimization.

## 11. Tags
`bfs`, `string`, `shortest-path`, `leetcode-127`, `difficulty:hard`
