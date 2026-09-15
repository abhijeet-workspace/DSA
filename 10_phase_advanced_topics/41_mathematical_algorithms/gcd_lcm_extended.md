# GCD, LCM & Extended Euclidean

## 1. Problem Statement
Compute `gcd(a,b)`, `lcm(a,b)`, and integers `x,y` satisfying `ax + by = gcd(a,b)` (Bézout).

- **Inputs:** integers `a`, `b`.
- **Output:** gcd; lcm; `(g, x, y)` from extended Euclid.
- **Valid answer:** any valid Bézout pair for extended form.
- **Edges:** `b=0`; negative inputs (define sign convention); lcm overflow.

## 2. Intuition
Euclid: `gcd(a,b)=gcd(b,a%b)`. Back-substitute remainders to recover coefficients. `lcm = a/gcd*b` (divide before multiply).

## 3. Brute Force → Optimal
- **Brute:** trial divisors from `min(a,b)` downward.
- **Optimal:** Euclidean algorithm — O(log min(a,b)).

## 4. Data Structure / Approach Justification
**Chosen:** recursive Euclid + recursive ExtGcd.

- **vs iterative ExtGcd:** same complexity, no stack.
- **vs `std::gcd` (C++17):** fine for plain gcd; ExtGcd still needed for inverses/CRT.

## 5. Logic Walkthrough
Base: `b==0` → `(g,x,y)=(a,1,0)`. Recurse on `(b,a%b)` getting `(x1,y1)`; set `x=y1`, `y=x1-(a/b)*y1`.

## 6. Dry Run
`gcd(48,18)` → `(18,12)` → `(12,6)` → `(6,0)` = 6. `extGcd(35,15)` → `g=5`, `x=1`, `y=-2` because `35·1+15·(-2)=5`.

## 7. Time & Space Complexity
Time **O(log min(a,b))**. Space **O(log)** recursion (or O(1) iterative). Why: remainders shrink exponentially (section 4).

## 8. Trade-offs & Alternatives
Binary GCD (Stein) avoids `%`. ExtGcd unlocks modular inverse and linear Diophantine equations.

## 9. Common Mistakes / Edge Cases
`lcm = a*b/gcd` overflowing; forgetting `gcd(a,0)=a`.

## 10. Interview Follow-ups / Variations
Solve `ax ≡ b (mod m)`; CRT; modular inverse via ExtGcd when mod is composite.

## 11. Tags
`math`, `gcd`, `lcm`, `extended-euclidean`, `number-theory`, `difficulty:easy`
