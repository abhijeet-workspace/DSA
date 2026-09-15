# Water and Jug Problem (LC 365)

## 1. Problem Statement
[LeetCode 365 — Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/): can you measure exactly `targetCapacity` litres using jugs of capacities `jug1` and `jug2`?

- **Operations:** fill, empty, pour between jugs.
- **Output:** true iff measurable.
- **Edges:** target 0; target > sum; one jug 0.

## 2. Intuition
Bézout's identity: with jugs x,y you can measure any multiple of gcd(x,y) that is ≤ x+y.

## 3. Brute Force → Optimal
- **Brute:** BFS on states (a,b) — O(xy).
- **Optimal:** gcd check — O(log).

## 4. Data Structure / Approach Justification
**Chosen:** `std::gcd` + capacity bounds.

**Pedagogy:** number-theory / Bézout application. BFS state-search appears in graph topics; here we teach the algebraic shortcut.

## 5. Logic Walkthrough
If target==0 true. If target > x+y false. Else target % gcd(x,y)==0 (handle x=y=0).

## 6. Dry Run
`x=3,y=5,target=4` → gcd=1, 4≤8 → **true**.

## 7. Time & Space Complexity
Time **O(log(min(x,y)))**, space **O(1)**.

## 8. Trade-offs & Alternatives
BFS needed if operation costs / shortest sequence required.

## 9. Common Mistakes / Edge Cases
Forgetting target≤x+y; gcd with zero capacities.

## 10. Interview Follow-ups / Variations
Frobenius coin problem (coprime unlimited); diophantine equations.

## 11. Tags
`number-theory`, `gcd`, `bezout`, `leetcode-365`, `difficulty:medium`
