# Dynamic Programming (DP) Theory Guide

Dynamic Programming (DP) is a powerful algorithmic technique used to solve optimization and counting problems by breaking them down into simpler, overlapping subproblems. Instead of recomputing results for the same subproblem, DP solves each subproblem once and stores its result (a process called *caching* or *memoization*), yielding significant performance gains.

---

## When is Dynamic Programming Applied?

To apply DP, a problem must exhibit two key properties:

### 1. Overlapping Subproblems
A problem has overlapping subproblems if solving it requires solving the same subproblems repeatedly.
* **Example**: Finding the $N$-th Fibonacci number ($F_n = F_{n-1} + F_{n-2}$). To find $F_5$, we calculate $F_4$ and $F_3$. To find $F_4$, we calculate $F_3$ and $F_2$. Here, $F_3$ is an overlapping subproblem because it is computed multiple times in the recursion tree.
* **Contrast**: Merge Sort divides an array into two disjoint halves (no overlap), so it uses Divide and Conquer, not DP.

### 2. Optimal Substructure
A problem has optimal substructure if an optimal solution to the overall problem can be constructed from the optimal solutions of its subproblems.
* **Example**: In the shortest path problem, if the shortest path from $A$ to $C$ passes through $B$, then the path from $A$ to $B$ must also be the shortest path from $A$ to $B$.

---

## How is Dynamic Programming Applied? (The 3-Step Framework)

When designing a DP solution, follow this systematic process:

1. **Define the State**: Define what your DP array/table or function arguments represent. For example, `dp[i]` might represent the maximum profit achievable using elements from index `0` to `i`.
2. **Formulate the Transition Relation**: Find the recurrence relation that connects the current state to previous states (e.g., `dp[i] = dp[i-1] + dp[i-2]` or `dp[i] = max(dp[i-1], val + dp[i-2])`).
3. **Identify Base Cases**: Determine the starting values that require no computation (e.g., `dp[0] = 0`, `dp[1] = 1`).

---

## The Two Approaches: Top-Down vs. Bottom-Up

| Metric | Top-Down (Memoization) | Bottom-Up (Tabulation) |
| :--- | :--- | :--- |
| **Concept** | Solves recursively; stores results in a lookup table before returning. | Solves iteratively; fills table from base cases up to the target. |
| **Direction** | Starts at the target state and works backward. | Starts at base states and works forward. |
| **Pros** | Easier to formulate directly from a recursive relation; only computes needed states. | No recursion call-stack overhead; can often be optimized for space. |
| **Cons** | Call-stack overhead can lead to Stack Overflow for deep recursions. | Computes all states, even if some are never needed. |

---

## Detailed C++ Sample Codes

### Example 1: Fibonacci Numbers (One-Dimensional DP)

#### 1. Top-Down (Memoization)
```cpp
#include <vector>

class FibonacciMemoization {
private:
    std::vector<int> memo;

    int solve(int n) {
        // Base cases
        if (n <= 1) return n;
        
        // Return cached result if already computed
        if (memo[n] != -1) return memo[n];
        
        // Compute, cache, and return
        return memo[n] = solve(n - 1) + solve(n - 2);
    }

public:
    int getFibonacci(int n) {
        memo.assign(n + 1, -1);
        return solve(n);
    }
};
```

#### 2. Bottom-Up (Tabulation)
```cpp
#include <vector>

int fibonacciTabulation(int n) {
    if (n <= 1) return n;
    
    // Create DP table
    std::vector<int> dp(n + 1);
    
    // Initialize base cases
    dp[0] = 0;
    dp[1] = 1;
    
    // Fill the table iteratively
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}
```

#### 3. Space-Optimized Tabulation
Since computing `dp[i]` only requires the last two values (`dp[i-1]` and `dp[i-2]`), we can optimize space from $O(N)$ to $O(1)$.
```cpp
int fibonacciSpaceOptimized(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0; // represents dp[i-2]
    int prev1 = 1; // represents dp[i-1]
    int current = 0;
    
    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}
```

---

### Example 2: 0/1 Knapsack Problem (Two-Dimensional DP)

**Problem Statement**: Given $N$ items with weights `wt[]` and values `val[]`, and a knapsack of capacity `W`, determine the maximum value you can obtain without exceeding the capacity. Each item can either be taken or left (0 or 1).

#### 1. Top-Down (Memoization)
* **State**: `dp[i][w]` is the max value using a subset of items `0...i` with remaining capacity `w`.
* **Transition**: `dp[i][w] = max(exclude_item, include_item)`

```cpp
#include <vector>
#include <algorithm>

class KnapsackMemoization {
private:
    std::vector<std::vector<int>> dp;

    int solve(int i, int w, const std::vector<int>& wt, const std::vector<int>& val) {
        // Base case: no items left or capacity is 0
        if (i < 0 || w == 0) return 0;

        // Return cached value
        if (dp[i][w] != -1) return dp[i][w];

        // Choice 1: Exclude the item
        int exclude = solve(i - 1, w, wt, val);

        // Choice 2: Include the item (if weight permits)
        int include = 0;
        if (wt[i] <= w) {
            include = val[i] + solve(i - 1, w - wt[i], wt, val);
        }

        return dp[i][w] = std::max(exclude, include);
    }

public:
    int knapsack(int W, const std::vector<int>& wt, const std::vector<int>& val) {
        int n = wt.size();
        dp.assign(n, std::vector<int>(W + 1, -1));
        return solve(n - 1, W, wt, val);
    }
};
```

#### 2. Bottom-Up (Tabulation)
```cpp
#include <vector>
#include <algorithm>

int knapsackTabulation(int W, const std::vector<int>& wt, const std::vector<int>& val) {
    int n = wt.size();
    // dp[i][w] represents maximum value with first i items and capacity w
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // Option 1: Don't take the current item (index i-1 in wt and val)
            dp[i][w] = dp[i - 1][w];

            // Option 2: Take the item if capacity allows
            if (wt[i - 1] <= w) {
                dp[i][w] = std::max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }
    return dp[n][W];
}
```

#### 3. Space-Optimized Tabulation (1D Array)
Because calculating row `i` only depends on values from row `i-1`, we can store just one row and update it backwards to avoid overwriting values needed in the same iteration step.
```cpp
#include <vector>
#include <algorithm>

int knapsackSpaceOptimized(int W, const std::vector<int>& wt, const std::vector<int>& val) {
    int n = wt.size();
    std::vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        // Iterate backwards to prevent using the same item multiple times
        for (int w = W; w >= wt[i]; --w) {
            dp[w] = std::max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}
```
