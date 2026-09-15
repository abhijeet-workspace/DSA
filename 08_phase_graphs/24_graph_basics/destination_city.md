# Destination City

## 1. Problem Statement
[LeetCode 1436](https://leetcode.com/problems/destination-city/) — `paths[i] = [cityA, cityB]` is a directed edge. The route is a simple path; return the destination city (outdegree 0).

- **Inputs:** list of directed edges as string pairs.
- **Output:** destination city name.
- **Valid answer:** unique sink.
- **Edges:** two cities; longer chain.

## 2. Intuition
Collect all start cities; the end city that never appears as a start is the destination.

## 3. Brute Force → Optimal
- **Brute:** build outdegree map.
- **Optimal:** hash set of starts, scan ends — O(E).

## 4. Data Structure / Approach Justification
**Chosen:** `unordered_set` of outgoing cities.

- **vs full graph:** unnecessary for a path/chain.

## 5. Logic Walkthrough
Insert all `p[0]`. Return first `p[1]` not in the set.

## 6. Dry Run
London→NY→Lima→Sao Paulo → **Sao Paulo**.

## 7. Time & Space Complexity
Time **O(E)**. Space **O(E)**. Why: hash starts (section 4).

## 8. Trade-offs & Alternatives
Outdegree map works for general DAGs with one sink.

## 9. Common Mistakes / Edge Cases
Comparing wrong index; assuming undirected.

## 10. Interview Follow-ups / Variations
Find sources; validate single path; itinerary reconstruction.

## 11. Tags
`graph`, `hash-set`, `leetcode-1436`, `difficulty:easy`
