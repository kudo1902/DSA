# Data Structures and Algorithms (DSA) in C++

Welcome to my repository for learning and practicing Data Structures and Algorithms! This repository is organized systematically to build deep theoretical understanding and practical problem-solving skills in C++.

## Repository Structure

Each topic (e.g., sorting, searching, trees, graphs) is structured into two main parts:
1. **Theory**: Contains explanations, time/space complexity analysis, and visualization notes.
2. **Practice**: Contains individual subfolders for each problem, including:
   - A `README.md` describing the problem statement and approach.
   - C++ solution code and test runners.

```text
DSA/
├── README.md                      # Main roadmap and structure
├── .gitignore                     # C++ specific gitignore
└── algorithms/
    └── [category]/                # e.g., sorting, searching
        ├── theory/
        │   └── README.md          # Theoretical concept guide
        └── practice/
            └── [problem_name]/    # e.g., bubble_sort, quick_sort, binary_search
                ├── README.md      # Problem statement & complexity
                ├── solution.cpp   # Solution implementation
                └── main.cpp       # Driver code & verification
```

## How to Compile and Run Solutions

To run any practice problem, navigate to the problem's directory and compile the files using `g++`:

```bash
# Go to the problem directory
cd algorithms/sorting/practice/bubble_sort

# Compile the solution with driver code
g++ -std=c++17 solution.cpp main.cpp -o main

# Run the executable
./main
```

## Topics Roadmap
- [ ] **Algorithms**
  - [ ] Sorting (Bubble, Selection, Insertion, Merge, Quick, Heap)
  - [ ] Searching (Linear, Binary)
  - [ ] Recursion & Backtracking
  - [ ] Dynamic Programming
  - [ ] Greedy Algorithms
  - [ ] Graph Algorithms
- [ ] **Data Structures** (To be added)
  - [ ] Arrays & Vectors
  - [ ] Linked Lists (Singly, Doubly, Circular)
  - [ ] Stacks & Queues
  - [ ] Trees (BST, AVL, Red-Black)
  - [ ] Heaps & Priority Queues
  - [ ] Hash Tables
  - [ ] Graphs (Adjacency Matrix, List)
