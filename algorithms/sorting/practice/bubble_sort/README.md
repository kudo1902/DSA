# Practice: Bubble Sort

Implement the classic Bubble Sort algorithm in C++.

## Problem Description

Given an unsorted array of integers, sort the array in ascending order using the Bubble Sort algorithm.

### Example
* **Input**: `[5, 1, 4, 2, 8]`
* **Output**: `[1, 2, 4, 5, 8]`

## Algorithm Description

Bubble Sort works by repeatedly swapping adjacent elements if they are in the wrong order. 
* In each pass through the array, the largest unsorted element "bubbles up" to its correct position at the end.
* **Optimization**: If a pass completes without any swaps, the array is already sorted, and we can terminate early.

### Complexity
- **Time Complexity**:
  - Best Case: $O(N)$ (when the array is already sorted, with optimization)
  - Average Case: $O(N^2)$
  - Worst Case: $O(N^2)$
- **Space Complexity**: $O(1)$ auxiliary space (in-place)
