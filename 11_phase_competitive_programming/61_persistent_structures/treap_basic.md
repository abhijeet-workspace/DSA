# Treap — Insert / Find / Erase

## 1. Problem Statement
Maintain a set as a randomized BST (treap) supporting insert, find, and erase.

- **Inputs:** sequence of keys.
- **Output:** membership after ops.
- **Valid answer:** BST order by key; heap order by random priority.
- **Edges:** empty; duplicates policy; erase missing key.

## 2. Intuition
Split/merge by key with random priorities keep the shape like a random BST → expected logarithmic height without explicit rotations API.

## 3. Brute Force → Optimal
- **Brute / baseline:** `std::set` (usually RB tree).
- **Treap:** expected O(log N) with easy split/merge extensions.

## 4. Data Structure / Approach Justification
**Chosen:** implicit rotations via `split`/`merge` + `mt19937` priorities.

| Alternative | Note |
|-------------|------|
| Splay tree | Amortized; different API |
| Skip list | Probabilistic layers |
| Policy-based GST | GNU extension |

## 5. Logic Walkthrough
1. `split(t, key)` → `< key` and `≥ key`.
2. `insert`: split, merge left + new node + right.
3. `erase`: split out `[key, key+1)`, drop middle, merge sides.
4. `find`: ordinary BST walk.

## 6. Dry Run
Insert 2,1,3; `find(1)` true; erase 2; `find(2)` false.

## 7. Time & Space Complexity
Expected **O(log N)** per op, space **O(N)**. Why: random priorities ⇒ random BST shape w.h.p. (section 4).

## 8. Trade-offs & Alternatives
Easy to extend to implicit-key sequences. Lab code leaks erased nodes for brevity — production must `delete`.

## 9. Common Mistakes / Edge Cases
Forgetting heap order in merge; duplicate keys without a policy; using poor RNG.

## 10. Interview Follow-ups / Variations
Implicit-key treap for arrays; split by size; persistent treap.

## 11. Tags
`treap`, `randomized-bst`, `split-merge`, `cp`, `difficulty:hard`
