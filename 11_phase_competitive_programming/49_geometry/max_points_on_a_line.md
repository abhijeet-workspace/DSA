# Max Points on a Line (LC 149)

## 1. Problem Statement
[LeetCode 149 — Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/): given points on a 2D plane, return the maximum number of points that lie on the same straight line.

- **Inputs:** points[i] = [xi, yi].
- **Output:** max count.
- **Edges:** ≤2 points; duplicates.

## 2. Intuition
For each origin point, map slopes of other points; same slope ⇒ collinear. Represent slope as reduced dy/dx fraction.

## 3. Brute Force → Optimal
- **Brute:** check all triples O(n³).
- **Optimal:** O(n²) hashmap of slopes per origin.

## 4. Data Structure / Approach Justification
**Chosen:** gcd-reduced slope pairs as map keys.

**Pedagogy:** classic analytic geometry / slope hashing.

## 5. Logic Walkthrough
For each i, map slopes to counts; track duplicates at i; ans = max(dup+same_slope).

## 6. Dry Run
`[[1,1],[2,2],[3,3]]` → **3**.

## 7. Time & Space Complexity
Time **O(n² log C)** with map (hash O(n²)), space **O(n)**.

## 8. Trade-offs & Alternatives
Use long double slopes carefully (precision); prefer fractions.

## 9. Common Mistakes / Edge Cases
Vertical line dx=0; duplicate points; gcd sign normalize.

## 10. Interview Follow-ups / Variations
Line equation ax+by+c; 3D variants.

## 11. Tags
`geometry`, `hashmap`, `leetcode-149`, `difficulty:hard`
