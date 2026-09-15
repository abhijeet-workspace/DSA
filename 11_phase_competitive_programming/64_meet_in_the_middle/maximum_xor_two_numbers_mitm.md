# Maximum XOR of Two Numbers — MITM vs Trie Note

## 1. Problem Statement
Find max `a[i] XOR a[j]` (i≠j).

- **Inputs:** integer array.
- **Output:** maximum XOR pair.
- **Related:** [LC 421](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/).
- **Note:** Preferred solution is binary trie. MITM on bits/halves is weak; lab implements trie and notes MITM is not preferred.
- **Link:** [LC 421](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)

## 2. Intuition
Greedy bit trie: for each number, try opposite bits from MSB.

## 3. Brute Force → Optimal
- **Brute:** O(N²).
- **Trie:** O(N · bits).
- **MITM:** uncommon here.

## 4. Data Structure / Approach Justification
**Chosen:** binary trie of bit prefixes.

| Alternative | Note |
|-------------|------|
| Brute | Tiny N |
| MITM | Prefer subset XOR problems, not this |

## 5. Logic Walkthrough
1. Insert all into bit trie.
2. For each num query best opposite path.
3. Track max.

## 6. Dry Run
`[3,10,5,25,2,8]` → **28** (5⊕25).

## 7. Time & Space Complexity
**O(N · 32)**.

## 8. Trade-offs & Alternatives
Document when MITM helps (subset XOR) vs trie (pair XOR).

## 9. Common Mistakes / Edge Cases
Signed shifts; not trying opposite bit first.

## 10. Interview Follow-ups / Variations
Max XOR subsequence; MITM subset XOR =k.

## 11. Tags
`trie`, `xor`, `lc-421`, `mitm-contrast`, `difficulty:medium`
