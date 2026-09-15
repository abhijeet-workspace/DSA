# Insert Delete GetRandom O(1) (LC 380)

## 1. Problem Statement
Design a set with `insert`, `remove`, `getRandom` all average O(1).

- **Inputs:** ops on integers.
- **Output:** random element uniformly among current members.
- **Valid answer:** [LC 380](https://leetcode.com/problems/insert-delete-getrandom-o1/).
- **Edges:** insert duplicate; remove missing; single element.
- **Note:** Randomized structure adjacent to skip-list/Bloom topic (not a skip list).
- **Link:** [LC 380](https://leetcode.com/problems/insert-delete-getrandom-o1/)

## 2. Intuition
Vector for random index + hashmap value→index; swap-remove.

## 3. Brute Force → Optimal
- **Brute:** list + scan.
- **Hash+vector:** O(1).

## 4. Data Structure / Approach Justification
**Chosen:** `unordered_map` + `vector`.

| Alternative | Note |
|-------------|------|
| Skip list random walk | Worse constants |
| Tree + size | O(log N) |

## 5. Logic Walkthrough
1. insert push_back + map.
2. remove swap with last, pop, fix map.
3. getRandom index via RNG.

## 6. Dry Run
insert 1,2; remove 1; getRandom → always 2.

## 7. Time & Space Complexity
Average **O(1)**.

## 8. Trade-offs & Alternatives
Classic design interview.

## 9. Common Mistakes / Edge Cases
Forgetting to update map after swap; RNG bias.

## 10. Interview Follow-ups / Variations
Duplicates allowed (LC 381); weighted random.

## 11. Tags
`hashmap`, `randomized`, `lc-380`, `difficulty:medium`
