# Twin Arrays Pair Sum (MITM)

## 1. Problem Statement
Teaching: given two arrays `A`,`B` and target `T`, count pairs `(i,j)` with `A[i]+B[j]=T` using hash MITM style (half of 4Sum II).

- **Inputs:** A, B, T.
- **Output:** pair count.
- **Edges:** duplicates; empty array.

## 2. Intuition
Hash A frequencies; probe T-B[j].

## 3. Brute Force → Optimal
- **Brute:** O(NM).
- **Hash:** O(N+M).

## 4. Data Structure / Approach Justification
**Chosen:** unordered_map on A.

| Alternative | Note |
|-------------|------|
| Sort + two pointers | If finding pairs in one array |

## 5. Logic Walkthrough
1. Freq map A.
2. For each b, add map[T-b].

## 6. Dry Run
A=`[1,2,3]`, B=`[3,2]`, T=4 → pairs (1,3),(2,2) → **2**.

## 7. Time & Space Complexity
**O(N+M)**.

## 8. Trade-offs & Alternatives
Building block for multi-array MITM.

## 9. Common Mistakes / Edge Cases
Mutating while iterating; overflow.

## 10. Interview Follow-ups / Variations
List indices; closest pair sum.

## 11. Tags
`hashmap`, `pair-sum`, `mitm-building-block`, `difficulty:easy`
