# Random Point in Circle (LC 478)

## 1. Problem Statement
Sample points uniformly inside a circle given center and radius.

- **Inputs:** radius, (x,y); `randPoint` queries.
- **Output:** points with uniform area distribution.
- **Valid answer:** [LC 478](https://leetcode.com/problems/generate-random-point-in-a-circle/).
- **Edges:** rejection vs sqrt-radius method.
- **Link:** [LC 478](https://leetcode.com/problems/generate-random-point-in-a-circle/)

## 2. Intuition
Uniform in disk: r = R*sqrt(U), θ=2πV — not uniform r alone.

## 3. Brute Force → Optimal
- **Rejection:** sample square, reject outside.
- **Polar with sqrt:** direct.

## 4. Data Structure / Approach Justification
**Chosen:** polar with `sqrt` for radius.

| Alternative | Note |
|-------------|------|
| Rejection sampling | Simple, some waste |
| Wrong polar without sqrt | Biased to center |

## 5. Logic Walkthrough
1. U,V ~ Uniform(0,1).
2. r=radius*sqrt(U); θ=2πV.
3. Return center + (r cos θ, r sin θ).

## 6. Dry Run
Many samples should fill disk evenly (visual check).

## 7. Time & Space Complexity
**O(1)** per sample.

## 8. Trade-offs & Alternatives
Know the sqrt bias fix — interview favorite.

## 9. Common Mistakes / Edge Cases
Using r=R*U without sqrt.

## 10. Interview Follow-ups / Variations
Annulus; sphere surface.

## 11. Tags
`geometry`, `sampling`, `lc-478`, `difficulty:medium`
