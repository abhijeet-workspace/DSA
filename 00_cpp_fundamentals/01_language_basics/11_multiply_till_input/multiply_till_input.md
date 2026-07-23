# Multiply Till Input

## 1. Problem Statement
Read an integer N, then read N integers and print their product.

- **Input:** N, then N integers
- **Output:** `Total :- <product>` (or `Total :- 1` when N ≤ 0)
- **Valid answer:** product of all entered values using a running accumulator
- **Edges:** N ≤ 0; zeros in the list (product becomes 0); overflow for large magnitudes

## 2. Intuition
Accumulate a running product while reading. Multiplication is associative for the collected values, so order of pairwise multiply does not change the mathematical product (ignoring overflow).

## 3. Brute Force → Optimal
- **Naive:** store all values, then reduce with a second loop — still O(N), extra pass.
- **This approach:** multiply into `total` during the read loop — same asymptotics, one pass.
- Still overflows for huge products; educational demo only. Prefer checked multiplication in serious code.

## 4. Data Structure / Approach Justification
`std::vector<long long> values` sized to N, plus `long long total`.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| VLA `long long a[n]` | Non-portable; avoided intentionally |
| No storage, only `total` | Sufficient if you never need the list again — even leaner |
| `int` accumulator | Overflows sooner than `long long` |

We keep the vector to show portable dynamic storage vs VLAs (common mistake called out in the original notes).

## 5. Logic Walkthrough
1. Read `number` (N) in `main`, call `multiplyOfNumber`.
2. If `number <= 0`, print product `1` (empty-product convention) and return.
3. Allocate `values` of size N; set `total = 1`.
4. For each `i`, read `values[i]` and do `total *= values[i]`.
5. Print `total`.

## 6. Dry Run
N = 3, inputs `2 4 5`:

| i | input | `total` after |
|---|-------|---------------|
| 0 | 2 | 2 |
| 1 | 4 | 8 |
| 2 | 5 | 40 |

Output: `Total :- 40`

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) for `values` (O(1) if only `total` were kept)
- Why: one linear scan; vector holds all factors

## 8. Trade-offs & Alternatives
- Drop the vector if you only need the product.
- Use big-integer libraries when overflow is unacceptable.
- Mentally note modular multiplication variants for contest math.

## 9. Common Mistakes / Edge Cases
- Variable-length arrays (non-portable) — use `std::vector`
- Ignoring N ≤ 0
- Silent `int` overflow
- Not handling a zero factor (product correctly becomes 0)

## 10. Interview Follow-ups / Variations
- Detect overflow before multiplying?
- Product of all except self (prefix/suffix products)?
- Streaming product without storing inputs?

## 11. Tags
`cpp-basics`, `loops`, `vector`, `product`, `beginner`
