# 3Sum

## 1. Problem Statement
Find all unique triplets `(a,b,c)` with `a+b+c=0`.

- **Input:** `nums` (may contain duplicates)
- **Output:** list of unique triplets (any order)
- **Edges:** all zeros; n<3; many duplicates

## 2. Intuition
After sorting, fix one value and solve Two Sum II on the suffix; skip equal values to unique-ify.

## 3. Brute Force → Optimal
- **Brute:** triple loops + set — O(N³).
- **Optimal:** sort + O(N) two pointers per fixed i → O(N²).

## 4. Data Structure / Approach Justification
Sorted `vector` enables monotonic two-pointer moves and cheap duplicate skips.

| Alternative | Why it loses here |
|-------------|-------------------|
| Hash set per fixed i | Harder uniqueness; similar time |
| Meet-in-middle | Better for large k / special constraints |

## 5. Logic Walkthrough
1. Sort ascending.
2. For each unique `i`, run `L=i+1`, `R=n-1`.
3. Sum == 0 → record, skip equal L/R; sum < 0 → ++L; else --R.

## 6. Dry Run
`[-1,0,1,2,-1,-4]` → sorted `[-4,-1,-1,0,1,2]`.
i=-1: finds `(-1,0,1)` and `(-1,-1,2)`. Skip duplicate i. → 2 triplets.

## 7. Time & Space Complexity
- **Time:** O(N²) after O(N log N) sort
- **Space:** O(1) extra excluding output (sort may use O(log N))

## 8. Trade-offs & Alternatives
Sorting mutates input (copy if needed). Output size can dominate space.

## 9. Common Mistakes / Edge Cases
Not skipping duplicate `i`/`L`/`R`; int overflow on sum (use wider type); `L` starting at 0.

## 10. Interview Follow-ups / Variations
kSum; 3Sum Closest; count triplets without listing.

## 11. Tags
`two-pointers`, `sorting`, `dedup`, `leetcode-15`
