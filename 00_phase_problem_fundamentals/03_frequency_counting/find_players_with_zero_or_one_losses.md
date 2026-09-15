# Find Players With Zero or One Losses

## 1. Problem Statement
[LeetCode 2225](https://leetcode.com/problems/find-players-with-zero-or-one-losses/) — From match results `[winner, loser]`, return players with 0 losses and players with exactly 1 loss, each sorted ascending.

- **Inputs:** `vector<vector<int>> matches`.
- **Output:** `{zeroLoss, oneLoss}` sorted lists.
- **Edges:** Player only wins; player loses many times; single match.

## 2. Intuition
Count losses per player; ensure winners appear with 0 if never lost.

## 3. Brute Force → Optimal
Sets of all players + recount losses. One map of loss counts.

## 4. Data Structure / Approach Justification
**Chosen:** ordered map `player → losses` so iteration is sorted.

`unordered_map` + sort at end is equivalent. Frequency of *losses* is the core idea.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. For each match: ensure winner exists with 0; `++losses[loser]`.
2. Partition into 0-loss and 1-loss lists (already sorted if `map`).

## 6. Dry Run
Sample → zero `[1,2,10]`, one `[4,5,7,8]`.

## 7. Time & Space Complexity
- **Time:** O(M log P) with `map`
- **Space:** O(P)

## 8. Trade-offs & Alternatives
Hash map + two sorts is often faster in practice.

## 9. Common Mistakes / Edge Cases
Omitting winners who never lost; including 2+ loss players in answer.

## 10. Interview Follow-ups / Variations
Players with at most k losses; win streaks.

## 11. Tags
`hash-map`, `frequency`, `sorting`, `leetcode-2225`, `difficulty:medium`
