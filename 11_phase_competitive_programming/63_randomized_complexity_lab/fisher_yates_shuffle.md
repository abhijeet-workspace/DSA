# Fisher–Yates Shuffle

## 1. Problem Statement
Produce a uniform random permutation of an array in-place (Fisher–Yates).

- **Inputs:** array `a`.
- **Output:** shuffled `a`; each permutation equally likely.
- **Edges:** n=0/1; prove index range `i..n-1`.

## 2. Intuition
For i from n-1..1, swap a[i] with a[rand 0..i].

## 3. Brute Force → Optimal
- **Brute:** generate all perms — impossible.
- **Fisher–Yates:** O(N).

## 4. Data Structure / Approach Justification
**Chosen:** modern Fisher–Yates with `mt19937`.

| Alternative | Note |
|-------------|------|
| Sort by random keys | Biased if ties |
| Naive rand swaps | Often biased |

## 5. Logic Walkthrough
1. Seed RNG.
2. Loop i=n-1..1 swap with uniform j∈[0,i].

## 6. Dry Run
`[1,2,3]` → one of 6 perms.

## 7. Time & Space Complexity
**O(N)** time, **O(1)** extra.

## 8. Trade-offs & Alternatives
Gold standard shuffle.

## 9. Common Mistakes / Edge Cases
Using `rand()%n` always; swapping with full range each time (bias).

## 10. Interview Follow-ups / Variations
Partial shuffle; random sample.

## 11. Tags
`shuffle`, `fisher-yates`, `randomized`, `difficulty:easy`
