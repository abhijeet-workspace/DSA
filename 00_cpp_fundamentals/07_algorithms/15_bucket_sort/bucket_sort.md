# Bucket Sort

## Problem Statement
Sort floats assumed roughly uniform in `[0,1)` via bucket sort.

## Intuition
Scatter into buckets by value range, sort locally, concatenate.

## Brute Force → Optimal
Comparison sort always O(N log N). Buckets average O(N) when uniform.

## Data Structure / Approach Justification
`vector<vector<float>>` buckets. A single array + insertion sort per bucket is a common variant.

## Logic Walkthrough
Create n buckets; index `floor(n*x)`; `std::sort` each; flatten.

## Dry Run
Demo array sorts ascending near 0.12 … 0.90.

## Time & Space Complexity
**Average Time:** O(N). **Worst:** O(N^2) if all land in one bucket. **Space:** O(N).

## Trade-offs & Alternatives
Needs distribution assumptions; poor on adversarial clustering.

## Common Mistakes / Edge Cases
Index out of range when `x==1`; wrong bucket count.

## Interview Follow-ups / Variations
Generalize to arbitrary [min,max]; histogram sort.

## Tags
`topic: sorting` · `pattern: bucket` · `difficulty: medium`
