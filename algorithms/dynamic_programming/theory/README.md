# Dynamic Programming Theory

Dynamic Programming (DP) is an algorithmic technique for solving optimization problems by breaking them down into simpler subproblems and utilizing the fact that the optimal solution to the overall problem depends upon the optimal solutions to its subproblems.

## Key Attributes of DP Problems
1. **Overlapping Subproblems**: The same subproblems are solved multiple times.
2. **Optimal Substructure**: The optimal solution to the problem can be constructed from the optimal solutions of its subproblems.

## Approaches
- **Top-Down (Memoization)**: Solves the problem recursively, caching the results of subproblems to avoid redundant calls.
- **Bottom-Up (Tabulation)**: Solves subproblems first (usually in an array/table) and builds up to the solution of the main problem iteratively.
