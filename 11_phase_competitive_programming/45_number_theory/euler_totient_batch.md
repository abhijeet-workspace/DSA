# Euler Totient Batch (1..N) — Teaching Lab

## 1. Problem Statement
**Teaching lab:** compute φ(i) for all i in `[1, N]` in O(N log log N) via sieve-like updates.

- **Inputs:** bound N.
- **Output:** array `phi[1..N]`.
- **Edges:** phi[1]=1.

## 2. Intuition
Initialize phi[i]=i. For each prime p, for multiples m=p,2p,… set phi[m]-=phi[m]/p.

## 3. Brute Force → Optimal
- **Brute:** factor each i separately — O(N√N).
- **Optimal:** totient sieve — O(N log log N).

## 4. Data Structure / Approach Justification
**Chosen:** linear-ish sieve updates on `vector<int> phi`.

**Pedagogy:** batch form of φ; single-n φ is in `number_theory`. Use batch when many totient queries share a bound.

## 5. Logic Walkthrough
phi[i]=i; for p=2..N if phi[p]==p (prime): for m=p; m<=N; m+=p: phi[m]-=phi[m]/p.

## 6. Dry Run
N=10 → φ = [-,1,1,2,2,4,2,6,4,6,4]. Sum check φ(1)+…+φ(10)=**20**? Actually sum_{k=1}^n φ(k) counts fractions; for n=10 sum=32? Wait: 1+1+2+2+4+2+6+4+6+4=32.

## 7. Time & Space Complexity
Time **O(N log log N)**, space **O(N)**.

## 8. Trade-offs & Alternatives
Linear sieve can compute phi while building primes.

## 9. Common Mistakes / Edge Cases
Starting from phi[i]=0; updating only primes incorrectly.

## 10. Interview Follow-ups / Variations
Sum of totient; gcd counting via φ; Euler theorem reductions.

## 11. Tags
`euler-totient`, `sieve`, `teaching-lab`, `difficulty:medium`
