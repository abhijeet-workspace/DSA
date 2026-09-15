# Skip List Insert / Search / Erase Demo

## 1. Problem Statement
Demonstrate skip list CRUD: insert keys, search membership, erase keys.

- **Inputs:** sequence of keys and ops.
- **Output:** contains true/false after ops.
- **Edges:** erase missing; duplicate insert policy; empty list.

## 2. Intuition
Towers of forward pointers; higher levels skip; random height ≈ geometric.

## 3. Brute Force → Optimal
- **Brute:** linked list O(N).
- **Skip list:** expected O(log N).

## 4. Data Structure / Approach Justification
**Chosen:** classic Pugh skip list with `mt19937` heights.

| Alternative | Note |
|-------------|------|
| `std::set` | RB tree |
| Treap | Rotations instead of towers |

## 5. Logic Walkthrough
1. Search path fills `update[]`.
2. Insert splices new tower.
3. Erase relinks around node.

## 6. Dry Run
Insert 3,1,2; erase 1; contains(1)=false, contains(2)=true.

## 7. Time & Space Complexity
Expected **O(log N)** per op.

## 8. Trade-offs & Alternatives
Simpler than some balanced trees; RNG dependent.

## 9. Common Mistakes / Edge Cases
Uneven update array; memory leaks (lab ignores deletes).

## 10. Interview Follow-ups / Variations
Range iterators; concurrent skip lists.

## 11. Tags
`skip-list`, `randomized`, `lab`, `difficulty:medium`
