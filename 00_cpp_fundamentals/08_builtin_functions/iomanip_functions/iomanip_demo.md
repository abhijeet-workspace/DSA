# Iomanip Demo (`<iomanip>`)

## Problem Statement
Print a client invoice with aligned columns (name, qty, unit price, line total) and a grand total using stream manipulators.

**Inputs:** client name + `vector<InvoiceItem>{name, quantity, unitPrice}`.  
**Valid answer:** fixed-width table, money to 2 decimals, divider lines.  
**Edges:** empty item list (header/total only), long names truncated by width visually.

## Intuition
Readable financial output is a formatting problem: column widths + alignment + fixed precision — exactly what `setw` / `left`/`right` / `fixed`/`setprecision` / `setfill` provide.

## Brute Force → Optimal
- **Brute:** manual padding with spaces/string concatenation → fragile.
- **Optimal:** sticky/non-sticky manipulators on `ostream` → O(R·W) print cost for R rows.

## Data Structure / Approach Justification (REQUIRED)
`std::vector<InvoiceItem>` for ordered line items (scan once top-to-bottom).
- **vs map keyed by name:** loses purchase order / duplicates.
- **vs raw arrays:** vector size is dynamic and matches STL range-for.

## Logic Walkthrough
Print header with `left`/`right` + `setw`; draw divider via `setfill('-')`; set `fixed`+`setprecision(2)`; accumulate `grandTotal`; print footer.

## Dry Run
Items MacBook (1×1999), adapters (3×19.99), mouse (2×59.50), protector (1×14) → grand total **2141.47**.

## Time & Space Complexity
**O(R)** time for R items, **O(1)** extra space. Why: single pass over vector (section 4).

## Trade-offs & Alternatives
`fmt` / `std::format` (C++20) for clearer format strings; locale facets for currency symbols.

## Common Mistakes / Edge Cases
Forgetting to reset `setfill(' ')`; assuming `setw` sticks (it doesn’t); mixing `fixed` with later scientific output without reset.

## Interview Follow-ups / Variations
Multi-currency columns; CSV export vs human table; right-align money with thousands separators.

## Tags
`iomanip`, `iostream`, `formatting`, `beginner`
