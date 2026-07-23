# Encode and Decode Strings

## 1. Problem Statement
Design `encode(list) → string` and `decode(string) → list` such that `decode(encode(strs)) == strs` for arbitrary strings (may contain delimiters).

- **Input:** `vector<string>`; then encoded blob
- **Output:** opaque string; recovered list
- **Valid answer:** exact round-trip
- **Edges:** empty strings; empty list; strings containing `#`

## 2. Intuition
Prefix each string with its length and a separator: `len#payload`. Length frames the payload exactly.

## 3. Brute Force → Optimal
- **Brute:** join with a rare delimiter — breaks if delimiter appears in data.
- **Optimal:** length-prefixed framing — unambiguous for any payload.

## 4. Data Structure / Approach Justification
Plain `string` builder + index walk on decode. No hash structures required.

| Alternative | Why it loses here |
|-------------|-------------------|
| Rare delimiter join | Collides with data |
| Escape schemes | Easy to get wrong in interview |

## 5. Logic Walkthrough
**Encode:** for each `s`, append `to_string(size) + '#' + s`.  
**Decode:** read digits until `#`, parse length, take next `len` chars, repeat.

## 6. Dry Run
`["lint","code","love","you"]`
- encode → `"4#lint4#code4#love3#you"`
- decode reads 4→lint, 4→code, 4→love, 3→you → original

## 7. Time & Space Complexity
- **Time:** O(N) total character length
- **Space:** O(N)
- Why: single pass encode/decode over all bytes.

## 8. Trade-offs & Alternatives
`len#` is interview-friendly. Escapes / varints / protobuf work in production systems.

## 9. Common Mistakes / Edge Cases
Splitting only on `#` without consuming length first; empty string payloads (`0#`).

## 10. Interview Follow-ups / Variations
Unicode / binary? Streaming encode? Cap on max length?

## 11. Tags
`string`, `encoding`, `design`, `neetcode`
