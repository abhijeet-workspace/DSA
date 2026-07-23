# Preprocessor Directives

## Problem Statement

Demonstrate that `#define PI 3.14` is text-replaced before the compiler sees the code, so printing `PI` prints `3.14`.

- **Inputs:** none (literal macro).
- **Outputs:** `PI = 3.14`.
- **Edge cases:** macros lack type safety; parenthesize macro expressions; prefer `constexpr` in modern C++.

## Intuition

The preprocessor runs first: `#include`, `#define`, `#ifdef`. Macros are copy-paste, not typed constants.

## Brute Force → Optimal

**Naive:** hardcode `3.14` at every use — brittle.

**Better classic:** `#define PI 3.14`.

**Modern preferred:** `constexpr double PI = 3.14;` (typed, scoped). This demo keeps `#define` to teach the preprocessor stage.

## Data Structure / Approach Justification

**Chosen:** object-like macro `#define`.

- **vs `const`/`constexpr`:** macros ignore scopes/types; constants are safer.
- **vs `enum`:** enums are integral only.
- Use macros for include guards / feature flags; prefer `constexpr` for values.

## Logic Walkthrough

1. `#define PI 3.14` registers replacement.
2. In `main`, token `PI` is replaced with `3.14`.
3. Stream prints the floating literal.

## Dry Run

Source seen by compiler after preprocess roughly:
`std::cout << "PI = " << 3.14 << '\n';`
Output: `PI = 3.14`.

## Time & Space Complexity

Preprocessor work is O(source size). Runtime of this demo is O(1).

## Trade-offs & Alternatives

Macros enable conditional compilation (`#ifdef DEBUG`) but hurt debuggability. Prefer `constexpr`, inline functions, and `enum class` when possible.

## Common Mistakes / Edge Cases

- `#define SQUARE(x) x*x` → `SQUARE(1+2)` becomes `1+2*1+2`. Use `(x)*(x)`.
- Putting `using namespace std;` in headers (related hygiene).
- Redefining macros without `#undef`.

## Interview Follow-ups / Variations

- Function-like macros vs `inline`/`constexpr` functions.
- `#ifdef` / `#ifndef` include guards vs `#pragma once`.
- Variadic macros and stringizing (`#x`).

## Tags

`preprocessor`, `macros`, `constexpr-alternative`, `difficulty:easy`
