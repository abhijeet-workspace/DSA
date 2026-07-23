# C++17 Features

## Problem Statement
Demonstrate structured bindings, init-statement `if`, `std::optional`, `std::variant` + `visit`, and `std::string_view` zero-copy views.

**Inputs:** student pair, vector search, bool DB flag, variant assignments, long string.  
**Valid answer:** printed bindings, found element, optional value/fallback, variant visits, view sizes.  
**Edges:** `nullopt`; `get<T>` wrong type throws; `string_view` dangling if source dies.

## Intuition
C++17 cleans API design: unpack tuples, scope locals inside `if`, express absence without sentinels, hold one-of-many types safely, and view strings without allocating.

## Brute Force → Optimal
| Need | Old | C++17 |
|---|---|---|
| Unpack pair | `.first`/`.second` | `auto [a,b]` |
| Find + use iterator | declare `it` outside | `if (auto it=...; ...)` |
| Missing value | `-1` / `nullptr` | `optional` |
| Tagged union | `union` + enum | `variant` |
| Read-only substring | `string` copy | `string_view` |

## Data Structure / Approach Justification (REQUIRED)
- `optional<string>` for maybe-user — clearer than empty string sentinel.
- `variant<int,double,string>` for heterogeneous single slot — type-safe vs C `union`.
- `string_view` for read-only params — **vs `const string&`:** also accepts literals without temp `string`; **vs owning `string`:** no allocation, but must not outlive source.

## Logic Walkthrough
Unpack student; init-if `find` 30; optional hit/miss with `value_or`; assign variant through types + `visit`; print full and `substr(0,10)` views.

## Dry Run
`[101, Alice]`. Find 30 → printed. User `Abhijeet`; missing → `Guest_User`. Variant ends as `"Modern C++"` visited. View size 47; substr size 10.

## Time & Space Complexity
Bindings/optional/variant access **O(1)**. `string_view::substr` **O(1)** time/space (pointer+length). `find` **O(N)**. Why: non-owning view + linear search (section 4).

## Trade-offs & Alternatives
`expected`/`Outcome` for error codes; `span` for arrays; `std::format` for printing; `visit` overload set vs `get_if`.

## Common Mistakes / Edge Cases
`string_view` to temporary; `std::get` on wrong alternative; ignoring `optional` emptiness then calling `value()` (throws).

## Interview Follow-ups / Variations
`optional` chaining; recursive variants; `string_view` tokenization; C++20 `ranges`.

## Tags
`cpp17`, `optional`, `variant`, `string_view`, `intermediate`
