# Rabin–Karp Algorithm

## Problem Statement
Find all starting indices of pattern `pat` in text `txt` using a rolling hash, verifying character equality on hash matches.

- **Inputs:** `txt`, `pat`, prime modulus `q`.
- **Output:** 0-based match starts.
- **Valid answer:** all true occurrences (no false positives after verify).
- **Edges:** no match; repetitive text; hash collision (spurious hit) must be rejected.

## Intuition
Compare windows by numeric fingerprint. Slide by removing the left character’s contribution and adding the new right character in O(1), then only scan characters when hashes equal.

## Brute Force → Optimal
- **Brute:** compare every window — O(N·M).
- **Average optimal:** Rabin–Karp — O(N + M) expected with good hash; worst O(N·M) if many collisions.
- **Worst-case linear alternative:** KMP / Z.

## Data Structure / Approach Justification
**Chosen:** polynomial rolling hash base `d=256`, mod prime `q`; O(1) aux beyond output.

- **vs KMP:** simpler multi-pattern / plagiarism vibe; weaker worst case.
- **vs Z:** Z guarantees linear without modular arithmetic pitfalls.

## Logic Walkthrough
Precompute `h = d^{m-1} % q`. Hash pattern and first window. For each `i`: if hashes match, verify chars; then `txtHash = (d*(txtHash - txt[i]*h) + txt[i+m]) % q`, fix negatives.

## Dry Run
`txt="GEEKS FOR GEEKS"`, `pat="GEEK"` → hits at **0** and **10**.
`pat="FAIL"` in `"SUCCESS"` → **none**.

## Time & Space Complexity
Average time **O(N + M)**; worst **O(N·M)**; space **O(1)** aux (+ output). Why: each window rehashes in O(1); verify costs O(M) per hit (section 4).

## Trade-offs & Alternatives
Great for teaching hashing and multi-pattern (several pattern hashes). Prefer KMP when worst-case guarantees matter. Double hashing reduces collision risk in CP.

## Common Mistakes / Edge Cases
Forgetting negative mod fix; skipping character verify; overflow without 64-bit / big mod; empty pattern.

## Interview Follow-ups / Variations
Multiple patterns; plagiarism detection; string hashing for substr equality / palindrome checks.

## Tags
`string`, `rabin-karp`, `rolling-hash`, `pattern-matching`, `difficulty:medium`
