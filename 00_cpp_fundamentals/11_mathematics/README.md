# Mathematics (C++ Fundamentals)

Progressive math track inside `00_cpp_fundamentals`: basic arithmetic → number-theory warmup.

Study order:

| # | Topic | Level | Folder |
|---|-------|-------|--------|
| 01 | Arithmetic basics | Beginner | `01_arithmetic_basics` |
| 02 | Divisors, GCD, LCM | Beginner | `02_divisors_gcd_lcm` |
| 03 | Primes & factorization | Beginner–Intermediate | `03_prime_checking_factors` |
| 04 | Digit problems | Beginner | `04_digit_problems` |
| 05 | Power & roots | Intermediate | `05_power_and_roots` |
| 06 | Modular arithmetic | Intermediate | `06_modular_arithmetic` |
| 07 | Series & sequences | Beginner–Intermediate | `07_series_and_sequences` |
| 08 | Combinatorics basics | Intermediate | `08_combinatorics_basics` |
| 09 | Sieve & totient intro | Advanced fundamentals | `09_sieve_and_totient_intro` |

Each topic has a `.md` explanation (same section template as other fundamentals) and a runnable `.cpp` demo with expected outputs.

## Where this sits in the repo

- **This section:** foundations and interview-style math drills in C++.
- **Next:** `10_phase_advanced_topics/41_mathematical_algorithms` (extended Euclid, modular inverse, Catalan, segmented themes).
- **CP depth:** `11_phase_competitive_programming/45_number_theory`, `46_combinatorics`, `48_advanced_math`, `49_geometry`.

## How to run a lesson

```bash
g++ -std=c++17 -Wall -Wextra -O0 \
  00_cpp_fundamentals/11_mathematics/02_divisors_gcd_lcm/divisors_gcd_lcm.cpp \
  -o /tmp/math_demo && /tmp/math_demo
```

Compile-all CI already picks up every `.cpp` under `00_cpp_fundamentals`.
