# Binary Exponentiation

## 1. Problem Statement
Compute `base^exp` modulo `mod` efficiently (building block for modular inverse, Catalan, etc.).

- **Inputs:** `base`, `exp`, `mod` (non-negative integers; `mod > 0`).
- **Output:** `(base^exp) % mod`.
- **Valid answer:** exact modular power.
- **Edges:** `exp=0` → 1; `base=0`; `mod=1` → 0; large intermediates (overflow risk).

## 2. Intuition
The exponent’s binary bits decide which squared powers multiply into the answer. Square `base` each step; when the current bit is set, multiply into `result`.

## 3. Brute Force → Optimal
- **Brute:** multiply `base` into an accumulator `exp` times — O(exp).
- **Optimal:** binary exponentiation — O(log exp) multiplications.

## 4. Data Structure / Approach Justification
**Chosen:** iterative bit loop with modular multiply.

- **vs recursive pow:** same asymptotics; iterative avoids stack depth.
- **vs naive loop:** required when `exp` is up to 10^18.

## 5. Logic Walkthrough
`result = 1`, reduce `base %= mod`. While `exp > 0`: if odd bit, `result = result * base % mod`; then `base = base * base % mod`, `exp >>= 1`.

## 6. Dry Run
`3^13`, `13 = 1101b`: start result=1, base=3 → bit0 set → result=3, base=9; bit1 unset, base=81; bit2 set → result=243, base=…; bit3 set → result=1594323.

## 7. Time & Space Complexity
Time **O(log exp)**. Space **O(1)**. Why: one multiply per bit of the exponent (section 4).

## 8. Trade-offs & Alternatives
Needs careful mod mul (or `__int128`) to avoid overflow. Matrix expo generalizes this for linear recurrences.

## 9. Common Mistakes / Edge Cases
Multiplying without `% mod`; overflow on `base * base`; forgetting `exp=0`.

## 10. Interview Follow-ups / Variations
Modular inverse via `a^(p-2)` (Fermat); pow for negative exponents; matrix exponentiation (Fibonacci).

## 11. Tags
`math`, `number-theory`, `binary-exponentiation`, `modular-arithmetic`, `difficulty:easy`
