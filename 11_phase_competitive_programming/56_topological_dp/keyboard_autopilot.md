# Keyboard Autopilot

## 1. Problem Statement
Teaching lab — count walks on a 3×3 keypad graph that spell a digit string `s` (each step must move to an adjacent key including staying on the listed self adjacency).

- **Inputs:** string `s` over `'1'..'9'`.
- **Output:** number of walks producing `s`.
- **Edges:** impossible adjacency → 0; length 1 → 1.

## 2. Intuition
`dp[i][key]` ways to place `s[i]` on `key`; transitions along keypad DAG layers `i → i+1`.

## 3. Brute Force → Optimal
- **Brute:** DFS walks.
- **Optimal:** layered DP O(|s|·states).

## 4. Data Structure / Approach Justification
**Chosen:** position × key DP (topo on string index).

| Alternative | Note |
|-------------|------|
| Matrix pow per step | Overkill for short s |

## 5. Logic Walkthrough
Seed `dp[0][s[0]]=1`; transition if edge to next required digit.

## 6. Dry Run
`12`→1, `11`→1, `13`→0.

## 7. Time & Space Complexity
Time **O(|s|)**. Space **O(|s|)** (or O(1) rolling).

## 8. Trade-offs & Alternatives
Illustrates DP on an explicit small DAG layered by time.

## 9. Common Mistakes / Edge Cases
Forgetting self-loops; including `0` key.

## 10. Interview Follow-ups / Variations
Knight dialer (LC 935); modulo.

## 11. Tags
`teaching`, `dag-dp`, `keypad`, `difficulty:easy`
