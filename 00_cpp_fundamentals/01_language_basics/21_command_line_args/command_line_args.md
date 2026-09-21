# Command-line Arguments

## 1. Problem Statement
Show `main(int argc, char* argv[])`: print argument count and each `argv[i]`, noting that `argv[0]` is typically the program path/name.

- **Input:** optional CLI args
- **Output:** `argc` and each argv string
- **Valid answer:** `argc >= 1`; user args start at index 1
- **Edges:** empty argc is rare; never assume argv strings are integers without parsing

## 2. Intuition
The OS passes the command line into your process. `argv` is an array of C-strings; `argc` is how many.

## 3. Brute Force → Optimal
- **Naive:** hardcode inputs inside `main`.
- **This approach:** take parameters from the shell for reusable CLIs.

## 4. Data Structure / Approach Justification
Raw `char* argv[]` as provided by the language.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `std::vector<std::string>(argv, argv+argc)` | Friendlier C++ API; slight copy cost |
| Libraries (`CLI11`, etc.) | Better for real CLIs; dependency |

## 5. Logic Walkthrough
1. Print `argc`.
2. Loop `i` from 0 to argc-1 printing `argv[i]`.
3. If argc>=2, highlight `argv[1]`.

## 6. Dry Run
Command: `./a.out hello 42`

| i | argv[i] |
|---|---------|
| 0 | `./a.out` |
| 1 | `hello` |
| 2 | `42` |
| argc | 3 |

## 7. Time & Space Complexity
- **Time:** O(argc + total chars printed)
- **Space:** O(1) beyond OS-provided argv
- Why: single scan

## 8. Trade-offs & Alternatives
- Prefer converting to `std::string` before parsing.
- Prefer a CLI parser for flags/options at scale.
- Document required args and exit non-zero on misuse.

## 9. Common Mistakes / Edge Cases
- Using `argv[1]` when `argc < 2`
- Forgetting `argv` entries are `char*` (C-strings)
- Assuming numeric encoding without `stoi`/`from_chars`

## 10. Interview Follow-ups / Variations
- How would you parse `--flag value`?
- Wide args on Windows (`wmain`)?
- Environment variables vs argv?

## 11. Tags
`cpp-basics`, `argv`, `cli`, `beginner`
