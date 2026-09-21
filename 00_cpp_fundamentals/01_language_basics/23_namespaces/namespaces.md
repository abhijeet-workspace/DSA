# Namespaces

## 1. Problem Statement
Show named namespaces, nested namespaces, qualified calls (`math::add`), and a `using`-declaration. Note why `using namespace` in headers is harmful.

- **Input:** none
- **Output:** `5`, `8`, and a greeting line
- **Valid answer:** same function names can coexist in different namespaces
- **Edges:** anonymous namespaces give internal linkage (not shown)

## 2. Intuition
Namespaces prevent name collisions by grouping related declarations under a prefix.

## 3. Brute Force → Optimal
- **Naive:** unique global prefixes (`math_add`, `util_greet`) everywhere.
- **This approach:** language-level namespaces + selective `using` at call sites.

## 4. Data Structure / Approach Justification
Free functions in namespaces — clearest teaching surface.

| Alternative | Why it loses here |
|-------------|-------------------|
| Classes as “namespaces” | Different tool (state + access control) |
| Global `using namespace std;` | Convenience; pollution risk |

## 5. Logic Walkthrough
1. Call `math::add` and `math::detail::twice` with qualification.
2. Import only `util::greet` with a using-declaration.
3. Avoid file-scope `using namespace` in headers (documented).

## 6. Dry Run
| Call | Result |
|------|--------|
| `math::add(2,3)` | 5 |
| `math::detail::twice(4)` | 8 |
| `greet()` after using-declaration | prints hello |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: namespaces are a compile-time naming tool

## 8. Trade-offs & Alternatives
- Prefer qualification or narrow using-declarations.
- Prefer nested `detail` for helpers not part of the public API.
- Prefer namespaces over macros for grouping.

## 9. Common Mistakes / Edge Cases
- `using namespace std;` in a header
- Accidental ADL surprises with operators
- Forgetting to close namespace braces

## 10. Interview Follow-ups / Variations
- What is ADL (argument-dependent lookup)?
- Anonymous namespace vs `static` free function?
- Inline namespaces for ABI versioning?

## 11. Tags
`cpp-basics`, `namespaces`, `linkage`, `beginner`
