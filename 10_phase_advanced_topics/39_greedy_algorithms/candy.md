# Candy

## 1. Problem Statement
[LeetCode 135](https://leetcode.com/problems/candy/) — give each child at least one candy; higher rating than a neighbor must get more candies than that neighbor; minimize total candies.

- **Inputs:** `ratings[i]` for each child in a line.
- **Output:** minimum total candies.
- **Valid answer:** any optimal assignment’s sum.
- **Edges:** `n=1`; strictly increasing / decreasing; plateaus of equal ratings.

## 2. Intuition
Satisfy left-neighbor and right-neighbor constraints separately: climb from left, then climb from right, taking the max at each index.

## 3. Brute Force → Optimal
- **Brute:** try assignments / hill-climbing — exponential or slow.
- **Optimal:** two linear passes + O(N) candy array — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `candies[i]` initialized to 1; L→R then R→L with `max`.

- **vs one-pass peak/valley formulas:** same idea, more error-prone.
- **vs sorting by rating:** more code; two-pass is standard.

## 5. Logic Walkthrough
Init all 1. For `i=1..n-1`, if rating rises left→right, `candies[i]=candies[i-1]+1`. For `i=n-2..0`, if rises right→left, take `max(candies[i], candies[i+1]+1)`. Sum.

## 6. Dry Run
`[1,0,2]`: after L→R → `[1,1,2]`; R→L bumps index 0 → `[2,1,2]`; sum **5**.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: each neighbor edge enforced once (section 4).

## 8. Trade-offs & Alternatives
O(1)-extra-space slope methods exist but are harder to get right in interviews.

## 9. Common Mistakes / Edge Cases
Using `=` instead of `max` on the second pass; giving extras on equal ratings; forgetting base 1 candy.

## 10. Interview Follow-ups / Variations
Circular line of children; maximize fairness under a candy budget.

## 11. Tags
`greedy`, `array`, `two-pass`, `leetcode-135`, `difficulty:hard`
