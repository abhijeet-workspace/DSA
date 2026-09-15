# Encode and Decode Strings

## 1. Problem Statement
[LeetCode 271](https://leetcode.com/problems/encode-and-decode-strings/) (premium) — design codec to encode a list of strings to one string and decode back (any charset).

- **Inputs:** `vector<string>`.
- **Output:** round-trip identical list.
- **Valid answer:** any correct framing.
- **Edges:** empty strings; delimiters in content; empty list.

## 2. Intuition
Length-prefix framing: `len#payload` for each string avoids delimiter collisions.

## 3. Brute Force → Optimal
- **Brute:** join with rare sentinel — fails if sentinel appears.
- **Optimal:** length prefix — O(total).

## 4. Data Structure / Approach Justification
**Chosen:** `to_string(size) + '#' + s` concatenation.

- **vs escaping:** longer and error-prone.

## 5. Logic Walkthrough
Encode appends prefixes. Decode parses int until `#`, then take next `len` chars.

## 6. Dry Run
`["Hello","World"]` round-trips.

## 7. Time & Space Complexity
Time **O(total chars)**. Space **O(total)**.

## 8. Trade-offs & Alternatives
Chunked transfer / protobuf-style varints for production.

## 9. Common Mistakes / Edge Cases
Not handling empty string; parsing past end; `#` in length field.

## 10. Interview Follow-ups / Variations
Serialize/deserialize binary trees; URL codec.

## 11. Tags
`string`, `design`, `leetcode-271`, `difficulty:medium`
