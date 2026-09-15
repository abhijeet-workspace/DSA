# Maximum Frequency Stack

## 1. Problem Statement
[LeetCode 895](https://leetcode.com/problems/maximum-frequency-stack/) — Design a stack-like structure: `push(val)`; `pop()` returns the most frequent element, breaking ties by closest-to-top (LIFO among that frequency).

- **Inputs:** Sequence of push/pop ops.
- **Output:** Popped values.
- **Edges:** All unique; one value dominates; pop until empty not required by tests here.

## 2. Intuition
Track frequency of each value; keep a stack *per frequency*. Pop from the max-frequency stack.

## 3. Brute Force → Optimal
Scan whole stack each pop — O(N). Frequency groups — amortized O(1).

## 4. Data Structure / Approach Justification
**Chosen:** `freq[val]` + `group[f] = stack of vals with frequency f`, plus `maxFreq`.

This is the hard capstone for frequency thinking. It touches stacks, but the *core invariant* is frequency tiers — not the monotonic-stack pattern (topic 17).

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
push: `f=++freq[val]`; update `maxFreq`; `group[f].push(val)`.
pop: take `group[maxFreq].back()`; decrement freq; shrink `maxFreq` if that group empties.

## 6. Dry Run
Push 5,7,5,7,4,5 → pop 5 (freq3), then 7 (freq2, newer), then 5, then 4.

## 7. Time & Space Complexity
- **Time:** O(1) amortized per op
- **Space:** O(N)

## 8. Trade-offs & Alternatives
Tree of frequencies is heavier. LFU cache (later) adds recency keys differently.

## 9. Common Mistakes / Edge Cases
Single stack + recount; forgetting to decrease `maxFreq` when a tier empties.

## 10. Interview Follow-ups / Variations
LFU Cache; min-frequency stack.

## 11. Tags
`hash-map`, `stack`, `frequency`, `design`, `leetcode-895`, `difficulty:hard`
