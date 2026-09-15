# Universal Hash Family Lab

## 1. Problem Statement
Demonstrate a simple universal hash family `h_{a,b}(x) = ((ax+b) mod p) mod m` and measure collision rates on random keys.

- **Inputs:** universe sample; table size m; random a,b.
- **Output:** max chain length / collision stats for chaining demo.
- **Edges:** a=0 degenerate; p prime > universe.

## 2. Intuition
Universal families bound expected collisions under adversarial keys.

## 3. Brute Force → Optimal
- **Fixed hash:** adversaries create collisions.
- **Random family:** expected O(1) chains.

## 4. Data Structure / Approach Justification
**Chosen:** Carter–Wegman style linear hash mod prime.

| Alternative | Note |
|-------------|------|
| `std::hash` | Implementation-defined |
| Multiply-shift | Practical universal |

## 5. Logic Walkthrough
1. Pick prime p, random a∈[1,p), b∈[0,p).
2. Insert keys into m buckets.
3. Report max load.

## 6. Dry Run
Random keys → max load near logarithmic / small.

## 7. Time & Space Complexity
**O(N)** build.

## 8. Trade-offs & Alternatives
Teaching model for hashing interviews.

## 9. Common Mistakes / Edge Cases
a=0; non-prime p; overflowing ax+b.

## 10. Interview Follow-ups / Variations
Perfect hashing; 2-universal vs strongly universal.

## 11. Tags
`universal-hashing`, `lab`, `randomized`, `difficulty:medium`
