# Asteroid Collision

## 1. Problem Statement
[LeetCode 735](https://leetcode.com/problems/asteroid-collision/) — each asteroid has signed size: positive moves right, negative left. Same direction never collide. On meeting, the smaller absolute size explodes; equal sizes both explode. Return surviving asteroids in order.

- **Inputs:** `vector<int> asteroids` (non-zero).
- **Output:** survivors left→right.
- **Edges:** all same sign; equal magnitudes; chain reaction of left-movers eating stack.

## 2. Intuition
Only a right-mover on the stack facing a new left-mover can collide. Simulate with a stack: pop smaller right-movers until the new asteroid dies, both die, or the stack top no longer faces it.

## 3. Brute Force → Optimal
- **Brute:** repeatedly scan for adjacent opposing pairs — O(N²) in worst chains.
- **Optimal:** one stack pass — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `vector` as stack of survivors so far.

| Alternative | Why it loses here |
|-------------|-------------------|
| Linked list of asteroids | Same logic, more boilerplate |
| Recursion on collisions | Stack depth and clarity worse |

## 5. Logic Walkthrough
1. For each asteroid `a`:
2. While stack top `> 0` and `a < 0`: compare `|top|` vs `|a|`; pop if top smaller; if equal pop and kill `a`; if top larger kill `a`.
3. If `a` still alive, push.

## 6. Dry Run
`[5,10,-5]`: `-5` hits `10` and dies → `[5,10]`.  
`[8,-8]`: equal → both gone → `[]`.  
`[10,2,-5]`: `-5` eats `2`, then dies to `10` → `[10]`.

## 7. Time & Space Complexity
- **Time:** O(N) — each asteroid pushed/popped ≤ once.
- **Space:** O(N) survivors stack.

## 8. Trade-offs & Alternatives
Processing right-to-left with mirrored signs is equivalent. Explicit two-pointer simulation is messier for multi-hop collisions.

## 9. Common Mistakes / Edge Cases
Colliding same-direction asteroids; forgetting equal-size double destroy; pushing a dead asteroid after a clash; treating `|a|` incorrectly when `a` is negative (`-a` vs `std::abs`).

## 10. Interview Follow-ups / Variations
Car fleet (merge by time); remove adjacent duplicates; asteroid collision with health/damage stats.

## 11. Tags
`stack`, `simulation`, `leetcode-735`, `difficulty:medium`
