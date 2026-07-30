# Fizz Buzz

## Problem Statement
[LeetCode 412](https://leetcode.com/problems/fizz-buzz/) — for `i` from 1 to `n`, return `"FizzBuzz"` if divisible by 3 and 5, `"Fizz"` by 3, `"Buzz"` by 5, else the number as string.

- **Inputs:** `int n`.
- **Output:** `vector<string>` length `n`.
- **Edges:** `n=1`; multiples of 15.

## Intuition
Check divisibility in most-specific-first order (15 before 3/5) to avoid missing combined cases.

## Brute Force → Optimal
Single pass is required — O(N). Optional: avoid `%` with counters every 3/5.

## Data Structure / Approach Justification
**Chosen:** direct `%` checks — clearest interview answer.

## Logic Walkthrough
For `i=1..n`: if `%15` → FizzBuzz; else `%3` → Fizz; else `%5` → Buzz; else `to_string(i)`.

## Dry Run
`n=5` → `["1","2","Fizz","4","Buzz"]`.

## Time & Space Complexity
Time **O(N)**. Space **O(N)** for output.

## Trade-offs & Alternatives
Counter approach reduces modulo ops; string concat `"Fizz"+"Buzz"` is another style.

## Common Mistakes / Edge Cases
Checking 3 before 15 without combining; off-by-one on range.

## Interview Follow-ups / Variations
Custom divisors/rules table.

## Tags
`math`, `string`, `simulation`, `leetcode-412`, `difficulty:easy`
